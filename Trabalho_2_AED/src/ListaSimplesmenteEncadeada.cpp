#include "ListaSimplesmenteEncadeada.h"
#include <iostream>

ListaSimplesmenteEncadeada::ListaSimplesmenteEncadeada(){ //O(1). construtor padrão + mensagenzinha
    cout << "Lista simplesmente encadeada criada com sucesso!\n\n";
}

ListaSimplesmenteEncadeada::~ListaSimplesmenteEncadeada(){ //O(n)
    no* aux = cabeca->getProx();
    no* delete_me = cabeca->getProx();
    while(aux != nullptr){ //percorre a lista eliminando os nós alocados
        aux = aux->getProx();
        delete delete_me;
        delete_me = aux;
    }
    cout << "Lista simplesmente encadeada deletada\n\n";
}

void ListaSimplesmenteEncadeada::no::imprimirInfo() const{ //O(1)
    cout << "\nID: " << ID << "\n\n"; //imprimi o id
}

void ListaSimplesmenteEncadeada::inserirNoInicio(int _id){ //O(1)
    no* novo = new no(_id, cabeca->getProx()); //para todos os casos, o novo nó passa a apontar para o prox da cabeça
    cabeca->setProx(novo); //e a cabeça passa a apontar para o novo nó
    cout << "Elemento inserido\n\n";
}

void ListaSimplesmenteEncadeada::inserirNoFim(int _id){ //O(n)
    no* saida = cabeca;

    while(saida->getProx() != nullptr) //procura o último elemento
        saida = saida->getProx();

    no* novo = new no(_id, nullptr); //cria o novo nó
    saida->setProx(novo); //diz que o último nó na lista aponta para o novo

    cout << "Elemento inserido\n\n";
}

int ListaSimplesmenteEncadeada::removerPeloID(int _id){ //O(n)
    no* saida = cabeca;
    no* chegada = cabeca->getProx();

    if(chegada == nullptr){  //se a lista está vazia:
        cout << "Lista vazia\n\n";
        return -1;
    }

    while(chegada != nullptr && chegada->getID() != _id){ //procura pelo id
        saida = chegada;
        chegada = saida->getProx();
    }

    if(chegada == nullptr){ //se não achar:
        cout << "ID nao encontrado\n\n";
        return -1;
    }

    //tendo achado:
    saida->setProx(chegada->getProx()); //fazemos seu antecessor apontar para seu sucessor
    delete chegada; //eliminamos o dito cujo

    cout << "Elemento removido\n\n";
    return 1;
}

int ListaSimplesmenteEncadeada::removerPrimeiro(){ //O(1)
    no* aux = cabeca->getProx();
    if(aux == nullptr){ //caso de lista vazia:
        cout << "Lista vazia\n\n";
        return -1;
    }

    cabeca->setProx(aux->getProx()); //faz a cabeça apontar para o sucessor do primeiro nó.
    delete aux; //elimina o primeiro nó

    cout << "Elemento removido\n\n";
    return 1;
}

int ListaSimplesmenteEncadeada::removerUltimo(){ //O(n)
    no* saida = cabeca;
    no* chegada = cabeca->getProx();

    if(chegada == nullptr){ //se as garras malignas do vazio já tiverem chegado aqui:
        cout << "Lista vazia\n\n";
        return -1;
    }

    while(chegada->getProx() != nullptr){ //percorre a lista até seu fim
        saida = chegada;
        chegada = saida->getProx();
    }

    delete saida->getProx(); //elimina o último nó
    saida->setProx(nullptr); //diz que o antecessor do antigo nó não tem mais sucessor

    cout << "Elemento removido\n\n";
    return 1;
}

int ListaSimplesmenteEncadeada::buscarPeloID(int _id) const{ //O(n)
    no* aux = cabeca->getProx();

    while(aux != nullptr){ //percorre a lista toda em busca do id informado
        if(aux->getID() == _id){ //se achar, imprimi suas informações
            cout << "Informacoes encontradas:\n";
            aux->imprimirInfo();
            return 1;
        }
        aux = aux->getProx();
    }
    //se não achar:
    cout << "ID nao encontrado\n\n";
    return -1;
}

int ListaSimplesmenteEncadeada::alterarPeloID(int id_velho, int id_novo){ //O(n)
    if(removerPeloID(id_velho) == 1){ //tenta remover o id velho
        inserirNoInicio(id_novo); //se conseguir, insere o novo id
        cout << "Alteracao realizada com sucesso\n\n";
        return 1;
    }
    cout << "Nao foi possivel realizar a alteracao\n\n";

    return -1; //não conseguindo, retorna erro
}

void ListaSimplesmenteEncadeada::imprimirLista() const{ //O(n)  //imprime a lista
    no* aux = cabeca->getProx();
    while(aux != nullptr){ //percorre a lista imprimindo as informações do nó atual
        aux->imprimirInfo();
        aux = aux->getProx();
    }
}
