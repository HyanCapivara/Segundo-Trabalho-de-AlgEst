#ifndef PILHAENCADEADA_H
#define PILHAENCADEADA_H

#include "ListaSimplesmenteEncadeada.h"

class PilhaEncadeada
{
    private:
        ListaSimplesmenteEncadeada suporte;
    public:
        PilhaEncadeada(){} //O(1)
        ~PilhaEncadeada(){} //O(1)
        void empilhar(int _id); //O(1)
        int desempilhar(); //O(1)
        int consultarTopo(); //O(1)
        bool pilhaVazia(); //O(1)
        int retornarTopo(); //O(1)
        //void empilharNElementos(int n); //O(n)
        //void desempilharNElementos(int n); //O(n)
};

#endif // PILHAENCADEADA_H
