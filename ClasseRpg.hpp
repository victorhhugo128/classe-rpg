#ifndef CLASSERPG_H
#define CLASSERPG_H
#include<string>

class ClasseRpg
{
    public:
        ClasseRpg(const std::string &, int = 0, int = 0, int = 0);
        ClasseRpg(const std::string &, bool, bool, int = 0, int = 0, int = 0);
        ClasseRpg(const ClasseRpg &);
        virtual ~ClasseRpg();
        virtual int ataqueBasico(int) const = 0;
        virtual int defender(int) const = 0;
        virtual int escolheAcao() const = 0;
        virtual void mostraAcoes() const = 0;
        virtual void recebeDano(int) = 0;
        virtual void mostrarAtributos() const;
    private:
        int hp, ataque, defesa;
        const int MAX_HP, N_ACOES;
        std::string nome;
        bool atordoado = false, defendendo = false;
    protected:
        int retornaHp() const;
        int retornaAtaque() const;
        int retornaDefesa() const;
        int retornaMaxHp() const;
        int retornaNAcoes() const;
        bool retornaAtordoado() const;
        bool retornaDefendendo() const;
        void modificaAtaque(int);
        void modificaDefesa(int);
        void modificaHp(int);
        void modificaAtordoado(bool);
        void modificaDefendendo(bool);
        void defineClasse(const std::string &);
        std::string retornaNome() const;
        std::string retornaClasse() const;
        std::string classe;
        bool buff_ataque = false, buff_defesa = false;
};

#endif // CLASSERPG_H