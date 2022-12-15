#include<iostream>
#include <Windows.h>
#include "ClasseRpg.cpp"
#include "AtaqueFisico.cpp"
#include "AtaqueDistancia.cpp"
#include "Guerreiro.cpp"
#include "Clerigo.cpp"
#include "Assassino.cpp"
#include "Arqueiro.cpp"
#include "Mago.cpp"
#include "Feiticeiro.cpp"
#include "Jogo.cpp"

int main(){
    SetConsoleOutputCP(CP_UTF8);
    
    Jogo *novo_jogo = new Jogo();

    novo_jogo->adicionarJogador("Kratos", "Guerreiro");
    novo_jogo->adicionarJogador("Sage", "Clérigo");

    novo_jogo->adicionarJogador("Cole", "Assassino");
    novo_jogo->adicionarJogador("Dorian", "Mago");

    novo_jogo->adicionarJogador("Criston", "Arqueiro");
    novo_jogo->adicionarJogador("Merlys", "Feiticeiro");

    novo_jogo->iniciarJogo();

}