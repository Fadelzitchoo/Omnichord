#include<SDL2/SDL.h>
#include <iostream>
#include<SDL2/SDL_image.h>
#include"sdlFunctions.hpp"

map<SDL_Keycode, int> teclasMapeadas = {            //Mapeamento das teclas e as notas referentes a ela
    {SDLK_q, 3},  {SDLK_w, 10}, {SDLK_e, 5},  {SDLK_r, 0},  {SDLK_t, 7},  {SDLK_y, 2},  {SDLK_u, 9},  {SDLK_i, 4},      {SDLK_o, 11},
    {SDLK_a, 3},  {SDLK_s, 10}, {SDLK_d, 5},  {SDLK_f, 0},  {SDLK_g, 7},  {SDLK_h, 2},  {SDLK_j, 9},  {SDLK_k, 4},      {SDLK_l, 11},
    {SDLK_z, 3},  {SDLK_x, 10}, {SDLK_c, 5},  {SDLK_v, 0},  {SDLK_b, 7},  {SDLK_n, 2},  {SDLK_m, 9},  {SDLK_COMMA, 4},  {SDLK_PERIOD, 11},
};

map<SDL_Keycode, int> mapTipo = {                   //Map dos tipos de teclas, Linhas superior, central e inferior
    {SDLK_q, 1},  {SDLK_w, 1}, {SDLK_e, 1},  {SDLK_r, 1},  {SDLK_t, 1},  {SDLK_y, 1},  {SDLK_u, 1},  {SDLK_i, 1},      {SDLK_o, 1},
    {SDLK_a, 2},  {SDLK_s, 2}, {SDLK_d, 2},  {SDLK_f, 2},  {SDLK_g, 2},  {SDLK_h, 2},  {SDLK_j, 2},  {SDLK_k, 2},      {SDLK_l, 2},
    {SDLK_z, 3},  {SDLK_x, 3}, {SDLK_c, 3},  {SDLK_v, 3},  {SDLK_b, 3},  {SDLK_n, 3},  {SDLK_m, 3},  {SDLK_COMMA, 3},  {SDLK_PERIOD, 3},
    {SDLK_KP_ENTER, 4},        {SDLK_UP, 5}, {SDLK_DOWN, 6}, {SDLK_1, 7}, {SDLK_2, 8}, {SDLK_3, 9},  {SDLK_SPACE, 10}
};

int retornaTecla(SDL_Event event) {                 //Retorna a nota mapeada ou manda um excecao -1
    if (event.type == SDL_KEYDOWN) {
        auto it = teclasMapeadas.find(event.key.keysym.sym);
        if (it != teclasMapeadas.end()) {
            return it->second;
        }
    }
    throw -1;
}

int retornaTipo(SDL_Event event) {                  //retorna as linhas mapeadas
    if (event.type == SDL_KEYDOWN) {
        auto it = mapTipo.find(event.key.keysym.sym);
        if (it != mapTipo.end()) {
            return it->second;
        }
    }
    return 1;
}

void destruirTudo(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Texture* corpoOmni, SDL_Texture* Potenciometro, SDL_Window *window){
    SDL_DestroyTexture(texture);                            
    SDL_DestroyTexture(corpoOmni);
    SDL_DestroyTexture(Potenciometro);
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

string nomeNota(int i){
    switch (i){
    case 0:
        return "C.wav";
    case 1:
        return "C#.wav";
        break;
    case 2:
        return "D.wav";
        break;
    case 3:
        return "D#.wav";
        break;
    case 4:
        return "E.wav";
        break;
    case 5:
        return "F.wav";
        break;
    case 6:
        return "F#.wav";
        break;
    case 7:
        return "G.wav";
        break;
    case 8:
        return "G#.wav";
        break;
    case 9:
        return "A.wav";
        break;
    case 10:
        return "A#.wav";
        break;
    case 11:
        return "B.wav";
        break;
    }
    return"C.wav";
}

int mudarOitava(bool *oitava){              //12 eh uma oitava acima, visto os 12 semtions
    if((*oitava) == true){
        (*oitava) = false;
        return 12;
    }
    if((*oitava) == false){
        (*oitava) = true;
        return 0;
    }
    return 0;
}