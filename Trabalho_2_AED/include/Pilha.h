#ifndef PILHA_H
#define PILHA_H

#include "ListaNaoOrdenada.h"

class Pilha
{
    public:
        Pilha(int _tam):suporte(_tam){} //O(1)
        ~Pilha(){} //O(1)
        int empilhar(int _id, string _nome, int _idade); //O(1)
        int empilhar(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria); //O(1)
        int desempilhar(); //O(1)
        void consultarTopo() const; //O(1)
        bool pilhaCheia(); //O(1)
        bool pilhaVazia(); //O(1)
        //void pilhaCheia(); //O(n)
        //void pilhaVazia(); //O(n)
    private:
        ListaNaoOrdenada suporte;
};

#endif // PILHA_H
