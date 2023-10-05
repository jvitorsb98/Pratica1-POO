#include "../Headers/Veiculo.hpp"

std::string Veiculo::getIdentificador(){
    return this->identificador;
}

void Veiculo::setIdentificador(std::string identificador){
    this->identificador = identificador;
}

std::string Veiculo::getMarca(){
    return this->marca;
}

void Veiculo::setMarca(std::string marca){
    this->marca = marca;
}

std::string Veiculo::getModelo(){
    return this->modelo;
}

void Veiculo::setModelo(std::string modelo){
    this->modelo = modelo;
}

int Veiculo::getAnoFabricacao(){
    return this->anoFabricacao;
}

void Veiculo::setAnoFabricacao(int anoFabricacao){
    this->anoFabricacao = anoFabricacao;
}

float Veiculo::getPrecoPorDia(){
    return this->precoPorDia;
}

void Veiculo::setPrecoPorDia(float precoPorDia){
    this->precoPorDia = precoPorDia;
}


std::vector<Aluguel*>* Veiculo::getListaAlugueis(){
    return &(this->listaAlugueis);
}

