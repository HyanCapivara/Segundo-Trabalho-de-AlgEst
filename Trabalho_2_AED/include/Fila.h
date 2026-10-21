#ifndef FILA_H
#define FILA_H

#include "ListaNaoOrdenada.h"

class Fila
{
    public:
        Fila(int _tam):suporte(_tam){} //O(1)
        ~Fila(){} //O(1)
        int enfileirar(int _id, string _nome, int _idade); //O(1) tanto com os métodos da lista quanto com os presentes aqui.
                                                          //Vale ressaltar que a remoção em O(1) só foi possível por ter sido adotado um padrão de lista circular
                                                         //que depende do código para inserção e remoção que se encontram abaixo, sendo códigos a parte da lista original

        int enfileirar(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria); //idem ao enfileirar acima
        int desenfileirar(); ////O(n), se usar os métodos nativos da listaNaoOrdenada. O(1), se usar o método remover abaixo
        void consultarInicio() const; //O(1)
        bool filaCheia(); //O(1)
        bool filaVazia(); //O(1)

        //int filaCheia(); //O(n), onde n é o tam da lista
        //int filaVazia(); //O(n)
    private:
        int RemoverPrimeiroF(); //O(1)
        int InserirNoFinal(int _id, string _nome, int _idade); //O(1)
        int InserirNoFinal(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria); //O(1)
        int ini = 0;
        ListaNaoOrdenada suporte;
};

#endif // FILA_H
