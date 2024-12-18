// Caio Florentin Oliveira 14562921
// Lucas Gonzalez Ribeiro da Silva 14675524

#ifndef AEROBICO_HPP
#define AEROBICO_HPP

#include <Treino.hpp>

class Aerobico : public Treino {
    public:
        Aerobico(int duracao, int calorias, std::string lugar, std::string nome, int intensidade);
        ~Aerobico();
        int getIntensidade();
        void salvaTreino(std::stringstream* out);
        void exibirTreino(std::ostream &out);

        bool operator==(std::shared_ptr<Treino> outro);
    private:
        int _intensidade;
};

#endif
