#include <iostream>
#include <string>

#include "Geral.h" //tem uns menus
//listas de alocação sequencial e derivados
#include "ListaNaoOrdenada.h"
#include "ListaOrdenadaID.h"
#include "Pilha.h"
#include "Fila.h"
//listas de alocação dinâmica e derivados
#include "ListaSimplesmenteEncadeada.h"
#include "ListaDuplamenteEncadeada.h"
#include "ListaDuplamenteEncadeadaCircular.h"
#include "PilhaEncadeada.h"
#include "FilaEncadeada.h"
#include "ArvoreBinariaBusca.h"
#include "Grafos.h"

using namespace std;

int main(){
    int escolha, tam;

    cout << "Gostaria de testar as Listas nao ordenadas? (sim = 1, nao = ~1)\n->";
    cin >> escolha;
    if(escolha == 1){
        cout << "Qual tamanho deseja para a lista?\n->";
        cin >> tam;
        while(tam < 0){
            cout << "Favor informe um numero positivo\n->";
            cin >> tam;
        }
        glista(tam);
    }

    cout << "Gostaria de testar as Listas ordenadas? (sim = 1, nao = ~1)\n->";
    cin >> escolha;
    if(escolha == 1){
        cout << "Qual tamanho deseja para a lista?\n->";
        cin >> tam;
        while(tam < 0){
            cout << "Favor informe um numero positivo\n->";
            cin >> tam;
        }
        glistaord(tam);
    }

    cout << "Gostaria de testar as pilhas? (sim = 1, nao = ~1)\n->";
    cin >> escolha;
    if(escolha == 1){
        cout << "Qual tamanho deseja para a pilha?\n->";
        cin >> tam;
        while(tam < 0){
            cout << "Favor informe um numero positivo\n->";
            cin >> tam;
        }
        gpilha(tam);
    }

    cout << "Gostaria de testar as filas? (sim = 1, nao = ~1)\n->";
    cin >> escolha;
    if(escolha == 1){
        cout << "Qual tamanho deseja para a fila?\n->";
        cin >> tam;
        while(tam < 0){
            cout << "Favor informe um numero positivo\n->";
            cin >> tam;
        }
        gfila(tam);
    }

    cout << "Gostaria de testar as Listas simplesmente encadeadas? (sim = 1, nao = ~1)\n->";
    cin >> escolha;
    if(escolha == 1)
        glistaSimples();

    cout << "Gostaria de testar as Listas duplamente encadeadas? (sim = 1, nao = ~1)\n->";
    cin >> escolha;
    if(escolha == 1)
        glistaDuplamente();

    cout << "Gostaria de testar as Listas duplamente encadeadas circulares? (sim = 1, nao = ~1)\n->";
    cin >> escolha;
    if(escolha == 1)
        glistaCircular();

    cout << "Gostaria de testar as Arvores? (sim = 1, nao = ~1)\n->";
    cin >> escolha;
    if(escolha == 1)
        gArvore();

    cout << "Gostaria de testar os grafos? (sim = 1, nao = ~1)\n->";
    cin >> escolha;
    if(escolha == 1){
        cout << "Informe uma quantidade inicial de vertices\n->";
        cin >> tam;
        while(tam < 0){
            cout << "Favor informe um numero positivo\n->";
            cin >> tam;
        }
        gGrafos(tam);
    }



    return 0;
}
