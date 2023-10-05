#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "Usuario.hpp"
#include "Aluguel.hpp"
#include <vector>

class Aluguel;
class Veiculo;

typedef struct tm Data;

class Cliente : public Usuario{

    std::string habilitacao;
    std::vector<Aluguel *> listaAlugueis;

    public:

        float cotar_Aluguel(Veiculo* veiculo,Data dataInicio, Data dataFim);
        Aluguel* solicitar_Aluguel(Veiculo* veiculo , Data dataInicio , Data DataFim);
        void devolver_veiculo(Aluguel* aluguel , Data dataDevolucao);

        std::string getHabilitacao();
        void setHabilitacao(std::string habitacao);


};

#endif