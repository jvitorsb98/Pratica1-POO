#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "Usuario.hpp"
#include "Aluguel.hpp"
#include <vector>

class Aluguel;
class Veiculo;

typedef struct tm Data;

class Cliente : public Usuario{

    static int numeroDeIdentificadores;

    std::string habilitacao;
    std::vector<Aluguel *> listaAlugueis;

    public:
        Cliente(std::string nome , std::string cpf , std::string telefone, std::string endereco , std::string habilitacao);
        Cliente();
        float cotar_Aluguel(Veiculo* veiculo,Data dataInicio, Data dataFim);
        Aluguel* solicitar_Aluguel(Veiculo* veiculo , Data dataInicio , Data DataFim);
        void devolver_veiculo(Aluguel* aluguel , Data dataDevolucao);

        std::string getHabilitacao();
        void setHabilitacao(std::string habitacao);
        void mostraCliente();

};

#endif