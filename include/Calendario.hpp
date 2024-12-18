// Caio Florentin Oliveira 14562921
// Lucas Gonzalez Ribeiro da Silva 14675524

#ifndef CALENDARIO_HPP
#define CALENDARIO_HPP

#include <map>
#include <vector>
#include <iostream>
#include <memory>
#include <algorithm>
#include <Treino.hpp>
#include <Aerobico.hpp> 
#include <Musculacao.hpp>

class Calendario {
    private:
        // Essa variavel de map indexa um vetor de treino a tres inteiros, ano, mes e dia
        std::map<int, std::map<int, std::map<int, std::vector<std::shared_ptr<Treino>>>>> _calendario; 
        bool existre_treino(int ano, int mes, int dia, const std::shared_ptr<Treino>& treino);
    public:
        void adicionarAerobico(int ano, int mes, int dia, int duracao, int calorias, std::string lugar, std::string nome, int intensidade);
        void adicionarMusculacao(int ano, int mes, int dia, int duracao, int calorias, std::string lugar, std::string nome, int series, std::vector<std::pair<int, float>> rep_peso);

        void removerTreino(int ano, int mes, int dia, const std::string& nome);
        std::vector<std::shared_ptr<Treino>> getTreinos(int ano, int mes, int dia);
        std::map<int, std::map<int, std::map<int, std::vector<std::shared_ptr<Treino>>>>> getCalendario();
        Calendario();
        ~Calendario();
};





#endif