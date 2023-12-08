Aluno: Felipe Da Silva Fadel

Projeto: Omnichord

O Omnichord é um instrumento eletronico, com ideia similiar a do acordeão. Desenvolvido em c++ 
"qwertyuio" são teclas referentes a acordes maiores
"asdfghjkl" são teclas referentes a acordes menores
"zxcvbnm,." são teclas referentes a acordes com a 7 dominante

Ao pressionar espaço as notas sáo escritas em um arquivo de texto que fica na pasta.
O tempo pode ser mudado atraves das seta pra cima ou pra baixo
E pode mudar entre duas oitavas atraves do botão enter do numPad

A aplicação foi feita usando a biblioteca SDL e SDL_mixer. Tanto para a parte grafica quanto para parte sonora

Comando pra compilação:
g++ main.cpp sdlFunctions.cpp instrumento.cpp nota.cpp acorde.cpp major.cpp minor.cpp seventh.cpp -o main -lSDL2 -lSDL2_image -lSDL2_mixer

nescessario instalar a biblioteca SDL2 e SDL_mixer, no linux basta usar "sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev"


Link da biblioteca no GitHub (SDL2)
https://github.com/libsdl-org/SDL/releases/tag/release-2.28.0

Link da biblioteca no Github (SDL2_mixer)
https://github.com/libsdl-org/SDL_mixer
