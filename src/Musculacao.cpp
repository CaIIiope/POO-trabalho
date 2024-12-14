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
        *out << "Treino Musculacao" << std::endl;
        *out << "Nome: " << getNome() << std::endl;
        *out << "Duracao: " << getDuracao() << std::endl;
        *out << "Calorias: " << getCalorias() << std::endl;
        *out << "Lugar: " << getLugar() << std::endl;
        *out << "Series: " << getSeries() << std::endl;
        *out << "Repeticoes: " << getRepeticoes() << std::endl;
        *out << "Peso: " << getPeso() << std::endl;
    }
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

bool Musculacao::operator==(Treino* outro){

    // Verifica se 'outro' é realmente uma instância de Musculacao
    Musculacao* outroMusculacao = dynamic_cast<Musculacao*>(outro);
    if (outroMusculacao == nullptr) {
        std::cout << "O treino comparado não é de musculação." << std::endl;
        return false;
    }


    std::cout << "Comparando treinos de musculação..." << std::endl;
    std::cout << "Nome: " << getNome() << " == " << outro->getNome() << std::endl;
    std::cout << "Duracao: " << getDuracao() << " == " << outro->getDuracao() << std::endl;
    std::cout << "Calorias: " << getCalorias() << " == " << outro->getCalorias() << std::endl;
    std::cout << "Lugar: " << getLugar() << " == " << outro->getLugar() << std::endl;
    std::cout << "Series: " << getSeries() << " == " << ((Musculacao*)outro)->getSeries() << std::endl;
    std::cout << "Repeticoes: " << getRepeticoes() << " == " << ((Musculacao*)outro)->getRepeticoes() << std::endl;
    std::cout << "Peso: " << getPeso() << " == " << ((Musculacao*)outro)->getPeso() << std::endl;

    return{
        getNome() == outro->getNome() &&
        getDuracao() == outro->getDuracao() &&
        getCalorias() == outro->getCalorias() &&
        getLugar() == outro->getLugar() &&
        getSeries() == ((Musculacao*)outro)->getSeries() &&
        getRepeticoes() == ((Musculacao*)outro)->getRepeticoes() &&
        getPeso() == ((Musculacao*)outro)->getPeso()
    };
}