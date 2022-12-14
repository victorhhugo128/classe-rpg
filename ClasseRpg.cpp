#include "ClasseRpg.hpp"
#include<iostream>
#include<string>

using std::string;
using std::cout;

ClasseRpg::ClasseRpg(const string &nome, int ataque, int defesa, int n_acoes)
:MAX_HP(5000), N_ACOES(n_acoes)
{
    this->nome = nome;
    this->hp = 5000;
    this->ataque = ataque;
    this->defesa = defesa;
    this->classe = "";
}

ClasseRpg::ClasseRpg(const string &nome, bool buff_ataque, bool buff_defesa, int ataque, int defesa, int n_acoes)
:MAX_HP(5000), N_ACOES(n_acoes)
{   
    this->nome = nome;
    this->hp = 5000;
    this->ataque = ataque;
    this->defesa = defesa;
    this->classe = "";
    this->buff_ataque = buff_ataque;
    this->buff_defesa = buff_defesa;
}

ClasseRpg::ClasseRpg(const ClasseRpg &other)
:MAX_HP(5000), N_ACOES(other.N_ACOES)
{   
    this->nome = other.nome;
    this->hp = other.hp;
    this->ataque = other.ataque;
    this->defesa = other.defesa;
    this->classe = other.classe;
}

ClasseRpg::~ClasseRpg()
{

}

void ClasseRpg::mostrarAtributos() const{
    cout << "Nome: " << this->nome 
    << "\nHP: " << this->hp
    << "\nAtaque: " << this->ataque
    << "\nDefesa: " << this->defesa
    << "\n";
}

int ClasseRpg::retornaHp() const{
    return this->hp;
}

int ClasseRpg::retornaAtaque() const{
    return this->ataque;
}

int ClasseRpg::retornaDefesa() const{
    return this->defesa;
}

int ClasseRpg::retornaMaxHp() const{
    return this->MAX_HP;
}

int ClasseRpg::retornaNAcoes() const{
    return this->N_ACOES;
}

bool ClasseRpg::retornaAtordoado() const{
    return this->atordoado;
}

bool ClasseRpg::retornaDefendendo() const{
    return this->defendendo;
}

bool ClasseRpg::retornaCongelado() const{
    return this->congelado;
}

void ClasseRpg::modificaAtaque(int acrescimo){
    this->ataque += acrescimo;
}

void ClasseRpg::modificaDefesa(int acrescimo){
    this->defesa += acrescimo;
}

void ClasseRpg::modificaHp(int acrescimo){
    if(this->hp + acrescimo > MAX_HP){
        this->hp = MAX_HP;
        return;
    }
    this->hp += acrescimo;
}

void ClasseRpg::modificaAtordoado(bool novo_estado){
    this->atordoado = novo_estado;
}

void ClasseRpg::modificaDefendendo(bool novo_estado){
    this->defendendo = novo_estado;
}

void ClasseRpg::modificaCongelado(bool novo_estado){
    this->congelado = novo_estado;
}

void ClasseRpg::defineClasse(const string &classe){
    this->classe = classe;
}

string ClasseRpg::retornaNome() const{
    return this->nome;
}

string ClasseRpg::retornaClasse() const{
    return this->classe;
}