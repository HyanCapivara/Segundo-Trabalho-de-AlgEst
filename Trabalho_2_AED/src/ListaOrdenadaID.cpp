#include "ListaOrdenadaID.h"
#include <iostream>

ListaOrdenadaID::ListaOrdenadaID(int _tam)
{
    ocupadas = 0;
    tam = _tam;
    vetor = new Elemento*[tam];
    cout << "Lista criada com sucesso!\n\n";
}

ListaOrdenadaID::~ListaOrdenadaID()
{
    delete[] vetor;
    cout << "Lista deletada!\n\n";
}

int ListaOrdenadaID::BuscaBinaria(int ini, int fim, int id_buscado) const{
    if(ini <= fim){
        int meio = (ini+fim)/2;
        if(id_buscado > vetor[meio]->getID())
            return BuscaBinaria(meio+1, fim, id_buscado);
        else if(id_buscado < vetor[meio]->getID())
            return BuscaBinaria(ini, meio-1, id_buscado);
        else
            return meio;
    }
    return ini;
}

int ListaOrdenadaID::BuscarPeloID(int id_buscado) const{
    int pos = BuscaBinaria(0, ocupadas-1, id_buscado);

    if(pos >= ocupadas || vetor[pos]->getID() != id_buscado){
        cout << "ID nao encontrado\n\n";
        return -1;
    }

    cout << "Dados encontrados:" << endl;
    vetor[pos]->imprimirInfo();

    return 1;
}

int ListaOrdenadaID::InserirOrdenadamente(int _id, string _nome, int _idade){
    if(ocupadas == tam){
        cout << "Lista cheia!\n\n";
        return -1;
    }

    int pos_ins = BuscaBinaria(0, ocupadas-1, _id);

    if(pos_ins < ocupadas && vetor[pos_ins]->getID() == _id){
        cout << "O ID informado ja esta associado a um elemento\n\n";
        return -1;
    }

    for(int i = ocupadas; i > pos_ins; i--)
        vetor[i] = vetor[i-1];

    vetor[pos_ins] = new humano(_id, _nome, _idade);
    ocupadas++;

    cout << "Elemento inserido\n\n";

    return 1;
}

int ListaOrdenadaID::InserirOrdenadamente(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria){
    if(ocupadas == tam){
        cout << "Lista cheia!\n\n";
        return -1;
    }

    int pos_ins = BuscaBinaria(0, ocupadas-1, _id);

    if(pos_ins < ocupadas && vetor[pos_ins]->getID() == _id){
        cout << "O ID informado ja esta associado a um elemento\n\n";
        return -1;
    }

    for(int i = ocupadas; i > pos_ins; i++)
        vetor[i] = vetor[i-1];

    vetor[pos_ins] = new professor(_id, _nome, _idade, _especialidade, _salario, _carga_horaria);
    ocupadas++;

    cout << "Elemento inserido\n\n";

    return 1;
}

int ListaOrdenadaID::RemoverPrimeiro(){ //mesmo método da lista desordenada, vou pensar em dar isso aqui de herança...
    if(ocupadas == 0){
        cout << "Lista vazia!\n\n";
        return -1;
    }

    delete vetor[0];
    for(int i = 0; i < ocupadas; i++) vetor[i] = vetor[i+1];
    ocupadas--;
    cout << "Elemento removido\n\n";
    return 1;
}

int ListaOrdenadaID::RemoverUltimo(){ //idem
    if(ocupadas == 0){
        cout << "Lista vazia!\n\n";
        return -1;
    }

    delete vetor[ocupadas-1];

    ocupadas--;
    cout << "Elemento removido\n\n";
    return 1;
}

int ListaOrdenadaID::RemoverPeloID(int id_remova_me){
    if(ocupadas == 0){
        cout << "Lista vazia!\n\n";
        return -1;
    }

    int pos_rem = BuscaBinaria(0, ocupadas-1, id_remova_me);

    if(pos_rem >= ocupadas || vetor[pos_rem]->getID() != id_remova_me){
        cout << "ID nao encontrado\n\n";
        return -1;
    }

    delete vetor[pos_rem];

    for(int i = pos_rem; i < ocupadas; i++)
        vetor[i] = vetor[i+1];

    ocupadas--;

    cout << "Elemento removido\n\n";

    return 1;
}

/*int ListaOrdenadaID::AlterarPeloID(int id_buscado, int _id, string _nome, int _idade){
    if(RemoverPeloID(id_buscado) == 1){
        InserirOrdenadamente(_id, _nome, _idade);
        return 1;
    }

    return -1;
}*/

int ListaOrdenadaID::AlterarPeloID(int id_buscado, string _nome, int _idade){
    int pos = BuscaBinaria(0, ocupadas-1, id_buscado);

    if(pos >= ocupadas || vetor[pos]->getID() != id_buscado){
        cout << "ID nao encontrado\n\n";
        return -1;
    }

    delete vetor[pos];
    vetor[pos] = new humano(id_buscado, _nome, _idade);
    cout << "Alteracao bem sucedida\n\n";

    return 1;
}

/*int ListaOrdenadaID::AlterarPeloID(int id_buscado, int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria){
    if(RemoverPeloID(id_buscado) == 1){
        InserirOrdenadamente(_id, _nome, _idade, _especialidade, _salario, _carga_horaria);
        return 1;
    }

    return -1;
}*/

int ListaOrdenadaID::AlterarPeloID(int id_buscado, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria){
    int pos = BuscaBinaria(0, ocupadas-1, id_buscado);

    if(pos >= ocupadas || vetor[pos]->getID() != id_buscado){
        cout << "ID nao encontrado\n\n";
        return -1;
    }

    delete vetor[pos];
    vetor[pos] = new professor(id_buscado, _nome, _idade, _especialidade, _salario, _carga_horaria);
    cout << "Alteracao bem sucedida\n\n";

    return 1;
}

void ListaOrdenadaID::ImprimirLista() const{
    for(int i = 0; i < ocupadas; i++){
        vetor[i]->imprimirInfo();
    }
}
