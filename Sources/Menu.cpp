#include "../Headers/Menu.hpp"
#include<fstream>

void Menu::pause(){
    std::cout << "Pressione <Enter> para avançar";
    getchar();
}

/**PRINCIPAL**/

void Menu::menu(std::vector<Cliente> &clientes,std::vector<Veiculo> &veiculos,std::vector<Funcionario> &funcionarios , std::vector<Aluguel> &alugueis){
    int escolha;
    do{ 
        system("clear||cls");
        Menu::mostraMenuPrincipal();
        std::cin >> escolha;
        std::cin.get();
        switch (escolha)
        {
        case 1:
            menuCliente(clientes);
            break;
        case 2:
            menuVeiculo(veiculos);
            break;
        case 3:
            menuFuncionario(funcionarios);
            break;
        case 4:
            menuAluguel(alugueis,clientes,veiculos,funcionarios);
            break;
        case 0:
            exit(0);
        
        default:
            break;
        }
    }while(escolha!=0);
}

void Menu::mostraMenuPrincipal(){
    
    std::cout << "-----------MENU PRINCIPAL-----------" << std::endl;
    std::cout << "[1] MENU CLIENTE" << std::endl;
    std::cout << "[2] MENU VEICULO" << std::endl;
    std::cout << "[3] MENU FUNCIONARIO" << std::endl;
    std::cout << "[4] MENU ALUGUEL" << std::endl;
    std::cout << "[0] SAIR" << std::endl;
}

/******CLIENTE********/

void Menu::menuCliente(std::vector<Cliente> &clientes){
    int escolha;
    do{ 
        system("clear||cls");
        Menu::mostraMenuCliente();
        std::cin >> escolha;
        std::cin.get();

        switch(escolha){
            case 1:
                insereCliente(clientes);
                break;
            case 2:
                listaClientes(clientes);
                break;
            case 3:
                encontraCliente(clientes);
                break;
            case 4:
                excluiCliente(clientes);
                break;
            case 5:
                modificaCliente(clientes);
                break;
        }

    }while(escolha!=0);
}

void Menu::mostraMenuCliente(){
    
    std::cout << "-----------MENU CLIENTES-----------" << std::endl;
    std::cout << "[1] INCLUIR" << std::endl;
    std::cout << "[2] LISTAR" << std::endl;
    std::cout << "[3] ENCONTRAR " << std::endl;
    std::cout << "[4] EXCLUIR " << std::endl;
    std::cout << "[5] MODIFICAR " << std::endl;
    std::cout << "[0] SAIR" << std::endl;

}

void Menu::insereCliente(std::vector<Cliente> &clientes){
    system("clear || cls");
    std::cout << "---INSERIR CLIENTE---" << std::endl;
    std::string nome,cpf,telefone,endereco,habilitacao;
    std::cout << "Nome : ";
    getline(std::cin,nome);
    std::cout << "CPF : ";
    getline(std::cin,cpf);
    std::cout << "Telefone : ";
    getline(std::cin,telefone);
    std::cout << "Endereço : ";
    getline(std::cin,endereco);
    std::cout << "Habilitação : ";
    getline(std::cin,habilitacao);

    Cliente cliente(nome,cpf,telefone,endereco,habilitacao);
    clientes.push_back(cliente);

    std::ofstream inClientes;
    inClientes.open("../BancoDeDados/clientes.txt",std::ios_base::app);
    if(inClientes.is_open()){
        inClientes << cliente.getId() << std::endl;
        inClientes << cliente.getNome() << std::endl;
        inClientes << cliente.getCpf() << std::endl;
        inClientes << cliente.getTelefone() << std::endl;
        inClientes << cliente.getEndereco() << std::endl;
        inClientes << cliente.getHabilitacao() << std::endl;
        inClientes.close();
    }
    pause();
}

void Menu::listaClientes(std::vector<Cliente> &clientes){
    system("clear || cls");
    std::cout << "---LISTA DE CLIENTES---" << std::endl;
    for(auto it=clientes.begin() ; it!=clientes.end() ; it++){
        std::cout << "------------------------------------" << std::endl;
        it->mostraCliente();
    }
    std::cout << "---FIM DA LISTA---" << std::endl;
    pause();
}

void Menu::encontraCliente(std::vector<Cliente> &clientes){
    system("clear || cls");
    int id;
    std::cout << "ID do cliente para busca : " << std::endl;
    std::cin >> id;
    std::cin.get();

    for(auto it=clientes.begin() ; it!=clientes.end() ; it++){
        if(it->getId() == id ){
            std::cout << "---CLIENTE ENCONTRADO---" << std::endl;
            it->mostraCliente();
            pause();
            return;
        }
    }
    std::cout << "Cliente não encontrado " << std::endl;
    pause();
}

void Menu::excluiCliente(std::vector<Cliente> &clientes){
    system("clear || cls");
    int id;
    std::cout << "ID do cliente para exclusão : " << std::endl;
    std::cin >> id;
    std::cin.get();
    bool clienteExcluido= false;

    for(auto it=clientes.begin() ; it!=clientes.end() ; it++){
        if(it->getId() == id ){
            clientes.erase(it);
            std::cout << "---CLIENTE EXCLUIDO---" << std::endl;
            pause();
            clienteExcluido = true;
            break;
        }
    }
    if(clienteExcluido){
        std::ofstream inClientes;
        inClientes.open("../BancoDeDados/clientes.txt",std::ios_base::out);
        if(inClientes.is_open()){
            for(auto it=clientes.begin() ; it!=clientes.end() ; it++){
                inClientes << it->getId() << std::endl;
                inClientes << it->getNome() << std::endl;
                inClientes << it->getCpf() << std::endl;
                inClientes << it->getTelefone() << std::endl;
                inClientes << it->getEndereco() << std::endl;
                inClientes << it->getHabilitacao() << std::endl;
            }
            inClientes.close();
        }
    }else{
        std::cout << "Cliente não encontrado " << std::endl;
        pause();
    }



}

void Menu::modificaCliente(std::vector<Cliente> &clientes){
    int escolha;
    system("clear || cls");
    int id;
    std::cout << "ID do cliente para modificação : " << std::endl;
    std::cin >> id;
    std::cin.get();
    bool clienteModificado= false;

    for(auto it=clientes.begin() ; it!=clientes.end() ; it++){
        if(it->getId() == id ){
            do{
                std::cout << "MENU DE MODIFICAÇÃO - CLIENTE" << std::endl;
                std::cout << "[1] NOME " << std::endl;
                std::cout << "[2] CPF " << std::endl;
                std::cout << "[3] TELEFONE " << std::endl;
                std::cout << "[4] ENDEREÇO " << std::endl;
                std::cout << "[5] HABILITAÇÃO" << std::endl; 
                std::cout << "[0] SAIR" << std::endl;

                std::cin >> escolha;
                std::cin.get();
                std::string nome;
                std::string cpf;
                std::string telefone;
                std::string endereco;
                std::string habilitacao;

                switch(escolha){
                    case 1:
                        system("clear || cls");
                        std::cout << "Novo Nome : " << std::endl;
                        getline(std::cin,nome);
                        it->setNome(nome);
                        clienteModificado = true;
                        break;
                    case 2:
                        system("clear || cls");
                        std::cout << "Novo CPF : " << std::endl;
                        getline(std::cin,cpf);
                        it->setCpf(cpf);
                        clienteModificado = true;
                        break;
                    case 3:
                        system("clear || cls");
                        std::cout << "Novo Telefone : " << std::endl;
                        getline(std::cin,telefone);
                        it->setTelefone(telefone);
                        clienteModificado = true;
                        break;
                    case 4:
                        system("clear || cls");
                        std::cout << "Novo Endereço : " << std::endl;
                        getline(std::cin,endereco);
                        it->setEndereco(endereco);
                        clienteModificado = true;
                        break;
                    case 5:
                        system("clear || cls");
                        std::cout << "Nova Habilitação : " << std::endl;
                        getline(std::cin,habilitacao);
                        it->setEndereco(habilitacao);
                        clienteModificado = true;
                        break;
                }
            }while( escolha !=0);
        }
    }

    if(clienteModificado){
        std::ofstream inClientes;
        inClientes.open("../BancoDeDados/clientes.txt",std::ios_base::out);
        if(inClientes.is_open()){
            for(auto it=clientes.begin() ; it!=clientes.end() ; it++){
                inClientes << it->getId() << std::endl;
                inClientes << it->getNome() << std::endl;
                inClientes << it->getCpf() << std::endl;
                inClientes << it->getTelefone() << std::endl;
                inClientes << it->getEndereco() << std::endl;
                inClientes << it->getHabilitacao() << std::endl;
            }
            inClientes.close();
        }
    }else{
        std::cout << "Cliente não encontrado " << std::endl;
        pause();
    }
}

/******VEICULO********/

void Menu::menuVeiculo(std::vector<Veiculo> &veiculos){
    int escolha;
    do{ 
        system("clear||cls");
        Menu::mostraMenuVeiculo();
        std::cin >> escolha;
        std::cin.get();

        switch(escolha){
            case 1:
                insereVeiculo(veiculos);
                break;
            case 2:
                listaVeiculo(veiculos);
                break;
            case 3:
                encontraVeiculo(veiculos);
                break;
            case 4:
                excluiVeiculo(veiculos);
                break;
            case 5:
                modificaVeiculo(veiculos);
                break;
        }

    }while(escolha!=0);
}

void Menu::mostraMenuVeiculo(){
    
    std::cout << "-----------MENU VEICULOS-----------" << std::endl;
    std::cout << "[1] INCLUIR" << std::endl;
    std::cout << "[2] LISTAR" << std::endl;
    std::cout << "[3] ENCONTRAR " << std::endl;
    std::cout << "[4] EXCLUIR " << std::endl;
    std::cout << "[5] MODIFICAR " << std::endl;
    std::cout << "[0] SAIR" << std::endl;

}

void Menu::insereVeiculo(std::vector<Veiculo> &veiculos){
    system("clear || cls");
    std::cout << "---INSERIR VEICULO---" << std::endl;
    std::string marca,modelo;
    int anoFabricacao;
    float precoPorDia;
    std::cout << "Marca : ";
    getline(std::cin,marca);
    std::cout << "Modelo : ";
    getline(std::cin,modelo);
    std::cout << "Ano de Fabricacao : ";
    std::cin >> anoFabricacao;
    std::cin.get();
    std::cout << "Preço por dia : ";
    std::cin >> precoPorDia;
    std::cin.get();

    Veiculo veiculo(marca,modelo,anoFabricacao,precoPorDia);
    veiculos.push_back(veiculo);

    std::ofstream inVeiculos;
    inVeiculos.open("../BancoDeDados/veiculos.txt",std::ios_base::app);
    if(inVeiculos.is_open()){
        inVeiculos << veiculo.getId() << std::endl;
        inVeiculos << veiculo.getMarca() << std::endl;
        inVeiculos << veiculo.getModelo() << std::endl;
        inVeiculos << veiculo.getAnoFabricacao() << std::endl;
        inVeiculos << veiculo.getPrecoPorDia() << std::endl;
        inVeiculos.close();
    }
    pause();
}

void Menu::listaVeiculo(std::vector<Veiculo> &veiculos){
    system("clear || cls");
    std::cout << "---LISTA DE VEICULOS---" << std::endl;
    for(auto it=veiculos.begin() ; it!=veiculos.end() ; it++){
        std::cout << "------------------------------------" << std::endl;
        it->mostraVeiculo();
    }
    std::cout << "---FIM DA LISTA---" << std::endl;
    pause();
}

void Menu::encontraVeiculo(std::vector<Veiculo> &veiculos){
    system("clear || cls");
    int id;
    std::cout << "ID do veiculo para busca : " << std::endl;
    std::cin >> id;
    std::cin.get();

    for(auto it=veiculos.begin() ; it!=veiculos.end() ; it++){
        if(it->getId() == id ){
            std::cout << "---VEICULO ENCONTRADO---" << std::endl;
            it->mostraVeiculo();
            pause();
            return;
        }
    }
    std::cout << "Veiculo não encontrado " << std::endl;
    pause();
}

void Menu::excluiVeiculo(std::vector<Veiculo> &veiculos){
    system("clear || cls");
    int id;
    std::cout << "ID do veiculo para exclusão : " << std::endl;
    std::cin >> id;
    std::cin.get();
    bool veiculoExcluido= false;

    for(auto it=veiculos.begin() ; it!=veiculos.end() ; it++){
        if(it->getId() == id ){
            veiculos.erase(it);
            std::cout << "---VEICULO EXCLUIDO---" << std::endl;
            pause();
            veiculoExcluido = true;
            break;
        }
    }

    if(veiculoExcluido){
        std::ofstream inVeiculos;
        inVeiculos.open("../BancoDeDados/veiculos.txt",std::ios_base::out);
        if(inVeiculos.is_open()){
            for(auto it=veiculos.begin() ; it!=veiculos.end() ; it++){
                inVeiculos << it->getId() << std::endl;
                inVeiculos << it->getMarca() << std::endl;
                inVeiculos << it->getModelo() << std::endl;
                inVeiculos << it->getAnoFabricacao() << std::endl;
                inVeiculos << it->getPrecoPorDia() << std::endl;
            }
            inVeiculos.close();
        }
    }else{
        std::cout << "Veiculo não encontrado " << std::endl;
        pause();
    }
}

void Menu::modificaVeiculo(std::vector<Veiculo> &veiculos){
    int escolha;
    system("clear || cls");
    int id;
    std::cout << "ID do veiculo para modificação : " << std::endl;
    std::cin >> id;
    std::cin.get();
    bool veiculoModificado= false;

    for(auto it=veiculos.begin() ; it!=veiculos.end() ; it++){
        if(it->getId() == id ){
            do{
                std::cout << "MENU DE MODIFICAÇÃO - VEICULO" << std::endl;
                std::cout << "[1] MARCA " << std::endl;
                std::cout << "[2] MODELO " << std::endl;
                std::cout << "[3] ANO DE FABRICAÇÃO " << std::endl;
                std::cout << "[4] PREÇO POR DIA " << std::endl;
                std::cout << "[0] SAIR" << std::endl;

                std::cin >> escolha;
                std::cin.get();
                std::string marca;
                std::string modelo;
                int anoFabricacao;
                float precoPorDia;

                switch(escolha){
                    case 1:
                        system("clear || cls");
                        std::cout << "Nova marca : " << std::endl;
                        getline(std::cin,marca);
                        it->setMarca(marca);
                        veiculoModificado = true;
                        break;
                    case 2:
                        system("clear || cls");
                        std::cout << "Novo Modelo : " << std::endl;
                        getline(std::cin,modelo);
                        it->setModelo(modelo);
                        veiculoModificado = true;
                        break;
                    case 3:
                        system("clear || cls");
                        std::cout << "Novo ano de Fabricação : " << std::endl;
                        std::cin >> anoFabricacao;
                        std::cin.get();
                        it->setAnoFabricacao(anoFabricacao);
                        veiculoModificado = true;
                        break;
                    case 4:
                        system("clear || cls");
                        std::cout << "Novo preço por dia : " << std::endl;
                        std::cin >> precoPorDia;
                        std::cin.get();
                        it->setPrecoPorDia(precoPorDia);
                        veiculoModificado = true;
                        break;
                }
            }while( escolha !=0);
        }
    }

    if(veiculoModificado){
        std::ofstream inVeiculos;
        inVeiculos.open("../BancoDeDados/veiculos.txt",std::ios_base::out);
        if(inVeiculos.is_open()){
            for(auto it=veiculos.begin() ; it!=veiculos.end() ; it++){
                inVeiculos << it->getId() << std::endl;
                inVeiculos << it->getMarca() << std::endl;
                inVeiculos << it->getModelo() << std::endl;
                inVeiculos << it->getAnoFabricacao() << std::endl;
                inVeiculos << it->getPrecoPorDia() << std::endl;
            }
            inVeiculos.close();
        }
    }else{
        std::cout << "Veiculo não encontrado " << std::endl;
        pause();
    }
}

/******FUNCIONARIO********/

void Menu::menuFuncionario(std::vector<Funcionario> &funcionarios){
    int escolha;
    do{ 
        system("clear||cls");
        Menu::mostraMenuFuncionario();
        std::cin >> escolha;
        std::cin.get();

        switch(escolha){
            case 1:
                insereFuncionario(funcionarios);
                break;
            case 2:
                listaFuncionario(funcionarios);
                break;
            case 3:
                encontraFuncionario(funcionarios);
                break;
            case 4:
                excluiFuncionario(funcionarios);
                break;
            case 5:
                modificaFuncionario(funcionarios);
                break;
        }

    }while(escolha!=0);
}

void Menu::mostraMenuFuncionario(){
    
    std::cout << "-----------MENU FUNCIONARIO-----------" << std::endl;
    std::cout << "[1] INCLUIR" << std::endl;
    std::cout << "[2] LISTAR" << std::endl;
    std::cout << "[3] ENCONTRAR " << std::endl;
    std::cout << "[4] EXCLUIR " << std::endl;
    std::cout << "[5] MODIFICAR " << std::endl;
    std::cout << "[0] SAIR" << std::endl;

}

void Menu::insereFuncionario(std::vector<Funcionario> &funcionarios){
    system("clear || cls");
    std::cout << "---INSERIR FUNCIONARIO---" << std::endl;
    std::string nome,cpf,telefone,endereco;
    std::cout << "Nome : ";
    getline(std::cin,nome);
    std::cout << "CPF : ";
    getline(std::cin,cpf);
    std::cout << "Telefone : ";
    getline(std::cin,telefone);
    std::cout << "Endereço : ";
    getline(std::cin,endereco);

    Funcionario funcionario(nome,cpf,telefone,endereco);
    funcionarios.push_back(funcionario);

    std::ofstream inFuncionarios;
    inFuncionarios.open("../BancoDeDados/funcionarios.txt",std::ios_base::app);
    if(inFuncionarios.is_open()){
        inFuncionarios << funcionario.getId() << std::endl;
        inFuncionarios << funcionario.getNome() << std::endl;
        inFuncionarios << funcionario.getCpf() << std::endl;
        inFuncionarios << funcionario.getTelefone() << std::endl;
        inFuncionarios << funcionario.getEndereco() << std::endl;
        inFuncionarios.close();
    }
    pause();
}

void Menu::listaFuncionario(std::vector<Funcionario> &funcionarios){
    system("clear || cls");
    std::cout << "---LISTA DE FUNCIONARIOS---" << std::endl;
    for(auto it=funcionarios.begin() ; it!=funcionarios.end() ; it++){
        std::cout << "------------------------------------" << std::endl;
        it->mostraFuncionario();
    }
    std::cout << "---FIM DA LISTA---" << std::endl;
    pause();
}

void Menu::encontraFuncionario(std::vector<Funcionario> &funcionarios){
    system("clear || cls");
    int id;
    std::cout << "ID do funcionario para busca : " << std::endl;
    std::cin >> id;
    std::cin.get();

    for(auto it=funcionarios.begin() ; it!=funcionarios.end() ; it++){
        if(it->getId() == id ){
            std::cout << "---FUNCIONARIO ENCONTRADO---" << std::endl;
            it->mostraFuncionario();
            pause();
            return;
        }
    }
    std::cout << "Funcionario não encontrado " << std::endl;
    pause();
}

void Menu::excluiFuncionario(std::vector<Funcionario> &funcionarios){
    system("clear || cls");
    int id;
    std::cout << "ID do Funcionario para exclusão : " << std::endl;
    std::cin >> id;
    std::cin.get();
    bool funcionarioExcluido= false;

    for(auto it=funcionarios.begin() ; it!=funcionarios.end() ; it++){
        if(it->getId() == id ){
            funcionarios.erase(it);
            std::cout << "---FUNCIONARIO EXCLUIDO---" << std::endl;
            pause();
            funcionarioExcluido = true;
            break;
        }
    }
    if(funcionarioExcluido){
        std::ofstream inFuncionarios;
        inFuncionarios.open("../BancoDeDados/funcionarios.txt",std::ios_base::out);
        if(inFuncionarios.is_open()){
            for(auto it=funcionarios.begin() ; it!=funcionarios.end() ; it++){
                inFuncionarios << it->getId() << std::endl;
                inFuncionarios << it->getNome() << std::endl;
                inFuncionarios << it->getCpf() << std::endl;
                inFuncionarios << it->getTelefone() << std::endl;
                inFuncionarios << it->getEndereco() << std::endl;
            }
            inFuncionarios.close();
        }
    }else{
        std::cout << "Funcionario não encontrado " << std::endl;
        pause();
    }

}

void Menu::modificaFuncionario(std::vector<Funcionario> &funcionarios){
    int escolha;
    system("clear || cls");
    int id;
    std::cout << "ID do funcionario para modificação : " << std::endl;
    std::cin >> id;
    std::cin.get();
    bool funcionarioModificado= false;

    for(auto it=funcionarios.begin() ; it!=funcionarios.end() ; it++){
        if(it->getId() == id ){
            do{
                std::cout << "MENU DE MODIFICAÇÃO - FUNCIONARIO" << std::endl;
                std::cout << "[1] NOME " << std::endl;
                std::cout << "[2] CPF " << std::endl;
                std::cout << "[3] TELEFONE " << std::endl;
                std::cout << "[4] ENDEREÇO " << std::endl;
                std::cout << "[0] SAIR" << std::endl;

                std::cin >> escolha;
                std::cin.get();
                std::string nome;
                std::string cpf;
                std::string telefone;
                std::string endereco;

                switch(escolha){
                    case 1:
                        system("clear || cls");
                        std::cout << "Novo Nome : " << std::endl;
                        getline(std::cin,nome);
                        it->setNome(nome);
                        funcionarioModificado = true;
                        break;
                    case 2:
                        system("clear || cls");
                        std::cout << "Novo CPF : " << std::endl;
                        getline(std::cin,cpf);
                        it->setCpf(cpf);
                        funcionarioModificado = true;
                        break;
                    case 3:
                        system("clear || cls");
                        std::cout << "Novo Telefone : " << std::endl;
                        getline(std::cin,telefone);
                        it->setTelefone(telefone);
                        funcionarioModificado = true;
                        break;
                    case 4:
                        system("clear || cls");
                        std::cout << "Novo Endereço : " << std::endl;
                        getline(std::cin,endereco);
                        it->setEndereco(endereco);
                        funcionarioModificado = true;
                        break;
                }
            }while( escolha !=0);
        }
    }

    if(funcionarioModificado){
        std::ofstream inFuncionarios;
        inFuncionarios.open("../BancoDeDados/funcionarios.txt",std::ios_base::out);
        if(inFuncionarios.is_open()){
            for(auto it=funcionarios.begin() ; it!=funcionarios.end() ; it++){
                inFuncionarios << it->getId() << std::endl;
                inFuncionarios << it->getNome() << std::endl;
                inFuncionarios << it->getCpf() << std::endl;
                inFuncionarios << it->getTelefone() << std::endl;
                inFuncionarios << it->getEndereco() << std::endl;
            }
            inFuncionarios.close();
        }
    }else{
        std::cout << "Funcionario não encontrado " << std::endl;
        pause();
    }
}

/******Aluguel********/


void Menu::menuAluguel(std::vector<Aluguel> &alugueis,std::vector<Cliente> &clientes,
        std::vector<Veiculo> &veiculos,std::vector<Funcionario> &funcionarios){
    int escolha;
    do{ 
        system("clear||cls");
        Menu::mostraMenuAluguel();
        std::cin >> escolha;
        std::cin.get();

        switch(escolha){
            case 1:
                insereAluguel(alugueis,clientes,veiculos,funcionarios);
                break;
            case 2:
                listaAluguel(alugueis);
                break;
            case 3:
                encontraAluguel(alugueis);
                break;
            case 4:
                excluiAluguel(alugueis);
                break;
            case 5:
                modificaAluguel(alugueis,clientes,veiculos,funcionarios);
                break;
        }

    }while(escolha!=0);
}

void Menu::mostraMenuAluguel(){
    
    std::cout << "-----------MENU ALUGUEL-----------" << std::endl;
    std::cout << "[1] INCLUIR" << std::endl;
    std::cout << "[2] LISTAR" << std::endl;
    std::cout << "[3] ENCONTRAR " << std::endl;
    std::cout << "[4] EXCLUIR " << std::endl;
    std::cout << "[5] MODIFICAR " << std::endl;
    std::cout << "[0] SAIR" << std::endl;

}

void Menu::insereAluguel(std::vector<Aluguel> &alugueis,std::vector<Cliente> &clientes,
        std::vector<Veiculo> &veiculos,std::vector<Funcionario> &funcionarios){
    
    int idCliente, idVeiculo, idFuncionario;
    std::cout << "Insira o Id de um cliente :";
    std::cin >> idCliente;
    std::cin.get();

    std::cout << "Insira o Id de um veiculo :";
    std::cin >> idVeiculo;
    std::cin.get();

    std::cout << "Insira o Id de um funcionario :";
    std::cin >> idFuncionario;
    std::cin.get();

    Cliente* cliente;
    Veiculo* veiculo;
    Funcionario* funcionario;
    Data dataInicio={};
    Data dataTermino={};
    float desconto;
    float adicional;

    for(auto it=clientes.begin() ; it!=clientes.end() ; it++){
        if(it->getId() == idCliente){
            cliente = &(*it);
        }
    }


    for(auto it=veiculos.begin() ; it!=veiculos.end() ; it++){
        if(it->getId() == idVeiculo){
            veiculo = &(*it);
        }
    }


    for(auto it=funcionarios.begin() ; it!=funcionarios.end() ; it++){
        if(it->getId() == idFuncionario){
            funcionario = &(*it);
        }
    }

    std::cout << "---INICIO DO ALUGUEL---" << std::endl;

    std::cout << "Dia : ";
    std::cin >> dataInicio.tm_mday;
    std::cin.get();

    std::cout << "Mês : ";
    std::cin >> dataInicio.tm_mon;
    std::cin.get();

    std::cout << "Ano : ";
    std::cin >> dataInicio.tm_year;
    std::cin.get();

    std::cout << "---FIM DO ALUGUEL---" << std::endl;
    std::cout << "Dia : ";
    std::cin >> dataTermino.tm_mday;
    std::cin.get();

    std::cout << "Mês : ";
    std::cin >> dataTermino.tm_mon;
    std::cin.get();

    std::cout << "Ano : ";
    std::cin >> dataTermino.tm_year;
    std::cin.get();

    std::cout << "Valor do desconto : ";
    std::cin >> desconto;
    std::cin.get();

    std::cout << "Valor do adicional : ";
    std::cin >> adicional;
    std::cin.get();

    Aluguel aluguel(cliente,veiculo,funcionario,dataInicio,dataTermino,desconto,adicional);
    alugueis.push_back(aluguel);
    
    std::ofstream inAlugueis;
    inAlugueis.open("../BancoDeDados/alugueis.txt",std::ios_base::app);
    if(inAlugueis.is_open()){
        inAlugueis << aluguel.getId() << std::endl;

        inAlugueis << aluguel.getCliente()->getId() << std::endl;
        inAlugueis << aluguel.getVeiculo()->getId() << std::endl;
        inAlugueis << aluguel.getFuncionario()->getId() << std::endl;

        inAlugueis << aluguel.getDataInicio().tm_mday << std::endl;
        inAlugueis << aluguel.getDataInicio().tm_mon << std::endl;
        inAlugueis << aluguel.getDataInicio().tm_year << std::endl;

        inAlugueis << aluguel.getDataTermino().tm_mday << std::endl;
        inAlugueis << aluguel.getDataTermino().tm_mon << std::endl;
        inAlugueis << aluguel.getDataTermino().tm_year << std::endl;

        inAlugueis << aluguel.getDataDevolucao().tm_mday << std::endl;
        inAlugueis << aluguel.getDataDevolucao().tm_mon << std::endl;
        inAlugueis << aluguel.getDataDevolucao().tm_year << std::endl;

        inAlugueis << aluguel.getDesconto() << std::endl;
        inAlugueis << aluguel.getAdicional() << std::endl;

        inAlugueis.close();
    }
    pause();
    
}

void Menu::listaAluguel(std::vector<Aluguel> &alugueis){
    system("clear || cls");
    std::cout << "---LISTA DE ALUGUEIS---" << std::endl;
    for(auto it=alugueis.begin() ; it!=alugueis.end() ; it++){
        std::cout << "------------------------------------" << std::endl;
        it->mostraAluguel();
    }
    std::cout << "------------------------------------" << std::endl;
    std::cout << "---FIM DA LISTA---" << std::endl;
    pause();
}

void Menu::encontraAluguel(std::vector<Aluguel> &alugueis){
    system("clear || cls");
    int id;
    std::cout << "ID do aluguel para busca : " << std::endl;
    std::cin >> id;
    std::cin.get();

    for(auto it=alugueis.begin() ; it!=alugueis.end() ; it++){
        if(it->getId() == id ){
            std::cout << "---ALUGUEL ENCONTRADO---" << std::endl;
            it->mostraAluguel();
            pause();
            return;
        }
    }
    std::cout << "Aluguel não encontrado " << std::endl;
    pause();
}

void Menu::excluiAluguel(std::vector<Aluguel> &alugueis){
    system("clear || cls");
    int id;
    std::cout << "ID do Funcionario para exclusão : " << std::endl;
    std::cin >> id;
    std::cin.get();
    bool aluguelExcluido= false;

    for(auto it=alugueis.begin() ; it!=alugueis.end() ; it++){
        if(it->getId() == id ){
            alugueis.erase(it);
            std::cout << "---ALUGUEL EXCLUIDO---" << std::endl;
            pause();
            aluguelExcluido = true;
            break;
        }
    }
    if(aluguelExcluido){
        std::ofstream inAlugueis;
        inAlugueis.open("../BancoDeDados/alugueis.txt",std::ios_base::out);
        if(inAlugueis.is_open()){
            for(auto it=alugueis.begin() ; it!=alugueis.end() ; it++){
                inAlugueis << it->getId() << std::endl;
                inAlugueis << it->getCliente()->getId() << std::endl;
                inAlugueis << it->getVeiculo()->getId() << std::endl;
                inAlugueis << it->getFuncionario()->getId() << std::endl;
                inAlugueis << it->getDataInicio().tm_mday << std::endl;
                inAlugueis << it->getDataInicio().tm_mon << std::endl;
                inAlugueis << it->getDataInicio().tm_year << std::endl;
                inAlugueis << it->getDataTermino().tm_mday << std::endl;
                inAlugueis << it->getDataTermino().tm_mon << std::endl;
                inAlugueis << it->getDataTermino().tm_year << std::endl;
                inAlugueis << it->getDataDevolucao().tm_mday << std::endl;
                inAlugueis << it->getDataDevolucao().tm_mon << std::endl;
                inAlugueis << it->getDataDevolucao().tm_year << std::endl;
                inAlugueis << it->getDesconto() << std::endl;
                inAlugueis << it->getAdicional() << std::endl;
            }
            inAlugueis.close();
        }
    }else{
        std::cout << "Aluguel não encontrado " << std::endl;
        pause();
    }
}

void Menu::modificaAluguel(std::vector<Aluguel> &alugueis,std::vector<Cliente> &clientes,
        std::vector<Veiculo> &veiculos,std::vector<Funcionario> &funcionarios){
    int escolha;
    system("clear || cls");
    int id;
    std::cout << "ID do aluguel para modificação : " << std::endl;
    std::cin >> id;
    std::cin.get();
    bool aluguelModificado= false;

    for(auto it=alugueis.begin() ; it!=alugueis.end() ; it++){
        if(it->getId() == id ){
            do{
                std::cout << "MENU DE MODIFICAÇÃO - ALUGUEL" << std::endl;
                std::cout << "[1] CLIENTE " << std::endl;
                std::cout << "[2] VEICULO " << std::endl;
                std::cout << "[3] FUNCIONARIO " << std::endl;
                std::cout << "[4] DATA DE INICIO " << std::endl;
                std::cout << "[5] DATA DE FIM" << std::endl;
                std::cout << "[6] DATA DE DEVOLUÇÃO" << std::endl;
                std::cout << "[7] DESCONTO" << std::endl;
                std::cout << "[8] ADICIONAL" << std::endl;
                std::cout << "[0] SAIR" << std::endl;


                std::cin >> escolha;
                std::cin.get();

                int idCliente;
                int idVeiculo;
                int idFuncionario;
                Data dataInicio;
                Data dataFim;
                Data dataDevolucao;
                float desconto;
                float adicional;

                Cliente* cliente;
                Veiculo* veiculo;
                Funcionario* funcionario;

                switch(escolha){
                    case 1:
                        system("clear || cls");
                        std::cout << "ID do novo Cliente : " << std::endl;
                        std::cin >> idCliente;
                        for(auto itera=clientes.begin() ; itera!=clientes.end() ; itera++){
                            if(itera->getId() == idCliente){
                                cliente = &(*itera);
                            }
                        }
                        it->setCliente(cliente);
                        aluguelModificado = true;
                        break;
                    case 2:
                        system("clear || cls");
                        std::cout << "ID do novo Veiculo : " << std::endl;
                        std::cin >> idVeiculo;
                        for(auto itera=veiculos.begin() ; itera!=veiculos.end() ; itera++){
                            if(itera->getId() == idVeiculo){
                                veiculo = &(*itera);
                            }
                        }
                        it->setVeiculo(veiculo);
                        aluguelModificado = true;
                        break;
                    case 3:
                        system("clear || cls");
                        std::cout << "ID do novo Funcionario : " << std::endl;
                        std::cin >> idFuncionario;
                        for(auto itera=funcionarios.begin() ; itera!=funcionarios.end() ; itera++){
                            if(itera->getId() == idFuncionario){
                                funcionario = &(*itera);
                            }
                        }
                        it->setFuncionario(funcionario);
                        aluguelModificado = true;
                        break;
                    case 4:
                        system("clear || cls");
                        std::cout << "Novo dia de inicio : " << std::endl;
                        std::cout << "Dia : ";
                        std::cin >> dataInicio.tm_mday;
                        std::cin.get();
                        std::cout << "Mês : ";
                        std::cin >> dataInicio.tm_mon;
                        std::cin.get();
                        std::cout << "Ano : ";
                        std::cin >> dataInicio.tm_year;
                        std::cin.get();
                        it->setDataInicio(dataInicio);
                        aluguelModificado = true;
                        break;
                    case 5:
                        system("clear || cls");
                        std::cout << "Novo dia de inicio : " << std::endl;
                        std::cout << "Dia : ";
                        std::cin >> dataFim.tm_mday;
                        std::cin.get();
                        std::cout << "Mês : ";
                        std::cin >> dataFim.tm_mon;
                        std::cin.get();
                        std::cout << "Ano : ";
                        std::cin >> dataFim.tm_year;
                        std::cin.get();
                        it->setDataTermino(dataFim);
                        aluguelModificado = true;
                        break;
                    case 6:
                        system("clear || cls");
                        std::cout << "Novo dia de devolução : " << std::endl;
                        std::cout << "Dia : ";
                        std::cin >> dataDevolucao.tm_mday;
                        std::cin.get();
                        std::cout << "Mês : ";
                        std::cin >> dataDevolucao.tm_mon;
                        std::cin.get();
                        std::cout << "Ano : ";
                        std::cin >> dataDevolucao.tm_year;
                        std::cin.get();
                        it->setDataDevolucao(dataDevolucao);
                        aluguelModificado = true;
                        break;
                    case 7:
                        system("clear || cls");
                        std::cout << "Novo valor de desconto : " << std::endl;
                        std::cin >> desconto;
                        it->setDesconto(desconto);
                        aluguelModificado = true;
                        break;
                    case 8:
                        system("clear || cls");
                        std::cout << "Novo valor de adicional : " << std::endl;
                        std::cin >> adicional;
                        it->setAdicional(adicional);
                        aluguelModificado = true;
                        break;
                }
            }while(escolha !=0);
        }
    }

    if(aluguelModificado){
        std::ofstream inAlugueis;
        inAlugueis.open("../BancoDeDados/alugueis.txt",std::ios_base::out);
        if(inAlugueis.is_open()){
            for(auto it=alugueis.begin() ; it!=alugueis.end() ; it++){
                inAlugueis << it->getId() << std::endl;
                inAlugueis << it->getCliente()->getId() << std::endl;
                inAlugueis << it->getVeiculo()->getId() << std::endl;
                inAlugueis << it->getFuncionario()->getId() << std::endl;
                inAlugueis << it->getDataInicio().tm_mday << std::endl;
                inAlugueis << it->getDataInicio().tm_mon << std::endl;
                inAlugueis << it->getDataInicio().tm_year << std::endl;
                inAlugueis << it->getDataTermino().tm_mday << std::endl;
                inAlugueis << it->getDataTermino().tm_mon << std::endl;
                inAlugueis << it->getDataTermino().tm_year << std::endl;
                inAlugueis << it->getDataDevolucao().tm_mday << std::endl;
                inAlugueis << it->getDataDevolucao().tm_mon << std::endl;
                inAlugueis << it->getDataDevolucao().tm_year << std::endl;
                inAlugueis << it->getDesconto() << std::endl;
                inAlugueis << it->getAdicional() << std::endl;
            }
            inAlugueis.close();
        }
    }else{
        std::cout << "Aluguel não encontrado " << std::endl;
        pause();
    }
}