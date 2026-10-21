#ifndef LISTAORDENADAID_H
#define LISTAORDENADAID_H

#include "Elemento.h"

class ListaOrdenadaID
{
    public:
        ListaOrdenadaID(int _tam); //O(1)
        ~ListaOrdenadaID(); //O(n)

        int BuscaBinaria(int ini, int fim, int id_buscado) const; //O(logn)
        int BuscarPeloID(int id_buscado) const; //O(logn)

        int InserirOrdenadamente(int _id, string _nome, int _idade); //O(n)

        int InserirOrdenadamente(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria); //O(n)

        int RemoverPrimeiro(); //O(n)
        int RemoverUltimo(); //O(1)
        int RemoverPeloID(int id_remova_me); //O(n)

        int AlterarPeloID(int id_buscado, int _id, string _nome, int _idade); //O(n)
        //int AlterarPeloID(int id_buscado, string _nome, int _idade); //O(n)

        int AlterarPeloID(int id_buscado, int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria); //O(n)
        //int AlterarPeloID(int id_buscado, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria); //O(n)

        void ImprimirLista() const; //O(n)

        int getOcupadas() const{return ocupadas;} //O(1)

    private:
        int tam;
        int ocupadas;
        Elemento** vetor;
};

#endif // LISTAORDENADAID_H
