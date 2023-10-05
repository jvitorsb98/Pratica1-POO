#ifndef USUARIO_HPP
#define USUARIO_HPP

#include<iostream>

class Usuario{

    std::string cpf;
    std::string nome;
    std::string endereco;
    std::string telefone;

    public:

        void setCpf(std::string cpf);
        void setNome(std::string nome);
        void setEndereco(std::string endereco);
        void setTelefone(std::string telefone);

        std::string getCpf();
        std::string getNome();
        std::string getEndereco();
        std::string getTelefone();

};


#endif