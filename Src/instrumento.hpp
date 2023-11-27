#ifndef INSTRUMENTO_HPP
#define INSTRUMENTO_HPP

class Instrumento{                          //Classe paizao
    private:
        int volume;
        int tempo;
    public:
        Instrumento();
        Instrumento(int volume, int tempo);
        
        void setVolume(int volume);
        int getVolume();

        virtual void setTempo(int tempo);
        int getTempo();
};

#endif