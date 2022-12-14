#ifndef MAGO_H
#define MAGO_H
#include "AtaqueDistancia.hpp"
#include<string>

class Mago: public AtaqueDistancia
{   
    public:
        Mago(const std::string &);
        Mago(const std::string &, bool, bool);
        Mago(const Mago &);
        ~Mago();

        int retornaMana() const;
        void modificaMana(int);

        int escolheAcao() const;
        void mostraAcoes() const;
        int ataqueBasico(int) const;
        int defender(int) const;
        int ataqueCarregado() const;

        int bolaDeFogo();

    private:
        int mana;
        const int MAX_MANA;
    protected:
        bool herdado;

};

#endif // MAGO_H