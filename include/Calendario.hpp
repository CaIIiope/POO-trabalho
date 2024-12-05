#ifndef CALENDARIO_HPP
#define CALENDARIO_HPP

#include <map>
#include <vector>
#include <iostream>
#include <Treino.hpp>

class Calendario{
    private:
        std::map<int, std::map<int, std::map<int, std::vector<Treino>>>> _calendario;
    public:
        void adicionarTreino(int ano, int mes, int dia, int duracao, int calorias,std::string lugar,std::string nome);
        void removerTreino(int ano, int mes, int dia, std::string& nome);
        std::vector<Treino> getTreinos(int ano, int mes, int dia);
        Calendario();
        ~Calendario();
        std::map<int, std::map<int, std::map<int, std::vector<Treino>>>> getCalendario();  
};





#endif