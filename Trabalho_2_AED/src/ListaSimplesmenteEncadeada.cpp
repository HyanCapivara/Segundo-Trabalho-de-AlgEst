#include "ListaSimplesmenteEncadeada.h"
#include <iostream>

ListaSimplesmenteEncadeada::ListaSimplesmenteEncadeada(){
    cout << "Lista simplesmente encadeada criada com sucesso!\n\n";
}

ListaSimplesmenteEncadeada::~ListaSimplesmenteEncadeada(){
    no* aux = cabeca->getProx();
    no* delete_me = cabeca->getProx();
    while(aux != nullptr){
        aux = aux->getProx();
        delete delete_me;
        delete_me = aux;
    }
    cout << "Lista simplesmente encadeada deletada\n\n";
}

void ListaSimplesmenteEncadeada::no::imprimirInfo() const{
    cout << "\nID: " << ID << "\n\n";
}

void ListaSimplesmenteEncadeada::inserirNoInicio(int _id){
    no* novo = new no(_id, cabeca->getProx());
    cabeca->setProx(novo);
    cout << "Elemento inserido\n\n";
}

void ListaSimplesmenteEncadeada::inserirNoFim(int _id){
    no* saida = cabeca;
    no* chegada = cabeca->getProx();

    while(chegada != nullptr){
        saida = chegada;
        chegada = saida->getProx();
    }

    chegada = new no(_id, nullptr);
    saida->setProx(chegada);

    cout << "Elemento inserido\n\n";
}

int ListaSimplesmenteEncadeada::removerPeloID(int _id){
    no* saida = cabeca;
    no* chegada = cabeca->getProx();

    if(chegada == nullptr){
        cout << "Lista vazia\n\n";
        return -1;
    }

    while(chegada != nullptr && chegada->getID() != _id){
        saida = chegada;
        chegada = saida->getProx();
    }

    if(chegada == nullptr){
        cout << "ID nao encontrado\n\n";
        return -1;
    }

    saida->setProx(chegada->getProx());
    delete chegada;

    cout << "Elemento removido\n\n";
    return 1;
}

int ListaSimplesmenteEncadeada::removerPrimeiro(){
    no* aux = cabeca->getProx();
    if(aux == nullptr){
        cout << "Lista vazia\n\n";
        return -1;
    }

    cabeca->setProx(aux->getProx());
    delete aux;

    cout << "Elemento removido\n\n";
    return 1;
}

int ListaSimplesmenteEncadeada::removerUltimo(){
    no* saida = cabeca;
    no* chegada = cabeca->getProx();

    if(chegada == nullptr){
        cout << "Lista vazia\n\n";
        return -1;
    }

    while(chegada->getProx() != nullptr){
        saida = chegada;
        chegada = saida->getProx();
    }

    delete saida->getProx();
    saida->setProx(nullptr);

    cout << "Elemento removido\n\n";
    return 1;
}

int ListaSimplesmenteEncadeada::buscarPeloID(int _id) const{
    no* aux = cabeca->getProx();

    while(aux != nullptr){
        if(aux->getID() == _id){
            cout << "Informacoes encontradas:\n";
            aux->imprimirInfo();
            return 1;
        }
        aux = aux->getProx();
    }

    cout << "ID nao encontrado\n\n";
    return -1;
}

void ListaSimplesmenteEncadeada::imprimirLista() const{
    no* aux = cabeca->getProx();
    while(aux != nullptr){
        aux->imprimirInfo();
        aux = aux->getProx();
    }
}
