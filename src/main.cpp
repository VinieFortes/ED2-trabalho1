#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <time.h>

#include "../include/Review.h"

using namespace std;

int menu();
void repeticaoMenu();
void selecionaChave(int chave);
bool verificaBinario(string nome);

/* Vetores da classe vector para representar as reviews dos usuarios (dataReview) */
vector<Review> dataReview;

/* Arquivo de saida */
ofstream arqSaida;

/* String que representa o caminho da pasta com os arquivos .csv */
string pathCsv;


int main(int argc, char* argv[])
{
    srand(time(NULL));

    cout << "Trabalho de ED II (Parte 1)" << endl;
    cout << "Leitura Iniciada!" << endl
        << endl;

    // Verifica se foi passado o caminho da pasta onde possui os arquivos .csv.
    // Caso nao tenha, considera vazio.
    if (argv[1])
    {
        pathCsv = argv[1];
        //pathCsv = pathCsv + "/";
    }
    else
    {
        pathCsv = "";
    }

    dataReview = Review::readCsv(pathCsv);    
    Review::writeBinary(dataReview.data(), dataReview.size());

    repeticaoMenu();

    return 0;
}


bool verificaBinario(string nome)
{
    string path = "./bin/" + nome;
    fstream arq(path);
    if (arq.is_open())
    {
        arq.close();
        return true;
    }
    return false;
}


void repeticaoMenu()
{
    int chave = -1;

    while (chave != 0)
    {
        chave = menu();

        if (chave >= 0 && chave <= 5)
        {
            selecionaChave(chave);
        }
    }

    cout << "Finalizando a execucao..." << endl;
    return;
}


int menu()
{
    int opcao;

    cout << endl
        << "| --------------------------- Testes de Importacao ---------------------------- |" << endl;

menu:
    cout << "(1) - Operacoes de N = 10 registros de reviews com impressao na tela" << endl
        << "(2) - Operacoes de N = 100 registros de reviews com impressao em arquivo txt" << endl
        << "(3) - Operacoes de N = 25 registros de reviews com impressao na tela" << endl
        << "(4) - Operacoes de N = 1000 registros de reviews com impressao em arquivo txt" << endl
        << "(5) - Acessa um registro especifico i definido pelo usuário" << endl
        << "(0) - Sair" << endl;
    cout << "Opcao: ";
    cin >> opcao;
    cout << endl;

    // Caso o usuario digita um numero diferente do que e mostrado na tela, imprime novamente o menu.
    if (opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 5 && opcao != 0)
    {
        cout << "Por favor, digite um numero entre as opcoes mostradas." << endl;
        goto menu;
    }

    return opcao;
}


void selecionaChave(int chave)
{
    Review* data;
    switch (chave)
    {
    case 1:
        data = Review::readBinaryN(10);
        for (int i = 0; i < 10; i++)
        {
            cout << "linha: " << i + 1 << endl;
            data[i].printElement();
        }
        break;
    case 2:
        data = Review::readBinaryN(100);

        Review::writeElementTxt(data, 100);
        break;
    case 3:
        data = Review::readBinaryN(25);
        for (int i = 0; i < 25; i++)
        {
            cout << "linha: " << i + 1 << endl;
            data[i].printElement();
        }
        break;
    case 4:
        data = Review::readBinaryN(1000);

        Review::writeElementTxt(data, 1000);
        break;
    case 5:
        cout << "Qual o numero de registro deseja acessar?" << endl;
        
        int accessI;
        cin >> accessI;

        data = Review::accessBinaryI(accessI);

        cout << "Registro: " << accessI << endl;
        data->printElement();
        break;
    default:
        break;
    }
}
