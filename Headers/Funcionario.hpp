#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include "Usuario.hpp"
#include "Aluguel.hpp"
#include <vector>

class Aluguel;
class Veiculo;
class Cliente;

typedef struct tm Data;

class Funcionario : public Usuario {

    std::vector<Aluguel*>historicoAlugueis; 
    static int numeroDeIdentificadores;

    public:
    Funcionario(std::string nome , std::string cpf , std::string telefone, std::string endereco);
    Funcionario();
    void alugaVeiculo(Cliente* cliente, Veiculo* veiculo , Data dataInicio , Data dataTermino);
    void finalizarAluguel(Aluguel* aluguel , Data dataDevolucao);

    void mostraFuncionario();

    std::vector<Aluguel*>* getHistoricoAlugueis();

};



#endif