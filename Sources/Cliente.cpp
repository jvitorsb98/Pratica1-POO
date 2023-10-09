#include "../Headers/Cliente.hpp"

int Cliente::numeroDeIdentificadores=0;


std::string Cliente::getHabilitacao(){
    return this->habilitacao;
}

void Cliente::setHabilitacao(std::string habilitacao){
    this->habilitacao = habilitacao;
}

Cliente::Cliente(std::string nome , std::string cpf , std::string telefone, std::string endereco , std::string habilitacao): habilitacao(habilitacao){
    setNome(nome);
    setCpf(cpf);
    setTelefone(telefone);
    setEndereco(endereco);
    Cliente::numeroDeIdentificadores++;
    setId(Cliente::numeroDeIdentificadores);
}

Cliente::Cliente(){

}

void Cliente::mostraCliente(){
    std::cout << "ID : " << getId() << std::endl;
    std::cout << "Nome : " << getNome() << std::endl;
    std::cout << "CPF : " << getCpf() << std::endl;
    std::cout << "Telefone : " << getTelefone() << std::endl;
    std::cout << "Endereço : " << getEndereco() << std::endl;
    std::cout << "Habilitação : " << getHabilitacao() << std::endl;
}


