#ifndef MINOR_HPP
#define MINOR_HPP

using namespace std;

#include "nota.hpp"
#include "acorde.hpp"
#include <vector>

class Minor : public Acorde{
    public:
        Minor(Nota root, Nota third, Nota fifth) : Acorde(root, third, fifth) {}
        Minor(const vector<Nota>* notas, int rootX) : Acorde((*notas)[rootX], (*notas)[rootX + 3], (*notas)[rootX + 7]) {}
        void reproduzAcorde(bool keyPressed);
};

#endif
