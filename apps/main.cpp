#include <iostream>
#include <sstream>
#include <string>
#include <Pessoa.hpp>

int main() {
    std::cout << "Bem vindo ao seu calendário de treinos!" << std::endl;
    std::string input;
    char opcao;
    while (true) {
        std::cout << "Escolha uma opção:" << std::endl
                  << "1 - Criar novo usuário" << std::endl
                  << "2 - Carregar usuário existente" << std::endl
                  << "3 - Sair" << std::endl;

        std::getline(std::cin, input);
        std::stringstream ss(input);
        ss >> opcao;

        if (opcao == '3') {
            std::cout << "Até mais!" << std::endl;
            break;
        } else if (opcao == '1') {
            std::cout << "Vamos criar um novo usuário!" << std::endl;
            std::string nome, pathdata;
            int idade;

            std::cout << "Digite seu nome: ";
            std::getline(std::cin, nome);

            std::cout << "Digite sua idade: ";
            std::getline(std::cin, input);
            std::stringstream(input) >> idade;

            std::cout << "Digite o caminho para salvar seus dados: ";
            std::getline(std::cin, pathdata);

            Pessoa pessoa(nome, pathdata, idade);
            pessoa.salvarDados();

            while (true) {
                std::cout << "Você deseja adicionar um treino? 1 - Sim 2 - Não" << std::endl;
                std::getline(std::cin, input);
                std::stringstream(input) >> opcao;

                if (opcao == '2') {
                    std::cout << "Ok, você pode adicionar treinos depois!" << std::endl;
                    pessoa.salvarDados();
                    break;
                } else if (opcao == '1') {
                    std::cout << "Escolha o tipo de treino: 1 - Musculação 2 - Aeróbico" << std::endl;
                    std::getline(std::cin, input);
                    std::stringstream(input) >> opcao;

                    std::string nome, lugar;
                    int duracao, calorias, series, repeticoes, intensidade, peso, ano, mes, dia;

                    std::cout << "Digite o nome do treino: ";
                    std::getline(std::cin, nome);

                    std::cout << "Digite o lugar do treino: ";
                    std::getline(std::cin, lugar);

                    std::cout << "Digite a duração do treino: ";
                    std::getline(std::cin, input);
                    std::stringstream(input) >> duracao;

                    std::cout << "Digite as calorias gastas: ";
                    std::getline(std::cin, input);
                    std::stringstream(input) >> calorias;

                    std::cout << "Digite a data no formato dd/mm/aaaa: ";
                    std::getline(std::cin, input);
                    std::stringstream dateStream(input);
                    char lixo;
                    dateStream >> dia >> lixo >> mes >> lixo >> ano;

                    if (opcao == '1') {
                        std::cout << "Digite o número de séries: ";
                        std::getline(std::cin, input);
                        std::stringstream(input) >> series;

                        std::cout << "Digite o número de repetições: ";
                        std::getline(std::cin, input);
                        std::stringstream(input) >> repeticoes;

                        std::cout << "Digite o peso: ";
                        std::getline(std::cin, input);
                        std::stringstream(input) >> peso;

                        pessoa.adicionarMusculacao(ano, mes, dia, duracao, calorias, lugar, nome, series, repeticoes, peso);
                    } else if (opcao == '2') {
                        std::cout << "Digite a intensidade: ";
                        std::getline(std::cin, input);
                        std::stringstream(input) >> intensidade;

                        pessoa.adicionarAerobico(ano, mes, dia, duracao, calorias, lugar, nome, intensidade);
                    } else {
                        std::cout << "Opção inválida" << std::endl;
                    }
                } else {
                    std::cout << "Opção inválida" << std::endl;
                }
            }
        } else if (opcao == '2') {
            std::cout << "Digite o caminho para carregar seus dados: ";
            std::string pathdata;
            std::getline(std::cin, pathdata);
            Pessoa pessoa(pathdata);
            pessoa.carregarDados();
            while (true){
                std::cout << "Escolha uma opção:" << std::endl
                          << "1 - Adicionar treino" << std::endl
                          << "2 - Remover treino" << std::endl
                          << "3 - Exibir treinos" << std::endl
                          << "4 - Sair" << std::endl;

                std::getline(std::cin, input);
                std::stringstream ss(input);
                ss >> opcao;

                if (opcao == '4') {
                    std::cout << "Até mais!" << std::endl;
                    pessoa.salvarDados();
                    break;
                } else if (opcao == '1') {
                    std::cout << "Escolha o tipo de treino: 1 - Musculação 2 - Aeróbico" << std::endl;
                    std::getline(std::cin, input);
                    std::stringstream(input) >> opcao;

                    std::string nome, lugar;
                    int duracao, calorias, series, repeticoes, intensidade, peso, ano, mes, dia;

                    std::cout << "Digite o nome do treino: ";
                    std::getline(std::cin, nome);

                    std::cout << "Digite o lugar do treino: ";
                    std::getline(std::cin, lugar);

                    std::cout << "Digite a duração do treino: ";
                    std::getline(std::cin, input);
                    std::stringstream(input) >> duracao;

                    std::cout << "Digite as calorias gastas: ";
                    std::getline(std::cin, input);
                    std::stringstream(input) >> calorias;

                    std::cout << "Digite a data no formato dd/mm/aaaa: ";
                    std::getline(std::cin, input);
                    std::stringstream dateStream(input);
                    char lixo;
                    dateStream >> dia >> lixo >> mes >> lixo >> ano;

                    if (opcao == '1') {
                        std::cout << "Digite o número de séries: ";
                        std::getline(std::cin, input);
                        std::stringstream(input) >> series;

                        std::cout << "Digite o número de repetições: ";
                        std::getline(std::cin, input);
                        std::stringstream(input) >> repeticoes;

                        std::cout << "Digite o peso: ";
                        std::getline(std::cin, input);
                        std::stringstream(input) >> peso;

                        pessoa.adicionarMusculacao(ano, mes, dia, duracao, calorias, lugar, nome, series, repeticoes, peso);
                    } else if (opcao == '2') {
                        std::cout << "Digite a intensidade: ";
                        std::getline(std::cin, input);
                        std::stringstream(input) >> intensidade;

                        pessoa.adicionarAerobico(ano, mes, dia, duracao, calorias, lugar, nome, intensidade);
                    } else {
                        std::cout << "Opção inválida" << std::endl;
                    }
                } else if (opcao == '2') {
                    while (true){
                        std::cout << "1 - Informe a data dd/mm/aaaa e o nome do treino" << std::endl
                                  << "2 - Sair" << std::endl;
                        std::getline(std::cin, input);
                        std::stringstream(input) >> opcao;
                        if (opcao == '1'){
                            std::string nome;
                            int ano, mes, dia;
                            std::cout << "Digite a data no formato dd/mm/aaaa: ";
                            std::getline(std::cin, input);
                            std::stringstream dateStream(input);
                            char lixo;
                            dateStream >> dia >> lixo >> mes >> lixo >> ano;

                            std::cout << "Digite o nome do treino: ";
                            std::getline(std::cin, nome);

                            pessoa.removerTreino(ano, mes, dia, nome);
                        } else if (opcao == '2'){
                            break;
                        } else {
                            std::cout << "Opção inválida" << std::endl;
                        }
                    }
                    
                }
                else if (opcao == '3'){
                    while (true){
                        std::cout << "1 - Informe a data dd/mm/aaaa" << std::endl
                                  << "2 - Sair" << std::endl;
                        std::getline(std::cin, input);
                        std::stringstream(input) >> opcao;
                        if (opcao == '1'){
                            int ano, mes, dia;
                            std::cout << "Digite a data no formato dd/mm/aaaa: ";
                            std::getline(std::cin, input);
                            std::stringstream dateStream(input);
                            char lixo;
                            dateStream >> dia >> lixo >> mes >> lixo >> ano;

                            pessoa.exibirTreinos(ano, mes, dia);
                        } else if (opcao == '2'){
                            break;
                        } else {
                            std::cout << "Opção inválida" << std::endl;
                        }
                    }
                    
                }
                else{
                    std::cout << "Opção inválida" << std::endl;
                }
            }
        }
        else {
            std::cout << "Opção inválida" << std::endl;
        }
    }
    return 0;
}
