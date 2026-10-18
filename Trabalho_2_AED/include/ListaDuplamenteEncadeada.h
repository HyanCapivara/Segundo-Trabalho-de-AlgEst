#ifndef LISTADUPLAMENTEENCADEADA_H
#define LISTADUPLAMENTEENCADEADA_H

class ListaDuplamenteEncadeada
{
    private:
        class no{
            public:
                no(int _id, no* _ant, no* _prox):ID(_id), ant(_ant), prox(_prox){}
                ~no(){}
                int getID() const{return ID;}
                void setProx(no* _prox){prox = _prox;}
                no* getProx() const{return prox;}
                void setAnt(no* _ant){ant = _ant;}
                no* getAnt() const{return ant;}
                void imprimirInfo() const;
            private:
                int ID;
                no* ant;
                no* prox;
        };

        no* cabeca = new no(0, nullptr, nullptr);

    public:
        ListaDuplamenteEncadeada();
        ~ListaDuplamenteEncadeada();
        void inserirNoInicio(int _id);
        void inserirNoFim(int _id);
        int removerPeloID(int _id);
        int removerPrimeiro();
        int removerUltimo();
        //int alterarPeloID(); <- preguicei. termina depois
        int buscarPeloID(int _id) const;
        void imprimirLista() const;
};

#endif // LISTADUPLAMENTEENCADEADA_H
