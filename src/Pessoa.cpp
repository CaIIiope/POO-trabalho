#include <Pessoa.hpp>

Pessoa::Pessoa(std::string nome, std::string pathdata, int idade){
    _calendario = Calendario();
    _pathdata = pathdata;
    _nome = nome;
    _idade = idade;
}   
Pessoa::Pessoa(const std::string& pathdata){
    _calendario = Calendario();
    _pathdata = pathdata;
    carregarDados();
}

Pessoa::~Pessoa(){
}

void Pessoa::adicionarMusculacao(int ano, int mes, int dia, int duracao, int calorias,std::string lugar,std::string nome, int series, int repeticoes, int peso){
    std::cout << "Adicionando treino de musculação..." << std::endl;
    _calendario.adicionarMusculacao(ano, mes, dia, duracao, calorias, lugar, nome, series, repeticoes, peso);
}

void Pessoa::adicionarAerobico(int ano, int mes, int dia, int duracao, int calorias,std::string lugar,std::string nome, int intensidade){
    _calendario.adicionarAerobico(ano, mes, dia, duracao, calorias, lugar, nome, intensidade);
}

void Pessoa::removerTreino(int ano, int mes, int dia, std::string& nome){
    _calendario.removerTreino(ano, mes, dia, nome);
}


void Pessoa::exibirTreinos(int ano, int mes, int dia){
    std::vector<Treino*> treinos = _calendario.getTreinos(ano, mes, dia);
    if (treinos.size() == 0){
        std::cout << "Nenhum treino encontrado para a data informada." << std::endl;
        return;
    }
    std::cout << "Treinos para a data " << dia << "/" << mes << "/" << ano << std::endl;
    for(auto treino : treinos){
        std::cout << *treino;
    }
}

void Pessoa::salvarDados(){
    std::ofstream file;
    file.open(_pathdata, std::ofstream::out | std::ofstream::trunc);
    if (!file.is_open()){
        std::cout << "Erro ao abrir arquivo" << std::endl;
        return;
    }

    file << _nome << std::endl;
    file << _idade << std::endl;

    std::stringstream conteudo;

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

int Pessoa::carregarDados(){
    std::ifstream file(_pathdata);
    if(!file.is_open())
        return 0;
    
    std::string line;

// carrega o nome e a idade
    std::getline(file, _nome);
    std::getline(file, line);
    _idade = std::stoi(line);

    int ano, mes, dia;
    int position;
    std::string dado;

    std::string nome, lugar;
    int duracao, calorias, series, repeticoes, peso, intensidade;

    while (std::getline(file, line)){
        
        //data
        if (line.substr(0, 4).compare("data") == 0){
            dado = line.substr(5, 2);
            dia = std::atoi(dado.c_str());
            dado = line.substr(8, 2);
            mes = std::atoi(dado.c_str());
            dado = line.substr(11);
            ano = std::atoi(dado.c_str());

        }

        if (line.compare("Treino Musculacao") == 0){

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
            repeticoes = std::atoi(line.substr(12).c_str());

            std::getline(file, line);
            peso = std::atoi(line.substr(6).c_str());

            _calendario.adicionarMusculacao(ano, mes, dia, duracao, calorias, lugar, nome, series, repeticoes, peso);

        }
        
        if (line.compare("Treino Aerobico") == 0){

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

            _calendario.adicionarAerobico(ano, mes, dia, duracao, calorias, lugar, nome, intensidade);

        }


    }
    
    file.close();
    return 1;

} 