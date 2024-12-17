#ifndef TREINO_HPP
#define TREINO_HPP

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
class Treino{
    private:
        int _duracao, _calorias;
        std::string _lugar, _nome;
    public:
        Treino(int duracao, int calorias, std::string lugar, std::string nome);
        ~Treino();
        virtual void salvaTreino(std::stringstream* out) = 0;
        virtual void exibirTreino(std::ostream &out) = 0;

        friend std::ostream& operator<<(std::ostream& out, Treino& treino);
        virtual bool operator==(Treino* outro) = 0;

        std::string getNome();
        std::string getLugar();
        int getDuracao();
        int getCalorias();
        
};

#endif