#include "../Headers/Menu.hpp"


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
            menuFuncionario(funcionarios,alugueis);
            break;
        case 4:
            menuAluguel(alugueis);
            break;
        case 0:
            exit(0);
        
        default:
            break;
        }
    }while(escolha!=0);
}

void Menu::menuCliente(std::vector<Cliente> &clientes){
    int escolha;
    do{ 
        system("clear||cls");
        Menu::mostraMenuCliente();
        std::cin >> escolha;
        std::cin.get();
    }while(escolha!=0);
}

void Menu::menuVeiculo(std::vector<Veiculo> &veiculos){
    int escolha;
    do{ 
        system("clear||cls");
        Menu::mostraMenuVeiculo();
        std::cin >> escolha;
        std::cin.get();
    }while(escolha!=0);
}

void Menu::menuFuncionario(std::vector<Funcionario> &funcionarios, std::vector<Aluguel> &alugueis){
    int escolha;
    do{ 
        system("clear||cls");
        Menu::mostraMenuFuncionario();
        std::cin >> escolha;
        std::cin.get();
    }while(escolha!=0);
}

void Menu::menuAluguel(std::vector<Aluguel> &alugueis){
    int escolha;
    do{ 
        system("clear||cls");
        Menu::mostraMenuAluguel();
        std::cin >> escolha;
        std::cin.get();
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

void Menu::mostraMenuCliente(){
    
    std::cout << "-----------MENU CLIENTES-----------" << std::endl;
    std::cout << "[1] INCLUIR" << std::endl;
    std::cout << "[2] LISTAR" << std::endl;
    std::cout << "[3] ENCONTRAR " << std::endl;
    std::cout << "[4] EXCLUIR " << std::endl;
    std::cout << "[5] MODIFICAR " << std::endl;
    std::cout << "[0] SAIR" << std::endl;

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


void Menu::mostraMenuFuncionario(){
    
    std::cout << "-----------MENU FUNCIONARIO-----------" << std::endl;
    std::cout << "[1] INCLUIR" << std::endl;
    std::cout << "[2] LISTAR" << std::endl;
    std::cout << "[3] ENCONTRAR " << std::endl;
    std::cout << "[4] EXCLUIR " << std::endl;
    std::cout << "[5] MODIFICAR " << std::endl;
    std::cout << "[0] SAIR" << std::endl;

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

