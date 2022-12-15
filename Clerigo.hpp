#ifndef CLERIGO_H
#define CLERIGO_H
#include<string>
#include "Guerreiro.hpp"

class Clerigo: public Guerreiro
{
    public: 
        Clerigo(const std::string &, int = 15);
        Clerigo(const std::string &, float, bool, bool, int);
        Clerigo(const Clerigo &);
        ~Clerigo();

        int retornaMana() const;
        void modificaMana(int);
        void curar();
    private:
        int mana;
        const int MAX_MANA;
};


#endif