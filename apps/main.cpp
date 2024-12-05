#include <iostream>
#include <Pessoa.hpp>


int main(){
    Pessoa pessoa("João", "joao_treinos.txt", 30);

        // Adicionando treinos
    pessoa.adicionarTreino(2024, 12, 4, 60, 500, "Academia", "Treino de força");
    pessoa.adicionarTreino(2024, 12, 4, 45, 300, "Parque", "Corrida");
    pessoa.adicionarTreino(2024, 12, 5, 30, 200, "Casa", "Yoga");

        // Salvar os dados no arquivo
    pessoa.salvarDados();

    std::cout << "Arquivo criado com sucesso! Verifique 'joao_treinos.txt'." << std::endl;
}