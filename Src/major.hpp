#ifndef MAJOR_HPP
#define MAJOR_HPP

using namespace std;

#include"acorde.hpp"
#include<vector>

class Major : public Acorde{
    public:
        Major(Nota root, Nota third, Nota fifth) : Acorde(root, third, fifth) {}
        Major(const vector<Nota>* notas, int rootX) : Acorde((*notas)[rootX], (*notas)[rootX + 4], (*notas)[rootX + 7]) {}
        void reproduzAcorde(bool keyPressed);
        Major operator+(const Nota &nota);
};


#endif