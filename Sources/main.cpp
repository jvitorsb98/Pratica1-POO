#include "../Headers/Aluguel.hpp"
#include "../Headers/Menu.hpp"

int main(){

    std::vector<Cliente> clientes;
    std::vector<Veiculo> veiculos;
    std::vector<Funcionario> funcionarios;
    std::vector<Aluguel> alugueis;

    Menu::menu(clientes,veiculos,funcionarios,alugueis);

    


    return 0;
}