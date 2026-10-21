#include "ListaOrdenadaID.h"
#include <iostream>

ListaOrdenadaID::ListaOrdenadaID(int _tam) //O(1)  //construtor da lista
{
    ocupadas = 0;
    tam = _tam;
    vetor = new Elemento*[tam];
    cout << "Lista criada com sucesso!\n\n";
}

ListaOrdenadaID::~ListaOrdenadaID() //O(n)  //destrutor da classe
{
    delete[] vetor;
    cout << "Lista deletada!\n\n";
}

int ListaOrdenadaID::BuscaBinaria(int ini, int fim, int id_buscado) const{ //O(logn)  //Separei ele para poder fazer uma função mais simples com a mensagenzinha. E também para poder usa-lo na inserção
    if(ini <= fim){ //É a busca binária, vai cortando o vetor no meio até achar oque você procura
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

int ListaOrdenadaID::BuscarPeloID(int id_buscado) const{ //O(logn)
    int pos = BuscaBinaria(0, ocupadas-1, id_buscado); //chama a função acima

    if(pos >= ocupadas || vetor[pos]->getID() != id_buscado){ //se o retorno indicar que o elemento não existe:
        cout << "ID nao encontrado\n\n";
        return -1;
    }
    //Se o elemento for achado/existir:
    cout << "Dados encontrados:" << endl;
    vetor[pos]->imprimirInfo();

    return 1;
}

int ListaOrdenadaID::InserirOrdenadamente(int _id, string _nome, int _idade){ //O(n)
    if(ocupadas == tam){ //não se insere em lista cheia
        cout << "Lista cheia!\n\n";
        return -1;
    }

    int pos_ins = BuscaBinaria(0, ocupadas-1, _id); //procura o id

    if(pos_ins < ocupadas && vetor[pos_ins]->getID() == _id){ //Se ele já estiver na lista, não permitirei uma segunda inserção
        cout << "O ID informado ja esta associado a um elemento\n\n";
        return -1;
    }
    //se ele for inédito:
    for(int i = ocupadas; i > pos_ins; i--) //move os elementos para frente, criando espaço para o novo
        vetor[i] = vetor[i-1];

    vetor[pos_ins] = new humano(_id, _nome, _idade); //insere o elemento no lugar adequado para manter a ordem
    ocupadas++;

    cout << "Elemento inserido\n\n";

    return 1;
}

int ListaOrdenadaID::InserirOrdenadamente(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria){ //Idem ao acima para a classe professor
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

    vetor[pos_ins] = new professor(_id, _nome, _idade, _especialidade, _salario, _carga_horaria);
    ocupadas++;

    cout << "Elemento inserido\n\n";

    return 1;
}

int ListaOrdenadaID::RemoverPrimeiro(){ //O(n)
    if(ocupadas == 0){ //caso a lista esteja vazia:
        cout << "Lista vazia!\n\n";
        return -1;
    }

    delete vetor[0]; //elimina o primeiro
    for(int i = 0; i < ocupadas; i++) vetor[i] = vetor[i+1]; //puxa os outros para trás, compensando a saida do primeiro elemento
    ocupadas--;
    cout << "Elemento removido\n\n";
    return 1;
}

int ListaOrdenadaID::RemoverUltimo(){ //O(1)
    if(ocupadas == 0){ //se a lista estiver vazia:
        cout << "Lista vazia!\n\n";
        return -1;
    }

    delete vetor[ocupadas-1]; //elimina o último. E só isso mesmo, não precisa de correções adicionais

    ocupadas--;
    cout << "Elemento removido\n\n";
    return 1;
}

int ListaOrdenadaID::RemoverPeloID(int id_remova_me){ //O(n)
    if(ocupadas == 0){ //se não houverem elementos
        cout << "Lista vazia!\n\n";
        return -1;
    }

    int pos_rem = BuscaBinaria(0, ocupadas-1, id_remova_me); //busca o elemento que buscamos remover

    if(pos_rem >= ocupadas || vetor[pos_rem]->getID() != id_remova_me){ //se ele não estiver na lista:
        cout << "ID nao encontrado\n\n";
        return -1;
    }
    //se ele estiver:
    delete vetor[pos_rem]; //elimino-o

    for(int i = pos_rem; i < ocupadas; i++) //cubro sua saída puxando os demais
        vetor[i] = vetor[i+1];

    ocupadas--;

    cout << "Elemento removido\n\n";

    return 1;
}

int ListaOrdenadaID::AlterarPeloID(int id_buscado, int _id, string _nome, int _idade){ //O(n)
    if(RemoverPeloID(id_buscado) == 1){ //tento remover o id_buscado
        int temp;
        temp = InserirOrdenadamente(_id, _nome, _idade); //se conseguir, tento inserir o novo elemento da classe humano.
        if(temp != -1){
            cout << "Alteracao bem sucedida\n\n";
            return 1;
        }
    }
    cout << "Nao foi possivel realizar a alteracao\n\n";
    return -1; //se não der para remover
}

/*int ListaOrdenadaID::AlterarPeloID(int id_buscado, string _nome, int _idade){ //O(n)
    int pos = BuscaBinaria(0, ocupadas-1, id_buscado); //busca o elemento a ser substituido

    if(pos >= ocupadas || vetor[pos]->getID() != id_buscado){ //se ele não existir:
        cout << "ID nao encontrado\n\n";
        return -1;
    }
    //se ele existir:
    delete vetor[pos]; //destroi ele
    vetor[pos] = new humano(id_buscado, _nome, _idade); //coloca, na mesma posição, um novo objeto com os parâmetros passados a essa função
    cout << "Alteracao bem sucedida\n\n";

    return 1;
}*/

int ListaOrdenadaID::AlterarPeloID(int id_buscado, int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria){ //idem ao acima para a classe professor
    if(RemoverPeloID(id_buscado) == 1){
        int temp;
        temp = InserirOrdenadamente(_id, _nome, _idade, _especialidade, _salario, _carga_horaria);
        if(temp != -1){
            cout << "Alteracao bem sucedida\n\n";
            return 1;
        }
    }
    cout << "Nao foi possivel realizar a alteracao\n\n";
    return -1;
}

/*int ListaOrdenadaID::AlterarPeloID(int id_buscado, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria){ //idem
    int pos = BuscaBinaria(0, ocupadas-1, id_buscado);

    if(pos >= ocupadas || vetor[pos]->getID() != id_buscado){
        cout << "ID nao encontrado\n\n";
        return -1;
    }

    delete vetor[pos];
    vetor[pos] = new professor(id_buscado, _nome, _idade, _especialidade, _salario, _carga_horaria);
    cout << "Alteracao bem sucedida\n\n";

    return 1;
}*/

void ListaOrdenadaID::ImprimirLista() const{ //O(n)
    for(int i = 0; i < ocupadas; i++){ //percorre a lista imprimindo seus elementos
        vetor[i]->imprimirInfo();
    }
}
