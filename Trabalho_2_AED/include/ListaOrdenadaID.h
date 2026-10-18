#ifndef LISTAORDENADAID_H
#define LISTAORDENADAID_H

#include "Elemento.h"

class ListaOrdenadaID
{
    public:
        ListaOrdenadaID(int _tam);
        ~ListaOrdenadaID();

        int BuscaBinaria(int ini, int fim, int id_buscado) const;
        int BuscarPeloID(int id_buscado) const;

        /*int InserirNoFinal(int _id, int _idade, string _nome);
        int InserirNoInicio(int _id, int _idade, string _nome);*/ //<- vai rolar não amigão. Essa liberdade destroi a ordem!
        int InserirOrdenadamente(int _id, string _nome, int _idade);

        /*int InserirNoFinal(nt _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria);
        int InserirNoInicio(nt _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria);*/
        int InserirOrdenadamente(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria);

        int RemoverPrimeiro(); //um pouco particular mas pode manter
        int RemoverUltimo(); //idem ao acima
        int RemoverPeloID(int id_remova_me);

        //int AlterarPeloID(int id_buscado, int _id, string _nome, int _idade);
        int AlterarPeloID(int id_buscado, string _nome, int _idade);

        //int AlterarPeloID(int id_buscado, int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria);
        int AlterarPeloID(int id_buscado, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria);

        void ImprimirLista() const;

        int getOcupadas() const{return ocupadas;}

    private:
        int tam;
        int ocupadas;
        Elemento** vetor;
};

#endif // LISTAORDENADAID_H
