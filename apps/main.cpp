#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <Pessoa.hpp>

// A main consiste em um aninhamento de ifs e elses para a escolha de opções disponiveis ao usuario
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

        std::system("clear");

        if (opcao == '3') { // Sair do programa
            std::cout << "Até mais!" << std::endl;
            break;
        } else if (opcao == '1') { // Criar novo usuario
            std::cout << "Vamos criar um novo usuário!" << std::endl;
            std::string nome, pathdata;
            int idade;

            std::cout << "Digite seu nome: ";
            std::getline(std::cin, nome);

            while(true) {
                std::cout << "Digite sua idade: ";
                std::getline(std::cin, input);
                if (std::stringstream(input) >> idade)
                    break;
                else
                    std::cout << "Idade inválida. Por favor, insira um número." << std::endl;
            }

            std::cout << "Digite o caminho para salvar seus dados: ";
            std::getline(std::cin, pathdata);

            Pessoa pessoa(nome, pathdata, idade);
            pessoa.salvarDados();

            std::system("clear");

            while (true) { // Apos criar novo usuario, pode-se adicionar treinos
                    std::cout << "Você deseja adicionar um treino? 1 - Sim 2 - Não" << std::endl;
                    std::getline(std::cin, input);
                    std::stringstream(input) >> opcao;

                    if (opcao == '2') { // Caso o usuario nao queira adicionar treinos
                        std::cout << "Ok, você pode adicionar treinos depois!" << std::endl;
                        pessoa.salvarDados(); // Salva os dados e volta ao menu principal
                        sleep(2);
                        std::system("clear");

                        break;
                    } else if (opcao == '1') { // Adicionar treino ao novo usuario
                        std::system("clear");
                        while (true) {
                            std::cout << "Escolha o tipo de treino: 1 - Musculação 2 - Aeróbico" << std::endl;
                            std::getline(std::cin, input);
                            std::stringstream(input) >> opcao;
                            if (opcao == '1' || opcao == '2') 
                                break;
                            else 
                                std::cout << "Opção inválida. Por favor, escolha 1 para Musculação ou 2 para Aeróbico." << std::endl;
                        }

                        std::string nome, lugar;
                        int duracao, calorias, series, repeticoes, intensidade, peso, ano, mes, dia;

                        std::system("clear");
                        std::cout << "Digite o nome do treino: ";
                        std::getline(std::cin, nome);

                        std::cout << "Digite o lugar do treino: ";
                        std::getline(std::cin, lugar);

                        while (true) {
                            std::cout << "Digite a duração do treino: ";
                            std::getline(std::cin, input);
                            if (std::stringstream(input) >> duracao) 
                                break;
                            else
                                std::cout << "Duração inválida. Por favor, insira um número." << std::endl;
                        }

                        while (true) {
                            std::cout << "Digite as calorias gastas: ";
                            std::getline(std::cin, input);
                            if (std::stringstream(input) >> calorias)
                                break;
                            else
                                std::cout << "Calorias inválidas. Por favor, insira um número." << std::endl;
                        }

                        std::cout << "Digite a data no formato dd/mm/aaaa: ";
                        std::getline(std::cin, input);
                        std::stringstream dateStream(input);
                        char lixo;
                        dateStream >> dia >> lixo >> mes >> lixo >> ano;

                        if (opcao == '1') { // Opcao para adicionar treino de musculacao
                            while (true) {
                                std::cout << "Digite o número de séries: ";
                                std::getline(std::cin, input);
                                if (std::stringstream(input) >> series) 
                                    break;
                                else
                                    std::cout << "Número de séries inválido. Por favor, insira um número." << std::endl;
                            }

                            pessoa.adicionarMusculacao(ano, mes, dia, duracao, calorias, lugar, nome, series);
                        } else if (opcao == '2') { // Opcao para adicionar treino aerobico
                            while (true) {
                                std::cout << "Digite a intensidade: ";
                                std::getline(std::cin, input);
                                if (std::stringstream(input) >> intensidade)
                                    break;
                                else
                                    std::cout << "Intensidade inválida. Por favor, insira um número." << std::endl;
                            }

                            pessoa.adicionarAerobico(ano, mes, dia, duracao, calorias, lugar, nome, intensidade);
                        } else {
                            std::cout << "Opção inválida" << std::endl;
                        }
                    }
            }
        } else if (opcao == '2') { // Caso o usuario queira carregar um usuario existente
            std::cout << "Digite o caminho para carregar seus dados: ";
            std::string pathdata;
            std::getline(std::cin, pathdata);
            Pessoa pessoa(pathdata);
            int flag = pessoa.carregarDados();
            if (flag == 0) {
                std::cout << "Erro ao carregar dados. Verifique o caminho informado." << std::endl;
                sleep(2);
                std::system("clear");
                continue;
            }
            while (true){ // Opcoes disponiveis para o usuario ja existente
                std::system("clear");
                std::cout << "Escolha uma opção:" << std::endl
                          << "1 - Adicionar treino" << std::endl
                          << "2 - Remover treino" << std::endl
                          << "3 - Exibir treinos" << std::endl
                          << "4 - Sair" << std::endl;

                std::getline(std::cin, input);
                std::stringstream ss(input);
                ss >> opcao;

                if (opcao == '4') { // Voltar ao menu principal
                    std::cout << "Até mais!" << std::endl;
                    pessoa.salvarDados(); 
                    break;
                } else if (opcao == '1') {  // Caso o usuario queira adicionar um treino
                    std::system("clear");
                    while (true) {
                        std::cout << "Escolha o tipo de treino: 1 - Musculação 2 - Aeróbico" << std::endl;
                        std::getline(std::cin, input);
                        std::stringstream(input) >> opcao;
                        if (opcao == '1' || opcao == '2')
                            break;
                        else
                            std::cout << "Opção inválida. Por favor, escolha 1 para Musculação ou 2 para Aeróbico." << std::endl;
                    }

                    std::string nome, lugar;
                    int duracao, calorias, series, intensidade, ano, mes, dia;

                    std::cout << "Digite o nome do treino: ";
                    std::getline(std::cin, nome);

                    std::cout << "Digite o lugar do treino: ";
                    std::getline(std::cin, lugar);

                    while (true) {
                        std::cout << "Digite a duração do treino: ";
                        std::getline(std::cin, input);
                        if (std::stringstream(input) >> duracao)
                            break;
                        else
                            std::cout << "Duração inválida. Por favor, insira um número." << std::endl;
                    }

                    while (true) {
                        std::cout << "Digite as calorias gastas: ";
                        std::getline(std::cin, input);
                        if (std::stringstream(input) >> calorias)
                            break;
                        else
                            std::cout << "Calorias inválidas. Por favor, insira um número." << std::endl;
                    }

                    std::cout << "Digite a data no formato dd/mm/aaaa: ";
                    std::getline(std::cin, input);
                    std::stringstream dateStream(input);
                    char lixo;
                    dateStream >> dia >> lixo >> mes >> lixo >> ano;

                    if (opcao == '1') { // Adicionar treino de musculacao
                        while (true) {
                            std::cout << "Digite o número de séries: ";
                            std::getline(std::cin, input);
                            if (std::stringstream(input) >> series)
                                break;
                            else
                                std::cout << "Número de séries inválido. Por favor, insira um número." << std::endl;
                        }


                        pessoa.adicionarMusculacao(ano, mes, dia, duracao, calorias, lugar, nome, series);
                    } else if (opcao == '2') { // Adicionar treino aerobico
                        while (true) {
                            std::cout << "Digite a intensidade: ";
                            std::getline(std::cin, input);
                            if (std::stringstream(input) >> intensidade)
                                break;
                            else
                                std::cout << "Intensidade inválida. Por favor, insira um número." << std::endl;
                        }

                        pessoa.adicionarAerobico(ano, mes, dia, duracao, calorias, lugar, nome, intensidade);
                    } 
                } else if (opcao == '2') { // Opcao para remover treino 
                    while (true){
                        std::system("clear");
                        std::cout << "1 - Informe a data dd/mm/aaaa e o nome do treino" << std::endl
                                  << "2 - Voltar" << std::endl;
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
                            sleep(2);
                            std::system("clear");
                        } else if (opcao == '2'){
                            break;
                        } else {
                            std::cout << "Opção inválida" << std::endl;
                        }
                    }
                    
                }
                else if (opcao == '3'){ // Opcao para exibir treinos
                    while (true){
                        std::system("clear");
                        std::cout << "1 - Informe a data dd/mm/aaaa" << std::endl
                                  << "2 - Voltar" << std::endl;
                        std::getline(std::cin, input);
                        std::stringstream(input) >> opcao;
                        if (opcao == '1'){
                            int ano, mes, dia;
                            std::cout << "Digite a data no formato dd/mm/aaaa: ";
                            std::getline(std::cin, input);
                            std::stringstream dateStream(input);
                            char lixo;
                            dateStream >> dia >> lixo >> mes >> lixo >> ano;
                            std::system("clear");
                            pessoa.exibirTreinos(ano, mes, dia);

                            std::cout << "Pressione qualquer tecla para voltar" << std::endl;
                            std::cin.get();

                        } else if (opcao == '2'){
                            break;
                        } else {
                            std::cout << "Opção inválida" << std::endl;
                        }
                    }
                    
                }
                else {
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
