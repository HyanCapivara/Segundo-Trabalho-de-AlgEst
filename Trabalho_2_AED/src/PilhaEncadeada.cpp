#include "PilhaEncadeada.h"
#include <iostream>

using namespace std;

//essa classe basicamente chama os métodos da lista simplesmente encadeada

void PilhaEncadeada::empilhar(int _id){ //O(1)
    suporte.inserirNoInicio(_id); //chama o inserir no inicio
}

int PilhaEncadeada::desempilhar(){ //O(1)
    return suporte.removerPrimeiro(); //chama o remover primeiro
}

int PilhaEncadeada::consultarTopo(){ //O(1)
    if(suporte.getCabeca()->getProx() != nullptr){ //se a cabeça aponta para alguém:
        suporte.getCabeca()->getProx()->imprimirInfo(); //imprime a informação desse alguém
        return suporte.getCabeca()->getProx()->getID();
    }
    //se a cabeça não apontar para ninguém:
    cout << "Pilha vazia\n\n";
    return -1;
}

int PilhaEncadeada::retornarTopo(){ //O(1)
    if(suporte.getCabeca()->getProx() != nullptr) return suporte.getCabeca()->getProx()->getID();
    return -1;
}

/*void PilhaEncadeada::empilharNElementos(int n){ //O(n)
    while(n > 0){ //faz n empilhamentos
        empilhar(n);
        n--;
    }
}

void PilhaEncadeada::desempilharNElementos(int n){ //O(n)
    while(n > 0){  //tenta fazer n desempilhamentos
        if(desempilhar() == -1)
            break;
        n--;
    }
}*/

bool PilhaEncadeada::pilhaVazia(){ //O(1)
    if(suporte.getCabeca()->getProx() == nullptr) return 1; //vê se a cabeça aponta para alguém, se não aponta, a lista está vazia
    return 0;
}
