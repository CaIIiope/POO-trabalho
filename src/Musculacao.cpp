#include <Musculacao.hpp>


Musculacao::Musculacao(int duracao, int calorias, std::string lugar, std::string nome, int series) : Treino(duracao, calorias, lugar, nome){
    _series = series;
    int repeticoes;
    float peso;
    std::pair<int, float> conjunto;
    std::string input;
    for (int i = 0; i < _series; i++){
        while (true) {
            std::cout << "Digite as repeticoes da serie  " << i+1 << " :";
            std::getline(std::cin, input);
            if (std::stringstream(input) >> repeticoes) 
                break;
            else
                std::cout << "Duração inválida. Por favor, insira um número." << std::endl;
        }
        while (true) {
            std::cout << "Digite o peso da serie  " << i+1 << " :";
            std::getline(std::cin, input);
            if (std::stringstream(input) >> peso) 
                break;
            else
                std::cout << "Duração inválida. Por favor, insira um número." << std::endl;
        }
        conjunto = std::make_pair(repeticoes, peso);
        _rep_peso.push_back(conjunto);
    }   
}

Musculacao::~Musculacao(){
}

int Musculacao::getSeries(){
    return _series;
}

std::pair<int, float> Musculacao::getRepeticoesEPeso(int serie){
    if (serie < 0 || serie >= _series) {
        throw std::out_of_range("Índice da série inválido.");
    }
    return _rep_peso[serie];
}

std::vector<std::pair<int, float>>& Musculacao::getAllRepeticoesEPeso(){
    return _rep_peso;
}

void Musculacao::salvaTreino(std::stringstream* out) {                                                                                                                                                                              
    if (out) {
        *out << "Treino Musculacao" << std::endl;
        *out << "Nome: " << getNome() << std::endl;
        *out << "Duracao: " << getDuracao() << std::endl;
        *out << "Calorias: " << getCalorias() << std::endl;
        *out << "Lugar: " << getLugar() << std::endl;
        *out << "Series: " << getSeries() << std::endl;
        *out << "Detalhes das séries:" << std::endl;
        for (size_t i = 0; i < _rep_peso.size(); ++i) {
            *out << "   Série " << i + 1 << ": "
                << _rep_peso[i].first << " repetições, "
                << _rep_peso[i].second << std::endl;
        }
    }
}

void Musculacao::exibirTreino(std::ostream &out){
    out << "Treino Musculacao" << std::endl;
    out << "Nome: " << getNome() << std::endl;
    out << "Duracao: " << getDuracao() << std::endl;
    out << "Calorias: " << getCalorias() << std::endl;
    out << "Lugar: " << getLugar() << std::endl;
    out << "Series: " << getSeries() << std::endl;
    out << "Detalhes das séries:" << std::endl;
    for (size_t i = 0; i < _rep_peso.size(); ++i) {
        out << "   Série " << i + 1 << ": "
        << _rep_peso[i].first << " repetições, "
        << _rep_peso[i].second << std::endl;
    }
}

bool Musculacao::operator==(Treino* outro){

    // Verifica se 'outro' é realmente uma instância de Musculacao
    Musculacao* outroMusculacao = dynamic_cast<Musculacao*>(outro);
    if (outroMusculacao == nullptr) {
        std::cout << "O treino comparado não é de musculação." << std::endl;
        return false;
    }

    return{
        getNome() == outroMusculacao->getNome() &&
        getDuracao() == outroMusculacao->getDuracao() &&
        getCalorias() == outroMusculacao->getCalorias() &&
        getLugar() == outroMusculacao->getLugar() &&
        _series == outroMusculacao->getSeries() &&
        _rep_peso == outroMusculacao->getAllRepeticoesEPeso()
    };
}