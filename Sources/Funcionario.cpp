#include "../Headers/Funcionario.hpp"

int Funcionario::numeroDeIdentificadores = 0;

void Funcionario::alugaVeiculo(Cliente* cliente, Veiculo* veiculo , Data dataInicio , Data dataTermino){
    Aluguel aluguel;
    aluguel.setCliente(cliente);
    aluguel.setVeiculo(veiculo);
    aluguel.setDataInicio(dataInicio);
    aluguel.setDataTermino(dataTermino);
    aluguel.setFuncionario(this);
    getHistoricoAlugueis()->push_back(&aluguel);
}

void Funcionario::finalizarAluguel(Aluguel *aluguel , tm dataDevolucao){
    aluguel->setDataDevolucao(dataDevolucao);
}

std::vector<Aluguel *>* Funcionario::getHistoricoAlugueis(){
    return &(this->historicoAlugueis);
}

Funcionario::Funcionario(std::string nome , std::string cpf , std::string telefone, std::string endereco){
    setNome(nome);
    setCpf(cpf);
    setTelefone(telefone);
    setEndereco(endereco);
    Funcionario::numeroDeIdentificadores++;
    setId(Funcionario::numeroDeIdentificadores);
}


Funcionario::Funcionario(){

}

void Funcionario::mostraFuncionario(){
    std::cout << "ID : " << getId() << std::endl;
    std::cout << "Nome : " << getNome() << std::endl;
    std::cout << "CPF : " << getCpf() << std::endl;
    std::cout << "Telefone : " << getTelefone() << std::endl;
    std::cout << "Endereço : " << getEndereco() << std::endl;
}

