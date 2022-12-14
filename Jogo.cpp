#include "Jogo.hpp"
#include "AtaqueFisico.hpp"
#include "AtaqueDistancia.hpp"
#include "Guerreiro.hpp"
#include "Clerigo.hpp"
#include "Assassino.hpp"
#include "Arqueiro.hpp"
#include "Mago.hpp"
#include "Feiticeiro.hpp"
#include<typeinfo>
#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::string;

Jogo::Jogo()
{
    this->jogadores;
    this->turno = 0;
    this->distancia = 2;
}

Jogo::~Jogo(){
    for(int ptr = 0; ptr < this->jogadores.size(); ++ptr){
        delete this->jogadores[ptr];
    }
}

void Jogo::adicionarJogador(const string &nome, const string &classe){
    ClasseRpg *ptr = NULL;

    if(classe == "Guerreiro"){
        ptr = new Guerreiro(nome);
    }
    else if(classe == "Clérigo"){
        ptr = new Clerigo(nome);
    }
    else if(classe == "Assassino"){
        ptr = new Assassino(nome);
    }
    else if(classe == "Arqueiro"){
        ptr = new Arqueiro(nome);
    }
    else if(classe == "Mago"){
        ptr = new Mago(nome);
    }
    else if(classe == "Feiticeiro"){
        ptr = new Feiticeiro(nome);
    }

    if(ptr == NULL){
        cout << "Nenhuma opção válida.\n\n";
        return;
    }

    jogadores.push_back(ptr);
    cout << "Jogador " << ptr->retornaNome() << " de classe " << ptr->retornaClasse() << " criado com sucesso!\n\n";
}

 void Jogo::iniciarJogo(){
    if(this->jogadores.size() < 2){
        cout << "Não há jogadores o suficiente para iniciar o jogo.\n\n";
        return;
    }

    int opcao, escolha1, escolha2, *dados = new int[5], dano;
    ClasseRpg *jogador1 = NULL, *jogador2 = NULL;
    cout << "Escolha o primeiro jogador:\n";
    this->mostraJogadores();

    cin >> opcao;

    while(opcao < 0 || opcao > this->jogadores.size() - 1){
        cout << "Opção inválida. Tente novamente.\n";
        cin >> opcao;
    }

    jogador1 = this->jogadores[opcao];
    this->jogadores.erase(this->jogadores.begin() + opcao);

    cout << "Escolha o segundo jogador:\n";
    this->mostraJogadores();

    cin >> opcao;

    while(opcao < 0 || opcao > this->jogadores.size() - 1){
        cout << "Opção inválida. Tente novamente.\n";
        cin >> opcao;
    }

    jogador2 = this->jogadores[opcao];
    this->jogadores.erase(this->jogadores.begin() + opcao);

    // if(typeid(*jogador1).name() == typeid(Guerreiro).name()){
    //     Guerreiro *jogador1 = dynamic_cast<Guerreiro*>(jogador1);
    // }
    // else if(typeid(*jogador1).name() == typeid(Clerigo).name()){
    //     Clerigo *jogador1 = dynamic_cast<Clerigo*>(jogador1);
    // }
    // else if(typeid(*jogador1).name() == typeid(Assassino).name()){
    //     Assassino *jogador1 = dynamic_cast<Assassino*>(jogador1);
    // }
    // else if(typeid(*jogador1).name() == typeid(Arqueiro).name()){
    //     Arqueiro *jogador1 = dynamic_cast<Arqueiro*>(jogador1);
    // }
    // else if(typeid(*jogador1).name() == typeid(Mago).name()){
    //     Mago *jogador1 = dynamic_cast<Mago*>(jogador1);
    // }
    // else if(typeid(*jogador1).name() == typeid(Feiticeiro).name()){
    //     Feiticeiro *jogador1 = dynamic_cast<Feiticeiro*>(jogador1);
    // }

    // if(typeid(*jogador2).name() == typeid(Guerreiro).name()){
    //     Guerreiro *jogador2 = dynamic_cast<Guerreiro*>(jogador2);
    // }
    // else if(typeid(*jogador2).name() == typeid(Clerigo).name()){
    //     Clerigo *jogador2 = dynamic_cast<Clerigo*>(jogador2);
    // }
    // else if(typeid(*jogador2).name() == typeid(Assassino).name()){
    //     Assassino *jogador2 = dynamic_cast<Assassino*>(jogador2);
    // }
    // else if(typeid(*jogador2).name() == typeid(Arqueiro).name()){
    //     Arqueiro *jogador2 = dynamic_cast<Arqueiro*>(jogador2);
    // }
    // else if(typeid(*jogador2).name() == typeid(Mago).name()){
    //     Mago *jogador2 = dynamic_cast<Mago*>(jogador2);
    // }
    // else if(typeid(*jogador2).name() == typeid(Feiticeiro).name()){
    //     Feiticeiro *jogador2 = dynamic_cast<Feiticeiro*>(jogador2);
    // } 

    while(jogador1->retornaHp() > 0 && jogador2->retornaHp() > 0){
        cout << "Turno " << this->turno << ":\n";
        cout << "Vez de jogador " << jogador1->retornaNome() << "\n";
        escolha1 = jogador1->escolheAcao();
        delete [] dados;
        switch(escolha1){
            case 1:
                dados = new int[5]{jogador1->ataqueBasico(this->distancia), 0, 0, 0, 0};
                break;
            case 2:
                dados = new int[5]{0, 0, 1, 0, 0};
                break;
            default:
                dados = this->acaoSubclasse(jogador1, opcao);
        }

        if(dados[0] > 0){
            dano = dados[0];
            if(jogador2->retornaDefendendo())
                dano = jogador2->defender(dano);
            if(jogador2->retornaDefendendoForte())
                dano = this->acaoSubclasse(jogador1, 5)[4];
            jogador2->recebeDano(dano);
        }
        else if(dados[1] > 0){
            jogador2->modificaAtordoado(dados[1]);
        }
        else if(dados[2] > 0){
            jogador1->modificaDefendendo(dados[2]);
        }
        else if(dados[3] > 0){
            jogador2->modificaCongelado(dados[3]);
        }
        else if(dados[4] > 0){
            jogador1->modificaDefendendoForte(dados[4]);
        }

        jogador2->modificaCongelado(false);
        jogador2->modificaDefendendo(false);
        jogador2->modificaDefendendoForte(false);
        jogador2->modificaCongelado(false);
        jogador2->modificaAtordoado(false);

        escolha2 = jogador2->escolheAcao(); 
        delete [] dados; 
        switch(escolha2){
            case 1:
                dados = new int[5]{jogador2->ataqueBasico(this->distancia), 0, 0, 0, 0};
                break;
            case 2:
                dados = new int[0, 0, 1, 0, 0];
                break;
            default:
                dados = this->acaoSubclasse(jogador2, opcao);
        }

        if(dados[0] > 0){
            dano = dados[0];
            if(jogador1->retornaDefendendo())
                dano = jogador1->defender(dano);
            if(jogador2->retornaDefendendoForte())
                dano = this->acaoSubclasse(jogador1, 5)[4];
            jogador1->recebeDano(dano);
        }
        else if(dados[1] > 0){
            jogador1->modificaAtordoado(dados[1]);
        }
        else if(dados[2] > 0){
            jogador2->modificaDefendendo(dados[2]);
        }
        else if(dados[3] > 0){
            jogador1->modificaCongelado(dados[3]);
        }
        else if(dados[4] > 0){
            jogador2->modificaDefendendoForte(dados[4]);
        }
        jogador1->modificaCongelado(false);
        jogador1->modificaDefendendo(false);
        jogador1->modificaDefendendoForte(false);
        jogador1->modificaCongelado(false);
        jogador1->modificaAtordoado(false);
        
    }
}

//int* = [dano, atordoado, defendendo, congelado, defesa_forte]

int *Jogo::acaoSubclasse(ClasseRpg *classe_base, int opcao, int dano) const{
    AtaqueDistancia *classe_distancia = dynamic_cast<AtaqueDistancia*>(classe_base);
    AtaqueFisico *classe_fisico = dynamic_cast<AtaqueFisico*>(classe_base);
    int dano_inflingido;

    if(opcao == 3){
        cout << "3!!";
        if(classe_distancia != 0){
            dano_inflingido = classe_distancia->ataqueCarregado();
            return new int[5]{dano_inflingido, 0, 0, 0, 0};
        }
        else if(classe_fisico != 0){
            dano_inflingido = classe_fisico->ataqueForte(this->distancia);
            return new int[5]{dano_inflingido, 0, 0, 0, 0};
        }
    }
    if(classe_distancia != 0){
        return this->acaoClasseDistancia(classe_distancia, opcao);
    }

    if(classe_fisico != 0){
        return this->acaoClasseFisico(classe_fisico, opcao, dano);
    }
}

int *Jogo::acaoClasseDistancia(AtaqueDistancia *classe_distancia, int opcao) const{
    Arqueiro *classe_arqueiro = dynamic_cast<Arqueiro*>(classe_distancia);
    Mago *classe_mago = dynamic_cast<Mago*>(classe_distancia);
    Feiticeiro *classe_feiticeiro = dynamic_cast<Feiticeiro*>(classe_distancia);
    int dano;
    bool congelado;

    if(opcao == 4){
        if(classe_arqueiro != 0){
            dano = classe_arqueiro->chuvaDeFlechas();
            return new int[5]{dano, 0, 0, 0, 0};
        }
        else if(classe_mago != 0){
            dano = classe_mago->bolaDeFogo();
            return new int[5]{dano, 0, 0, 0, 0};
        }
        else if(classe_feiticeiro != 0){
            dano = classe_feiticeiro->bolaDeFogo();
            return new int[5]{dano, 0, 0, 0, 0};
        }
    }
    if(classe_feiticeiro != 0){
        congelado = classe_feiticeiro->congelar();
        return new int[5]{0, 0, 0, congelado, 0};
    }
}

int *Jogo::acaoClasseFisico(AtaqueFisico *classe_fisico, int opcao, int dano) const{
    Guerreiro *classe_guerreiro = dynamic_cast<Guerreiro*>(classe_fisico);
    Assassino *classe_assassino = dynamic_cast<Assassino*>(classe_fisico);
    Clerigo *classe_clerigo = dynamic_cast<Clerigo*>(classe_fisico);
    bool atordoar, defendendo_forte;
    int dano_inflingido;

    if(opcao == 4){
        if(classe_guerreiro != 0){
            atordoar = classe_guerreiro->atordoar();
            return new int[5]{0, atordoar, 0, 0, 0};
        }
        else if(classe_clerigo != 0){
            atordoar = classe_clerigo->atordoar();
            return new int[5]{0, atordoar, 0, 0, 0};
        }
        else if(classe_assassino != 0){
            dano_inflingido = classe_assassino->ataqueFlanqueado(this->distancia);
            return new int[5]{dano_inflingido, 0, 0, 0, 0};
        }
    }

    if(opcao == 5){
        if(classe_guerreiro != 0){
            cout << "?";
            defendendo_forte = classe_guerreiro->defesaForte(dano);
            if(classe_guerreiro->retornaDefendendoForte()){
                return new int[5]{0, 0, 0, 0, defendendo_forte};
            }
            return new int[5]{0, 0, 0, 0, 1};
        }
        else if(classe_clerigo != 0){
            defendendo_forte = classe_clerigo->defesaForte(dano);
            if(classe_clerigo->retornaDefendendoForte()){
                return new int[5]{0, 0, 0, 0, defendendo_forte};
            }
            return new int[5]{0, 0, 0, 0, 1};
        }
    }

    if(classe_clerigo != 0){
        classe_clerigo->curar();
        return new int[5]{0, 0, 0, 0, 0};
    }

}

void Jogo::mostraJogadores()const{
    cout << "   Jogadores\t\tClasses\n";
    for(int jogador = 0; jogador < this->jogadores.size(); ++jogador){
        cout  << jogador <<"- " << this->jogadores[jogador]->retornaNome() << "\t\t\t" << this->jogadores[jogador]->retornaClasse() << "\n"; 
    }
    cout << "\t";

} 