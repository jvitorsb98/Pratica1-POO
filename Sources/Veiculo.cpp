#include "../Headers/Veiculo.hpp"

int Veiculo::numeroDeIdentificadores=0;


Veiculo::Veiculo(std::string marca , std::string modelo , int anoFabricacao, float precoPorDia) : marca(marca) , modelo(modelo) , anoFabricacao(anoFabricacao) , precoPorDia(precoPorDia){
    Veiculo::numeroDeIdentificadores++;
    setId(Veiculo::numeroDeIdentificadores);
}
Veiculo::Veiculo(){
}

void Veiculo::mostraVeiculo(){
    std::cout << "ID : " << getId() << std::endl;
    std::cout << "Marca : " << getMarca() << std::endl;
    std::cout << "Modelo : " << getModelo() << std::endl;
    std::cout << "Ano de Fabricação : " << getAnoFabricacao() << std::endl;
    std::cout << "Preço por dia : " << getPrecoPorDia() << std::endl;
}

int Veiculo::getId(){
    return this->id;
}

void Veiculo::setId(int id){
    this->id = id;
}

std::string Veiculo::getMarca(){
    return this->marca;
}

void Veiculo::setMarca(std::string marca){
    this->marca = marca;
}

std::string Veiculo::getModelo(){
    return this->modelo;
}

void Veiculo::setModelo(std::string modelo){
    this->modelo = modelo;
}

int Veiculo::getAnoFabricacao(){
    return this->anoFabricacao;
}

void Veiculo::setAnoFabricacao(int anoFabricacao){
    this->anoFabricacao = anoFabricacao;
}

float Veiculo::getPrecoPorDia(){
    return this->precoPorDia;
}

void Veiculo::setPrecoPorDia(float precoPorDia){
    this->precoPorDia = precoPorDia;
}


std::vector<Aluguel*>* Veiculo::getListaAlugueis(){
    return &(this->listaAlugueis);
}

