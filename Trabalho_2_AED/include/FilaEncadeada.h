#ifndef FILAENCADEADA_H
#define FILAENCADEADA_H

#include "ListaDuplamenteEncadeadaCircular.h"

class FilaEncadeada
{
    private:
        ListaDuplamenteEncadeadaCircular suporte;
    public:
        FilaEncadeada();
        ~FilaEncadeada();
        void enfileirar(int _id);
        int desenfileirar();
        void consultarFrente();
        void enfileirarNElementos(int n);
        void desenfileirarNElementos(int n);
};

#endif // FILAENCADEADA_H
