#ifndef VEICULO_HPP
#define VEICULO_HPP

#include<iostream>
#include<vector>
#include "Aluguel.hpp"

class Aluguel;

class Veiculo{

    static int numeroDeIdentificadores;

    int  id;
    std::string marca;
    std::string modelo;
    int anoFabricacao;
    float precoPorDia;
    std::vector<Aluguel*> listaAlugueis;

    public:
        Veiculo(std::string marca , std::string modelo , int anoFabricacao, float precoPorDia);
        Veiculo();

        int getId();
        std::string getMarca();
        std::string getModelo();
        int getAnoFabricacao();
        float getPrecoPorDia();
        std::vector<Aluguel*>* getListaAlugueis();

        void setId(int id);
        void setMarca(std::string marca);
        void setModelo(std::string modelo);
        void setAnoFabricacao(int anoFabricacao);
        void setPrecoPorDia(float precoPorDia);
        void mostraVeiculo();

};

#endif