#ifndef ARVOREBINARIABUSCA_H
#define ARVOREBINARIABUSCA_H


class ArvoreBinariaBusca
{
    private:
        class no{
            private:
                int ID;
                no* esq;
                no* dir;
            public:
                no(int _id, no* _esq, no* _dir):ID(_id), esq(_esq), dir(_dir){} //O(1)
                ~no(){} //O(1)
                int getID() const{return ID;} //O(1)
                no* getEsq() const{return esq;} //O(1)
                no* getDir() const{return dir;} //O(1)
                void setEsq(no* _esq){esq = _esq;} //O(1)
                void setDir(no* _dir){dir = _dir;} //O(1)
                void imprimirInfo() const; //O(1)
        };
        no *raiz = nullptr;
        void desmatamento(no* raiz); //O(n)
        //esses métodos auxiliares são responsáveis por fazer o percurso, efetivamente.
        //Fiz eles para impedir que eu precisasse, sempre que quisesse realizar um percurso, extrair a raiz privada da classe para enviar aqui.
        //Com essa escolha, eu sempre chamo o percurso desejado e o método dele se encarrega de enviar a raiz
        void auxPre(no* raiz) const; //O(n)
        void auxPos(no* raiz) const; //O(n)
        void auxOrdem(no* raiz) const; //O(n)
    public:
        ArvoreBinariaBusca(); //O(1)
        ~ArvoreBinariaBusca(); //O(n)
        int Inserir(int _id); //O(h) ou O(n)
        int BuscarPeloId(int _id); //O(h) ou O(n)
        int RemoverPeloId(int _id); //O(h) ou O(n)
        void preOrdem() const; //O(n)
        void emOrdem() const; //O(n)
        void posOrdem() const; //O(n)
};

#endif // ARVOREBINARIABUSCA_H
