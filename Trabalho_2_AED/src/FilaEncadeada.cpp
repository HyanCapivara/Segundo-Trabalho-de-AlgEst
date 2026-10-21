#include "FilaEncadeada.h"
#include <iostream>

using namespace std;

//essa classe basicamente só chama métodos da listaDuplamenteEncadeadaCircular. Não muito mais o que comentar...

void FilaEncadeada::enfileirar(int _id){ //O(1)
    suporte.inserirNoFim(_id);
}

int FilaEncadeada::desenfileirar(){ //O(1)
    return suporte.removerPrimeiro();
}

int FilaEncadeada::consultarFrente(){ //O(1)
    if(suporte.getCabeca()->getProx() != suporte.getCabeca()){
        suporte.getCabeca()->getProx()->imprimirInfo();
        return suporte.getCabeca()->getProx()->getID();
    }
    cout << "Fila vazia\n\n";
    return -1;
}

int FilaEncadeada::retornarFrente(){ //O(1)
    if(suporte.getCabeca()->getProx() != suporte.getCabeca()) return suporte.getCabeca()->getProx()->getID();
    return -1;
}

bool FilaEncadeada::filaVazia(){ //O(1)
    if(suporte.getCabeca()->getProx() == suporte.getCabeca()) return 1; //nesse caso, como essa fila deriva de uma lista circular, a condição para estar vazia é apontar para a própria cabeça
    return 0;
}

/*
void FilaEncadeada::enfileirarNElementos(int n){ //O(n)
    while(n > 0){
        enfileirar(n);
        n--;
    }
}

void FilaEncadeada::desenfileirarNElementos(int n){ //O(n)
    while(n > 0){
        if(desenfileirar() == -1)
            break;
        n--;
    }
}
*/
