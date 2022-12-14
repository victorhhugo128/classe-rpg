#include "Feiticeiro.hpp"
#include<iostream>
#include<string>

using std::string;
using std::cout;

Feiticeiro::Feiticeiro(const string &nome)
:Mago(nome){
    this->defineClasse("feiticeiro");
    this->herdado = true;
}

Feiticeiro::Feiticeiro(const string &nome, bool buff_ataque, bool buff_defesa)
:Mago(nome, buff_ataque, buff_defesa){
    this->defineClasse("feiticeiro");
    this->herdado = true;
}

Feiticeiro::Feiticeiro(const Feiticeiro &other)
:Mago(other){
}

Feiticeiro::~Feiticeiro(){

}

bool Feiticeiro::congelar() const{
    if(rand() % 100 > 60){ // 40% de chance do movimento falhar
        cout << "O congelamento falhou.\n\n";
        return false;
    }
    
    cout << "O congelamento funcionou!\n\n";

    return true;
}