#include"acorde.hpp"

Acorde::Acorde(Nota root, Nota third, Nota fifth) : Instrumento(){
    this->root = root;
    this->third = third;
    this->fifth = fifth;
}

Acorde::~Acorde(){              //Ao destruir a classe
    pararReproducao();          
}

void Acorde::pararReproducao(){
    Mix_HaltChannel(-1);
}
