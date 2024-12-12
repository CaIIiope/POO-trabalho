#include <Musculacao.hpp>


Musculacao::Musculacao(int duracao, int calorias, std::string lugar, std::string nome, int repeticoes, int series, int peso) : Treino(duracao, calorias, lugar, nome){
    _peso = peso;
    _repeticoes = repeticoes;
    _series = series;
}

Musculacao::~Musculacao(){
}

int Musculacao::getRepeticoes(){
    return _repeticoes;
}

int Musculacao::getSeries(){
    return _series;
}

int Musculacao::getPeso(){
    return _peso;
}

void Musculacao::salvaTreino(std::stringstream* out) {                                                                                                                                                                              
    if (out) {
        std::cout << "Salvando treino de musculação..." << std::endl;
        *out << "Treino Musculacao" << std::endl;
        *out << "Nome: " << getNome() << std::endl;
        *out << "Duracao: " << getDuracao() << std::endl;
        *out << "Calorias: " << getCalorias() << std::endl;
        *out << "Lugar: " << getLugar() << std::endl;
        *out << "Series: " << getSeries() << std::endl;
        *out << "Repeticoes: " << getRepeticoes() << std::endl;
        *out << "Peso: " << getPeso() << std::endl;
    }
    else std::cout << "kjhkjhk";
}

void Musculacao::exibirTreino(std::ostream &out){
    out << "Treino Musculacao" << std::endl;
    out << "Nome: " << getNome() << std::endl;
    out << "Duracao: " << getDuracao() << std::endl;
    out << "Calorias: " << getCalorias() << std::endl;
    out << "Lugar: " << getLugar() << std::endl;
    out << "Series: " << getSeries() << std::endl;
    out << "Repeticoes: " << getRepeticoes() << std::endl;
    out << "Peso: " << getPeso() << std::endl;
}