#ifndef ATAQUEFISICO_H
#define ATAQUEFISICO_H
#include "ClasseRpg.hpp"
#include<string> 

class AtaqueFisico: public ClasseRpg
{
    public: 
        AtaqueFisico(const std::string &, int = 0, int = 0, int = 0);
        AtaqueFisico(const std::string &, float, bool, bool, int = 0, int = 0, int = 0);
        AtaqueFisico(const AtaqueFisico &);
        virtual ~AtaqueFisico();
        virtual int ataqueForte(int) = 0;
        int retornaStamina() const;
        int retornaMaxStamina() const;
        void modificaStamina(int);
    private:
        const int MAX_STAMINA;
    protected:
        int stamina;
};

#endif // ATAQUEFISICO_H