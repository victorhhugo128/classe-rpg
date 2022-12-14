#include "Arqueiro.hpp"
#include<iostream>
#include<string>
#include<cstdlib>

using std::cout;
using std::cin;
using std::string;

Arqueiro::Arqueiro(const string &nome)
:AtaqueDistancia(nome, 100, 30, 3), MAX_STAMINA(200){
    this->stamina = MAX_STAMINA;
    this->defineClasse("arqueiro");
}

Arqueiro::Arqueiro(const string &nome, bool buff_ataque, bool buff_defesa)
:AtaqueDistancia(nome, buff_ataque, buff_defesa, 100, 30, 3), MAX_STAMINA(200){
    this->stamina = MAX_STAMINA;
    this->defineClasse("arqueiro");
}

Arqueiro::Arqueiro(const Arqueiro &other)
:AtaqueDistancia(other), MAX_STAMINA(other.MAX_STAMINA){
    this->stamina = other.stamina;
}

Arqueiro::~Arqueiro(){

}

int Arqueiro::retornaStamina() const{
    return this->stamina;
}

void Arqueiro::modificaStamina(int acrescimo){
    this->stamina += acrescimo;
}

int Arqueiro::escolheAcao() const{
    int escolha = -1;

    cout << "Escolha uma das ações para o turno do Arqueiro " << this->retornaNome() << ":\n";
    cin >> escolha;
    
    while(escolha < 1 && escolha >  this->retornaNAcoes()){
        cout << "Escolha inválida. Insira um valor válido: ";
        cin >> escolha;
    }

    return escolha;
}

void Arqueiro::mostraAcoes() const{
    cout << "1 - Ataque Básico\n2 - Defender\n3 - Chuva de Flechasn\n";
}

int Arqueiro::ataqueBasico(int distancia) const{
    int chances = 100, dano_de_ataque = 0;
    float multiplicador = 0;

    if(rand() % chances > 98){ // 2% de chance do ataque falhar
        cout << "O ataque forte de " << this->retornaClasse() << " " << this->retornaNome() << " falhou.\n\n";
        return 0;
    }

    multiplicador = (rand() % chances)/100;

    dano_de_ataque = multiplicador * this->retornaAtaque() + 45;

    cout << "O ataque básico de " << this->retornaClasse() << " " << this->retornaNome() << " acertou!\n\n";

    return dano_de_ataque;
}


int Arqueiro::defender(int dano) const{
    int dano_mitigado = 0;
    float multiplicador = 0;

    if(rand() % 100 > 60){ // 60% de chance de defender corretamente
        cout << "A defesa falhou.\n\n";
        return dano;
    } 

    multiplicador = (rand() % 30 + 5)/100; // proporcional a 5 - 35% de mitigação de dano baseado na defesa

    dano_mitigado = dano - this->retornaDefesa()*multiplicador;

    cout << "O " << this->retornaClasse() << " " << this->retornaNome() << " defendeu com sucesso.\n\n";

    return dano;

}


int Arqueiro::chuvaDeFlechas(){
    if(this->retornaStamina() < 30){
        cout << "Não há stamina suficiente para concluir ataque chuva de flechas. Ataque falhou.\n\n";
        return 0;
    }

    int n_flechas = rand() % 4 + 2; // de 2 a 6 flechas
    int dano = 0;

    for(int ataque = 0; ataque < n_flechas; ataque++){
        dano += this->retornaAtaque() * (rand() % 4 + 2)/4;
    }

    cout << "A chuva de flechas de " << this->retornaClasse() << " " << this->retornaNome() << " acertou " << n_flechas << " vezes!!\n\n";

    this->modificaStamina(-30);

    return dano;

}