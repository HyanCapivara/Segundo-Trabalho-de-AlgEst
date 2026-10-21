#ifndef FILAENCADEADA_H
#define FILAENCADEADA_H

#include "ListaDuplamenteEncadeadaCircular.h"

class FilaEncadeada
{
    private:
        ListaDuplamenteEncadeadaCircular suporte;
    public:
        FilaEncadeada(){} //O(1)
        ~FilaEncadeada(){} //O(1)
        void enfileirar(int _id); //O(1)
        int desenfileirar(); //O(1)
        int consultarFrente(); //O(1)
        bool filaVazia(); //O(1)
        int retornarFrente(); //O(1)
        //void enfileirarNElementos(int n); //O(n)
        //void desenfileirarNElementos(int n); //O(n)
};

#endif // FILAENCADEADA_H
