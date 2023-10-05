#ifndef VEICULO_HPP
#define VEICULO_HPP

#include<iostream>
#include<vector>
#include "Aluguel.hpp"

class Aluguel;

class Veiculo{

    std::string identificador;
    std::string marca;
    std::string modelo;
    int anoFabricacao;
    float precoPorDia;
    std::vector<Aluguel*> listaAlugueis;

    public:

        std::string getIdentificador();
        std::string getMarca();
        std::string getModelo();
        int getAnoFabricacao();
        float getPrecoPorDia();
        std::vector<Aluguel*>* getListaAlugueis();

        void setIdentificador(std::string identificador);
        void setMarca(std::string marca);
        void setModelo(std::string modelo);
        void setAnoFabricacao(int anoFabricacao);
        void setPrecoPorDia(float precoPorDia);

};

#endif