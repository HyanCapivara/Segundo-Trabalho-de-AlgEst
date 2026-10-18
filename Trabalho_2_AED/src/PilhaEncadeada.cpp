#include "PilhaEncadeada.h"
#include <iostream>

using namespace std;

PilhaEncadeada::PilhaEncadeada()
{

}

PilhaEncadeada::~PilhaEncadeada()
{

}

void PilhaEncadeada::empilhar(int _id){
    suporte.inserirNoInicio(_id);
}

int PilhaEncadeada::desempilhar(){
    return suporte.removerPrimeiro();
}

void PilhaEncadeada::consultarTopo(){
    if(suporte.getCabeca()->getProx() != nullptr){
        suporte.getCabeca()->getProx()->imprimirInfo();
    }
    else
        cout << "Pilha vazia\n\n";
}

void PilhaEncadeada::empilharNElementos(int n){
    while(n > 0){
        empilhar(n);
        n--;
    }
}

void PilhaEncadeada::desempilharNElementos(int n){
    while(n > 0){
        if(desempilhar() == -1)
            break;
        n--;
    }
}
