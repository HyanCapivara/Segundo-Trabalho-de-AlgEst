#ifndef LISTANAOORDENADA_H
#define LISTANAOORDENADA_H

#include "Elemento.h"

class ListaNaoOrdenada
{
    public:
        ListaNaoOrdenada(int _tam); //O(1)
        ~ListaNaoOrdenada(); //O(n)

        //insercoes para humano
        int InserirNoFinal(int _id, string _nome, int _idade); //O(1)
        int InserirNoInicio(int _id, string _nome, int _idade); //O(1)
        //int InserirNoInicio_Deslocamento(int _id, string _nome, int _idade); //O(n). É uma possibilidade mas, visto que a ordem não importa, é melhor não usar

        //insercoes para professor
        int InserirNoFinal(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria); //O(1)
        int InserirNoInicio(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria); //O(1)
        //int InserirNoInicio_Deslocamento(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria); //O(n)

        //as remoções são iguais para ambas as classes
        int RemoverPrimeiro(); //O(1)
        int RemoverPrimeiroF(); //O(n), essa opção remove o primeiro e faz um algoritmo de "passo" para cobrir o buraco. É mais cara para a lista mas é um método para simular fila (não é o melhor, mas é um método válido)
        int RemoverUltimo(); //O(1)
        int RemoverPeloID(int id_remova_me); //O(n)

        //a busca também é a mesma
        int BuscarPeloID(int id_buscado) const; //O(n)

        //alteracao para humano
        int AlterarPeloID(int id_buscado, int _id, string _nome, int _idade); //O(n) //essa versão elimina o objeto associado ao id buscado e insere um novo objeto, com novo id, de tipo humano
        //int AlterarPeloID(int id_buscado, string _nome, int _idade); //O(n) //essa versão elimina o objeto associado ao id buscado e cria, no mesmo lugar e com o mesmo id, um novo objeto de tipo humano

        //alteracao para professor
        int AlterarPeloID(int id_buscado, int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria); //O(n) //idem ao acima mas para a classe professor
        //int AlterarPeloID(int id_buscado, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria); //O(n)  //idem

        void ImprimirLista() const; //O(n)

        //esses métodos são para uso externo, vide a lista
        int getOcupadas() const; //O(1)
        void setOcupadas(int _ocupadas); //O(1)
        int getTam() const; //O(1)
        Elemento* getVetor(int pos) const; //O(1)
        Elemento** getVetorPAlterar(int pos) const; //O(1)

    private:
        int tam;
        int ocupadas;
        Elemento** vetor;
};

#endif // LISTANAOORDENADA_H
