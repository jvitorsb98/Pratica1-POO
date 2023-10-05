#include "../Headers/Funcionario.hpp"

void Funcionario::alugaVeiculo(Cliente* cliente, Veiculo* veiculo , Data dataInicio , Data dataTermino){
    Aluguel aluguel(veiculo,cliente,dataInicio,dataTermino);
    aluguel.setFuncionario(this);
    getHistoricoAlugueis()->push_back(&aluguel);
}

void finalizarAluguel(Aluguel *aluguel , tm dataDevolucao){
    aluguel->setDataDevolucao(dataDevolucao);
}

std::vector<Aluguel *>* Funcionario::getHistoricoAlugueis(){
    return &(this->historicoAlugueis);
}

