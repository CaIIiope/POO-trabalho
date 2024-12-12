#include "Calendario.hpp"

void Calendario::adicionarAerobico(int ano, int mes, int dia, int duracao, int calorias,std::string lugar,std::string nome, int intensidade){
    Treino* treino= new Aerobico(duracao, calorias, lugar, nome, intensidade);
    _calendario[ano][mes][dia].push_back(treino);
}

void Calendario::adicionarMusculacao(int ano, int mes, int dia, int duracao, int calorias,std::string lugar,std::string nome, int series, int repeticoes, int peso){
    Treino* treino= new Musculacao(duracao, calorias, lugar, nome, series, repeticoes, peso);
    _calendario[ano][mes][dia].push_back(treino);
}

void Calendario::removerTreino(int ano, int mes, int dia, std::string& nome){
    if (_calendario[ano][mes][dia].size() == 0){
        std::cout << "Nenhum treino agendado para essa data" << std::endl;
        return;
    }
    if (_calendario.find(ano) != _calendario.end()){
        if (_calendario[ano].find(mes) != _calendario[ano].end()){
            if (_calendario[ano][mes].find(dia) != _calendario[ano][mes].end()){
                for (int i = 0; i < _calendario[ano][mes][dia].size(); i++){
                    if (_calendario[ano][mes][dia][i]->getNome() == nome){
                        _calendario[ano][mes][dia].erase(_calendario[ano][mes][dia].begin() + i);
                        return;
                    }
                }
                std::cout << "Treino não realizado nesse dia" << std::endl;
            }
        }
    }
    else{
        std::cout << "Data não encontrada" << std::endl;
    }


}

std::vector<Treino *> Calendario::getTreinos(int ano, int mes, int dia){
    if (_calendario.count(ano) && _calendario.at(ano).count(mes) && _calendario.at(ano).at(mes).count(dia)) {
        return _calendario.at(ano).at(mes).at(dia); 
    }   
    else {
        return {};
    }
}

Calendario::Calendario(){
}

Calendario::~Calendario(){
}

std::map<int, std::map<int, std::map<int, std::vector<Treino*>>>> Calendario::getCalendario(){
    return _calendario;
}