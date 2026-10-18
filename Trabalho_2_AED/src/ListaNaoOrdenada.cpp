#include "ListaNaoOrdenada.h"
#include <iostream>

ListaNaoOrdenada::ListaNaoOrdenada(int _tam)
{
    tam = _tam;
    ocupadas = 0;
    vetor = new Elemento*[tam];
    cout << "Lista de tamanho " << tam << " criada com sucesso!\n\n";
}

ListaNaoOrdenada::~ListaNaoOrdenada()
{
    delete[] vetor;
    cout << "Lista deletada!\n\n";
}

int ListaNaoOrdenada::InserirNoFinal(int _id, string _nome, int _idade){
    if(ocupadas == tam){
        cout << "Lista cheia!\n\n";
        return -1;
    }

    vetor[ocupadas] = new humano(_id, _nome, _idade);
    ocupadas++;
    return 1;
}

int ListaNaoOrdenada::InserirNoInicio(int _id, string _nome, int _idade){
    if(ocupadas == tam){
        cout << "Lista cheia!\n\n";
        return -1;
    }

    vetor[ocupadas] = vetor[0];

    vetor[0] = new humano(_id, _nome, _idade);
    ocupadas++;
    return 1;
}

/*int ListaNaoOrdenada::InserirNoInicio_Deslocamento(int _id, string _nome, int _idade){
    if(ocupadas == tam){
        cout << "lista cheia!" << endl;
        return -1;
    }

    for(int i = ocupadas; i > 0; i--) vetor[i] = vetor[i-1];

    vetor[0] = new humano(_id, _nome, _idade);
    ocupadas++;
    return 1;
}*/

int ListaNaoOrdenada::InserirNoFinal(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria){
    if(ocupadas == tam){
        cout << "Lista cheia!\n\n";
        return -1;
    }

    vetor[ocupadas] = new professor(_id, _nome, _idade, _especialidade, _salario, _carga_horaria);
    ocupadas++;
    return 1;
}

int ListaNaoOrdenada::InserirNoInicio(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria){
    if(ocupadas == tam){
        cout << "Lista cheia!\n\n";
        return -1;
    }

    vetor[ocupadas] = vetor[0];

    vetor[0] = new professor(_id, _nome, _idade, _especialidade, _salario, _carga_horaria);
    ocupadas++;
    return 1;
}

/*int ListaNaoOrdenada::InserirNoInicio_Deslocamento(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria){
    if(ocupadas == tam){
        cout << "lista cheia!" << endl;
        return -1;
    }

    for(int i = ocupadas; i > 0; i--) vetor[i] = vetor[i-1];

    vetor[0] = new professor(_id, _nome, _idade, _especialidade, _salario, _carga_horaria);
    ocupadas++;
    return 1;
}*/

int ListaNaoOrdenada::RemoverPrimeiro(){
    if(ocupadas == 0){
        cout << "Lista vazia!\n\n";
        return -1;
    }

    delete vetor[0];

    vetor[0] = vetor[ocupadas-1];

    ocupadas--;
    cout << "Elemento removido\n\n";
    return 1;
}

int ListaNaoOrdenada::RemoverPrimeiroF(){
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

int ListaNaoOrdenada::RemoverUltimo(){
    if(ocupadas == 0){
        cout << "Lista vazia!\n\n";
        return -1;
    }

    delete vetor[ocupadas-1];
    ocupadas--;
    cout << "Elemento removido\n\n";
    return 1;
}

int ListaNaoOrdenada::RemoverPeloID(int id_remova_me){
    for(int i = 0; i < ocupadas; i++){
        if(vetor[i]->getID() == id_remova_me){
            delete vetor[i];
            vetor[i] = vetor[ocupadas-1];
            ocupadas--;
            cout << "Elemento removido\n\n";
            return 1;
        }
    }

    cout << "Elemento nao encontrado\n\n";
    return -1;
}

int ListaNaoOrdenada::BuscarPeloID(int id_buscado) const{
    for(int i = 0; i < ocupadas; i++){
        if(vetor[i]->getID() == id_buscado){
            cout << "Dados encontrados:" << endl;
            vetor[i]->imprimirInfo();
            return i;
        }
    }

    cout << "ID nao encontrado\n\n";

    return -1;
}

/*int ListaNaoOrdenada::AlterarPeloID(int id_buscado, int _id, string _nome, int _idade){
    if(RemoverPeloID(id_buscado) == 1){
        InserirNoFinal(_id, _nome, _idade); //a escolha da insercao foi arbritaria
        cout << "Substituicao bem sucedida\n\n";
        return 1;
    }

    cout << "Nao foi possivel efetuar a substituicao\n\n";
    return -1;
}*/

int ListaNaoOrdenada::AlterarPeloID(int id_buscado, string _nome, int _idade){
    for(int i = 0; i < ocupadas; i++){
        if(id_buscado == vetor[i]->getID()){
            delete vetor[i];
            vetor[i] = new humano(id_buscado, _nome, _idade);
            cout << "Substituicao bem sucedida\n\n";
            return 1;
        }
    }

    cout << "Nao foi possivel efetuar a substituicao\n\n";
    return -1;
}

/*int ListaNaoOrdenada::AlterarPeloID(int id_buscado, int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria){
    if(RemoverPeloID(id_buscado) == 1){
        InserirNoFinal(_id, _nome, _idade, _especialidade, _salario, _carga_horaria); //a escolha da insercao foi arbritaria
        cout << "Substituicao bem sucedida\n\n";
        return 1;
    }

    cout << "Nao foi possivel efetuar a substituicao\n\n";
    return -1;
}*/

int ListaNaoOrdenada::AlterarPeloID(int id_buscado, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria){
    for(int i = 0; i < ocupadas; i++){
        if(id_buscado == vetor[i]->getID()){
            delete vetor[i];
            vetor[i] = new professor(id_buscado, _nome, _idade, _especialidade, _salario, _carga_horaria);
            cout << "Substituicao bem sucedida\n\n";
            return 1;
        }
    }

    cout << "ID nao encontrado\n\n";
    return -1;
}

void ListaNaoOrdenada::ImprimirLista() const{
    for(int i = 0; i < ocupadas; i++){
        vetor[i]->imprimirInfo();
    }
}

int ListaNaoOrdenada::getOcupadas() const{return ocupadas;}
void ListaNaoOrdenada::setOcupadas(int _ocupadas){ocupadas = _ocupadas;}
int ListaNaoOrdenada::getTam() const{return tam;}
Elemento* ListaNaoOrdenada::getVetor(int pos) const{return vetor[pos];}
Elemento** ListaNaoOrdenada::getVetorPAlterar(int pos) const{return &vetor[pos];}
