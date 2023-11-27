#ifndef SEVENTH_HPP
#define SEVENTH_HPP

using namespace std;

#include "nota.hpp"
#include "acorde.hpp"
#include <vector>

class Seventh : public Acorde{
    private:
        Nota seventh;                                           //Possui uma nota a mais, a setima dominante da tonica
    public:
        Seventh(Nota root, Nota third, Nota fifth) : Acorde(root, third, fifth) {}
        Seventh(const vector<Nota>* notas, int rootX) : Acorde((*notas)[rootX], (*notas)[rootX + 4], (*notas)[rootX + 7]), seventh((*notas)[rootX + 10]) {}
        void reproduzAcorde(bool keyPressed);
};

#endif