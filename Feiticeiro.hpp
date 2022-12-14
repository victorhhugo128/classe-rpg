#ifndef FEITICEIRO_H
#define FEITICEIRO_H
#include "Mago.hpp"
#include<string>

class Feiticeiro: public Mago
{
    public:
        Feiticeiro(const std::string &);
        Feiticeiro(const std::string &, bool, bool);
        Feiticeiro(const Feiticeiro &);
        ~Feiticeiro();

        bool congelar() const;
};


#endif