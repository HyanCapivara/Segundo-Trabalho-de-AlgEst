#include "Fila.h"
#include <iostream>

int Fila::InserirNoFinal(int _id, string _nome, int _idade){ //O(1)
//Eu usei o mesmo nome do método da classe listanaoordenada. Fora o nome e o objetivo, esses métodos não tem relação nenhuma
    if(suporte.getOcupadas() == suporte.getTam()){
        cout << "Fila cheia!\n\n";
        return -1;
    }
    *suporte.getVetorPAlterar( (ini+suporte.getOcupadas())%suporte.getTam() ) = new humano(_id, _nome, _idade);
    suporte.setOcupadas(suporte.getOcupadas()+1);
    cout << "Elemento inserido\n\n";
    return 1;
}

int Fila::InserirNoFinal(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria){ //O(1). idem ao acima
    if(suporte.getOcupadas() == suporte.getTam()){
        cout << "Fila cheia!\n\n";
        return -1;
    }

    *suporte.getVetorPAlterar( (ini+suporte.getOcupadas())%suporte.getTam() ) = new humano(_id, _nome, _idade);
    suporte.setOcupadas(suporte.getOcupadas()+1);
    cout << "Elemento inserido\n\n";
    return 1;
}

int Fila::RemoverPrimeiroF(){ //O(1)
//a remoção é a mesma para os dois tipos de elementos. idem ao acima
    if(suporte.getOcupadas() == 0){
        cout << "Fila vazia!\n\n";
        return -1;
    }

    delete suporte.getVetor(ini);
    ini = (ini+1)%suporte.getTam();
    suporte.setOcupadas(suporte.getOcupadas()-1);
    cout << "Elemento removido\n\n";
    return 1;
}

int Fila::enfileirar(int _id, string _nome, int _idade){ //O(1)
    //return suporte.InserirNoFinal(_id, _nome, _idade); //a primeira implementação usava o método de inserção da listaNaoOrenada. funcional, mas obriga o uso de uma remoção ineficiente
    return InserirNoFinal(_id, _nome, _idade); //a segunda implementação chama a função feita a parte
}

int Fila::enfileirar(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria){ //idem ao acima
    //return suporte.InserirNoFinal(_id, _nome, _idade, _especialidade, _salario, _carga_horaria);
    return InserirNoFinal(_id, _nome, _idade, _especialidade, _salario, _carga_horaria);
}

int Fila::desenfileirar(){ //O(n), se usar o código comentado. O(1), do jeito que está
    //return suporte.RemoverPrimeiroF();
    return RemoverPrimeiroF();
}

void Fila::consultarInicio() const{ //O(1)  //Imprime o primeiro elemento da fila
    if(suporte.getOcupadas() == 0)
        cout << "Fila vazia!\n\n";
    else
        suporte.getVetor(ini)->imprimirInfo();
}

bool Fila::filaCheia(){ //O(1)   //verifica se a lista está cheia
    if(suporte.getOcupadas() == suporte.getTam()) return 1;
    return 0;
}

bool Fila::filaVazia(){ //O(1)   //verifica se a lista está vazia
    if(suporte.getOcupadas() == 0) return 1;
    return 0;
}
/* //esses métodos enchem e esvaziam a fila. Num sabia o que era o filacheia/vazia. Tinha imaginado que fosse isso (;-;)
void Fila::filaCheia(){ //O(n)
    for(int i = suporte.getTam()-suporte.getOcupadas(); i > 0; i--)
        suporte.InserirNoFinal(i, "generico", i);
}

void Fila::filaVazia(){ //O(n)
    int temp = suporte.getOcupadas();
    while(temp>0){
        suporte.RemoverUltimo();
        temp--;
    }
}
*/
