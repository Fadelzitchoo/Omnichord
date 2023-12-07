#ifndef ACORDE_HPP
#define ACORDE_HPP

using namespace std;

#include"nota.hpp"
#include"instrumento.hpp"

class Acorde : public Instrumento{                                      //deriva Instrumento,  que armazena o tempo e o volume
    protected:
        Nota root;                  //NotaPrincipal
        Nota third;                 //TerceiraNota
        Nota fifth;                 //QuintaNota
        Nota extra; 
    public:
        Acorde(Nota root, Nota third, Nota fifth);
        virtual void reproduzAcorde(bool keyPressed) = 0;               //Metodo puro
        void pararReproducao();
        
        ~Acorde();
};

#endif
