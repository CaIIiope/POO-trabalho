#include <Musculacao.hpp>

// Construtor da classe Musculacao, derivada da classe Treino
// Recebe como parâmetro o numero de series para adicionar ao vetor de pares {repetições, peso}
Musculacao::Musculacao(int duracao, int calorias, std::string lugar, std::string nome, int series, std::vector<std::pair<int, float>> rep_peso) : Treino(duracao, calorias, lugar, nome){
    _series = series;
    _rep_peso = rep_peso;

}

Musculacao::~Musculacao(){
}

// Getter para o número de séries
int Musculacao::getSeries(){
    return _series;
}

// Getter para o par {repetições, peso} de uma série específica
std::pair<int, float> Musculacao::getRepeticoesEPeso(int serie){
    if (serie < 0 || serie >= _series) {
        throw std::out_of_range("Índice da série inválido.");
    }
    return _rep_peso[serie];
}
 
// Getter para o vetor de pares {repetições, peso}
std::vector<std::pair<int, float>>& Musculacao::getAllRepeticoesEPeso(){
    return _rep_peso;
}

// Salva as informações do treino em um stringstream por referencia para ser salvo no arquivo
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

// Exibe as informações do treino no terminal
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
// Sobrecarga do operador de comparação para verificar se dois treinos são iguais
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