#include "Elemento.h"
#include <iostream>

Elemento::Elemento(int _id) //O(1)  //construtor de elemento. Só inicia ID e é o único meio que eu permite para "manipular" essa variável
{
    ID = _id;
}

Elemento::~Elemento() //O(1)  //vou usar o destrutor padrão
{
}

int Elemento::getID() const{return ID;} //O(1)  //O get solicitado no enunciado

humano::humano(int _id, string _nome, int _idade):Elemento(_id){ //O(1)  //construtor da classe humano. Também usei o destrutor padrão, mas dessa vez deixei a declaração dele como inline no .h
    nome = _nome;
    idade = _idade;
}

void humano::imprimirInfo() const{ //O(1)  //Dá forma ao método virtual imprimirInfo, da classe Elemento
    cout << "\nID: " << getID() << "\nNome: " << getNome() << "\nIdade: " << getIdade() << "\n\n";
}

int humano::getIdade() const{return idade;} //O(1)  //get para a idade
string humano::getNome() const{return nome;} //O(1)  //get para o nome

professor::professor(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria):humano(_id, _nome, _idade){ //O(1)  //construtor da classe professor.
    //essa classe herda de humano e por isso usei uma lista de inicialização no final do cabeçalho para iniciar o id, o nome e a idade
    carga_horaria = _carga_horaria;
    salario = _salario;
    especialidade = _especialidade;
}

void professor::imprimirInfo() const{ //O(1)  //Forma do imprimirInfo apropriada a classe professor
    cout << "\nID: " << getID() << "\nNome: " << getNome() << "\nIdade: " << getIdade() << "\nEspecialidade: " << especialidade << "\nSalario: " << salario << "\nCarga horaria: " << carga_horaria << "\n\n";
}
