#include "ListaDuplamenteEncadeada.h"
#include <iostream>

using namespace std;

ListaDuplamenteEncadeada::ListaDuplamenteEncadeada(){ //O(1), construtor padrão com uma mensagenzinha.
//Talvez ela deva ser eliminada já que as classes derivadas sempre denunciam o uso da lista que elas instanciam
    cout << "Lista duplamente encadeada criada com sucesso!\n\n";
}

ListaDuplamenteEncadeada::~ListaDuplamenteEncadeada(){ //O(n) //Destrutor personalizado. Tenho que desalocar toda a memória que eu pedi o que engloba percorrer todos os elementos, daí o O(n)
    no* aux = cabeca->getProx();
    no* delete_me = cabeca->getProx();
    while(aux != nullptr){ //percorre todos os nós eliminando-os
        aux = aux->getProx();
        delete delete_me;
        delete_me = aux;
    }
    cout << "Lista duplamente encadeada deletada\n\n";
}

void ListaDuplamenteEncadeada::no::imprimirInfo() const{ //O(1)
    cout << "\nID: " << ID << "\n";
}

void ListaDuplamenteEncadeada::inserirNoInicio(int _id){ //O(1)
    no* novo;
    if(cabeca->getProx() == nullptr){ //se não existem elementos, basta fazer a cabeça apontar para um novo nó
        novo = new no(_id, cabeca, nullptr);
        cabeca->setProx(novo);
    }
    else{ //se existem elementos, basta fazer o novo elemento apontar para o prox da cabeça e fazer a cabeça apontar para o novo
        novo = new no(_id, cabeca, cabeca->getProx());
        novo->getProx()->setAnt(novo);
        cabeca->setProx(novo);
    }

    cout << "Elemento inserido\n\n";
}

void ListaDuplamenteEncadeada::inserirNoFim(int _id){ //O(n)
    no* aux = cabeca;

    while(aux->getProx() != nullptr){ //Temos que achar o nó sem sucessor
        aux = aux->getProx();
    }

    no* novo = new no(_id, aux, nullptr);
    aux->setProx(novo); //e dizer que o novo nó é seu sucessor

    cout << "Elemento inserido\n\n";
}

int ListaDuplamenteEncadeada::removerPeloID(int _id){ //O(n)
    no* aux = cabeca->getProx();

    if(aux == nullptr){ //se não tem lista, não tem o que remover
        cout << "Lista vazia\n\n";
        return -1;
    }

    while(aux != nullptr && aux->getID() != _id){ //busca o id
        aux = aux->getProx();
    }

    if(aux == nullptr){ //se não tiver achado:
        cout << "ID nao encontrado\n\n";
        return -1;
    }

    //se tiver achado,
    if(aux->getProx() == nullptr){ //ele é o último? se for, basta dizer que o anterior a ele não tem mais sucessor
        aux->getAnt()->setProx(nullptr);
    }
    else{ //se não for, basta fazer o antecessor apontar para o sucessor e vice-versa
        aux->getProx()->setAnt(aux->getAnt());
        aux->getAnt()->setProx(aux->getProx());
    }

    delete aux; //não esqueça de desalocar a memória

    cout << "Elemento removido\n\n";
    return 1;
}

int ListaDuplamenteEncadeada::removerPrimeiro(){ //O(1)
    if(cabeca->getProx() == nullptr){ //se não tiver elementos:
        cout << "Lista vazia\n\n";
        return -1;
    }

    no* aux = cabeca->getProx();
    //se tem elementos:
    if(aux->getProx() == nullptr){ //o primeiro elemento é o único? se for, basta dizer que a cabeça não tem sucessor
        cabeca->setProx(nullptr);
    }
    else{ //se não for, basta fazer a cabeça e o seu sucessor trocarem contatos
        cabeca->setProx(aux->getProx());
        aux->getProx()->setAnt(cabeca);
    }

    delete aux; //não esqueça da memória

    cout << "Elemento inserido\n\n";
    return 1;
}

int ListaDuplamenteEncadeada::removerUltimo(){ //O(n)
    if(cabeca->getProx() == nullptr){ //caso não hajam elementos:
        cout << "Lista vazia\n\n";
        return -1;
    }

    no* aux = cabeca->getProx();

    while(aux->getProx() != nullptr){ //encontra o último
        aux = aux->getProx();
    }

    aux->getAnt()->setProx(nullptr); //diz que o antecessor do último não tem sucessor
    delete aux; //limpa a memória

    cout << "Elemento removido\n\n";
    return 1;
}

int ListaDuplamenteEncadeada::alterarPeloID(int id_velho, int id_novo){ //O(n)
    if(removerPeloID(id_velho) == 1){ //Vou tentar tirar o velho
        inserirNoInicio(id_novo); //se conseguir, vou inserir o novo
        cout << "Alteracao bem sucedida\n\n";
        return 1;
    }
    cout << "Nao foi possivel realizar a alteracao\n\n";
    return -1; //se em algum momento os processos anteriores deram pau, retornar erro
}

int ListaDuplamenteEncadeada::buscarPeloID(int _id) const{ //O(n)
    no* aux = cabeca->getProx();

    while(aux != nullptr && aux->getID() != _id){ //procura pelo id até ele ser encontrado ou a lista acabar
        aux = aux->getProx();
    }

    if(aux == nullptr){ //se não achou:
        cout << "ID nao encontrado\n\n";
        return -1;
    }

    cout << "Dados encontrados:\n"; //se achou:
    aux->imprimirInfo();

    return 1;
}

void ListaDuplamenteEncadeada::imprimirLista() const{ //O(n). Imprime a lista... Será que alguém vai ler isso?
    no* aux = cabeca->getProx();

    while(aux != nullptr){
        aux->imprimirInfo();
        aux = aux->getProx();
    }
}
