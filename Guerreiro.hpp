#ifndef GUERREIRO_H
#define GUERREIRO_H
#include "AtaqueFisico.hpp"
#include<string>

class Guerreiro: public AtaqueFisico
{
    public:
        Guerreiro(const std::string &, int = 20);
        Guerreiro(const std::string &, float, bool, bool, int);
        Guerreiro(const Guerreiro &);
        ~Guerreiro();

        int retornaArmadura() const;
        int escolheAcao() const;
        void mostraAcoes() const;
        int ataqueBasico(int) const;
        int defender(int) const;
        int ataqueForte(int);

        bool atordoar();
        int defesaForte(int) const;
        void recebeDano(int);
    private:
        int armadura;
    protected:
        bool herdado;
};

#endif // GUERREIRO_H