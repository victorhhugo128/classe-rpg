#include "Assassino.hpp"
#include<iostream>
#include<string>
#include<cstdlib>

using std::string;
using std::cout;
using std::cin;

Assassino::Assassino(const string &nome, int armadura)
:AtaqueFisico(nome, 90, 60, 4)
{
    this->defineClasse("assassino");
    this->astucia = 35;
}

Assassino::Assassino(const string &nome, float porcento_stamina, bool buff_ataque, bool buff_defesa, int armadura)
:AtaqueFisico(nome, porcento_stamina, buff_ataque, buff_defesa, 90, 60, 4)
{
    this->defineClasse("guerreiro");
    this->astucia = 35;
}

Assassino::Assassino(const Assassino &other)
:AtaqueFisico(other){
    this->astucia = other.astucia;
}

Assassino::~Assassino(){

}

int Assassino::retornaAstucia() const{
    return this->astucia;
}

int Assassino::escolheAcao() const{
    int escolha = -1;

    cout << "Escolha uma das ações para o turno do Guerreiro " << this->retornaNome() << ":\n";
    cin >> escolha;
    
    while(escolha < 1 && escolha >  this->retornaNAcoes()){
        cout << "Escolha inválida. Insira um valor válido: ";
        cin >> escolha;
    }

    return escolha;
}

void Assassino::mostraAcoes() const{
    cout << "1 - Ataque Básico\n2 - Defender\n3 - Ataque Forte\n4 - Ataque Flanqueado\n\n";
}


int Assassino::ataqueBasico(int distancia) const{
    if(distancia > 3){
        cout << "O " << this->retornaClasse() << " " << this->retornaNome() << " não pode atacar. Ele está muito longe.\n\n";
        return 0;
    }

    int chances = 100, dano_de_ataque = 0, critico = 1;
    float multiplicador = 0;

    if(rand() % chances > 95){ // 5% de chance do ataque falhar
        cout << "O ataque forte de " << this->retornaClasse() << " " << this->retornaNome() << " falhou.\n\n";
        return 0;
    }

    multiplicador = (rand() % chances)/100;

    if(rand() % 100 > 50){ // 50% de chance de ataque crítico
        critico = 2;
        cout << "Foi um ataque crítico!!\n";
    }

    dano_de_ataque = multiplicador * this->retornaAtaque() * critico;

    cout << "O ataque básico de " << this->retornaClasse() << " " << this->retornaNome() << " acertou!\n\n";

    return dano_de_ataque;
}

int Assassino::defender(int dano) const{
    int dano_mitigado = 0;
    float multiplicador = 0;

    if(rand() % 100 > 60){ // 60% de chance de defender corretamente
        cout << "A defesa falhou.\n\n";
        return dano;
    } 

    multiplicador = (rand() % 30 + 5)/100; // 5 - 35% de mitigação de dano

    dano_mitigado = dano - this->retornaDefesa()*multiplicador;

    cout << "O " << this->retornaClasse() << " " << this->retornaNome() << " defendeu com sucesso. Sofreu " << dano_mitigado << " de dano.\n\n";

    return dano;

}

int Assassino::ataqueForte(int distancia){
    if(this->retornaStamina() < 15){
        cout << "Não há stamina o suficiente. Não foi possível atacar.\n\n";
        return 0;
    }
    if(distancia > 3){
        cout << "O " << this->retornaClasse() << " " << this->retornaNome() << " não pode atacar. Ele está muito longe.\n\n";
        return 0;
    }

    int chances = 100, dano_de_ataque = 0, critico = 1;
    float multiplicador = 0;

    cout << rand() % chances << "\n";

    if(rand() % chances > 80){ // 20% de chance do ataque falhar
        cout << "O ataque forte de " << this->retornaClasse() << " " << this->retornaNome() << " falhou.\n\n";
        return 0;
    }


    multiplicador = (rand() % chances)/100;

    if(rand() % 100 > 70){ // 30% de chance de ataque crítico
        critico = 2;
        cout << "Foi um ataque crítico!!\n";
    }

    dano_de_ataque = (this->retornaAtaque() * 2 + this->retornaAtaque()*multiplicador) * critico;

    cout << "O ataque forte de " << this->retornaClasse() << " " << this->retornaNome() << " acertou.\n\n";
    this->modificaStamina(-20);
    return dano_de_ataque;
}

int Assassino::ataqueFlanqueado(int distancia){
    if(this->retornaStamina() < 15){
        cout << "Não há stamina o suficiente. Não foi possível usar ataque flanqueado.\n\n";
        return 0;
    }

    if(rand() % 100 > 40){ // 60% de chance do ataque falhar
        cout << "O ataque flanqueado de " << this->retornaClasse() << " " << this->retornaNome() << " falhou.\n\n";
        return 0;
    }

    int dano = (this->retornaAtaque() * 2) * this->retornaAstucia()/4; // dano do ataque flanqueado

    cout << "O ataque flanqueado de " << this->retornaClasse() << " " << this->retornaNome() << " foi um sucesso!\n\n";

    return dano;
}

void Assassino::recebeDano(int dano){
    cout << "O " << this->retornaClasse() << " " << this->retornaNome() << " perdeu " << dano << " de HP.\n\n";

    this->modificaHp(-dano);
}