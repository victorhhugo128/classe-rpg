#include "Clerigo.hpp"
#include<iostream>
#include<string>

using std::string;
using std::cout;

Clerigo::Clerigo(const string &nome, int armadura)
:Guerreiro(nome, armadura), MAX_MANA(200){
    this->defineClasse("clérigo");
    this->herdado = true;
    this->mana = 200;
}

Clerigo::Clerigo(const string &nome, float porcento_stamina, bool buff_ataque, bool buff_defesa, int armadura)
:Guerreiro(nome, porcento_stamina, buff_ataque, buff_defesa, armadura), MAX_MANA(300){
    this->defineClasse("clérigo");
    this->herdado = true;
    this->mana = 200;
}

Clerigo::Clerigo(const Clerigo &other)
:Guerreiro(other), MAX_MANA(other.MAX_MANA){
    this->mana = other.mana;
}

Clerigo::~Clerigo(){

}

void Clerigo::curar(){
    int cura = 40;

    this->modificaHp(40);
    cout << "HP de " << this->retornaClasse() << " " << this->retornaNome() << " aumentado para " << this->retornaHp() << ".\n\n";
}