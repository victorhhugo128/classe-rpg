#include "Guerreiro.hpp"
#include<iostream>
#include<string>
#include<cstdlib>

using std::string;
using std::cout;
using std::cin;

Guerreiro::Guerreiro(const string &nome, int armadura)
:AtaqueFisico(nome, 90, 60, 4)
{
    this->armadura = armadura;
    this->herdado = false;
    this->defineClasse("guerreiro");
}

Guerreiro::Guerreiro(const string &nome, float porcento_stamina, bool buff_ataque, bool buff_defesa, int armadura)
:AtaqueFisico(nome, porcento_stamina, buff_ataque, buff_defesa, 90, 60, 4)
{
    this->armadura = armadura;
    this->herdado = false;
    this->defineClasse("guerreiro");
}

Guerreiro::Guerreiro(const Guerreiro &other)
:AtaqueFisico(other){
    this->armadura = other.armadura;
    this->herdado = other.herdado;
}

Guerreiro::~Guerreiro(){

}

int Guerreiro::retornaArmadura() const{
    return this->armadura;
}

int Guerreiro::escolheAcao() const{
    int escolha = -1, limite_maior = this->retornaNAcoes();

    cout << "Escolha uma das ações para o turno do Guerreiro " << this->retornaNome() << ":\n";
    cin >> escolha;
    if(this->herdado)
        limite_maior += 1;
    
    while(escolha < 1 && escolha > limite_maior){
        cout << "Escolha inválida. Insira um valor válido: ";
        cin >> escolha;
    }

    return escolha;
}

void Guerreiro::mostraAcoes() const{
    cout << "1 - Ataque Básico\n2 - Defender\n3 - Ataque Forte\n4 - Atordoar\n4 - Defesa Forte";
    if(this->herdado)
        cout << "\n5 - Curar";
    cout << "\n\n";
}


int Guerreiro::ataqueBasico(int distancia) const{
    if(distancia > 2){
        cout << "O " << this->retornaClasse() << " " << this->retornaNome() << " não pode atacar. Ele está muito longe.\n\n";
        return 0;
    }

    int chances = 100, dano_de_ataque = 0;
    float multiplicador = 0;

    if(rand() % chances > 95){ // 5% de chance do ataque falhar
        cout << "O ataque básico de " << this->retornaClasse() << " " << this->retornaNome() << " falhou.\n\n";
        return 0;
    }

    multiplicador = (rand() % chances)/100;

    dano_de_ataque = multiplicador * this->retornaAtaque();

    cout << "O ataque básico de " << this->retornaClasse() << " " << this->retornaNome() << " acertou!\n\n";

    return dano_de_ataque;
}

int Guerreiro::defender(int dano) const{
    int dano_mitigado = 0;
    float multiplicador = 0;

    if(rand() % 100 > 70){ // 70% de chance de defender corretamente
        cout << "A defesa falhou.\n\n";
        return dano;
    } 

    multiplicador = (rand() % 60 + 10)/100; // 10 - 70% de mitigação de dano

    dano_mitigado = dano - this->retornaDefesa()*multiplicador;

    cout << "O " << this->retornaClasse() << " " << this->retornaNome() << " defendeu com sucesso. Sofreu " << dano_mitigado << " de dano.\n\n";

    return dano;

}

int Guerreiro::ataqueForte(int distancia){
    if(this->retornaStamina() < 15){
        cout << "Não há stamina o suficiente. Não foi possível atacar.\n\n";
        return 0;
    }
    if(distancia > 2){
        cout << "O " << this->retornaClasse() << " " << this->retornaNome() << " não pode atacar. Ele está muito longe.\n\n";
        return 0;
    }

    int chances = 100, dano_de_ataque = 0;
    float multiplicador = 0;

    cout << rand() % chances << "\n";

    if(rand() % chances > 80){ // 20% de chance do ataque falhar
        cout << "O ataque forte de " << this->retornaClasse() << " " << this->retornaNome() << " falhou.\n\n";
        return 0;
    }


    multiplicador = (rand() % chances)/100;

    dano_de_ataque = this->retornaAtaque() * 2 + this->retornaAtaque()*multiplicador;

    cout << "O ataque forte de " << this->retornaClasse() << " " << this->retornaNome() << " acertou.\n\n";
    this->modificaStamina(-15);
    return dano_de_ataque;
}

bool Guerreiro::atordoar() const{
    if(rand() % 100 > 70){ // 5% de chance do movimento falhar
        cout << "O atordoamento falhou.\n\n";
        return false;
    }
    
    cout << "O atordoamento funcionou!\n\n";

    return true;
}

int Guerreiro::defesaForte(int dano) const{
    if(rand() % 100 > 90){
        cout << "A defesa forte falhou.\n\n";
        return dano;
    }

    cout << "A defesa forte de " << this->retornaClasse() << " " << this->retornaNome() << " defendeu com sucesso.\n\n";
    return 0;
}

void Guerreiro::recebeDano(int dano){
    int dano_final = dano - (rand() % 50)/100 * this->retornaArmadura(); // mitiga entre 0 e 50% do dano com base na armadura

    if(dano_final < 0)
        dano_final = 0;

    cout << "O " << this->retornaClasse() << " " << this->retornaNome() << " perdeu " << dano_final << " de HP.\n\n";

    this->modificaHp(-dano_final);
}