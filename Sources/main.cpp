#include "../Headers/Aluguel.hpp"
#include "../Headers/Menu.hpp"
#include "../Headers/Persistencia.hpp"

int main(){

    std::vector<Cliente> clientes;
    std::vector<Veiculo> veiculos;
    std::vector<Funcionario> funcionarios;
    std::vector<Aluguel> alugueis;
    Persistencia::recuperaClientes(clientes);
    Persistencia::recuperaVeiculos(veiculos);
    Persistencia::recuperaFuncionarios(funcionarios);
    Persistencia::recuperaAlugueis(alugueis,clientes,veiculos,funcionarios);
    Menu::menu(clientes,veiculos,funcionarios,alugueis);
    
    


    return 0;
}