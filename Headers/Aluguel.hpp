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

class Aluguel{

    static int numeroDeIdentificadores;

    std::string identificador;
    Veiculo* veiculo;
    Cliente* cliente;
    Funcionario* funcionario;
    struct tm dataInicio;
    struct tm dataTermino;
    struct tm dataDevolucao;
    float desconto;
    float adicional;

    public:

        Aluguel(Veiculo* veiculo , Cliente* cliente, tm dataInicio, tm dataTermino);
        Aluguel();

        static int getNumeroDeIdentificadores();
        static void setNumeroDeIdentificadores(int numeroDeAlugueis);

        std::string getIdentificador();
        void setIdentificador(std::string identificador);

        Veiculo* getVeiculo();
        void setVeiculo(Veiculo* veiculo);

        Funcionario* getFuncionario();
        void setFuncionario(Funcionario* funcionario);

        tm getDataInicio();
        void setDataInicio(tm dataInicio);

        tm getDataTermino();
        void setDataTermino(tm dataInicio);

        tm getDataDevolucao();
        void setDataDevolucao(tm dataInicio);

        float getDesconto();
        void setDesconto(float desconto);

        float getAdicional();
        void setAdicional(float adicional);

        float calcular_valor_final();

};


#endif