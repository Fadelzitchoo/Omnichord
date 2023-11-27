#include"major.hpp"
#include<vector>

void Major::reproduzAcorde(bool keyPressed) {               //Reproduz os acordes enquanto a tecla for pressionada
    if (keyPressed == 1) {
        Mix_PlayChannel(-1, root.getNota(), 0);
        Mix_PlayChannel(-1, third.getNota(), 0);
        Mix_PlayChannel(-1, fifth.getNota(), 0);
        if(extra.getNota() != nullptr)                      //se nota extra existir reproduz ela
            Mix_PlayChannel(-1, extra.getNota(), 0);        
    } else {
            Mix_HaltChannel(-1);
    }
}

Major Major::operator+(const Nota &nota){                   //retorna um acorde com a nota extra incluida
    Major majorComExtra(*this);
    majorComExtra.extra = nota;
    return majorComExtra;
}



