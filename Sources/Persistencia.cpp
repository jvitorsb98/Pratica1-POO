#include "../Headers/Persistencia.hpp"
#include<fstream>
#include<cctype>

void Persistencia::recuperaClientes(std::vector<Cliente> &clientes){
    std::ifstream inClientes;
    inClientes.open("../BancoDeDados/clientes.txt",std::ios_base::in);

    if(inClientes.is_open()){
        while(inClientes.eof() == false){
            std::string id;
            std::string nome;
            std::string cpf;
            std::string telefone;
            std::string endereco;
            std::string habilitacao;
            getline(inClientes,id);
            getline(inClientes,nome);
            getline(inClientes,cpf);
            getline(inClientes,telefone);
            getline(inClientes,endereco);
            getline(inClientes,habilitacao);

            if(id.length()>0){
                int idd = stoi(id);
                Cliente cliente(nome,cpf,telefone,endereco,habilitacao);
                cliente.setId(idd);
                clientes.push_back(cliente);
            }
        }
        inClientes.close();
    }
}

void Persistencia::recuperaVeiculos(std::vector<Veiculo> &veiculos){
   std::ifstream inVeiculos;
    inVeiculos.open("../BancoDeDados/veiculos.txt",std::ios_base::in);

    if(inVeiculos.is_open()){
        while(inVeiculos.eof() == false){
            std::string id;
            std::string marca;
            std::string modelo;
            std::string anoFabricacao;
            std::string precoPorDia;
            getline(inVeiculos,id);
            getline(inVeiculos,marca);
            getline(inVeiculos,modelo);
            getline(inVeiculos,anoFabricacao);
            getline(inVeiculos,precoPorDia);

            if(id.length()>0){
                int idd = stoi(id);
                int anoFabricacaoInt = stoi(anoFabricacao);
                float precoPorDiaFloat = stof(precoPorDia);
                Veiculo veiculo(marca,modelo,anoFabricacaoInt,precoPorDiaFloat);
                veiculo.setId(idd);
                veiculos.push_back(veiculo);
            }
        }
        inVeiculos.close();
    }
}

void Persistencia::recuperaFuncionarios(std::vector<Funcionario> &funcionarios){
    std::ifstream inFuncionarios;
    inFuncionarios.open("../BancoDeDados/funcionarios.txt",std::ios_base::in);

    if(inFuncionarios.is_open()){
        while(inFuncionarios.eof() == false){
            std::string id;
            std::string nome;
            std::string cpf;
            std::string telefone;
            std::string endereco;
            getline(inFuncionarios,id);
            getline(inFuncionarios,nome);
            getline(inFuncionarios,cpf);
            getline(inFuncionarios,telefone);
            getline(inFuncionarios,endereco);

            if(id.length()>0){
                int idd = stoi(id);
                Funcionario funcionario(nome,cpf,telefone,endereco);
                funcionario.setId(idd);
                funcionarios.push_back(funcionario);
            }
        }
        inFuncionarios.close();
    }
}

void Persistencia::recuperaAlugueis(std::vector<Aluguel> &alugueis,
    std::vector<Cliente> &clientes,std::vector<Veiculo> &veiculos,std::vector<Funcionario> &funcionarios){

    std::ifstream inAlugueis;
    inAlugueis.open("../BancoDeDados/alugueis.txt",std::ios_base::in);

    if(inAlugueis.is_open()){
        while(inAlugueis.eof() == false){
            std::string id;
            std::string idCliente;
            std::string idVeiculo;
            std::string idFuncionario;
            std::string diaInicio;
            std::string mesInicio;
            std::string anoInicio;
            std::string diaFim;
            std::string mesFim;
            std::string anoFim;
            std::string diaDevolucao;
            std::string mesDevolucao;
            std::string anoDevolucao;
            std::string desconto;
            std::string adicional;

            getline(inAlugueis,id);
            getline(inAlugueis,idCliente);
            getline(inAlugueis,idVeiculo);
            getline(inAlugueis,idFuncionario);
            getline(inAlugueis,diaInicio);
            getline(inAlugueis,mesInicio);
            getline(inAlugueis,anoInicio);
            getline(inAlugueis,diaFim);
            getline(inAlugueis,mesFim);
            getline(inAlugueis,anoFim);
            getline(inAlugueis,diaDevolucao);
            getline(inAlugueis,mesDevolucao);
            getline(inAlugueis,anoDevolucao);
            getline(inAlugueis,desconto);
            getline(inAlugueis,adicional);

            if(id.length()>0){
                int idd = stoi(id);
                Cliente* cliente;
                Veiculo* veiculo;
                Funcionario* funcionario;
                Data dataInicio;
                Data dataFim;
                Data dataDevolucao;
                float descontoFloat, adicionalFloat;


                for(auto it=clientes.begin() ; it!=clientes.end() ; it++){
                    if(it->getId() == stoi(idCliente)){
                        cliente = &(*it);
                    }
                }


                for(auto it=veiculos.begin() ; it!=veiculos.end() ; it++){
                    if(it->getId() == stoi(idVeiculo)){
                        veiculo = &(*it);
                    }
                }


                for(auto it=funcionarios.begin() ; it!=funcionarios.end() ; it++){
                    if(it->getId() == stoi(idFuncionario)){
                        funcionario = &(*it);
                    }
                }

                dataInicio.tm_mday = stoi(diaInicio);
                dataInicio.tm_mon = stoi(mesInicio);
                dataInicio.tm_year = stoi(anoInicio);

                dataFim.tm_mday = stoi(diaFim);
                dataFim.tm_mon = stoi(mesFim);
                dataFim.tm_year = stoi(anoFim);

                dataDevolucao.tm_mday = stoi(diaDevolucao);
                dataDevolucao.tm_mon = stoi(mesDevolucao);
                dataDevolucao.tm_year = stoi(anoDevolucao);

                descontoFloat = stof(desconto);
                adicionalFloat = stof(adicional);


                Aluguel aluguel(cliente,veiculo,funcionario,dataInicio,dataFim,descontoFloat,adicionalFloat);
                aluguel.setId(idd);
                aluguel.setDataDevolucao(dataDevolucao);
                alugueis.push_back(aluguel);

            }
        }
        inAlugueis.close();
    }

}

