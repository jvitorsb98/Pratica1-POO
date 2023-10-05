#include "../Headers/Usuario.hpp"

void Usuario::setCpf(std::string cpf){
    this->cpf = cpf;
}

void Usuario::setNome(std::string nome){
    this->nome = nome;
}

void Usuario::setEndereco(std::string endereco){
    this->endereco = endereco;
}

void Usuario::setTelefone(std::string telefone){
    this->telefone = telefone;
}

std::string Usuario::getCpf(){
    return this->cpf;
}

std::string Usuario::getNome(){
    return this->nome;
}

std::string Usuario::getEndereco(){
    return this->endereco;
}

std::string Usuario::getTelefone(){
    return this->telefone;
}