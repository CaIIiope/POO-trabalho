#ifndef MUSCULACAO_HPP
#define MUACULACAO_HPP
#include <Treino.hpp>
class Musculacao : public Treino{
    private:
        int _peso;
        int _repeticoes;
        int _series;
    public:
        Musculacao(int duracao, int calorias, std::string lugar, std::string nome, int repeticoes, int series, int peso);
        ~Musculacao();
        int getRepeticoes();
        int getSeries();
        int getPeso();

        void salvaTreino(std::stringstream* out);
        void exibirTreino(std::ostream &out);
};

#endif