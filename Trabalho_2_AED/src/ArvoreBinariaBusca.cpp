#include "ArvoreBinariaBusca.h"
#include <iostream>

using namespace std;

ArvoreBinariaBusca::ArvoreBinariaBusca(){ //O(1)
    cout << "Arvore construida!\n\n";
}

ArvoreBinariaBusca::~ArvoreBinariaBusca(){ //O(n), n = número de nós
    desmatamento(raiz);
    cout << "Arvore deletada\n\n";
}

void ArvoreBinariaBusca::desmatamento(no* raiz){ //O(n)
    if(raiz != nullptr){
        desmatamento(raiz->getEsq());
        desmatamento(raiz->getDir());
        delete raiz;
    }
}

void ArvoreBinariaBusca::no::imprimirInfo() const{ //O(1) //imprime o ID... só isso
    cout << ID << endl;
}

int ArvoreBinariaBusca::Inserir(int _id){ //O(h), onde h é a altura da árvore. h pode variar de logn a n. Portanto O(n)
    if(raiz == nullptr){ //se não houverem elementos, basta criar um nó e dizer o endereço dele para a raiz
        raiz = new no(_id, nullptr, nullptr);
        cout << "Elemento inserido\n\n";
        return 1;
    }

    //se já existem elementos:

    no* raizDoAux = raiz;
    no* aux = raiz;
    while(aux != nullptr){ //temos que procurar o lugar certo para inserir o novo:
        raizDoAux = aux;
        if(_id > aux->getID()){
            aux = aux->getDir();
        }
        else if(_id < aux->getID()){
            aux = aux->getEsq();
        }
        else{
            cout << "O ID informado ja pertence a arvore\n\n"; //não permitirei duplicatas de ID
            return -1;
        }
    }

    aux = new no(_id, nullptr, nullptr);

    if(_id > raizDoAux->getID()) //o algoritmo de busca acima informa quem é o pai, mas não diz se o filho é esquerdo ou direito.
        raizDoAux->setDir(aux);
    else
        raizDoAux->setEsq(aux);

    cout << "Elemento inserido\n\n";
    return 1;
}

int ArvoreBinariaBusca::BuscarPeloId(int _id){ //O(h) ou O(n)
    no* aux = raiz;
    while(aux != nullptr){ //enquanto houverem elementos, o análogo da busca binária para estruturas encadeadas é aplicado:
        if(_id > aux->getID()){
            aux = aux->getDir();
        }
        else if(_id < aux->getID()){
            aux = aux->getEsq();
        }
        else{
            cout << "Informacoes encontradas:\n";
            aux->imprimirInfo();
            cout << "\n";
            return 1;
        }
    }

    cout << "ID nao encontrado\n\n"; //se a busca acabar em nullptr (não tem mais elementos para serem checados), o elemento buscado não existirá na árvore
    return -1;
}

int ArvoreBinariaBusca::RemoverPeloId(int _id){ //O(h) ou O(n)
    if(raiz == nullptr){ //se a arvore está vazia
        cout << "Arvore vazia\n\n";
        return 1;
    }

    no* raizDeAux = raiz;
    no* aux = raiz;

    while(aux != nullptr){ //encontra o elemento a ser removido (aux) e seu nó-pai (raizDeAux)
        if(_id > aux->getID()){
            raizDeAux = aux;
            aux = aux->getDir();
        }
        else if(_id < aux->getID()){
            raizDeAux = aux;
            aux = aux->getEsq();
        }
        else{
            break;
        }
    }

    if(aux == nullptr){ //se não tiver encontrado o elemento a ser removido
        cout << "ID nao encontrado\n\n";
        return -1;
    }

    if(aux == raiz){ //se o elemento a ser removido estiver na raiz
        if(raiz->getDir() == nullptr && raiz->getEsq() == nullptr) //raiz não aponta para ninguém, basta deleta-la
            aux = nullptr;
        else if(raiz->getDir() == nullptr) //raiz não tem filho direito, basta tornar o filho esquerdo a nova raiz
            aux = raiz->getEsq();
        else if(aux->getEsq() == nullptr) //raiz não tem filho esquerdo, basta tornar o filho direito a nova raiz
            aux = raiz->getDir();
        else{ //se a raiz tem ambos os filhos, buscamos o elemento imediatamente maior/menor (optei pelo menor) que ela e os permutamos. Não esquecendo de eliminar a "afiliação" do nó substituto
            aux = raiz->getEsq();
            raizDeAux = raiz;

            if(aux->getDir() == nullptr)
                aux->setDir(raiz->getDir());
            else{
                while(aux->getDir() != nullptr){
                    raizDeAux = aux;
                    aux = aux->getDir();
                }

                raizDeAux->setDir(aux->getEsq());
                aux->setDir(raiz->getDir());
                aux->setEsq(raiz->getEsq());
            }
        }

        delete raiz;
        raiz = aux;
        cout << "Elemento removido\n\n";
        return 1;
    }

    //não estando na raiz:

    if(aux->getDir() == nullptr){ //caso não tenha filho direito, basta troca-lo pelo filho esquerdo.
        //Não se desespere caso também não haja um filho direito. Nesse caso, a raizDeAux passa a apontar para nullptr o que é correto visto que, nesse caso, tiramos seu único filho
        if(_id > raizDeAux->getID()) raizDeAux->setDir(aux->getEsq());
        else raizDeAux->setEsq(aux->getEsq());
    }
    else if(aux->getEsq() == nullptr){ //caso não tenha filho esquerdo, basta troca-lo pelo filho direito.
        if(_id > raizDeAux->getID()) raizDeAux->setDir(aux->getDir());
        else raizDeAux->setEsq(aux->getDir());
    }
    else{ //se tiver os dois filhos, temos que buscar o elemento imediatamente maior/menor: (optei pelo menor)
        no* substitutoAux = aux->getEsq();
        no* paiDoSubstituto = aux;

        if(substitutoAux->getDir() == nullptr)
            substitutoAux->setDir(aux->getDir());
        else{
            while(substitutoAux->getDir() != nullptr){
                paiDoSubstituto = substitutoAux;
                substitutoAux = substitutoAux->getDir();
            }

            substitutoAux->setDir(aux->getDir());
            substitutoAux->setEsq(aux->getEsq());
            paiDoSubstituto->setDir(aux->getEsq());
        }

        if(_id > raizDeAux->getID()) raizDeAux->setDir(substitutoAux);
        else raizDeAux->setEsq(substitutoAux);
    }

    delete aux;
    cout << "Elemento removido\n\n";
    return 1;
}

void ArvoreBinariaBusca::auxPre(no* raiz) const{ //O(n)  //faz o percurso, efetivamente.
    if(raiz != nullptr){
        raiz->imprimirInfo();
        auxPre(raiz->getEsq());
        auxPre(raiz->getDir());
    }
}

void ArvoreBinariaBusca::preOrdem() const{ //O(n)   //chama a função que faz o percurso com parâmetro inicial raiz, o atributo privado da classe ABB
    if(raiz == nullptr)
        cout << "Arvore vazia\n\n";
    else{
        auxPre(raiz);
        cout << endl;
    }
}

void ArvoreBinariaBusca::auxOrdem(no* raiz) const{ //O(n)   //idem para essas duas
    if(raiz != nullptr){
        auxOrdem(raiz->getEsq());
        raiz->imprimirInfo();
        auxOrdem(raiz->getDir());
    }
}

void ArvoreBinariaBusca::emOrdem() const{ //O(n)
    if(raiz == nullptr)
        cout << "Arvore vazia\n\n";
    else{
        auxOrdem(raiz);
        cout << endl;
    }
}

void ArvoreBinariaBusca::auxPos(no* raiz) const{ //O(n)    //idem para essas duas
    if(raiz != nullptr){
        auxPos(raiz->getEsq());
        auxPos(raiz->getDir());
        raiz->imprimirInfo();
    }
}

void ArvoreBinariaBusca::posOrdem() const{ //O(n)
    if(raiz == nullptr)
        cout << "Arvore vazia\n\n";
    else{
        auxPos(raiz);
        cout << endl;
    }
}
