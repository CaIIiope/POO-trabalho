#include "Calendario.hpp"

void Calendario::adicionarAerobico(int ano, int mes, int dia, int duracao, int calorias,std::string lugar,std::string nome, int intensidade){
    Treino* treino= new Aerobico(duracao, calorias, lugar, nome, intensidade);
    if (existre_treino(ano, mes, dia, treino)){
        std::cout << "Treino já salvo nesse dia!" << std::endl;
        return;
    }
    _calendario[ano][mes][dia].push_back(treino);
}

void Calendario::adicionarMusculacao(int ano, int mes, int dia, int duracao, int calorias,std::string lugar,std::string nome, int series, int repeticoes, int peso){
    Treino* treino= new Musculacao(duracao, calorias, lugar, nome, series, repeticoes, peso);
    if (existre_treino(ano, mes, dia, treino)){
        std::cout << "Treino já salvo nesse dia!" << std::endl;
        return;
    }
    _calendario[ano][mes][dia].push_back(treino);
}

bool Calendario::existre_treino(int ano, int mes, int dia, Treino* treino) {
    // Verifica se a data existe no calendário
    if (_calendario.find(ano) == _calendario.end() ||
        _calendario[ano].find(mes) == _calendario[ano].end() ||
        _calendario[ano][mes].find(dia) == _calendario[ano][mes].end()) {
        return false; // Data não existe
    }

    // Percorre os treinos no vetor do dia
    for (auto t : _calendario[ano][mes][dia]) {
        if (*t == treino) { // Usando o operador == sobrecarregado
            return true; // Treino equivalente encontrado
        }
    }
    return false; // Nenhum treino equivalente encontrado
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