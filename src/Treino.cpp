#include "Treino.hpp"

Treino::Treino(int duracao, int calorias, std::string lugar, std::string nome){
    _duracao = duracao;
    _calorias = calorias;
    _lugar = lugar;
    _nome = nome;
}

Treino::~Treino(){
}

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
