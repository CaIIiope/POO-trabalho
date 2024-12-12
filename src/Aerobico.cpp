#include "Aerobico.hpp"

Aerobico::Aerobico(int duracao, int calorias, std::string lugar, std::string nome, int intensidade)
    : Treino(duracao, calorias, lugar, nome), _intensidade(intensidade) {}

Aerobico::~Aerobico() {}

int Aerobico::getIntensidade() {
    return _intensidade;
}

void Aerobico::salvaTreino(std::stringstream* out) {
    if (out) {
    *out << "Treino Aerobico" << std::endl;
    *out << "Nome: " << getNome() << std::endl;
    *out << "Duracao: " << getDuracao() << std::endl;
    *out << "Calorias: " << getCalorias() << std::endl;
    *out << "Lugar: " << getLugar() << std::endl;
    *out << "Intensidade: " << getIntensidade() << std::endl;
    }


}