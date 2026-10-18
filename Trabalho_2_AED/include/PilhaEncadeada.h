#ifndef PILHAENCADEADA_H
#define PILHAENCADEADA_H

#include "ListaSimplesmenteEncadeada.h"

class PilhaEncadeada
{
    private:
        ListaSimplesmenteEncadeada suporte;
    public:
        PilhaEncadeada();
        ~PilhaEncadeada();
        void empilhar(int _id);
        int desempilhar();
        void consultarTopo();
        void empilharNElementos(int n);
        void desempilharNElementos(int n);
};

#endif // PILHAENCADEADA_H
