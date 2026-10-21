#ifndef FILAENCADEADA_H
#define FILAENCADEADA_H

#include "ListaDuplamenteEncadeadaCircular.h"

class FilaEncadeada
{
    private:
        ListaDuplamenteEncadeadaCircular suporte;
    public:
        FilaEncadeada(){} //O(1)
        ~FilaEncadeada(){} //O(n)
        void enfileirar(int _id); //O(1)
        int desenfileirar(); //O(1)
        int consultarFrente(); //O(1)
        bool filaVazia(); //O(1)
        int retornarFrente(); //O(1) //para grafos  É um get com nome diferente
        //void enfileirarNElementos(int n); //O(n)
        //void desenfileirarNElementos(int n); //O(n)
};

#endif // FILAENCADEADA_H
