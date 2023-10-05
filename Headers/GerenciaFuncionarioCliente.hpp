#ifndef GERENCIA_FUNCIONARIO_CLIENTE_HPP
#define GERENCIA_FUNCIONARIO_CLIENTE_HPP

#include "Funcionario.hpp"

class GerenciaFuncionarioCliente{

    private:
        Funcionario* funcionario;
        Cliente* cliente;

    public:
        void assoscia(Funcionario* funcionario , Cliente* cliente);

};


#endif