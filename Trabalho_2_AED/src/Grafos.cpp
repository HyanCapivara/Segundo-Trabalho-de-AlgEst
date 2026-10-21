#include "Grafos.h"
#include <iostream>
#include "FilaEncadeada.h"
#include "PilhaEncadeada.h"

using namespace std;

Grafos::Grafos(int _tam) //O(n^2), n é o número de vértices   //construtor da classe
{
    matrizDeAdjacencia = new int*[_tam]; //cria uma matriz de inteiros com n linhas
    listaDeAdjacencia = new ListaSimplesmenteEncadeada[_tam]; //cria uma lista com n linhas
    tam = _tam;
    usados = _tam;
    for(int i = 0; i < _tam; i++){ // cria n colunas para a matriz acima
        matrizDeAdjacencia[i] = new int[_tam];
        inicializarLinha(matrizDeAdjacencia[i]); //inicia cada linha na matriz com 0
    }
}

Grafos::~Grafos() //O(n^2)
{
    for(int i = 0; i < tam; i++) //visita cada linha e elimina o vetor que está associado a ela
        delete[] matrizDeAdjacencia[i];
    delete[] matrizDeAdjacencia;
    delete[] listaDeAdjacencia; //vai ter que chamar o destrutor dessa classe n vezes e ele custa O(n)
}

void Grafos::copiarMatriz(int **origem, int **copia){ //O(n^2).  Vai passar por todos os nós copiando-os para a nova matriz
    for(int i = 0; i < usados; i++){
        for(int j = 0; j < usados; j++){
            copia[i][j] = origem[i][j];
        }
    }
}

void Grafos::inicializarLinha(int* linha){ //O(n).  Coloca 0 em todas as entradas de uma linha
    for(int i = 0; i < usados; i++)
        linha[i] = 0;
}

void Grafos::inicializarColuna(int** matriz){ //O(n).  Coloca 0 em todas as entradas de uma coluna
    for(int i = 0; i <= usados; i++)
        matriz[i][usados] = 0;
}

void Grafos::copiarLista(ListaSimplesmenteEncadeada *origem, ListaSimplesmenteEncadeada *copia){ //O(n^2).  Vai passar por todos os nós armazenados na lista de adjacencia.
                                                                                            //No pior caso, a lista está cheia e dai teremos que passar por n listas com n elementos
    ListaSimplesmenteEncadeada::no* aux;
    for(int i = 0; i < usados; i++){
        aux = origem[i].getCabeca()->getProx();
        while(aux != nullptr){
            copia[i].inserirNoInicio(aux->getID());
            aux = aux->getProx();
        }
    }
}

void Grafos::AdicionarVertice(){ //O(n^2).  Se a estrutura atual não suportar mais vértices, o código vai ter que criar novas estruturas para armazena-los.
//Para manter as relações anteriores, será necessário chamar os códigos de cópia acima. Mesmo no melhor caso, custa O(n)
    if(usados >= tam){
        int** matrizNova = new int*[tam*2];
        for(int i = 0; i < tam*2; i++)
            matrizNova[i] = new int[tam*2];
        copiarMatriz(matrizDeAdjacencia, matrizNova);
        for(int i = 0; i < usados; i++)
            delete[] matrizDeAdjacencia[i];
        delete[] matrizDeAdjacencia;
        matrizDeAdjacencia = matrizNova;
        ListaSimplesmenteEncadeada *novaLista = new ListaSimplesmenteEncadeada[tam*2];
        copiarLista(listaDeAdjacencia, novaLista);
        delete[] listaDeAdjacencia;
        listaDeAdjacencia = novaLista;
        tam = tam*2;
        cout << "Novas estruturas foram criadas\n\n";
    }
    inicializarLinha(matrizDeAdjacencia[usados]);
    inicializarColuna(matrizDeAdjacencia);
    usados++;
}

int Grafos::VerificarVizinho(int vertice1, int vertice2){ //O(1)
    if(vertice1 > usados || vertice2 > usados || vertice1 < 1 || vertice2 < 1) return -1; //verifica se o vértice existe

    if(matrizDeAdjacencia[vertice1-1][vertice2-1] == 1) //verifica se a matriz de adjacência tem uma aresta para esses vértices
        return 1;
    else
        return 0;
}

int Grafos::AdicionarAresta(int vertice1, int vertice2){ //O(1)
    int temp = VerificarVizinho(vertice1, vertice2);
    if(temp == 1){ //Se esses vértices já forem vizinhos:
        cout << "Esses vertices ja sao vizinhos\n\n";
        return -1;
    }
    else if(temp == -1){ //se esses vértices não existirem
        cout << "Ao menos um desses vertices nao existe\n\n";
        return 1;
    }
    else{ //não sendo vizinhos e existindo:
        matrizDeAdjacencia[vertice1-1][vertice2-1] = 1; //marca a aresta na matriz
        matrizDeAdjacencia[vertice2-1][vertice1-1] = 1; //note que eu marco que x é vizinho de y e também que y é vizinho de x
        listaDeAdjacencia[vertice1-1].inserirNoInicio(vertice2); //marca a vizinhança na lista
        listaDeAdjacencia[vertice2-1].inserirNoInicio(vertice1);
        cout << "Aresta adicionada\n\n";
        return 1;
    }
}

int Grafos::Grau(int vertice){ //O(n)
    if(vertice > usados || vertice < 1){  //verifica se o vértice existe
        cout << "O vertice informado nao existe\n\n";
        return -1;
    }
    int n = 0;
    ListaSimplesmenteEncadeada::no* aux = listaDeAdjacencia[vertice-1].getCabeca()->getProx();
    while(aux != nullptr){ //percorre a lista para contar os vizinhos
        n++;
        aux = aux->getProx();
    }
    cout << "O vertice informado tem " << n << " vizinhos\n\n";
    return n;
}

int Grafos::buscaEmLargura(int verticeInicial){ //O(n^2). No pior dos casos, você vai percorrer todos os n vértices e verificar todos os seus n-1 vizinhos
    if(verticeInicial > usados || verticeInicial < 1){ //vê se o vértice inicial existe
        cout << "Vertice inexistente\n\n";
        return -1;
    }
    int encontrados[usados]; //evita redundância
    int verticeAtual;
    ListaSimplesmenteEncadeada::no* aux; //vai ser usado para percorrer um dado vértice
    inicializarLinha(encontrados);
    FilaEncadeada filaSuporte; //estrutura de suporte para o percurso
    filaSuporte.enfileirar(verticeInicial);

    encontrados[verticeInicial-1] = 1;

    while(!filaSuporte.filaVazia()){ //enquanto houverem vértices
        verticeAtual = filaSuporte.retornarFrente(); //guarda o vértice atual
        filaSuporte.desenfileirar(); //remove o vértice atual da lista
        aux = listaDeAdjacencia[verticeAtual-1].getCabeca()->getProx(); //aux passa a ver a lista de adjacência do vértice atual

        while(aux != nullptr){ //enquanto houverem nós:
            if(encontrados[aux->getID()-1] != 1){ //se eu ainda não vi eles:
                encontrados[aux->getID()-1] = 1;
                filaSuporte.enfileirar(aux->getID());
            }
            aux = aux->getProx(); //segue em frente
        }
    }

    cout << "Os seguintes vertices foram visitados: "; //informa quem foi visto

    for(int i = 1; i <= usados; i++){
        if(encontrados[i-1] == 1)
            cout << i << " ";
    }
    cout << "\n\n";
    return 1;
}

int Grafos::buscaEmProfundidade(int verticeInicial){ //O(n^2). Idem ao caso anterior
    if(verticeInicial > usados || verticeInicial < 1){ //vê se o vértice inicial existe
        cout << "Vertice inexistente\n\n";
        return -1;
    }
    int encontrados[usados]; //evita redundancia
    int verticeAtual;
    ListaSimplesmenteEncadeada::no* aux; //vai ser usado para percorrer um dado vertice
    inicializarLinha(encontrados);
    PilhaEncadeada pilhaSuporte; //estrutura de suporte para o percurso
    pilhaSuporte.empilhar(verticeInicial);

    encontrados[verticeInicial-1] = 1;

    while(!pilhaSuporte.pilhaVazia()){ //enquanto houverem vértices
        verticeAtual = pilhaSuporte.retornarTopo(); //guarda o vértice atual
        pilhaSuporte.desempilhar(); //remove o vértice atual da lista
        aux = listaDeAdjacencia[verticeAtual-1].getCabeca()->getProx(); //aux passa a ver a lista de adjacência do vértice atual

        while(aux != nullptr){ //enquanto houverem nós:
            if(encontrados[aux->getID()-1] != 1){ //se eu ainda não vi eles:
                encontrados[aux->getID()-1] = 1;
                pilhaSuporte.empilhar(aux->getID());
            }
            aux = aux->getProx(); //segue em frente
        }
    }

    cout << "Os seguintes vertices foram visitados: "; //informa quem foi visto

    for(int i = 1; i <= usados; i++){
        if(encontrados[i-1] == 1)
            cout << i << " ";
    }
    cout << "\n\n";

    return 1;
}
