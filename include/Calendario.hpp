#ifndef CALENDARIO_HPP
#define CALENDARIO_HPP

#include <map>
#include <vector>
#include <iostream>
#include <Treino.hpp>
#include <Aerobico.hpp> 
#include <Musculacao.hpp>

class Calendario{
    private:
         // Essa variavel de map indexa um vetor de treino a tres inteiros, ano, mes e dia
        std::map<int, std::map<int, std::map<int, std::vector<Treino*>>>> _calendario; 
        bool existre_treino(int ano, int mes, int dia, Treino* treino);
    public:
        void adicionarAerobico(int ano, int mes, int dia, int duracao, int calorias,std::string lugar,std::string nome, int intensidade);
        void adicionarMusculacao(int ano, int mes, int dia, int duracao, int calorias,std::string lugar,std::string nome, int series);

        void removerTreino(int ano, int mes, int dia, std::string& nome);
        std::vector<Treino*> getTreinos(int ano, int mes, int dia);
        Calendario();
        ~Calendario();
        std::map<int, std::map<int, std::map<int, std::vector<Treino*>>>>getCalendario();  
};





#endif