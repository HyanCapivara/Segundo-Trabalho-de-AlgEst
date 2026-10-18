#include "Fila.h"
#include <iostream>

int Fila::InserirNoFinal(int _id, string _nome, int _idade){
    if(suporte.getOcupadas() == suporte.getTam()){
        cout << "Fila cheia!\n\n";
        return -1;
    }

    *suporte.getVetorPAlterar( (ini+suporte.getOcupadas())%suporte.getTam() ) = new humano(_id, _nome, _idade);
    suporte.setOcupadas(suporte.getOcupadas()+1);
    return 1;
}

int Fila::InserirNoFinal(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria){
    if(suporte.getOcupadas() == suporte.getTam()){
        cout << "Fila cheia!\n\n";
        return -1;
    }

    *suporte.getVetorPAlterar( (ini+suporte.getOcupadas())%suporte.getTam() ) = new humano(_id, _nome, _idade);
    suporte.setOcupadas(suporte.getOcupadas()+1);
    return 1;
}

int Fila::RemoverPrimeiroF(){
    if(suporte.getOcupadas() == 0){
        cout << "Fila vazia!\n\n";
        return -1;
    }

    delete suporte.getVetor(ini);
    ini = (ini+1)%suporte.getTam();
    suporte.setOcupadas(suporte.getOcupadas()-1);
    return 1;
}

int Fila::enfileirar(int _id, string _nome, int _idade){
    return InserirNoFinal(_id, _nome, _idade);
}

int Fila::enfileirar(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria){
    return InserirNoFinal(_id, _nome, _idade, _especialidade, _salario, _carga_horaria);
}

int Fila::desenfileirar(){
    return RemoverPrimeiroF();
}

void Fila::consultarInicio() const{
    if(suporte.getOcupadas() == 0)
        cout << "Fila vazia!\n\n";
    else
        suporte.getVetor(ini)->imprimirInfo();
}

void Fila::filaCheia(){
    int temp = suporte.getTam();
    for(int i = suporte.getOcupadas(); i < temp; i++)
        suporte.InserirNoFinal(i, "generico", i);
}

void Fila::filaVazia(){
    int temp = suporte.getOcupadas();
    while(temp>0){
        suporte.RemoverUltimo();
        temp--;
    }
}
