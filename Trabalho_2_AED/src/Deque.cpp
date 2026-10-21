#include "Deque.h"
#include <iostream>

using namespace std;

void Deque::inserirCabeca(int _id){cabeca.inserirNoFim(_id);} //O(1)  //insere na primeira lista
void Deque::inserirCalda(int _id){calda.inserirNoFim(_id);} //O(1)  //insere na segunda lista

int Deque::removerCabeca(){return cabeca.removerPrimeiro();} //O(1)  //remove da primeira lista
int Deque::removerCalda(){return calda.removerPrimeiro();} //O(1)  //remove da segunda lisat

void Deque::olharTopoCabeca(){ //O(1)  //informa o primeiro elemento da primeira lista
    if(cabeca.getCabeca()->getProx() != cabeca.getCabeca()){
        cabeca.getCabeca()->getProx()->imprimirInfo();
    }
    else
        cout << "Cabeca vazia\n\n";
}

void Deque::olharTopoCalda(){ //O(1)  //informa o primeiro elemento da segunda lista
    if(calda.getCabeca()->getProx() != calda.getCabeca()){
        calda.getCabeca()->getProx()->imprimirInfo();
    }
    else
        cout << "Fila vazia\n\n";
}

bool Deque::cabecaVazia(){ //O(1)  //verifica se a primeira lista está vazia
    if(cabeca.getCabeca()->getProx() == cabeca.getCabeca()) return 1;
    return -1;
}

bool Deque::caldaVazia(){ //O(1)  //verifica se a segunda lista está vazia
    if(calda.getCabeca()->getProx() == calda.getCabeca()) return 1;
    return -1;
}

/*void Deque::inserirNCabeca(int n){
    while(n > 0)
        inserirCabeca(n);
}

void Deque::inserirNCalda(int n){
    while(n > 0)
        inserirCalda(n);
}

void Deque::removerNCabeca(int n){
    while(n > 0){
        if(removerCabeca() == -1)
            break;
        n--;
    }
}

void Deque::removerNCalda(int n){
    while(n > 0){
        if(removerCalda() == -1)
            break;
        n--;
    }
}
*/
