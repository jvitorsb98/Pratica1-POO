#ifndef MENU_HPP
#define MENU_HPP

#include<iostream>
#include<vector>
#include "Aluguel.hpp"

class Menu{

    public:

        static void menu(std::vector<Cliente> &clientes,std::vector<Veiculo> &veiculos,std::vector<Funcionario> &funcionarios , std::vector<Aluguel> &alugueis);
        static void mostraMenuPrincipal();

        static void menuCliente(std::vector<Cliente> &clientes);
        static void mostraMenuCliente();

        static void menuVeiculo(std::vector<Veiculo> &veiculos);
        static void mostraMenuVeiculo();

        static void menuFuncionario(std::vector<Funcionario> &funcionaios, std::vector<Aluguel> &alugueis);
        static void mostraMenuFuncionario();

        static void menuAluguel(std::vector<Aluguel> &alugueis);
        static void mostraMenuAluguel();

};





#endif 