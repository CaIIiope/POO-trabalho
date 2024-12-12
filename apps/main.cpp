#include <iostream>
#include <Pessoa.hpp>


int main(){
    Pessoa pessoa("João", "joao_treinos.txt", 30);

    // Adicionar treinos
    std::cout << "Adicionando treinos..." << std::endl;
    pessoa.adicionarMusculacao(2021, 10, 10, 60, 300, "Academia", "Supino", 3, 10, 40);
    pessoa.adicionarAerobico(2021, 10, 10, 30, 200, "Parque", "Corrida", 5);
    pessoa.adicionarMusculacao(2021, 10, 11, 60, 300, "Academia", "Leg-Press", 3, 10, 200);
    pessoa.adicionarAerobico(2021, 10, 11, 30, 200, "Parque", "Corrida", 5);
    pessoa.adicionarMusculacao(2021, 10, 12, 60, 300, "Academia", "Rosca Direta", 3, 10, 20);
    pessoa.adicionarAerobico(2021, 10, 12, 30, 200, "Parque", "Corrida", 5);

    // Salvar os dados no arquivo
    pessoa.salvarDados();

    std::cout << "Arquivo criado com sucesso! Verifique 'joao_treinos.txt'." << std::endl;
}