#include <Pessoa.hpp>

Pessoa::Pessoa(std::string nome, std::string pathdata, int idade){
    _calendario = Calendario();
    _pathdata = pathdata;
    _nome = nome;
    _idade = idade;
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