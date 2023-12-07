#ifndef SDLFUNCTION_HPP
#define SDLFUNCTION_HPP

#include<SDL2/SDL.h>
#include<string>
#include<map>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

using namespace std;

void KeyboardEvent(SDL_Event event);
void destruirTudo(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Texture* corpoOmni, SDL_Texture* Potenciometro, SDL_Window *window);
string nomeNota(int i);
int retornaTecla(SDL_Event event);
int retornaTipo(SDL_Event event);
int mudarOitava(bool *oitava);

#endif