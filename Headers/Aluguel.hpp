#ifndef ALUGUEL_HPP
#define ALUGUEL_HPP

#include "Veiculo.hpp"
#include "Cliente.hpp"
#include "Funcionario.hpp"
#include <string>
#include <ctime>

class Cliente; // Declaração avançada
class Funcionario; // Declaração avançada
class Veiculo;

typedef struct tm Data;

class Aluguel{

    static int numeroDeIdentificadores;

    int id;
    Veiculo* veiculo;
    Cliente* cliente;
    Funcionario* funcionario;
    Data dataInicio;
    Data dataTermino;
    Data dataDevolucao;
    float desconto;
    float adicional;

    public:

        Aluguel(Cliente* cliente,Veiculo* veiculo , Funcionario* funcionario,  Data dataInicio, Data dataTermino, float desconto , float adicional);
        Aluguel();

        int getId();
        void setId(int id);

        Cliente* getCliente();
        void setCliente(Cliente* cliente);

        Veiculo* getVeiculo();
        void setVeiculo(Veiculo* veiculo);

        Funcionario* getFuncionario();
        void setFuncionario(Funcionario* funcionario);

        Data getDataInicio();
        void setDataInicio(Data dataInicio);

        Data getDataTermino();
        void setDataTermino(Data dataInicio);

        Data getDataDevolucao();
        void setDataDevolucao(Data dataInicio);

        float getDesconto();
        void setDesconto(float desconto);

        float getAdicional();
        void setAdicional(float adicional);

        float calcular_valor_final();

        void mostraAluguel();

};


#endif