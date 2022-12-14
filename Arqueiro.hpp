#ifndef ARQUEIRO_H
#define ARQUEIRO_H
#include "AtaqueDistancia.hpp"
#include<string>

class Arqueiro: public AtaqueDistancia
{
    public:
        Arqueiro(const std::string &);
        Arqueiro(const std::string &, bool, bool);
        Arqueiro(const Arqueiro &);
        ~Arqueiro();

        int retornaStamina() const;
        void modificaStamina(int);
        int escolheAcao() const;
        void mostraAcoes() const;
        int ataqueBasico(int) const;
        int defender(int) const;

        int chuvaDeFlechas();

    private:
        int stamina;
        const int MAX_STAMINA;
};

#endif // ARQUEIRO_H