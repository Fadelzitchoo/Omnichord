#include"seventh.hpp"

void Seventh::reproduzAcorde(bool keyPressed) {                 //Reproduz 4 notas ao inves de 3
    if (keyPressed == 1) {
        Mix_PlayChannel(-1, root.getNota(), 0);
        Mix_PlayChannel(-1, third.getNota(), 0);
        Mix_PlayChannel(-1, fifth.getNota(), 0);
        Mix_PlayChannel(-1, seventh.getNota(), 0);
    } else {
            Mix_HaltChannel(-1);
    }
}
