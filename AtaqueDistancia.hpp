#ifndef ATAQUE_DISTANCIA
#define ATAQUE_DISTANCIA
#include "ClasseRpg.hpp"
#include<string>

class AtaqueDistancia: public ClasseRpg
{
    public:
        AtaqueDistancia(const std::string &, int = 0, int = 0, int = 0);
        AtaqueDistancia(const std::string &, bool, bool, int = 0, int = 0, int = 0);
        AtaqueDistancia(const AtaqueDistancia &);
        ~AtaqueDistancia();
        virtual int ataqueCarregado() = 0;

        void modificaCarregandoAtaque(bool);
    private:
        bool carregando_ataque;
};


#endif // ATAQUE_DISTANCIA