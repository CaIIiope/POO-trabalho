#ifndef AEROBICO_HPP
#define AEROBICO_HPP

#include <Treino.hpp>

class Aerobico : public Treino {
public:
    Aerobico(int duracao, int calorias, std::string lugar, std::string nome, int intensidade);
    ~Aerobico();
    int getIntensidade();
    void salvaTreino(std::stringstream* out);

private:
    int _intensidade;
};

#endif
