#ifndef DEQUE_H
#define DEQUE_H

#include "ListaDuplamenteEncadeadaCircular.h"

class Deque
{
    public:
        Deque(){} //O(1)
        ~Deque(){} //O(n) -> vai precisar limpar as listas alocadas
        void inserirCabeca(int _id); //O(1)
        void inserirCalda(int _id); //O(1)

        int removerCabeca(); //O(1)
        int removerCalda(); //O(1)

        void olharTopoCabeca(); //O(1)
        void olharTopoCalda(); //O(1)

        bool cabecaVazia(); //O(1)
        bool caldaVazia(); //O(1)

        /*void inserirNCabeca(int n); //O(n)
        void inserirNCalda(int n); //O(n)

        void removerNCabeca(int n); //O(n)
        void removerNCalda(int n);*/ //O(n)
    private:
        ListaDuplamenteEncadeadaCircular cabeca;
        ListaDuplamenteEncadeadaCircular calda;
};

#endif // DEQUE_H
