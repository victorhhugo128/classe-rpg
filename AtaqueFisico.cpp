#include "AtaqueFisico.hpp"
#include<iostream>
#include<string>

using std::string;

AtaqueFisico::AtaqueFisico(const string &nome, int ataque, int defesa, int n_acoes)
:ClasseRpg(nome, ataque, defesa, n_acoes), MAX_STAMINA(200){
    this->stamina = MAX_STAMINA;
}

AtaqueFisico::AtaqueFisico(const string &nome, float porcento_stamina, bool buff_ataque, bool buff_defesa, int ataque, int defesa, int n_acoes)
:ClasseRpg(nome, buff_ataque, buff_defesa, ataque, defesa, n_acoes), MAX_STAMINA(200){
    this->stamina = porcento_stamina/100 * MAX_STAMINA;
}

AtaqueFisico::AtaqueFisico(const AtaqueFisico &other)
:ClasseRpg(other), MAX_STAMINA(200){
    this->stamina = other.stamina;
}

AtaqueFisico::~AtaqueFisico(){

}

int AtaqueFisico::retornaStamina() const{
    return this->stamina;
}

int AtaqueFisico::retornaMaxStamina() const{
    return this->MAX_STAMINA;
}

void AtaqueFisico::modificaStamina(int acrecimo){
    this->stamina += acrecimo;
}