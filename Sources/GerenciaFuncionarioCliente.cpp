#include "../Headers/GerenciaFuncionarioCliente.hpp"

void GerenciaFuncionarioCliente::assoscia(Funcionario* funcionario , Cliente* cliente){
    this->funcionario = funcionario;
    this->cliente = cliente;
}
