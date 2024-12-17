#include "Calendario.hpp"

// Salva um objeto da classe Aerobico no mapa calendario
void Calendario::adicionarAerobico(int ano, int mes, int dia, int duracao, int calorias,std::string lugar,std::string nome, int intensidade){
    //Cria um objeto da classe Aerobico
    Treino* treino= new Aerobico(duracao, calorias, lugar, nome, intensidade);
    //Verifica se o treino existe e já foi salvo nesse dia
    if (existre_treino(ano, mes, dia, treino)){
        std::cout << "Treino já salvo nesse dia!" << std::endl;
        
        return;
    }
    //Adiciona o treino no mapa calendario
    _calendario[ano][mes][dia].push_back(treino);

    
    return;
}

// Salva um objeto da classe Musculacao no mapa calendario
void Calendario::adicionarMusculacao(int ano, int mes, int dia, int duracao, int calorias,std::string lugar,std::string nome, int series, std::vector<std::pair<int, float>> rep_peso){
    // Cria um objeto da classe Musculacao
    Treino* treino= new Musculacao(duracao, calorias, lugar, nome, series, rep_peso);
    // Verifica se o treino existe e já foi salvo nesse dia
    if (existre_treino(ano, mes, dia, treino)){
        std::cout << "Treino já salvo nesse dia!" << std::endl;
        return;
    }
    // Adiciona o treino no mapa calendario
    _calendario[ano][mes][dia].push_back(treino);
}

// Verifica se um treino já foi salvo em uma data
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

// Remove treino do calendario procurando no mapa pela data e pelo nome do treino
void Calendario::removerTreino(int ano, int mes, int dia, std::string& nome){
    // Verifica se existe treino na data
    if (_calendario[ano][mes][dia].size() == 0){
        std::cout << "Nenhum treino agendado para essa data" << std::endl;
        return;
    }
    // Procura o treino pela data e pelo nome
    if (_calendario.find(ano) != _calendario.end()){
        if (_calendario[ano].find(mes) != _calendario[ano].end()){
            if (_calendario[ano][mes].find(dia) != _calendario[ano][mes].end()){
                for (int i = 0; i < _calendario[ano][mes][dia].size(); i++){
                    if (_calendario[ano][mes][dia][i]->getNome() == nome){
                        _calendario[ano][mes][dia].erase(_calendario[ano][mes][dia].begin() + i);
                        std::cout << "Treino removido" << std::endl;
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

// Retorna um vetor de treinos de uma data específica
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
    for (auto& ano : _calendario) {
        for (auto& mes : ano.second) {
            for (auto& dia : mes.second) {
                for (auto treino : dia.second) {
                    delete treino;
                }
            }
        }
    }
}

// Getter para o mapa calendario
std::map<int, std::map<int, std::map<int, std::vector<Treino*>>>> Calendario::getCalendario(){
    return _calendario;
}