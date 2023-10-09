#ifndef MENU_HPP
#define MENU_HPP

#include<iostream>
#include<vector>
#include "Aluguel.hpp"
#include "Cliente.hpp"

class Menu{

    public:

        static void menu(std::vector<Cliente> &clientes,std::vector<Veiculo> &veiculos,std::vector<Funcionario> &funcionarios , std::vector<Aluguel> &alugueis);
        static void mostraMenuPrincipal();

        /**CLIENTE**/
        static void menuCliente(std::vector<Cliente> &clientes);
        static void mostraMenuCliente();

        static void insereCliente(std::vector<Cliente> &clientes);
        static void listaClientes(std::vector<Cliente> &clientes);
        static void encontraCliente(std::vector<Cliente> &clientes);
        static void excluiCliente(std::vector<Cliente> &clientes);
        static void modificaCliente(std::vector<Cliente> &clientes);

        /**VEICULO**/
        static void menuVeiculo(std::vector<Veiculo> &veiculos);
        static void mostraMenuVeiculo();

        static void insereVeiculo(std::vector<Veiculo> &veiculos);
        static void listaVeiculo(std::vector<Veiculo> &veiculos);
        static void encontraVeiculo(std::vector<Veiculo> &veiculos);
        static void excluiVeiculo(std::vector<Veiculo> &veiculos);
        static void modificaVeiculo(std::vector<Veiculo> &veiculos);

        /**FUNCIONARIO**/

        static void menuFuncionario(std::vector<Funcionario> &funcionarios);
        static void mostraMenuFuncionario();

        static void insereFuncionario(std::vector<Funcionario> &funcionarios);
        static void listaFuncionario(std::vector<Funcionario> &funcionarios);
        static void encontraFuncionario(std::vector<Funcionario> &funcionarios);
        static void excluiFuncionario(std::vector<Funcionario> &funcionarios);
        static void modificaFuncionario(std::vector<Funcionario> &funcionarios);

        /**ALUGUEL**/

        static void menuAluguel(std::vector<Aluguel> &alugueis,std::vector<Cliente> &clientes,
        std::vector<Veiculo> &veiculos,std::vector<Funcionario> &funcionarios);
        static void mostraMenuAluguel();

        static void insereAluguel(std::vector<Aluguel> &alugueis,std::vector<Cliente> &clientes,
        std::vector<Veiculo> &veiculos,std::vector<Funcionario> &funcionarios);
        static void listaAluguel(std::vector<Aluguel> &alugueis);
        static void encontraAluguel(std::vector<Aluguel> &alugueis);
        static void excluiAluguel(std::vector<Aluguel> &alugueis);
        static void modificaAluguel(std::vector<Aluguel> &alugueis,std::vector<Cliente> &clientes,
        std::vector<Veiculo> &veiculos,std::vector<Funcionario> &funcionarios);


        static void pause();

};





#endif 