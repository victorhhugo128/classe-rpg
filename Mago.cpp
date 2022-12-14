#include<iostream>
#include<string>
#include<cstdlib>
#include "Mago.hpp"

using std::cout;
using std::cin;
using std::string;

Mago::Mago(const string &nome)
:AtaqueDistancia(nome, 150, 10, 3), MAX_MANA(200){
    this->mana = MAX_MANA;
    this->defineClasse("mago");
}

Mago::Mago(const string &nome, bool buff_ataque, bool buff_defesa)
:AtaqueDistancia(nome, buff_ataque, buff_defesa, 150, 10, 3), MAX_MANA(200){
    this->mana = MAX_MANA;
    this->defineClasse("mago");
}

Mago::Mago(const Mago &other)
:AtaqueDistancia(other), MAX_MANA(other.MAX_MANA){
    this->mana = other.mana;
}

Mago::~Mago(){

}

int Mago::retornaMana() const{
    return this->mana;
}

void Mago::modificaMana(int acrescimo){
    this->mana += acrescimo;
}

int Mago::escolheAcao() const{
    int escolha = -1;

    cout << "Escolha uma das ações para o turno do Mago " << this->retornaNome() << ":\n";
    cin >> escolha;
    
    while(escolha < 1 && escolha >  this->retornaNAcoes()){
        cout << "Escolha inválida. Insira um valor válido: ";
        cin >> escolha;
    }

    return escolha;
}

void Mago::mostraAcoes() const{
    cout << "1 - Ataque Básico\n2 - Defender\n3 - Bola de Fogon\n";
}

int Mago::ataqueBasico(int distancia) const{
    int chances = 100, dano_de_ataque = 0;
    float multiplicador = 0;

    if(rand() % chances > 85){ // 15% de chance do ataque falhar
        cout << "O ataque forte de " << this->retornaClasse() << " " << this->retornaNome() << " falhou.\n\n";
        return 0;
    }

    multiplicador = (rand() % chances)/100;

    dano_de_ataque = multiplicador * this->retornaAtaque() + 10;

    cout << "O ataque básico de " << this->retornaClasse() << " " << this->retornaNome() << " acertou!\n\n";

    return dano_de_ataque;
}


int Mago::defender(int dano) const{
    int dano_mitigado = 0;
    float multiplicador = 0;

    if(rand() % 100 > 50){ // 50% de chance de defender corretamente
        cout << "A defesa falhou.\n\n";
        return dano;
    } 

    multiplicador = (rand() % 15)/100; // proporcional a 0 - 15% de mitigação de dano baseado na defesa

    dano_mitigado = dano - this->retornaDefesa()*multiplicador;

    cout << "O " << this->retornaClasse() << " " << this->retornaNome() << " defendeu com sucesso.\n\n";

    return dano;

}

int Mago::bolaDeFogo(){
    if(this->retornaMana() < 40){
        cout << " O mago não pode concluir bola de fogo. Não há mana o suficiente.\n\n";
        return 0;
    }

    if(rand() % 100 > 60){
        cout << "O mago falhou em completar bola de fogo.\n\n";
        return 0;
    }

    int dano = 150;
    float multiplicador = (rand() % 100)/100 * this->retornaAtaque()/3;

    cout << "A bola de fogo de " << this->retornaClasse() << " " << this->retornaNome() << " foi um sucesso.\n\n";

    return dano * multiplicador;
}