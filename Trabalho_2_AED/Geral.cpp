#include <iostream>
#include <string>
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

//função para receber todos os dados necessários para um objeto da classe humano
void dados_humano(int& _id, string& _nome, int& _idade){
    cout << "Informe o identificador (ID):\n->";
    cin >> _id;
    cout << "Informe o nome:\n->";
    cin.ignore();
    getline(cin, _nome);
    cout << "Informe a idade:\n->";
    cin >> _idade;
}
//idem para classe professor
void dados_professor(int& _id, string& _nome, int& _idade, string& _especialidade, float& _salario, int& _carga_horaria){
    dados_humano(_id, _nome, _idade);
    cout << "Informe a especialidade\n->";
    cin.ignore();
    getline(cin, _especialidade);
    cout << "Informe o salario:\n->";
    cin >> _salario;
    cout << "Informe a carga horaria:\n->";
    cin >> _carga_horaria;
}

//gerencia o uso da lista não ordenada. é um menu, semelhante aos tantos que fizemos ao longo do semestre. E todas as outras funções aqui são análogas a essa
void glista(int tam){
    ListaNaoOrdenada l1(tam);
    int escolha;

    int _id, _idade, _carga_horaria, id_velho;
    float _salario;
    string _nome, _especialidade;

    cout << "Escolha uma operacao:\nInserir no inicio (1)\nInserir no final (2)\nRemover o primeiro elemento (3)\n"
    "Remover o ultimo elemento (4)\nRemover um dado ID (5)\nBuscar por um ID (6)\nAlterar pelo ID (7)\nImprimir lista (8)\nEncerrar (qualquer outro valor)\n->";
    cin >> escolha;
    while(escolha >= 1 && escolha <= 8){
        switch(escolha){
        case 1:
            cout << "Deseja adicionar um elemento de tipo humano (1) ou tipo professor (2)\n->";
            cin >> tam;
            while(tam != 1 && tam != 2){
                cout << "Insira uma opcao valida\n->";
                cin >> tam;
            }

            if(tam == 1){
                dados_humano(_id, _nome, _idade);
                l1.InserirNoInicio(_id, _nome, _idade);
            }
            else{
                dados_professor(_id, _nome, _idade, _especialidade, _salario, _carga_horaria);
                l1.InserirNoInicio(_id, _nome, _idade, _especialidade, _salario, _carga_horaria);
            }
            break;
        case 2:
            cout << "Deseja adicionar um elemento de tipo humano (1) ou tipo professor (2)\n->";
            cin >> tam;
            while(tam != 1 && tam != 2){
                cout << "Insira uma opcao valida\n->";
                cin >> tam;
            }

            if(tam == 1){
                dados_humano(_id, _nome, _idade);
                l1.InserirNoFinal(_id, _nome, _idade);
            }
            else{
                dados_professor(_id, _nome, _idade, _especialidade, _salario, _carga_horaria);
                l1.InserirNoFinal(_id, _nome, _idade, _especialidade, _salario, _carga_horaria);
            }
            break;
        case 3:
            l1.RemoverPrimeiro();
            break;
        case 4:
            l1.RemoverUltimo();
            break;
        case 5:
            cout << "Qual ID voce deseja remover\n->";
            cin >> _id;
            l1.RemoverPeloID(_id);
            break;
        case 6:
            cout << "Qual ID deseja buscar\n->";
            cin >> _id;
            l1.BuscarPeloID(_id);
            break;
        case 7:
            cout << "Qual ID deseja alterar?\n->";
            cin >> id_velho;
            cout << "deseja alterar as informacoes para armazenar um elemento de tipo humano (1) ou professor (2)?\n->";
            cin >> tam;
            while(tam != 1 && tam != 2){
                cout << "Insira uma opcao valida\n->";
                cin >> tam;
            }

            if(tam == 1){
                dados_humano(_id, _nome, _idade);
                l1.AlterarPeloID(id_velho, _id, _nome, _idade);
            }
            else{
                dados_professor(_id, _nome, _idade, _especialidade, _salario, _carga_horaria);
                l1.AlterarPeloID(id_velho, _id, _nome, _idade, _especialidade, _salario, _carga_horaria);
            }
            break;
        case 8:
            l1.ImprimirLista();
            break;
        }
        cout << "\nDeseja realizar mais alguma operacao?\n";
        cout << "Inserir no inicio (1)\nInserir no final (2)\nRemover o primeiro elemento (3)\n"
    "Remover o ultimo elemento (4)\nRemover um dado ID (5)\nBuscar por um ID (6)\nAlterar pelo ID (7)\nImprimir lista (8)\nEncerrar (qualquer outro valor)\n->";
        cin >> escolha;
    }
    cout << "Encerrando...\n\n";
}

void glistaord(int tam){
    ListaOrdenadaID l1(tam);
    int escolha;

    int _id, _idade, _carga_horaria, id_velho;
    float _salario;
    string _nome, _especialidade;

    cout << "Escolha uma operacao:\nInserir elemento (1)\nRemover o primeiro elemento (2)\n"
    "Remover o ultimo elemento (3)\nRemover um dado ID (4)\nBuscar por um ID (5)\nAlterar pelo ID (6)\nImprimir lista (7)\nEncerrar (qualquer outro valor)\n->";
    cin >> escolha;
    while(escolha >= 1 && escolha <= 7){
        switch(escolha){
        case 1:
            cout << "Deseja adicionar um elemento de tipo humano (1) ou tipo professor (2)\n->";
            cin >> tam;
            while(tam != 1 && tam != 2){
                cout << "Insira uma opcao valida\n->";
                cin >> tam;
            }

            if(tam == 1){
                dados_humano(_id, _nome, _idade);
                l1.InserirOrdenadamente(_id, _nome, _idade);
            }
            else{
                dados_professor(_id, _nome, _idade, _especialidade, _salario, _carga_horaria);
                l1.InserirOrdenadamente(_id, _nome, _idade, _especialidade, _salario, _carga_horaria);
            }
            break;
        case 2:
            l1.RemoverPrimeiro();
            break;
        case 3:
            l1.RemoverUltimo();
            break;
        case 4:
            cout << "Qual ID deseja remover?\n->";
            cin >> _id;
            l1.RemoverPeloID(_id);
            break;
        case 5:
            cout << "Qual ID deseja buscar?\n->";
            cin >> _id;
            l1.BuscarPeloID(_id);
            break;
        case 6:
            cout << "Qual ID deseja alterar?\n->";
            cin >> id_velho;
            cout << "deseja alterar as informacoes para armazenar um elemento de tipo humano (1) ou professor (2)?\n->";
            cin >> tam;
            while(tam != 1 && tam != 2){
                cout << "Insira uma opcao valida\n->";
                cin >> tam;
            }

            if(tam == 1){
                dados_humano(_id, _nome, _idade);
                l1.AlterarPeloID(id_velho, _id, _nome, _idade);
            }
            else{
                dados_professor(_id, _nome, _idade, _especialidade, _salario, _carga_horaria);
                l1.AlterarPeloID(id_velho, _id, _nome, _idade, _especialidade, _salario, _carga_horaria);
            }
            break;
        case 7:
            l1.ImprimirLista();
            break;
        }
        cout << "\nDeseja realizar mais alguma operacao?\n";
        cout << "Inserir elemento (1)\nRemover o primeiro elemento (2)\n"
    "Remover o ultimo elemento (3)\nRemover um dado ID (4)\nBuscar por um ID (5)\nAlterar pelo ID (6)\nImprimir lista (7)\nEncerrar (qualquer outro valor)\n->";
        cin >> escolha;
    }
    cout << "Encerrando...\n\n";
}


void gpilha(int tam){
    Pilha l1(tam);
    int escolha;

    int _id, _idade, _carga_horaria;
    float _salario;
    string _nome, _especialidade;

    cout << "Escolha uma operacao:\nEmpilhar elemento (1)\nDesempilhar elemento (2)\n"
    "Olhar o topo (3)\nPilha cheia (4)\nPilha vazia (5)\nEncerrar (qualquer outro valor)\n->";
    cin >> escolha;
    while(escolha >= 1 && escolha <= 5){
        switch(escolha){
        case 1:
            cout << "Deseja adicionar um elemento de tipo humano (1) ou tipo professor (2)\n->";
            cin >> tam;
            while(tam != 1 && tam != 2){
                cout << "Insira uma opcao valida\n->";
                cin >> tam;
            }

            if(tam == 1){
                dados_humano(_id, _nome, _idade);
                l1.empilhar(_id, _nome, _idade);
            }
            else{
                dados_professor(_id, _nome, _idade, _especialidade, _salario, _carga_horaria);
                l1.empilhar(_id, _nome, _idade, _especialidade, _salario, _carga_horaria);
            }
            break;
        case 2:
            l1.desempilhar();
            break;
        case 3:
            l1.consultarTopo();
            break;
        case 4:
            if(l1.pilhaCheia()){
                cout << "Esta cheia\n\n";
                break;
            }
            cout << "Nao esta cheia\n\n";
            break;
        case 5:
            if(l1.pilhaVazia()){
                cout << "Esta vazia\n\n";
                break;
            }
            cout << "Nao esta vazia\n\n";
            break;
        }
        cout << "\nDeseja realizar mais alguma operacao?\n";
        cout << "Empilhar elemento (1)\nDesempilhar elemento (2)\n"
    "Olhar o topo (3)\nPilha cheia (4)\nPilha vazia (5)\nEncerrar (qualquer outro valor)\n->";
        cin >> escolha;
    }
    cout << "Encerrando...\n\n";
}


void gfila(int tam){
    Fila l1(tam);
    int escolha;

    int _id, _idade, _carga_horaria;
    float _salario;
    string _nome, _especialidade;

    cout << "Escolha uma operacao:\nEnfileirar elemento (1)\nDesenfileirar elemento (2)\n"
    "Olhar o inicio (3)\nFila cheia (4)\nFila vazia (5)\nEncerrar (qualquer outro valor)\n->";
    cin >> escolha;
    while(escolha >= 1 && escolha <= 5){
        switch(escolha){
        case 1:
            cout << "Deseja adicionar um elemento de tipo humano (1) ou tipo professor (2)\n->";
            cin >> tam;
            while(tam != 1 && tam != 2){
                cout << "Insira uma opcao valida\n->";
                cin >> tam;
            }

            if(tam == 1){
                dados_humano(_id, _nome, _idade);
                l1.enfileirar(_id, _nome, _idade);
            }
            else{
                dados_professor(_id, _nome, _idade, _especialidade, _salario, _carga_horaria);
                l1.enfileirar(_id, _nome, _idade, _especialidade, _salario, _carga_horaria);
            }
            break;
        case 2:
            l1.desenfileirar();
            break;
        case 3:
            l1.consultarInicio();
            break;
        case 4:
            if(l1.filaCheia()){
                cout << "Esta cheia\n\n";
                break;
            }
            cout << "Nao esta cheia\n\n";
            break;
        case 5:
            if(l1.filaVazia()){
                cout << "Esta vazia\n\n";
                break;
            }
            cout << "Nao esta vazia\n\n";
            break;
        }
        cout << "\nDeseja realizar mais alguma operacao?\n";
        cout << "Enfileirar elemento (1)\nDesenfileirar elemento (2)\n"
    "Olhar o inicio (3)\nFila cheia (4)\nFila vazia (5)\nEncerrar (qualquer outro valor)\n->";
        cin >> escolha;
    }
    cout << "Encerrando...\n\n";
}

void glistaSimples(){
    ListaSimplesmenteEncadeada l1;
    int escolha;

    int _id, id_velho;

    cout << "Escolha uma operacao:\nInserir no inicio (1)\nInserir no final (2)\nRemover o primeiro elemento (3)\n"
    "Remover o ultimo elemento (4)\nRemover um dado ID (5)\nBuscar por um ID (6)\nAlterar pelo ID (7)\nImprimir lista (8)\nEncerrar (qualquer outro valor)\n->";
    cin >> escolha;
    while(escolha >= 1 && escolha <= 8){
        switch(escolha){
        case 1:
            cout << "Informe o ID a ser inserido\n->";
            cin >> _id;
            l1.inserirNoInicio(_id);
            break;
        case 2:
            cout << "Informe o ID a ser inserido\n->";
            cin >> _id;
            l1.inserirNoFim(_id);
            break;
        case 3:
            l1.removerPrimeiro();
            break;
        case 4:
            l1.removerUltimo();
            break;
        case 5:
            cout << "Qual ID voce deseja remover\n->";
            cin >> _id;
            l1.removerPeloID(_id);
            break;
        case 6:
            cout << "Qual ID deseja buscar\n->";
            cin >> _id;
            l1.buscarPeloID(_id);
            break;
        case 7:
            cout << "Qual ID deseja alterar?\n->";
            cin >> id_velho;
            cout << "Qual sera o novo ID?\n->";
            cin >> _id;
            l1.alterarPeloID(id_velho, _id);
            break;
        case 8:
            l1.imprimirLista();
            break;
        }
        cout << "\nDeseja realizar mais alguma operacao\n";
        cout << "Inserir no inicio (1)\nInserir no final (2)\nRemover o primeiro elemento (3)\n"
    "Remover o ultimo elemento (4)\nRemover um dado ID (5)\nBuscar por um ID (6)\nAlterar pelo ID (7)\nImprimir lista (8)\nEncerrar (qualquer outro valor)\n->";
        cin >> escolha;
    }
    cout << "Encerrando...\n\n";
}

void glistaDuplamente(){
    ListaDuplamenteEncadeada l1;
    int escolha;

    int _id, id_velho;

    cout << "Escolha uma operacao:\nInserir no inicio (1)\nInserir no final (2)\nRemover o primeiro elemento (3)\n"
    "Remover o ultimo elemento (4)\nRemover um dado ID (5)\nBuscar por um ID (6)\nAlterar pelo ID (7)\nImprimir lista (8)\nEncerrar (qualquer outro valor)\n->";
    cin >> escolha;
    while(escolha >= 1 && escolha <= 8){
        switch(escolha){
        case 1:
            cout << "Informe o ID a ser inserido\n->";
            cin >> _id;
            l1.inserirNoInicio(_id);
            break;
        case 2:
            cout << "Informe o ID a ser inserido\n->";
            cin >> _id;
            l1.inserirNoFim(_id);
            break;
        case 3:
            l1.removerPrimeiro();
            break;
        case 4:
            l1.removerUltimo();
            break;
        case 5:
            cout << "Qual ID voce deseja remover\n->";
            cin >> _id;
            l1.removerPeloID(_id);
            break;
        case 6:
            cout << "Qual ID deseja buscar\n->";
            cin >> _id;
            l1.buscarPeloID(_id);
            break;
        case 7:
            cout << "Qual ID deseja alterar?\n->";
            cin >> id_velho;
            cout << "Qual sera o novo ID?\n->";
            cin >> _id;
            l1.alterarPeloID(id_velho, _id);
            break;
        case 8:
            l1.imprimirLista();
            break;
        }
        cout << "\nDeseja realizar mais alguma operacao?\n";
        cout << "Inserir no inicio (1)\nInserir no final (2)\nRemover o primeiro elemento (3)\n"
    "Remover o ultimo elemento (4)\nRemover um dado ID (5)\nBuscar por um ID (6)\nAlterar pelo ID (7)\nImprimir lista (8)\nEncerrar (qualquer outro valor)\n->";
        cin >> escolha;
    }
    cout << "Encerrando...\n\n";
}

void glistaCircular(){
    ListaDuplamenteEncadeadaCircular l1;
    int escolha;

    int _id, id_velho;

    cout << "Escolha uma operacao:\nInserir no inicio (1)\nInserir no final (2)\nRemover o primeiro elemento (3)\n"
    "Remover o ultimo elemento (4)\nRemover um dado ID (5)\nBuscar por um ID (6)\nAlterar pelo ID (7)\nImprimir lista (sentido ->) (8)\nImprimir lista (sentido <-) (9)\nEncerrar (qualquer outro valor)\n->";
    cin >> escolha;
    while(escolha >= 1 && escolha <= 9){
        switch(escolha){
        case 1:
            cout << "Informe o ID a ser inserido\n->";
            cin >> _id;
            l1.inserirNoInicio(_id);
            break;
        case 2:
            cout << "Informe o ID a ser inserido\n->";
            cin >> _id;
            l1.inserirNoFim(_id);
            break;
        case 3:
            l1.removerPrimeiro();
            break;
        case 4:
            l1.removerUltimo();
            break;
        case 5:
            cout << "Qual ID voce deseja remover\n->";
            cin >> _id;
            l1.removerPeloID(_id);
            break;
        case 6:
            cout << "Qual ID deseja buscar\n->";
            cin >> _id;
            l1.buscarPeloID(_id);
            break;
        case 7:
            cout << "Qual ID deseja alterar?\n->";
            cin >> id_velho;
            cout << "Qual sera o novo ID?\n->";
            cin >> _id;
            l1.alterarPeloID(id_velho, _id);
            break;
        case 8:
            l1.imprimirSentidoDireito();
            break;
        case 9:
            l1.imprimirSentidoEsquerdo();
            break;
        }
        cout << "\nDeseja realizar mais alguma operacao?\n";
        cout << "Inserir no inicio (1)\nInserir no final (2)\nRemover o primeiro elemento (3)\n"
    "Remover o ultimo elemento (4)\nRemover um dado ID (5)\nBuscar por um ID (6)\nAlterar pelo ID (7)\nImprimir lista (sentido ->) (8)\nImprimir lista (sentido <-) (9)\nEncerrar (qualquer outro valor)\n->";
        cin >> escolha;
    }
    cout << "Encerrando...\n\n";
}


void gpilhaEncadeada(){
    PilhaEncadeada l1;
    int escolha, id;

    cout << "Escolha uma operacao:\nEmpilhar elemento (1)\nDesempilhar elemento (2)\n"
    "Olhar o topo (3)\nPilha vazia (4)\nEncerrar (qualquer outro valor)\n->";
    cin >> escolha;
    while(escolha >= 1 && escolha <= 4){
        switch(escolha){
        case 1:
            cout << "Informe o ID que deseja inserir\n->";
            cin >> id;
            l1.empilhar(id);
            break;
        case 2:
            l1.desempilhar();
            break;
        case 3:
            l1.consultarTopo();
            break;
        case 4:
            if(l1.pilhaVazia()){
                cout << "Esta vazia\n\n";
                break;
            }
            cout << "Nao esta vazia\n\n";
            break;
        }
        cout << "\nDeseja realizar mais alguma operacao?\n";
        cout << "Empilhar elemento (1)\nDesempilhar elemento (2)\n"
    "Olhar o topo (3)\nPilha vazia (4)\nEncerrar (qualquer outro valor)\n->";
        cin >> escolha;
    }
    cout << "Encerrando...\n\n";
}

void gfilaEncadeada(){
    FilaEncadeada l1;
    int escolha, id;

    cout << "Escolha uma operacao:\nEnfileirar elemento (1)\nDesenfileirar elemento (2)\n"
    "Olhar o topo (3)\nFila vazia (4)\nEncerrar (qualquer outro valor)\n->";
    cin >> escolha;
    while(escolha >= 1 && escolha <= 4){
        switch(escolha){
        case 1:
            cout << "Informe o ID que deseja inserir\n->";
            cin >> id;
            l1.enfileirar(id);
            break;
        case 2:
            l1.desenfileirar();
            break;
        case 3:
            l1.consultarFrente();
            break;
        case 4:
            if(l1.filaVazia()){
                cout << "Esta vazia\n\n";
                break;
            }
            cout << "Nao esta vazia\n\n";
            break;
        }
        cout << "\nDeseja realizar mais alguma operacao?\n";
        cout << "Enfileirar elemento (1)\nDesenfileirar elemento (2)\n"
    "Olhar o topo (3)\nFila vazia (4)\nEncerrar (qualquer outro valor)\n->";
        cin >> escolha;
    }
    cout << "Encerrando...\n\n";
}

void gArvore(){
    ArvoreBinariaBusca l1;
    int escolha, id;
    cout << "Escolha uma operacao:\nInserir elemento (1)\nRemover elemento (2)\n"
    "Buscar elemento (3)\nPercurso em pre-ordem (4)\nPercurso em pos-ordem (5)\nPercurso em ordem (6)\nEncerrar (qualquer outro valor)\n->";
    cin >> escolha;
    while(escolha >= 1 && escolha <= 6){
        switch(escolha){
        case 1:
            cout << "Informe o ID que deseja inserir\n->";
            cin >> id;
            l1.Inserir(id);
            break;
        case 2:
            cout << "Informe o ID que deseja remover\n->";
            cin >> id;
            l1.RemoverPeloId(id);
            break;
        case 3:
            cout << "Informe o elemento que deseja buscar\n->";
            cin >> id;
            l1.BuscarPeloId(id);
            break;
        case 4:
            l1.preOrdem();
            break;
        case 5:
            l1.posOrdem();
            break;
        case 6:
            l1.emOrdem();
            break;
        }
        cout << "\nDeseja realizar mais alguma operacao?\n";
        cout << "Inserir elemento (1)\nRemover elemento (2)\n"
    "Buscar elemento (3)\nPercurso em pre-ordem (4)\nPercurso em pos-ordem (5)\nPercurso em ordem (6)\nEncerrar (qualquer outro valor)\n->";
        cin >> escolha;
    }
    cout << "Encerrando...\n\n";
}

void gGrafos(int tam){
    Grafos l1(tam);
    int escolha, vertice1, vertice2;
    cout << "Escolha uma operacao:\nAdicionar vertice (1)\nAdicionar aresta (2)\n"
    "Verificar vizinhos (3)\nDeterminar grau (4)\nBusca em profundidade (5)\nBusca em largura (6)\nEncerrar (qualquer outro valor)\n->";
    cin >> escolha;
    while(escolha >= 1 && escolha <= 6){
        switch(escolha){
        case 1:
            l1.AdicionarVertice();
            break;
        case 2:
            cout << "Ligando quais nos? ex: 1 3\n->";
            cin >> vertice1;
            cin >> vertice2;
            l1.AdicionarAresta(vertice1, vertice2);
            break;
        case 3:
            cout << "Informe os vertices cujo contato deseja verificar ex: 1 3\n->";
            cin >> vertice1;
            cin >> vertice2;
            if(l1.VerificarVizinho(vertice1, vertice2) == 1){
                cout << "Sao vizinhos\n\n";
            }
            else{
                cout << "Nao sao vizinhos";
            }
            break;
        case 4:
            cout << "Informe o vertice cujo grau deseja determinar\n->";
            cin >> vertice1;
            l1.Grau(vertice1);
            break;
        case 5:
            cout << "Informe o vertice inicial\n->";
            cin >> vertice1;
            l1.buscaEmProfundidade(vertice1);
            break;
        case 6:
            cout << "Informe o vertice inicial\n->";
            cin >> vertice1;
            l1.buscaEmLargura(vertice1);
            break;
        }
        cout << "\nDeseja realizar mais alguma operacao?\n";
        cout << "Adicionar vertice (1)\nAdicionar aresta (2)\n"
    "Verificar vizinhos (3)\nDeterminar grau (4)\nBusca em profundidade (5)\nBusca em largura (6)\nEncerrar (qualquer outro valor)\n->";
        cin >> escolha;
    }
    cout << "Encerrando...\n\n";

}
