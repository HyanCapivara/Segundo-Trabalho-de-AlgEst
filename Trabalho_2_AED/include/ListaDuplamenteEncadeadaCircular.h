#ifndef LISTADUPLAMENTEENCADEADACIRCULAR_H
#define LISTADUPLAMENTEENCADEADACIRCULAR_H

#include "Grafos.h"

class ListaDuplamenteEncadeadaCircular
{
    private:
        class no{
            public:
                no(int _id, no* _ant, no* _prox):ID(_id), ant(_ant), prox(_prox){} //O(1)
                ~no(){} //O(1)
                int getID() const{return ID;} //O(1)
                void setProx(no* _prox){prox = _prox;} //O(1)
                no* getProx() const{return prox;} //O(1)
                void setAnt(no* _ant){ant = _ant;} //O(1)
                no* getAnt() const{return ant;} //O(1)
                void imprimirInfo() const; //O(1)
            private:
                int ID;
                no* ant;
                no* prox;
        };

        no* cabeca = new no(0, nullptr, nullptr);

    public:
        ListaDuplamenteEncadeadaCircular(); //O(1)
        ~ListaDuplamenteEncadeadaCircular(); //O(n)
        void inserirNoInicio(int _id); //O(1)
        void inserirNoFim(int _id); //O(1)
        int removerPeloID(int _id); //O(n)
        int removerPrimeiro(); //O(1)
        int removerUltimo(); //O(1)
        int alterarPeloID(int id_velho, int id_novo); //O(n)
        int buscarPeloID(int _id) const; //O(n)
        void imprimirSentidoDireito() const; //O(n)
        void imprimirSentidoEsquerdo() const; //O(n)
        no* getCabeca() const{return cabeca;} //O(1)
};

#endif // LISTADUPLAMENTEENCADEADACIRCULAR_H
