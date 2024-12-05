#include <Pessoa.hpp>

Pessoa::Pessoa(std::string nome, std::string pathdata, int idade){
    _calendario = Calendario();
    _pathdata = pathdata;
    _nome = nome;
    _idade = idade;
}   

Pessoa::~Pessoa(){
}

void Pessoa::adicionarTreino(int ano, int mes, int dia, int duracao, int calorias,std::string lugar,std::string nome){
    _calendario.adicionarTreino(ano, mes, dia, duracao, calorias, lugar, nome);
}

void Pessoa::removerTreino(int ano, int mes, int dia, std::string& nome){
    _calendario.removerTreino(ano, mes, dia, nome);
}

void Pessoa::salvarDados(){
    std::ofstream file;
    file.open(_pathdata);
    if (!file.is_open()){
        std::cout << "Erro ao abrir arquivo" << std::endl;
        return;
    }

    file << _nome << std::endl;
    file << _idade << std::endl;

// https://www.youtube.com/watch?v=4J5linNcw6g

    for (auto& [ano, meses]: _calendario.getCalendario()){
        for(auto& [mes, dias] : meses){
            for(auto& dia : dias){
                file << "data " << (dia.first < 10 ? "0" : "") << dia.first << "/" << (mes < 10 ? "0" : "") << mes << "/"<< ano << std::endl;          
                for(auto& treino : dia.second){
                    file << "- " << treino.getNome() << " (" << treino.getDuracao() << " min, " << treino.getCalorias() << " kcal, " << treino.getLugar() << ")" << std::endl;
                }
            }
        }

    }

    file.close();
}