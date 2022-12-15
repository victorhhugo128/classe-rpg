#ifndef JOGO_H
#define JOGO_H
#include "ClasseRpg.hpp"
#include "AtaqueDistancia.hpp"
#include "AtaqueFisico.hpp"

#include<vector>
#include<string>

class ClasseRpg;

class Jogo
{
    public:
        Jogo();
        ~Jogo();

        void adicionarJogador(const std::string &, const std::string &);
        void iniciarJogo();
        void mostraInformacaoJogador(ClasseRpg*) const;
    private:
        void incrementaTurno();
        int* acaoSubclasse(ClasseRpg*, int, int = 0) const;
        int* acaoClasseDistancia(AtaqueDistancia*, int) const;
        int* acaoClasseFisico(AtaqueFisico*, int, int = 0) const;
        void mostraJogadores() const;
        void mostraInformacaoAtaqueFisico(AtaqueFisico*) const;
        void mostraInformacaoAtaqueDistancia(AtaqueDistancia*) const;
        std::vector<ClasseRpg*> jogadores;
        int turno, distancia;
};



#endif