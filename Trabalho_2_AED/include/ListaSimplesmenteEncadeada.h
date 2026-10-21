#ifndef LISTASIMPLESMENTEENCADEADA_H
#define LISTASIMPLESMENTEENCADEADA_H

using namespace std;

class ListaSimplesmenteEncadeada
{
    private:
        class no{
            public:
                no(int _id, no* _prox):ID(_id), prox(_prox){} //O(1)
                ~no(){} //O(1)
                int getID() const{return ID;} //O(1)
                void setProx(no* _prox){prox = _prox;} //O(1)
                no* getProx() const{return prox;} //O(1)
                void imprimirInfo() const; //O(1)
            private:
                int ID;
                no* prox;
        };

        no* cabeca = new no(0, nullptr);

    public:
        ListaSimplesmenteEncadeada(); //O(1)
        ~ListaSimplesmenteEncadeada(); //O(n)
        void inserirNoInicio(int _id); //O(1)
        void inserirNoFim(int _id); //O(n)
        no* getCabeca(){return cabeca;} //O(1)
        int removerPeloID(int _id); //O(n)
        int removerPrimeiro(); //O(1)
        int removerUltimo(); //O(n)
        int alterarPeloID(int id_velho, int id_novo); //O(n)
        int buscarPeloID(int _id) const; //O(n)
        void imprimirLista() const; //O(n)

};

#endif // LISTASIMPLESMENTEENCADEADA_H
