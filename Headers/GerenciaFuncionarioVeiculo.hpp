#ifndef GERENCIA_FUNCIONARIO_VEICULO_HPP
#define GERENCIA_FUNCIONARIO_VEICULO_HPP

#include "Funcionario.hpp"

class Funcionario;
class Veiculo;

class GerenciaFuncionarioVeiculo{

    private:
        Funcionario* funcionario;
        Veiculo* veiculo;

    public:
        void assoscia(Funcionario* funcionario , Veiculo* veiculo);

};


#endif