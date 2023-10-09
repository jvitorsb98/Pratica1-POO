#include "../Headers/Aluguel.hpp"

int Aluguel::numeroDeIdentificadores = 0;

Aluguel::Aluguel(Cliente* cliente,Veiculo* veiculo , Funcionario* funcionario, Data dataInicio,Data dataTermino, float desconto , float adicional){
    Data dataDevolucao = {};
    Aluguel::numeroDeIdentificadores++;
    setId(Aluguel::numeroDeIdentificadores);
    setCliente(cliente);
    setVeiculo(veiculo);
    setFuncionario(funcionario);
    setDataInicio(dataInicio);
    setDataTermino(dataTermino);
    setDesconto(desconto);
    setAdicional(adicional);
    setDataDevolucao(dataDevolucao);
}

Aluguel::Aluguel(){

}


int Aluguel::getId(){
    return this->id;
}

void Aluguel::setId(int id){
    this->id = id;
}

Cliente* Aluguel::getCliente(){
    return this->cliente;
}

void Aluguel::setCliente(Cliente* cliente){
    this->cliente = cliente;
}

Veiculo* Aluguel::getVeiculo(){
    return this->veiculo;
}

void Aluguel::setVeiculo(Veiculo* veiculo){
    this->veiculo = veiculo;
}

Funcionario* Aluguel::getFuncionario(){
    return this->funcionario;
}

void Aluguel::setFuncionario(Funcionario* funcionario){
    this->funcionario = funcionario;
}

Data Aluguel::getDataInicio(){
    return this->dataInicio;
}

void Aluguel::setDataInicio(Data dataInicio){
    this->dataInicio = dataInicio;
}

Data Aluguel::getDataTermino(){
    return this->dataTermino;
}

void Aluguel::setDataTermino(Data dataTermino){
    this->dataTermino = dataTermino;
}

Data Aluguel::getDataDevolucao(){
    return this->dataDevolucao;
}

void Aluguel::setDataDevolucao(Data dataDevolucao){
    this->dataDevolucao = dataDevolucao;
}

float Aluguel::getDesconto(){
    return this->desconto;
}

void Aluguel::setDesconto(float desconto){
    this->desconto = desconto;
}

float Aluguel::getAdicional(){
    return this->adicional;
}

void Aluguel::setAdicional(float adicional){
    this->adicional = adicional;
}

float Aluguel::calcular_valor_final(){
    return ( (difftime(mktime(&dataInicio),mktime(&dataDevolucao))/86400) * getVeiculo()->getPrecoPorDia() ) - getDesconto() + getAdicional();
}


void Aluguel::mostraAluguel(){
    std::cout << "ID : " << getId() << std::endl;
    std::cout << "---CLIENTE---" << std::endl;
    getCliente()->mostraCliente();
    std::cout << "---VEICULO---" << std::endl;
    getVeiculo()->mostraVeiculo();
    std::cout << "---FUNCIONARIO---" << std::endl;
    getFuncionario()->mostraFuncionario();
    std::cout << "---DATA DE INICIO---" << std::endl;
    std::cout << getDataInicio().tm_mday << "/" << getDataInicio().tm_mday << "/" <<  getDataInicio().tm_mday << std::endl;
    std::cout << "---DATA PREVISTA DE DEVOLUÇÃO---" << std::endl;
    std::cout << getDataTermino().tm_mday << "/" << getDataTermino().tm_mday << "/" <<  getDataTermino().tm_mday << std::endl;
    std::cout << "---DATA DE DEVOLUÇÃO REAL---" << std::endl;
    if(getDataDevolucao().tm_mday==0 && getDataDevolucao().tm_mon==0  && getDataDevolucao().tm_year==0 ){
        std::cout << "Sem data cadastrada" << std::endl;
    }else{
        std::cout << getDataTermino().tm_mday << "/" << getDataTermino().tm_mday << "/" <<  getDataTermino().tm_mday << std::endl;
    }
    std::cout << "---DESCONTO---" << std:: endl;
    std::cout << "Valor : " << getDesconto() << std::endl;
    std::cout << "---ADICIONAL---" << std:: endl;
    std::cout << "Valor : " << getAdicional() << std::endl;


    
}
