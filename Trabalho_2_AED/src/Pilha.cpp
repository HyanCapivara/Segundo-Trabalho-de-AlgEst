#include "Pilha.h"
#include <iostream>

//as funções da lista não ordenada conseguem produzir pilhas com O(1) sem maiores rodeios. Não há muito o que se falar aqui, tendo em mente o .cpp da listaNaoOrdenada

int Pilha::empilhar(int _id, string _nome, int _idade){ //O(1)
    return suporte.InserirNoFinal(_id, _nome, _idade); //chama a inserção no final da listanaoordenada para a classe humano
}

int Pilha::empilhar(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria){ //O(1)
    return suporte.InserirNoFinal(_id, _nome, _idade, _especialidade, _salario, _carga_horaria); //chama a inserção no final da listanaoordenada para a classe professor
}

int Pilha::desempilhar(){ //O(1)
    return suporte.RemoverUltimo(); //chama o método de remoção da lista não ordenada
}

void Pilha::consultarTopo() const{ //O(1)
    if(suporte.getOcupadas() == 0) //se a lista está vazia, não há topo para se olhar
        cout << "Pilha vazia!\n\n";
    else
        suporte.getVetor(suporte.getOcupadas()-1)->imprimirInfo(); //se existem elementos, basta pegar o primeiro deles e tortura-lo para que ele compartilhe amigavelmente suas informações
}

bool Pilha::pilhaCheia(){ //O(1)
    if(suporte.getOcupadas() == suporte.getTam()) return 1; //verifica se a capacidade máxima coincide com a quantidade usada
    return 0;
}

bool Pilha::pilhaVazia(){ //O(1)
    if(suporte.getOcupadas() == 0) return 1; //verifica se a ocupação é igual a 0
    return 0;
}

/*
void Pilha::pilhaCheia(){ //O(n), faz tam-ocupadas inserções
    int temp = suporte.getTam();
    for(int i = suporte.getOcupadas(); i < temp; i++)
        suporte.InserirNoFinal(i, "generico", i);
}

void Pilha::pilhaVazia(){ //O(n), faz ocupadas remoções
    int temp = suporte.getOcupadas();
    while(temp>0){
        suporte.RemoverUltimo();
        temp--;
    }
}
*/
