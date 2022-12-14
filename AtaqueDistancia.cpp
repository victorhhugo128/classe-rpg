#include "AtaqueDistancia.hpp"
#include<string>
#include<iostream>

using std::string;
using std::cout;

AtaqueDistancia::AtaqueDistancia(const string &nome, int ataque, int defesa, int n_acoes)
:ClasseRpg(nome, ataque, defesa, n_acoes){
    this->carregando_ataque = false;

}

AtaqueDistancia::AtaqueDistancia(const string &nome, bool buff_ataque, bool buff_defesa, int ataque, int defesa, int n_acoes)
:ClasseRpg(nome, buff_ataque, buff_defesa, ataque, defesa, n_acoes){
    this->carregando_ataque = false;

}

AtaqueDistancia::AtaqueDistancia(const AtaqueDistancia &other)
:ClasseRpg(other){
    this->carregando_ataque = other.carregando_ataque;
}

AtaqueDistancia::~AtaqueDistancia(){

}

void AtaqueDistancia::modificaCarregandoAtaque(bool novo_estado){
    this->carregando_ataque = novo_estado;
}

bool AtaqueDistancia::retornaCarregandoAtaque() const{
    return this->carregando_ataque;
}

void AtaqueDistancia::recebeDano(int dano){
    cout << "O " << this->retornaClasse() << " " << this->retornaNome() << " perdeu " << dano << " de HP.\n\n";

    this->modificaHp(-dano);
}