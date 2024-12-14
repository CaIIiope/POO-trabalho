
#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <iostream>
#include <string>
#include <Calendario.hpp>
#include <fstream>

class Pessoa{
    private:

        std::string _nome, _pathdata;
        int _idade;
        Calendario _calendario;

    public:
        Pessoa(std::string nome, std::string pathdata, int idade);
        Pessoa(const std::string& pathdata);
        ~Pessoa();

        void adicionarMusculacao(int ano, int mes, int dia, int duracao, int calorias,std::string lugar, std::string nome, int series, int repeticoes, int peso);
        void adicionarAerobico(int ano, int mes, int dia, int duracao, int calorias,std::string lugar,std::string nome, int intensidade);

        void removerTreino(int ano, int mes, int dia, std::string& nome);

        void exibirTreinos(int ano, int mes, int dia);

        void salvarDados();
        int carregarDados();
};


#endif