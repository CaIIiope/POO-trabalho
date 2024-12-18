// Caio Florentin Oliveira 14562921
// Lucas Gonzalez Ribeiro da Silva 14675524

#include "Treino.hpp"

// Construtor da classe Treino
Treino::Treino(int duracao, int calorias, std::string lugar, std::string nome){
    _duracao = duracao;
    _calorias = calorias;
    _lugar = lugar;
    _nome = nome;
}

Treino::~Treino(){
}

// Getters do atributos privados
std::string Treino::getNome(){
    return _nome;
}

std::string Treino::getLugar(){
    return _lugar;
}

int Treino::getDuracao(){
    return _duracao;
}

int Treino::getCalorias(){
    return _calorias;
}


// Sobrecarga do operador << para imprimir os treinos
std::ostream& operator<<(std::ostream& out, Treino& treino){
    treino.exibirTreino(out);
    return out;
}