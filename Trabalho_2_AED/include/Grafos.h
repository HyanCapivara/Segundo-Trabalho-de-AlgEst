#ifndef GRAFOS_H
#define GRAFOS_H

#include "ListaDuplamenteEncadeada.h"

class Grafos
{
    public:
        Grafos(int tam); //O(n)
        ~Grafos(); //O(n^2)
        void AdicionarVertice(); //O(n^2)
        int AdicionarAresta(int vertice1, int vertice2); //O(1)
        int VerificarVizinho(int vertice1, int vertice2); //O(1)
        int Grau(int vertice); //O(n)
        int buscaEmLargura(int verticeInicial); //O(n^2)
        int buscaEmProfundidade(int verticeInicial); //O(n^2)
    private:
        void copiarMatriz(int **origem, int **copia); //O(n^2)
        void inicializarLinha(int* linha); //O(n)
        void inicializarColuna(int **matriz); //O(n)
        void copiarLista(ListaDuplamenteEncadeada *origem, ListaDuplamenteEncadeada *copia); //O(n^2)
        int tam;
        int usados;
        ListaDuplamenteEncadeada *listaDeAdjacencia;
        int **matrizDeAdjacencia;
};

#endif // GRAFOS_H
