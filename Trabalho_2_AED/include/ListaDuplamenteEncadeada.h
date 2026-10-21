#ifndef LISTADUPLAMENTEENCADEADA_H
#define LISTADUPLAMENTEENCADEADA_H

class ListaDuplamenteEncadeada
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
        ListaDuplamenteEncadeada(); //O(1)
        ~ListaDuplamenteEncadeada(); //O(n), onde n é o número de nós armazenados
        void inserirNoInicio(int _id); //O(1)
        void inserirNoFim(int _id); //O(n)
        int removerPeloID(int _id); //O(n)
        int removerPrimeiro(); //O(1)
        int removerUltimo(); //O(n)
        int alterarPeloID(int id_velho, int id_novo); //O(n)
        int buscarPeloID(int _id) const; //O(n)
        void imprimirLista() const; //O(n)

        no* getCabeca(){return cabeca;} //O(1)  //para ser usado nos grafos
};

#endif // LISTADUPLAMENTEENCADEADA_H
