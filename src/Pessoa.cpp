#include <Pessoa.hpp>

// Construtor da classe Pessoa  para novo usuario
Pessoa::Pessoa(std::string nome, std::string pathdata, int idade){
    _calendario = Calendario();
    _pathdata = pathdata;
    _nome = nome;
    _idade = idade;
}   

// Construtor da classe Pessoa para usuario ja existente
Pessoa::Pessoa(const std::string& pathdata){
    _calendario = Calendario();
    _pathdata = pathdata;
    carregarDados();
}

Pessoa::~Pessoa(){
}

// Adiciona um treino de musculação no calendario
void Pessoa::adicionarMusculacao(int ano, int mes, int dia, int duracao, int calorias,std::string lugar,std::string nome, int series){
    std::cout << "Adicionando treino de musculação..." << std::endl;
    std::vector<std::pair<int, float>> rep_peso;
    std::pair<int, float> conjunto;
    int repeticoes;
    float peso;
    std::string input;
    for (int i = 0; i < series; i++){  // Para o numero de series do exercicio
        while (true) {
            std::cout << "Digite as repeticoes da serie  " << i+1 << " :";
            std::getline(std::cin, input);
            if (std::stringstream(input) >> repeticoes) 
                break;
            else
                std::cout << "Duração inválida. Por favor, insira um número." << std::endl;
        }
        while (true) {
            std::cout << "Digite o peso da serie  " << i+1 << " :";
            std::getline(std::cin, input);
            if (std::stringstream(input) >> peso) 
                break;
            else
                std::cout << "Duração inválida. Por favor, insira um número." << std::endl;
        }
        conjunto = std::make_pair(repeticoes, peso);
        rep_peso.push_back(conjunto);
    }   
    _calendario.adicionarMusculacao(ano, mes, dia, duracao, calorias, lugar, nome, series, rep_peso);
}

// Adiciona um treino aerobico no calendario
void Pessoa::adicionarAerobico(int ano, int mes, int dia, int duracao, int calorias,std::string lugar,std::string nome, int intensidade){
    std::cout << "Adicionando treino aeróbico..." << std::endl;
    _calendario.adicionarAerobico(ano, mes, dia, duracao, calorias, lugar, nome, intensidade);
}

// Remove um treino do calendario
void Pessoa::removerTreino(int ano, int mes, int dia, std::string& nome){
    _calendario.removerTreino(ano, mes, dia, nome);
}


// Exibe os treinos de uma data
void Pessoa::exibirTreinos(int ano, int mes, int dia){
    // Pega os treinos da data informada
    std::vector<Treino*> treinos = _calendario.getTreinos(ano, mes, dia);
    // Verifica se existem treinos
    if (treinos.size() == 0){
        std::cout << "Nenhum treino encontrado para a data informada." << std::endl;
        return;
    }
    // Caso existam treinos, exibe-os
    std::cout << "Treinos para a data " << dia << "/" << mes << "/" << ano << std::endl;
    for(auto treino : treinos){
        std::cout << *treino;
    }
}

// Salva os dados do usuario no arquivo texto
void Pessoa::salvarDados(){
    std::ofstream file;

    // Abre o arquivo para escrita
    file.open(_pathdata, std::ofstream::out | std::ofstream::trunc);
    // Verifica se o arquivo existe
    if (!file.is_open()){
        std::cout << "Erro ao abrir arquivo" << std::endl;
        return;
    }

    file << _nome << std::endl;
    file << _idade << std::endl;

    std::stringstream conteudo;
    // Salva os treinos no arquivo por cada dia do calendario
    for (auto& [ano, meses]: _calendario.getCalendario()){
        for(auto& [mes, dias] : meses){
            for(auto& dia : dias){
                file << "data " << (dia.first < 10 ? "0" : "") << dia.first << "/" << (mes < 10 ? "0" : "") << mes << "/"<< ano << std::endl;          
                for(auto& treino : dia.second){
                    treino->salvaTreino(&conteudo);
                    file << conteudo.str();
                    conteudo.clear();
                    conteudo.str("");
                }
            }
        }
    }
    file.close();
}

// Carrega os dados do usuario do arquivo texto
int Pessoa::carregarDados() {
    std::ifstream file(_pathdata);
    // Verifica se o arquivo existe
    if (!file.is_open())
        return 0;

    std::string line;

    // Carrega o nome e a idade
    std::getline(file, _nome);
    std::getline(file, line);
    _idade = std::stoi(line);

    int ano, mes, dia;
    std::string dado;

    std::string nome, lugar;
    int duracao, calorias, series, repeticoes;
    float peso, intensidade;

    while (std::getline(file, line)) {
        // Lê a data do calendário que está no arquivo
        if (line.substr(0, 4) == "data") {
            dado = line.substr(5, 2);
            dia = std::atoi(dado.c_str());
            dado = line.substr(8, 2);
            mes = std::atoi(dado.c_str());
            dado = line.substr(11);
            ano = std::atoi(dado.c_str());
        }

        // Lê os atributos da classe Musculacao
        if (line == "Treino Musculacao") {
            std::getline(file, line);
            nome = line.substr(6);

            std::getline(file, line);
            duracao = std::atoi(line.substr(9).c_str());

            std::getline(file, line);
            calorias = std::atoi(line.substr(10).c_str());

            std::getline(file, line);
            lugar = line.substr(7);

            std::getline(file, line);
            series = std::atoi(line.substr(8).c_str());

            std::getline(file, line);

            // Vetor para armazenar as séries
            std::vector<std::pair<int, float>> rep_peso;

            // Lê os detalhes de cada série
            for (int i = 0; i < series; ++i) {
                std::getline(file, line);

                std::smatch match;
                regex_search(line, match, std::regex(R"(Série (\d+): (\d+) repetições, (\d+))"));

                repeticoes = std::stoi(match[2]);
                peso = std::stof(match[3]);

                rep_peso.emplace_back(repeticoes, peso);
            }

            // Adiciona o treino ao calendário
            _calendario.adicionarMusculacao(ano, mes, dia, duracao, calorias, lugar, nome, series, rep_peso);
        }

        // Lê os atributos da classe Aerobico
        if (line == "Treino Aerobico") {
            std::getline(file, line);
            nome = line.substr(6);

            std::getline(file, line);
            duracao = std::atoi(line.substr(9).c_str());

            std::getline(file, line);
            calorias = std::atoi(line.substr(10).c_str());

            std::getline(file, line);
            lugar = line.substr(7);

            std::getline(file, line);
            intensidade = std::atoi(line.substr(12).c_str());

            // Adiciona o treino ao calendário
            _calendario.adicionarAerobico(ano, mes, dia, duracao, calorias, lugar, nome, intensidade);
        }
    }

    file.close();
    return 1;
}
