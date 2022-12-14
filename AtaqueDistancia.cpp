#include "AtaqueDistancia.hpp"
#include<string>

using std::string;

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