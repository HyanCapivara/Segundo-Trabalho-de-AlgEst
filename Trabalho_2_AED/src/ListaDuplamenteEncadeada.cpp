#include "ListaDuplamenteEncadeada.h"
#include <iostream>

using namespace std;

ListaDuplamenteEncadeada::ListaDuplamenteEncadeada(){
    cout << "Lista duplamente encadeada criada com sucesso!\n\n";
}

ListaDuplamenteEncadeada::~ListaDuplamenteEncadeada(){
    no* aux = cabeca->getProx();
    no* delete_me = cabeca->getProx();
    while(aux != nullptr){
        aux = aux->getProx();
        delete delete_me;
        delete_me = aux;
    }
    cout << "Lista duplamente encadeada deletada\n\n";
}

void ListaDuplamenteEncadeada::no::imprimirInfo() const{
    cout << "\nID: " << ID << "\n\n";
}

void ListaDuplamenteEncadeada::inserirNoInicio(int _id){
    no* novo;
    if(cabeca->getProx() == nullptr){
        novo = new no(_id, cabeca, nullptr);
        cabeca->setProx(novo);
    }
    else{
        novo = new no(_id, cabeca, cabeca->getProx());
        novo->getProx()->setAnt(novo);
        cabeca->setProx(novo);
    }

    cout << "Elemento inserido\n\n";
}

void ListaDuplamenteEncadeada::inserirNoFim(int _id){
    no* aux = cabeca;

    while(aux->getProx() != nullptr){
        aux = aux->getProx();
    }

    no* novo = new no(_id, aux, nullptr);
    aux->setProx(novo);

    cout << "Elemento inserido\n\n";
}

int ListaDuplamenteEncadeada::removerPeloID(int _id){
    no* aux = cabeca->getProx();

    if(aux == nullptr){
        cout << "Lista vazia\n\n";
        return -1;
    }

    while(aux != nullptr && aux->getID() != _id){
        aux = aux->getProx();
    }

    if(aux == nullptr){
        cout << "ID nao encontrado\n\n";
        return -1;
    }

    if(aux->getProx() == nullptr){
        aux->getAnt()->setProx(nullptr);
    }
    else{
        aux->getProx()->setAnt(aux->getAnt());
        aux->getAnt()->setProx(aux->getProx());
    }

    delete aux;

    cout << "Elemento removido\n\n";
    return 1;
}

int ListaDuplamenteEncadeada::removerPrimeiro(){
    if(cabeca->getProx() == nullptr){
        cout << "Lista vazia\n\n";
        return -1;
    }

    no* aux = cabeca->getProx();

    if(aux->getProx() == nullptr){
        cabeca->setProx(nullptr);
    }
    else{
        cabeca->setProx(aux->getProx());
        aux->getProx()->setAnt(cabeca);
    }

    delete aux;

    cout << "Elemento inserido\n\n";
    return 1;
}

int ListaDuplamenteEncadeada::removerUltimo(){
    if(cabeca->getProx() == nullptr){
        cout << "Lista vazia\n\n";
        return -1;
    }

    no* aux = cabeca->getProx();

    while(aux->getProx() != nullptr){
        aux = aux->getProx();
    }

    aux->getAnt()->setProx(nullptr);
    delete aux;

    cout << "Elemento removido\n\n";
    return 1;
}

//int ListaDuplamenteEncadeada::alterarPeloID(); <- preguicei. termina depois
int ListaDuplamenteEncadeada::buscarPeloID(int _id) const{
    no* aux = cabeca->getProx();

    while(aux != nullptr && aux->getID() != _id){
        aux = aux->getProx();
    }

    if(aux == nullptr){
        cout << "ID nao encontrado\n\n";
        return -1;
    }

    cout << "Dados encontrados:\n";
    aux->imprimirInfo();

    return 1;
}

void ListaDuplamenteEncadeada::imprimirLista() const{
    no* aux = cabeca->getProx();

    while(aux != nullptr){
        aux->imprimirInfo();
        aux = aux->getProx();
    }
}
