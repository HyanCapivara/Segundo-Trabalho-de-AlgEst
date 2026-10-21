#ifndef GERAL_H
#define GERAL_H

#include <string>

using namespace std;

void dados_humano(int& _id, string& _nome, int& _idade);
void dados_professor(int& _id, string& _nome, int& _idade, string& _especialidade, float& _salario, int& _carga_horaria);
void glista(int tam);
void glistaord(int tam);
void gpilha(int tam);
void gfila(int tam);
void glistaSimples();
void glistaDuplamente();
void glistaCircular();
void gArvore();
void gGrafos(int tam0);

#endif // GERAL_H
