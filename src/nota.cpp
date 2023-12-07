#include"nota.hpp"

Nota::Nota(){
    root = NULL;
}

Nota::Nota(string rootName){                                        
    this->ticks = ticks;
    root = Mix_LoadWAV(rootName.c_str());                               //Comeca a apontar pro chunck onde fica o .wav
    if(root == NULL){                                                   
        cout << "Não carrego o som, erro: " << Mix_GetError() << endl;
    }
}

bool Nota::reproduzSom(bool keyPressed) {                               //Metodos que reproduz as notas individuamente
    if (keyPressed) {
        if (Mix_Playing(-1) == 0) {
            Mix_PlayChannel(-1, root, -1); // Reproduz o som em loop
        }
    } else {
        if (Mix_Playing(-1) != 0) {
            Mix_HaltChannel(-1); // Interrompe a reprodução do som
        }
    }

    return true;
}

void Nota::setNota(string rootName){                                    
    root = Mix_LoadWAV(rootName.c_str());
    if(root == NULL){
        cout << "Não carrego o som, erro: " << Mix_GetError() << endl;
    }
}

Mix_Chunk *Nota::getNota(){
    return root;
}