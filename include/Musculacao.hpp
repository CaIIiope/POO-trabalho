// Caio Florentin Oliveira 14562921
// Lucas Gonzalez Ribeiro da Silva 14675524

#ifndef MUSCULACAO_HPP
#define MUACULACAO_HPP
#include <Treino.hpp>

class Musculacao : public Treino{
    private:
        int _series;
        std::vector<std::pair<int, float>> _rep_peso; // Vetor de pares {repetições, peso} para cada série
    public:
        Musculacao(int duracao, int calorias, std::string lugar, std::string nome, int series, std::vector<std::pair<int, float>> rep_peso);
        ~Musculacao();
        int getSeries();
        std::pair<int, float> getRepeticoesEPeso(int serie); 
        std::vector<std::pair<int, float>>& getAllRepeticoesEPeso(); 

        bool operator==(std::shared_ptr<Treino> outro);

        void salvaTreino(std::stringstream* out);
        void exibirTreino(std::ostream &out);
};

#endif