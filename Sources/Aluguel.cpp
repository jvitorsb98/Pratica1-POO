#include "../Headers/Aluguel.hpp"

int Aluguel::numeroDeIdentificadores = 0;

Aluguel::Aluguel(Veiculo* veiculo , Cliente* cliente, tm dataInicio, tm dataTermino):veiculo(veiculo),cliente(cliente),dataInicio(dataInicio),dataTermino(dataTermino){

}

Aluguel::Aluguel(){

}

int Aluguel::getNumeroDeIdentificadores(){
    return Aluguel::numeroDeIdentificadores;
}

void Aluguel::setNumeroDeIdentificadores(int numeroDeAlugueis){
    Aluguel::numeroDeIdentificadores = numeroDeAlugueis;
}

std::string Aluguel::getIdentificador(){
    return this->identificador;
}

void Aluguel::setIdentificador(std::string identificador){
    this->identificador = identificador;
}

Veiculo* Aluguel::getVeiculo(){
    return this->veiculo;
}

void Aluguel::setVeiculo(Veiculo* veiculo){
    this->veiculo = veiculo;
}

Funcionario* Aluguel::getFuncionario(){
    return this->funcionario;
}

void Aluguel::setFuncionario(Funcionario* funcionario){
    this->funcionario = funcionario;
}

tm Aluguel::getDataInicio(){
    return this->dataInicio;
}

void Aluguel::setDataInicio(tm dataInicio){
    this->dataInicio;
}

tm Aluguel::getDataTermino(){
    return this->dataTermino;
}

void Aluguel::setDataTermino(tm dataTermino){
    this->dataTermino;
}

tm Aluguel::getDataDevolucao(){
    return this->dataDevolucao;
}

void Aluguel::setDataDevolucao(tm dataDevolucao){
    this->dataDevolucao;
}

float Aluguel::getDesconto(){
    return this->desconto;
}

void Aluguel::setDesconto(float desconto){
    this->desconto = desconto;
}

float Aluguel::getAdicional(){
    return this->adicional;
}

void Aluguel::setAdicional(float adicional){
    this->adicional = adicional;
}

float Aluguel::calcular_valor_final(){
    return ( (difftime(mktime(&dataInicio),mktime(&dataDevolucao))/86400) * getVeiculo()->getPrecoPorDia() ) - getDesconto() + getAdicional();
}

