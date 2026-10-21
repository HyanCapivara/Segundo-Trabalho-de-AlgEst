#ifndef ELEMENTO_H
#define ELEMENTO_H

#include <string>

using namespace std;

class Elemento
{
    public:
        Elemento(int _id); //O(1)  //O único método para inserir ID's
        virtual ~Elemento(); //O(1)  //destrutor virtual já que vou usar um vetor com classes derivadas de elemento
        virtual void imprimirInfo() const = 0; //O(só o filho vai dizer)
        int getID() const;
    protected:
        int ID;
    private:
};

class humano:public Elemento{ //primeira classe que herda de Elemento
    public:
        humano(int _id, string _nome, int _idade); //O(1)
        ~humano(){} //usei definição inline //O(1)
        void imprimirInfo() const; //O(1)  //redefinição do método de impressão de elemento
        int getIdade() const; //O(1)
        string getNome() const; //O(1)
    private:
        string nome;
        int idade;
};

class professor:public humano{ //segunda classe que herda de Elemento. Também é filha de humano
    public:
        professor(int _id, string nome, int _idade, string _especialidade, float _salario, int _carga_horaria); //O(1)
        ~professor(){} //O(1)
        void imprimirInfo() const; //O(1)
    private:
        int carga_horaria;
        float salario;
        string especialidade;
};

#endif // ELEMENTO_H
