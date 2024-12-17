#include "Aerobico.hpp"

// Construtor da classe Aerobico, derivada da classe Treino
Aerobico::Aerobico(int duracao, int calorias, std::string lugar, std::string nome, int intensidade)
    : Treino(duracao, calorias, lugar, nome), _intensidade(intensidade) {}

Aerobico::~Aerobico() {}

// Getter do atributo intensidade
int Aerobico::getIntensidade() {
    return _intensidade;
}

// Guarda as informações do treino em um stringstream por referencia para ser salvo no arquivo
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

// Exibe as informações do treino no terminal
void Aerobico::exibirTreino(std::ostream &out) {
    out << "Treino Aerobico" << std::endl;
    out << "Nome: " << getNome() << std::endl;
    out << "Duracao: " << getDuracao() << std::endl;
    out << "Calorias: " << getCalorias() << std::endl;
    out << "Lugar: " << getLugar() << std::endl;
    out << "Intensidade: " << getIntensidade() << std::endl;
}

// Sobrecarga do operador de comparação para verificar se dois treinos são iguais
bool Aerobico::operator==(Treino* outro) {

    // Verifica se 'outro' é realmente uma instância de aerobico
    Aerobico* outroaerobico = dynamic_cast<Aerobico*>(outro);
    if (outroaerobico == nullptr) {
        return false;
    }

    return{
        getNome() == outro->getNome() &&
        getDuracao() == outro->getDuracao() &&
        getCalorias() == outro->getCalorias() &&
        getLugar() == outro->getLugar() &&
        getIntensidade() == ((Aerobico*)outro)->getIntensidade()

    };
}