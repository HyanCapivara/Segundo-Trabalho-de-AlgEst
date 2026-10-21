#include "ListaDuplamenteEncadeadaCircular.h"

#include <iostream>

using namespace std;

ListaDuplamenteEncadeadaCircular::ListaDuplamenteEncadeadaCircular(){ //O(1).
//inicializa a cabeça com ponteiros para si mesma. Nas outras estruturas encadeadas isso não foi necessário já que suas referências eram a nullptr
    cabeca->setAnt(cabeca);
    cabeca->setProx(cabeca);
    cout << "Lista duplamente encadeada circular criada com sucesso!\n\n";
}

ListaDuplamenteEncadeadaCircular::~ListaDuplamenteEncadeadaCircular(){ //O(n) //Assim como nas outras listas, o destrutor precisa desalocar a memória solicitada
    no* aux = cabeca->getProx();
    no* delete_me = cabeca->getProx();
    while(aux != cabeca){
        aux = aux->getProx();
        delete delete_me;
        delete_me = aux;
    }
    cout << "Lista duplamente encadeada circular deletada\n\n";
}

void ListaDuplamenteEncadeadaCircular::no::imprimirInfo() const{ //O(1)
    cout << "\nID: " << ID << "\n\n";
}

void ListaDuplamenteEncadeadaCircular::inserirNoInicio(int _id){ //O(1)
    no* novo;
    if(cabeca->getProx() == cabeca){ //se a lista está vazia, o novo nó e a cabeça passam a se apontar
        novo = new no(_id, cabeca, cabeca);
        cabeca->setProx(novo);
        cabeca->setAnt(novo);
    }
    else{ //se a lista tem elementos, o novo elemento passará a apontar para a cabeça e para seu prox e o prox da cabeça, bem como a cabeça, passam a apontar para novo
        novo = new no(_id, cabeca, cabeca->getProx());
        cabeca->getProx()->setAnt(novo);
        cabeca->setProx(novo);
    }

    cout << "Elemento inserido\n\n";
}

void ListaDuplamenteEncadeadaCircular::inserirNoFim(int _id){ //O(1). //Basicamente o mesmo código da inserção no inicio só que ao invés de olharmos para a parte direita da lista, olhamos para a esquerda
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

int ListaDuplamenteEncadeadaCircular::removerPeloID(int _id){ //O(n)
    no* aux = cabeca->getProx();

    while(aux != cabeca && aux->getID() != _id){ //procura até a lista voltar para a cabeça ou até achar o elemento
        aux = aux->getProx();
    }

    if(aux == cabeca){ //se tiver voltado a cabeça:
        cout << "ID nao encontrado\n\n";
        return -1;
    }

    aux->getAnt()->setProx(aux->getProx()); //Se tiver achado, faz com que o seu sucessor aponte para seu antecessor e vice-versa
    aux->getProx()->setAnt(aux->getAnt());
    delete aux; //libera a memória

    cout << "Elemento removido\n\n";
    return 1;
}

int ListaDuplamenteEncadeadaCircular::removerPrimeiro(){ //O(1)
    if(cabeca->getProx() == cabeca){ //se a lista está vazia:
        cout << "Lista vazia\n\n";
        return -1;
    }

    no* aux = cabeca->getProx(); //não estando, faz cabeça apontar para o sucessor do primeiro elemento e faz o sucessor apontar para a cabeça
    aux->getProx()->setAnt(cabeca);
    aux->getAnt()->setProx(aux->getProx());
    delete aux;

    cout << "Elemento removido\n\n";
    return 1;
}

int ListaDuplamenteEncadeadaCircular::removerUltimo(){ //O(1). Semelhante ao código acima. A única mudança é trabalhar com a parte esquerda
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

int ListaDuplamenteEncadeadaCircular::alterarPeloID(int id_velho, int id_novo){ //O(n)
    if(removerPeloID(id_velho) == 1){ //tenta remover o id velho
        inserirNoInicio(id_novo); //se conseguir, insere o novo
        cout << "Alteracao bem sucedida\n\n";
        return 1;
    }
    cout << "Nao foi possivel realizar a alteracao\n\n";
    return -1;
}

int ListaDuplamenteEncadeadaCircular::buscarPeloID(int _id) const{ //O(n)
    no* aux = cabeca->getProx();

    if(aux == cabeca){ //caso padrão de lista vazia
        cout << "Lista vazia\n\n";
        return -1;
    }

    while(aux != cabeca && aux->getID() != _id){ //procura pelo id
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

void ListaDuplamenteEncadeadaCircular::imprimirSentidoDireito() const{ //O(n).
    no* aux = cabeca->getProx();
    while(aux != cabeca){ //percorre a lista imprimindo seus ids
        aux->imprimirInfo();
        aux = aux->getProx();
    }
}

void ListaDuplamenteEncadeadaCircular::imprimirSentidoEsquerdo() const{ //O(n)
    no* aux = cabeca->getAnt();
    while(aux != cabeca){ //idem ao acima
        aux->imprimirInfo();
        aux = aux->getAnt();
    }
}
