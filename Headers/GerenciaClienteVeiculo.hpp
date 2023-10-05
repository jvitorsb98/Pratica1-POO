#ifndef GERENCIA_CLIENTE_VEICULO_HPP
#define GERENCIA_CLIENTE_VEICULO_HPP

#include "Funcionario.hpp"

class GerenciaClienteVeiculo{

    private:
        Cliente* cliente;
        Veiculo* veiculo;

    public:
        void assoscia(Cliente* cliente , Veiculo* veiculo);

};


#endif