#ifndef ASSASSINO_H
#define ASSASSINO_H
#include "AtaqueFisico.hpp"

class Assassino: public AtaqueFisico
{
    public:
        Assassino(const std::string &, int = 20);
        Assassino(const std::string &, float, bool, bool, int);
        Assassino(const Assassino &);
        ~Assassino();

        int retornaAstucia() const;
        int escolheAcao() const;
        void mostraAcoes() const;
        int ataqueBasico(int) const;
        int defender(int) const;
        int ataqueForte(int);

        int ataqueFlanqueado(int);
        void recebeDano(int);
    private:
        int astucia;
};

#endif