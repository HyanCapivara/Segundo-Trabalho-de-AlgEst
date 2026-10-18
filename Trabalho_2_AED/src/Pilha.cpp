#include "Pilha.h"
#include <iostream>

int Pilha::empilhar(int _id, string _nome, int _idade){
    return suporte.InserirNoFinal(_id, _nome, _idade);
}

int Pilha::empilhar(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria){
    return suporte.InserirNoFinal(_id, _nome, _idade, _especialidade, _salario, _carga_horaria);
}

int Pilha::desempilhar(){
    return suporte.RemoverUltimo();
}

void Pilha::consultarTopo() const{
    if(suporte.getOcupadas() == 0)
        cout << "Pilha vazia!\n\n";
    else
        suporte.getVetor(suporte.getOcupadas()-1)->imprimirInfo();
}

void Pilha::pilhaCheia(){
    int temp = suporte.getTam();
    for(int i = suporte.getOcupadas(); i < temp; i++)
        suporte.InserirNoFinal(i, "generico", i);
}

void Pilha::pilhaVazia(){
    int temp = suporte.getOcupadas();
    while(temp>0){
        suporte.RemoverUltimo();
        temp--;
    }
}
