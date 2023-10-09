#ifndef PERSISTENCIA_HPP
#define PERSISTENCIA_HPP

#include "../Headers/Cliente.hpp"
#include "../Headers/Veiculo.hpp"

class Persistencia{

    public:

    static void recuperaClientes(std::vector<Cliente> &clientes);
    static void recuperaVeiculos(std::vector<Veiculo> &veiculos);
    static void recuperaFuncionarios(std::vector<Funcionario> &funcionarios);
    static void recuperaAlugueis(std::vector<Aluguel> &alugueis,
    std::vector<Cliente> &clientes,std::vector<Veiculo> &veiculos,std::vector<Funcionario> &funcionarios);
};


#endif