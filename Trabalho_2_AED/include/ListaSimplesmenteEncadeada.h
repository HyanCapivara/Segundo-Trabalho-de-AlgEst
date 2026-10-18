#ifndef LISTASIMPLESMENTEENCADEADA_H
#define LISTASIMPLESMENTEENCADEADA_H

using namespace std;

class ListaSimplesmenteEncadeada
{
    private:
        class no{
            public:
                no(int _id, no* _prox):ID(_id), prox(_prox){}
                ~no(){}
                int getID() const{return ID;}
                void setProx(no* _prox){prox = _prox;}
                no* getProx() const{return prox;}
                void imprimirInfo() const;
            private:
                int ID;
                no* prox;
        };

        no* cabeca = new no(0, nullptr);

    public:
        ListaSimplesmenteEncadeada();
        ~ListaSimplesmenteEncadeada();
        void inserirNoInicio(int _id);
        void inserirNoFim(int _id);
        no* getCabeca(){return cabeca;}
        int removerPeloID(int _id);
        int removerPrimeiro();
        int removerUltimo();
        //int alterarPeloID(); <- preguicei. termina depois
        int buscarPeloID(int _id) const;
        void imprimirLista() const;

};

#endif // LISTASIMPLESMENTEENCADEADA_H
