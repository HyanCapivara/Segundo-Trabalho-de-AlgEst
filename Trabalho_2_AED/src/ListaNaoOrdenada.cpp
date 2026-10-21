#include "ListaNaoOrdenada.h"
#include <iostream>

ListaNaoOrdenada::ListaNaoOrdenada(int _tam) //O(1)  //construtor da lista
{
    tam = _tam;
    ocupadas = 0;
    vetor = new Elemento*[tam]; //cria um vetor com o tamanho informado pelo usuario
    cout << "Lista de tamanho " << tam << " criada com sucesso!\n\n";
}

ListaNaoOrdenada::~ListaNaoOrdenada() //O(n)
{
    //deleta o vetor criado. Esse processo engloba eliminar n objetos de classes derivadas de elemento
    for(int i = 0; i < tam; i++)
        delete vetor[i];
    delete[] vetor;
    cout << "Lista deletada!\n\n";
}

int ListaNaoOrdenada::InserirNoFinal(int _id, string _nome, int _idade){ //O(1). //insere um "humano"
    if(ocupadas == tam){ //se a lista estiver cheia:
        cout << "Lista cheia!\n\n";
        return -1;
    }
    vetor[ocupadas] = new humano(_id, _nome, _idade); //tendo espaço, basta colocar o novo elemento no final da lista atual
    ocupadas++;
    return 1;
}

int ListaNaoOrdenada::InserirNoInicio(int _id, string _nome, int _idade){ //O(1)  //insere um "humano"
    if(ocupadas == tam){ //verifica lista cheia
        cout << "Lista cheia!\n\n";
        return -1;
    }

    vetor[ocupadas] = vetor[0]; //move o primeiro elemento para o final

    vetor[0] = new humano(_id, _nome, _idade); //insere o novo elemento no espaço recém vago
    ocupadas++;
    return 1;
}

/*int ListaNaoOrdenada::InserirNoInicio_Deslocamento(int _id, string _nome, int _idade){ //O(n)
    if(ocupadas == tam){ //verifica a ocupação da lista
        cout << "lista cheia!" << endl;
        return -1;
    }

    for(int i = ocupadas; i > 0; i--) vetor[i] = vetor[i-1]; //faz um passo a frente, criando um espaço no inicio

    vetor[0] = new humano(_id, _nome, _idade); //insere no inicio
    ocupadas++;
    return 1;
}*/

int ListaNaoOrdenada::InserirNoFinal(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria){ //O(1). É o mesmo código de antes só que para a classe professor
    if(ocupadas == tam){
        cout << "Lista cheia!\n\n";
        return -1;
    }

    vetor[ocupadas] = new professor(_id, _nome, _idade, _especialidade, _salario, _carga_horaria);
    ocupadas++;
    return 1;
}

int ListaNaoOrdenada::InserirNoInicio(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria){ //O(1) //idem
    if(ocupadas == tam){
        cout << "Lista cheia!\n\n";
        return -1;
    }

    vetor[ocupadas] = vetor[0];

    vetor[0] = new professor(_id, _nome, _idade, _especialidade, _salario, _carga_horaria);
    ocupadas++;
    return 1;
}

/*int ListaNaoOrdenada::InserirNoInicio_Deslocamento(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria){ //O(n)
    if(ocupadas == tam){
        cout << "lista cheia!" << endl;
        return -1;
    }

    for(int i = ocupadas; i > 0; i--) vetor[i] = vetor[i-1];

    vetor[0] = new professor(_id, _nome, _idade, _especialidade, _salario, _carga_horaria);
    ocupadas++;
    return 1;
}*/

int ListaNaoOrdenada::RemoverPrimeiro(){ //O(1)
    if(ocupadas == 0){ //se a lista  estiver vazia:
        cout << "Lista vazia!\n\n";
        return -1;
    }

    delete vetor[0]; //elimina o primeiro elemento

    vetor[0] = vetor[ocupadas-1]; //passa o último elemento para o começo. Talvez seja lixo, mas a variável "ocupadas" vai (tenho fé nisso) me impedir de usa-lo

    ocupadas--;
    cout << "Elemento removido\n\n";
    return 1;
}

int ListaNaoOrdenada::RemoverPrimeiroF(){ //O(n).  //Esse método só está aqui por ser útil para as filas. Não fosse por elas, ficava só com a remoção acima
    if(ocupadas == 0){ //se a lista está vazia:
        cout << "Lista vazia!\n\n";
        return -1;
    }

    delete vetor[0]; //elimina o primeiro elemento

    for(int i = 0; i < ocupadas; i++) vetor[i] = vetor[i+1]; //move os demais elementos para cobrir o "buraco"

    ocupadas--;
    cout << "Elemento removido\n\n";
    return 1;
}

int ListaNaoOrdenada::RemoverUltimo(){ //O(1)
    if(ocupadas == 0){ //quantifica o vazio existencial
        cout << "Lista vazia!\n\n";
        return -1;
    }

    delete vetor[ocupadas-1]; //elimina o último elemento
    ocupadas--;
    cout << "Elemento removido\n\n";
    return 1;
}

int ListaNaoOrdenada::RemoverPeloID(int id_remova_me){ //O(n)
    for(int i = 0; i < ocupadas; i++){ //procura o id a ser eliminado
        if(vetor[i]->getID() == id_remova_me){ //se achar:
            delete vetor[i]; //elimina-o
            vetor[i] = vetor[ocupadas-1]; //passa o ultimo pro lugar dele. Talvez ele seja o último e daí essa linha não muda nada
            ocupadas--;
            cout << "Elemento removido\n\n";
            return 1;
        }
    }

    cout << "Elemento nao encontrado\n\n"; //se ele não está na lista:
    return -1;
}

int ListaNaoOrdenada::BuscarPeloID(int id_buscado) const{ //O(n)
    for(int i = 0; i < ocupadas; i++){ //percorre a lista caçando o elemento informado
        if(vetor[i]->getID() == id_buscado){ //se achar:
            cout << "Dados encontrados:" << endl;
            vetor[i]->imprimirInfo();
            return i;
        }
    }

    //se não tiver achado:
    cout << "ID nao encontrado\n\n";

    return -1;
}

int ListaNaoOrdenada::AlterarPeloID(int id_buscado, int _id, string _nome, int _idade){ //O(n)
    if(RemoverPeloID(id_buscado) == 1){ //tenta remover o id_buscado
        InserirNoFinal(_id, _nome, _idade); //se conseguir, insere os novos dados
        cout << "Substituicao bem sucedida\n\n";
        return 1;
    }

    //não conseguindo:
    cout << "Nao foi possivel efetuar a substituicao\n\n";
    return -1;
}

/*int ListaNaoOrdenada::AlterarPeloID(int id_buscado, string _nome, int _idade){ //O(n)
    for(int i = 0; i < ocupadas; i++){ //percorre a lista atrás do id
        if(id_buscado == vetor[i]->getID()){ achando-o
            delete vetor[i]; //elimina-o
            vetor[i] = new humano(id_buscado, _nome, _idade); coloca no lugar dele um objeto de mesmo id mas com os novos dados
            cout << "Substituicao bem sucedida\n\n";
            return 1;
        }
    }
    //não encontrando o elemento:
    cout << "Nao foi possivel efetuar a substituicao\n\n";
    return -1;
}*/

int ListaNaoOrdenada::AlterarPeloID(int id_buscado, int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria){ //idem ao acima para a classe professor
    if(RemoverPeloID(id_buscado) == 1){
        InserirNoFinal(_id, _nome, _idade, _especialidade, _salario, _carga_horaria); //a escolha da insercao foi arbritaria
        cout << "Substituicao bem sucedida\n\n";
        return 1;
    }

    cout << "Nao foi possivel efetuar a substituicao\n\n";
    return -1;
}

/*int ListaNaoOrdenada::AlterarPeloID(int id_buscado, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria){ //idem ao acima para a classe professor
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
}*/

void ListaNaoOrdenada::ImprimirLista() const{ //O(n)
    for(int i = 0; i < ocupadas; i++){ //percorre a lista e imprime ela
        vetor[i]->imprimirInfo();
    }
}

int ListaNaoOrdenada::getOcupadas() const{return ocupadas;} //O(1)
void ListaNaoOrdenada::setOcupadas(int _ocupadas){ocupadas = _ocupadas;} //O(1)
int ListaNaoOrdenada::getTam() const{return tam;} //O(1)
Elemento* ListaNaoOrdenada::getVetor(int pos) const{return vetor[pos];} //O(1)
Elemento** ListaNaoOrdenada::getVetorPAlterar(int pos) const{return &vetor[pos];} //O(1)
