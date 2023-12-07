#include"minor.hpp"

void Minor::reproduzAcorde(bool keyPressed) {
    if (keyPressed == 1) {
        Mix_PlayChannel(-1, root.getNota(), 0);
        Mix_PlayChannel(-1, third.getNota(), 0);
        Mix_PlayChannel(-1, fifth.getNota(), 0);
    } else {
            Mix_HaltChannel(-1);
    }
}
