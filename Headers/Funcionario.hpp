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

    public:

    void alugaVeiculo(Cliente* cliente, Veiculo* veiculo , Data dataInicio , Data dataTermino);
    void finalizarAluguel(Aluguel* aluguel , Data dataDevolucao);

    std::vector<Aluguel*>* getHistoricoAlugueis();

};



#endif