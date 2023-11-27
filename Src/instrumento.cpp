#include "instrumento.hpp"

Instrumento::Instrumento(){
    volume = 100;
    tempo = 120;
}

Instrumento::Instrumento(int volume, int tempo){
    this->volume = volume;
    this->tempo = tempo;
}

void Instrumento::setVolume(int volume){
    this->volume = volume;
}

int Instrumento::getVolume(){
    return volume;
}

void Instrumento::setTempo(int tempo){
    this->tempo = tempo;
}

int Instrumento::getTempo(){
    return tempo;
}
