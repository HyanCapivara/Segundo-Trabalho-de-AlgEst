#include <iostream>
#include <string>
#include "ListaNaoOrdenada.h"
#include "ListaOrdenadaID.h"
#include "Pilha.h"
#include "Fila.h"

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

//função para receber todos os dados necessários para alterar um objeto da classe humano - o ID
void dados_humano_alterar(string& _nome, int& _idade){
    cout << "Informe o nome:\n->";
    cin.ignore();
    getline(cin, _nome);
    cout << "Informe a idade:\n->";
    cin >> _idade;
}
//idem para classe professor
void dados_professor_alterar(string& _nome, int& _idade, string& _especialidade, float& _salario, int& _carga_horaria){
    dados_humano_alterar(_nome, _idade);
    cout << "Informe a especialidade\n->";
    cin.ignore();
    getline(cin, _especialidade);
    cout << "Informe o salario:\n->";
    cin >> _salario;
    cout << "Informe a carga horaria:\n->";
    cin >> _carga_horaria;
}

//gerencia o uso da lista nao ordenada. é uum menu, semelhante aos tantos que fizemos ao longo do semestre
void glista(int tam){
    ListaNaoOrdenada l1(tam);
    int escolha;

    int _id, _idade, _carga_horaria;
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
            cin >> _id;
            cout << "deseja alterar as informacoes para armazenar um elemento de tipo humano (1) ou professor (2)?\n->";
            cin >> tam;
            while(tam != 1 && tam != 2){
                cout << "Insira uma opcao valida\n->";
                cin >> tam;
            }

            if(tam == 1){
                dados_humano_alterar(_nome, _idade);
                l1.AlterarPeloID(_id, _nome, _idade);
            }
            else{
                dados_professor_alterar(_nome, _idade, _especialidade, _salario, _carga_horaria);
                l1.AlterarPeloID(_id, _nome, _idade, _especialidade, _salario, _carga_horaria);
            }
            break;
        case 8:
            l1.ImprimirLista();
            break;
        }
        cout << "\nDeseja realizar mais alguma operacao\n->";
        cin >> escolha;
    }
    cout << "Encerrando...";
}

void glistaord(int tam){
    ListaOrdenadaID l1(tam);
    int escolha;

    int _id, _idade, _carga_horaria;
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
            cin >> _id;
            cout << "deseja alterar as informacoes para armazenar um elemento de tipo humano (1) ou professor (2)?\n->";
            cin >> tam;
            while(tam != 1 && tam != 2){
                cout << "Insira uma opcao valida\n->";
                cin >> tam;
            }

            if(tam == 1){
                dados_humano_alterar(_nome, _idade);
                l1.AlterarPeloID(_id, _nome, _idade);
            }
            else{
                dados_professor_alterar(_nome, _idade, _especialidade, _salario, _carga_horaria);
                l1.AlterarPeloID(_id, _nome, _idade, _especialidade, _salario, _carga_horaria);
            }
            break;
        case 7:
            l1.ImprimirLista();
            break;
        }
        cout << "\nDeseja realizar mais alguma operacao\n->";
        cin >> escolha;
    }
    cout << "Encerrando...";
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
            l1.pilhaCheia();
            break;
        case 5:
            l1.pilhaVazia();
            break;
        }
        cout << "\nDeseja realizar mais alguma operacao\n->";
        cin >> escolha;
    }
    cout << "Encerrando...";
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
            l1.filaCheia();
            break;
        case 5:
            l1.filaVazia();
            break;
        }
        cout << "\nDeseja realizar mais alguma operacao\n->";
        cin >> escolha;
    }
    cout << "Encerrando...";
}

