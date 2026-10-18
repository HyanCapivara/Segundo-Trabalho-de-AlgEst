#include "FilaEncadeada.h"
#include <iostream>

using namespace std;

FilaEncadeada::FilaEncadeada()
{
    //ctor
}

FilaEncadeada::~FilaEncadeada()
{
    //dtor
}

void FilaEncadeada::enfileirar(int _id){
    suporte.inserirNoFim(_id);
}

int FilaEncadeada::desenfileirar(){
    return suporte.removerPrimeiro();
}

void FilaEncadeada::consultarFrente(){
    if(suporte.getCabeca()->getProx() != suporte.getCabeca()){
        suporte.getCabeca()->getProx()->imprimirInfo();
    }
    else
        cout << "Fila vazia\n\n";
}

void FilaEncadeada::enfileirarNElementos(int n){
    while(n > 0){
        enfileirar(n);
        n--;
    }
}

void FilaEncadeada::desenfileirarNElementos(int n){
    while(n > 0){
        if(desenfileirar() == -1)
            break;
        n--;
    }
}
