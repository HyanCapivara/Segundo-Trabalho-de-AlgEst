#include "ListaDuplamenteEncadeadaCircular.h"

#include <iostream>

using namespace std;

ListaDuplamenteEncadeadaCircular::ListaDuplamenteEncadeadaCircular(){
    cabeca->setAnt(cabeca);
    cabeca->setProx(cabeca);
    cout << "Lista duplamente encadeada circular criada com sucesso!\n\n";
}

ListaDuplamenteEncadeadaCircular::~ListaDuplamenteEncadeadaCircular(){
    no* aux = cabeca->getProx();
    no* delete_me = cabeca->getProx();
    while(aux != cabeca){
        aux = aux->getProx();
        delete delete_me;
        delete_me = aux;
    }
    cout << "Lista duplamente encadeada circular deletada\n\n";
}

void ListaDuplamenteEncadeadaCircular::no::imprimirInfo() const{
    cout << "\nID: " << ID << "\n\n";
}

void ListaDuplamenteEncadeadaCircular::inserirNoInicio(int _id){
    no* novo;
    if(cabeca->getProx() == cabeca){
        novo = new no(_id, cabeca, cabeca);
        cabeca->setProx(novo);
        cabeca->setAnt(novo);
    }
    else{
        novo = new no(_id, cabeca, cabeca->getProx());
        cabeca->getProx()->setAnt(novo);
        cabeca->setProx(novo);
    }

    cout << "Elemento inserido\n\n";
}

void ListaDuplamenteEncadeadaCircular::inserirNoFim(int _id){
    no* novo;
    if(cabeca->getAnt() == cabeca){
        novo = new no(_id, cabeca, cabeca);
        cabeca->setProx(novo);
        cabeca->setAnt(novo);
    }
    else{
        novo = new no(_id, cabeca->getAnt(), cabeca);
        cabeca->setAnt(novo);
        novo->getAnt()->setProx(novo);
    }

    cout << "Elemento inserido\n\n";
}

int ListaDuplamenteEncadeadaCircular::removerPeloID(int _id){
    no* aux = cabeca->getProx();

    while(aux != cabeca && aux->getID() != _id){
        aux = aux->getProx();
    }

    if(aux == cabeca){
        cout << "ID nao encontrado\n\n";
        return -1;
    }

    aux->getAnt()->setProx(aux->getProx());
    aux->getProx()->setAnt(aux->getAnt());
    delete aux;

    cout << "Elemento removido\n\n";
    return 1;
}

int ListaDuplamenteEncadeadaCircular::removerPrimeiro(){
    if(cabeca->getProx() == cabeca){
        cout << "Lista vazia\n\n";
        return -1;
    }

    no* aux = cabeca->getProx();
    aux->getProx()->setAnt(cabeca);
    aux->getAnt()->setProx(aux->getProx());
    delete aux;

    cout << "Elemento removido\n\n";
    return 1;
}

int ListaDuplamenteEncadeadaCircular::removerUltimo(){
    if(cabeca->getAnt() == cabeca){
        cout << "Lista vazia\n\n";
        return -1;
    }

    no* aux = cabeca->getAnt();
    aux->getAnt()->setProx(aux->getProx());
    aux->getProx()->setAnt(aux->getAnt());
    delete aux;

    cout << "Elemento removido\n\n";
    return 1;
}

//int ListaDuplamenteEncadeadaCircular::alterarPeloID(); <- preguicei. termina depois
int ListaDuplamenteEncadeadaCircular::buscarPeloID(int _id) const{
    no* aux = cabeca->getProx();

    if(aux == cabeca){
        cout << "Lista vazia\n\n";
        return -1;
    }

    while(aux != cabeca && aux->getID() != _id){
        aux = aux->getProx();
    }

    if(aux == cabeca){
        cout << "ID nao encontrado\n\n";
        return -1;
    }

    cout << "Dados encontrados:\n";
    aux->imprimirInfo();

    return 1;
}

void ListaDuplamenteEncadeadaCircular::imprimirListaTrasPFrente() const{
    no* aux = cabeca->getProx();
    while(aux != cabeca){
        aux->imprimirInfo();
        aux = aux->getProx();
    }
}

void ListaDuplamenteEncadeadaCircular::imprimirListaFrentePTras() const{
    no* aux = cabeca->getAnt();
    while(aux != cabeca){
        aux->imprimirInfo();
        aux = aux->getAnt();
    }
}
