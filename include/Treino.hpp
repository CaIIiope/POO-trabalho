#ifndef TREINO_HPP
#define TREINO_HPP

#include <string>

class Treino{
    private:
        int _duracao, _calorias;
        std::string _lugar, _nome;
    public:
        Treino(int duracao, int calorias, std::string lugar, std::string nome);
        ~Treino();
        std::string getNome();
        std::string getLugar();
        int getDuracao();
        int getCalorias();
        
};

#endif