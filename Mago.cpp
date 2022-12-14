#include<iostream>
#include<string>
#include<cstdlib>
#include "Mago.hpp"

using std::cout;
using std::cin;
using std::string;

Mago::Mago(const string &nome)
:AtaqueDistancia(nome, 150, 10, 4), MAX_MANA(200){
    this->mana = MAX_MANA;
    this->defineClasse("mago");
    this->herdado = false;
}

Mago::Mago(const string &nome, bool buff_ataque, bool buff_defesa)
:AtaqueDistancia(nome, buff_ataque, buff_defesa, 150, 10, 4), MAX_MANA(200){
    this->mana = MAX_MANA;
    this->defineClasse("mago");
    this->herdado = false;
}

Mago::Mago(const Mago &other)
:AtaqueDistancia(other), MAX_MANA(other.MAX_MANA){
    this->mana = other.mana;
    this->herdado = other.herdado;
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
    int escolha = -1, limite_superior = this->retornaNAcoes();

    cout << "Escolha uma das ações para o turno do Mago " << this->retornaNome() << ":\n";
    this->mostraAcoes();
    cin >> escolha;

    if(this->herdado)
        limite_superior += 1;
    
    while(escolha < 1 || escolha >  limite_superior){
        cout << "Escolha inválida. Insira um valor válido: ";
        cin >> escolha;
    }

    return escolha;
}

void Mago::mostraAcoes() const{
    cout << "1 - Ataque Básico\n2 - Defender\n3 - Ataque Carregado\n4 - Bola de fogo\n";
    if(this->herdado)
        cout << "5 - Congelar\n";
    cout << "\n";
}

int Mago::ataqueBasico(int distancia) const{
    int chances = 100, dano_de_ataque = 0;
    float multiplicador = 0, num_rand = rand() % chances;

    if(rand() % chances > 85){ // 15% de chance do ataque falhar
        cout << "O ataque forte de " << this->retornaClasse() << " " << this->retornaNome() << " falhou.\n\n";
        return 0;
    }

    multiplicador = num_rand/100;

    dano_de_ataque = multiplicador * this->retornaAtaque() + 10;

    cout << "O ataque básico de " << this->retornaClasse() << " " << this->retornaNome() << " acertou!\n\n";

    return dano_de_ataque;
}


int Mago::defender(int dano) const{
    int dano_mitigado = 0;
    float multiplicador = 0, num_rand = rand() % 15;

    if(rand() % 100 > 50){ // 50% de chance de defender corretamente
        cout << "A defesa falhou.\n\n";
        return dano;
    } 

    multiplicador = num_rand/100; // proporcional a 0 - 15% de mitigação de dano baseado na defesa

    dano_mitigado = dano - this->retornaDefesa()*multiplicador;

    cout << "O " << this->retornaClasse() << " " << this->retornaNome() << " defendeu com sucesso.\n\n";

    return dano;

}

int Mago::ataqueCarregado() const{
    cout << " O ataque carregado de " << this->retornaClasse() << " " << this->retornaNome() << " foi um sucesso!\n\n";
    return this->retornaAtaque() * 3;
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
    float num_rand = rand() % 100, multiplicador = num_rand/100 * this->retornaAtaque()/3;

    cout << "A bola de fogo de " << this->retornaClasse() << " " << this->retornaNome() << " foi um sucesso.\n\n";

    return dano * multiplicador;
}