// Caio Florentin Oliveira 14562921
// Lucas Gonzalez Ribeiro da Silva 14675524

#include "Calendario.hpp"

void Calendario::adicionarAerobico(int ano, int mes, int dia, int duracao, int calorias, std::string lugar, std::string nome, int intensidade) {
    // Cria um shared_ptr para o treino
    auto treino = std::make_shared<Aerobico>(duracao, calorias, lugar, nome, intensidade);

    // Verifica se o treino já existe nesse dia
    if (existre_treino(ano, mes, dia, treino)) {
        std::cout << "Treino já salvo nesse dia!" << std::endl;
        return;
    }

    // Adiciona o treino no mapa
    _calendario[ano][mes][dia].push_back(treino);
}

// Salva um objeto da classe Musculacao no mapa calendario
void Calendario::adicionarMusculacao(int ano, int mes, int dia, int duracao, int calorias,std::string lugar,std::string nome, int series, std::vector<std::pair<int, float>> rep_peso){
    // Cria um objeto da classe Musculacao
    auto treino = std::make_shared<Musculacao>(duracao, calorias, lugar, nome, series, rep_peso);
    // Verifica se o treino existe e já foi salvo nesse dia
    if (existre_treino(ano, mes, dia, treino)){
        std::cout << "Treino já salvo nesse dia!" << std::endl;
        return;
    }
    // Adiciona o treino no mapa calendario
    _calendario[ano][mes][dia].push_back(treino);
}

// Verifica se um treino já foi salvo em uma data
// bool Calendario::existre_treino(int ano, int mes, int dia, Treino* treino) {
bool Calendario::existre_treino(int ano, int mes, int dia, const std::shared_ptr<Treino>& treino) {
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

// Remove um treino de uma data específica
void Calendario::removerTreino(int ano, int mes, int dia, const std::string& nome) {
    // Verifica se a data existe no calendário
    if (_calendario.find(ano) == _calendario.end() ||
        _calendario[ano].find(mes) == _calendario[ano].end() ||
        _calendario[ano][mes].find(dia) == _calendario[ano][mes].end()) {
        
        std::cout << "Data não encontrada" << std::endl;
        return;
    }

    auto& treinos = _calendario[ano][mes][dia];
    // Remove o treino com o nome informado se ele for achado
    // std::remove_if retorna um iterador para o primeiro elemento removido
    auto removido = std::remove_if(treinos.begin(), treinos.end(),
                             [&nome](const std::shared_ptr<Treino>& treino) {
                                 return treino->getNome() == nome;
                             });

    // Se o treino foi removido, apaga os elementos do vetor a partir do iterador retornado
    if (removido != treinos.end()) {
        treinos.erase(removido, treinos.end());
        std::cout << "Treino removido" << std::endl;
    } else {
        std::cout << "Treino não realizado nesse dia" << std::endl;
    }
}


// Retorna um vetor de treinos de uma data específica
std::vector<std::shared_ptr<Treino>> Calendario::getTreinos(int ano, int mes, int dia){
    if (_calendario.count(ano) && _calendario.at(ano).count(mes) && _calendario.at(ano).at(mes).count(dia)) {
        return _calendario.at(ano).at(mes).at(dia); 
    }   
    else {
        return {};
    }
}

Calendario::Calendario(){
}

Calendario::~Calendario() {
    _calendario.clear(); // Limpa o mapa principal
}



// Getter para o mapa calendario
std::map<int, std::map<int, std::map<int, std::vector<std::shared_ptr<Treino>>>>> Calendario::getCalendario(){
    return _calendario;
}