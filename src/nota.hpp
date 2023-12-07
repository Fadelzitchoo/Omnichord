#ifndef NOTA_HPP
#define NOTA_HPP

#include<string>
#include<SDL2/SDL.h>
#include<SDL2/SDL_mixer.h>
#include<iostream>

using namespace std;

class Nota{
    private:
        Mix_Chunk *root;
        int ticks;
    public:
        Nota();
        Nota(string rootName);
        bool reproduzSom(bool keyPressed);

        void setNota(string rootName);
        Mix_Chunk *getNota();
};

#endif