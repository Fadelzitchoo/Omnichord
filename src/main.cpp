    #include <stdlib.h>
    #include <vector>
    #include <string>

    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include <SDL2/SDL_mixer.h>
    #include <fstream>                                  //Biblioteca pra mexer com arquvios

    #include "sdlFunctions.hpp"	
    #include "instrumento.hpp"
    #include "nota.hpp"
    #include "acorde.hpp"
    #include "major.hpp"
    #include "minor.hpp"
    #include "seventh.hpp"

    using namespace std;

    #define SCREEN_WIDTH 1280	//Especificação do tamnho da tela
    #define SCREEN_HEIGHT 720

    int main(){

        string location = "resources/Audio/";               //Diretorio padrao dos audios

        SDL_Event event;
        SDL_Renderer* renderer = NULL;
        SDL_Texture* texture = NULL;                        //SDL_... são para o funcionamento da biblioteca SDL
        SDL_Texture* corpoOmni = NULL;
        SDL_Texture* Potenciometro;
        SDL_Window* window = NULL;

        bool teclaPressionada = false, OitavaBool = false, rep = false, rec = false, arqLimpo = false, tickFim;
        int notaInt, oitava = 0, tempo = 100, mod = 0, contador = 0;
	
	cout << "Digite o tempo: ";			//Definições iniciais
   	cin >> tempo;
	cout << "\ndigite a oitava (0 ou 1): ";
	cin >> oitava;
	cout << endl;

	if(oitava > 1)
		oitava = 1;
	else
		oitava = 0;

        SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO | SDL_INIT_AUDIO); //Inicialiação do SDL
        IMG_Init(IMG_INIT_PNG);

        Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);          //Criar um device de audio

        SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);    //Cria a nova janela
        SDL_SetWindowTitle(window, "Omnichord");
        texture = IMG_LoadTexture(renderer, "resources/Fundo.jpeg");

        corpoOmni = IMG_LoadTexture(renderer, "resources/Omnichord.png");
        Potenciometro = IMG_LoadTexture(renderer, "resources/Potenciometro.png");

        SDL_Rect corpoRect = { 100, 50, 1100, 599 };
        SDL_Rect PoteRect  = { 217, 125, 60, 62 };      // Div 1, Parte superior
        SDL_Rect PoteRect2 = { 264, 143, 60, 62 };      // Div 1, Parte superior
        SDL_Rect PoteRect3 = { 309, 162, 60, 62 };      // Div 1, Parte superior
        SDL_Rect PoteRect4 = { 199, 307, 60, 62 };      // Div 2, Parte Meio
        SDL_Rect PoteRect5 = { 245, 326, 60, 62 };      // Div 2, Parte Meio
        SDL_Rect PoteRect6 = { 207, 410, 60, 62 };      // Div 3, Parte Baixo

        Instrumento instru1;
        Instrumento instru2(100, 30);			//Exemplo de criação de instruments=os

        vector<Nota> notas;                             //Vetor de notas, 36 notas, 3 oitavas, 12³

        int j = 2;
        while(j < 5){
            for(int i = 0; i < 12; i++){
                string locationFinal = location + to_string(j) + nomeNota(i);   //Carrega o diretorio e o nome do arquivo .wav
                Nota notaX(locationFinal);
                notas.push_back(notaX);                                         //Colocar as notas no vetor em ordem crescente
            }
            j++;
        }

        ofstream arquivo("registro.txt", ofstream::out | ofstream::trunc);      //Abre em modo de escrita e limpa o arquvivo quando abre

        while (1) {                                                             //While principal

            Acorde *acorde = nullptr;                                           //Ponteiro da classe base, inicialmente aponto pra nulo

            SDL_RenderCopy(renderer, texture, NULL, NULL);
            SDL_RenderCopy(renderer, corpoOmni, NULL, &corpoRect);

            SDL_RenderCopyEx(renderer, Potenciometro, NULL, &PoteRect,  1, NULL, SDL_FLIP_NONE);        // Div 1, Parte Superior
            SDL_RenderCopyEx(renderer, Potenciometro, NULL, &PoteRect2, 1, NULL, SDL_FLIP_NONE);        // Div 1, Parte Superior
            SDL_RenderCopyEx(renderer, Potenciometro, NULL, &PoteRect3, 1, NULL, SDL_FLIP_NONE);        // Div 1, Parte Superior
            SDL_RenderCopyEx(renderer, Potenciometro, NULL, &PoteRect4, tempo, NULL, SDL_FLIP_NONE);    // Div 2, Parte Meio
            SDL_RenderCopyEx(renderer, Potenciometro, NULL, &PoteRect5, 1, NULL, SDL_FLIP_NONE);        // Div 2, Parte Meio
            SDL_RenderCopyEx(renderer, Potenciometro, NULL, &PoteRect6, 1, NULL, SDL_FLIP_NONE);        // Div 3, Parte Baixo

            SDL_RenderPresent(renderer);

            if (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    delete acorde;
                    break;
                } else if (event.type == SDL_KEYDOWN) {
                    
                    try{                                                //tenta retornar uma tecla que foi estipulada
                        notaInt = retornaTecla(event);
                    }catch(const int ex){                               //caso retorne uma nao existentes
                        if(ex == -1)
                            cout << "Atencao, essa tecla nao tem funcao de nota!" << endl ;
                            notaInt = 0;                                //trata essa execacao colocando um valor padrao
                    }

                    if(retornaTipo(event) == 1){                       //Linha de cima, notas tipo Major
                        acorde = new Major(&notas, notaInt + oitava);
                        if(mod == 1){
                            Major majorCombinado(&notas, notaInt + oitava);
                            majorCombinado = majorCombinado + notas.at(11);         //Sobrecarga do operador +, adiciona uma nota escolhida ao acorde major
                        }                                                           //Nesse exemplo Tranforma o acorde em um Maj7
                    } 
                    else if(retornaTipo(event) == 2){                               //Linha central, acorde menores
                        acorde = new Minor(&notas, notaInt + oitava);
                    }
                    else if(retornaTipo(event) == 3){                               //Linha inferior, acordes com 7 dominante
                        acorde = new Seventh(&notas, notaInt + oitava);
                    }
                    else if(retornaTipo(event) == 4){                               //Muda a oitava, subindo uma ou descendo uma
                        oitava = mudarOitava(&OitavaBool);
                    }
                    else if(retornaTipo(event) == 5){                               //Sobe o tempo
                        if(tempo < 150)
                            tempo = tempo + 10;
                        cout << "Tempo: " << tempo << endl;
                    }
                    else if(retornaTipo(event) == 6){                               //desce o tempo
                        if(tempo > 50)
                            tempo = tempo - 10;
                        cout << "Tempo: " << tempo << endl;
                    }
                    else if(retornaTipo(event) == 7){                               
                        mod = 1;
                    }
                    else if(retornaTipo(event) == 8){
                        mod = 0;
                    }
                    else if(retornaTipo(event) == 9){                               //Liga a reproducacao o arquivo 
                        rep = !rep;
                    }
                    else if(retornaTipo(event) == 10){                              //Liga a gravacao em um arquivo
                        rec = !rec;
                    }

                teclaPressionada = true;

                if(acorde != nullptr && rep == false){
                    if(mod == 0){
                        acorde->setTempo(tempo);
                        acorde->reproduzAcorde(teclaPressionada);                   //Reproduz os sons do acorde
                    }
                }else{
                    if(contador > tempo){                                           
                        contador++;
                        tickFim = true;
                        acorde->reproduzAcorde(tickFim);
                        if(contador + 2 > tempo)
                            tickFim = false;   
                    }
                    else
                        contador = 0;
                }

                if(rec == true){                                                    //Escreve as notas mapeadas no arquivo
                    cout << "Gravando... " << endl;
                    if(arquivo.is_open())
                        arquivo << notaInt;
                }

                } else if (event.type == SDL_KEYUP) {
                    teclaPressionada = false;
                    Mix_HaltChannel(-1);                                            //Para todos os sons
                }
            }
        }

	cout << "finalização do programa" << endl;

        arquivo.close();                                                            //Fecha o arquivo
        destruirTudo(renderer, texture, corpoOmni, Potenciometro, window);          //Desaloca toda a memoria utilizada

        return EXIT_SUCCESS;
    }
    
