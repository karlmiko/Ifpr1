//18. Maior qualquer - Implementar uma função que recebe dois valores de qualquer tipo de dado (cadeia, número
//inteiro ou real, caractere) e retorna o maior.

#include "biblaureano.h"

string stVerificaMaior (string stCadeia1, string stCadeia2);

int main()
{
    string stCadeia1 = readString("Cadeia 1: ");
    string stCadeia2 = readString("Cadeia 2: ");

    cout << "A maior cadeia é " << stVerificaMaior(stCadeia1, stCadeia2);
}

string stVerificaMaior (string stCadeia1, string stCadeia2)
{
    int iTamanhoCadeia1 = stCadeia1.size();
    int iTamanhoCadeia2 = stCadeia2.size();

    if (iTamanhoCadeia1 > iTamanhoCadeia2)
    {
        return stCadeia1;
    }
    else if (iTamanhoCadeia1 < iTamanhoCadeia2)
    {
        return stCadeia2;
    }
    else if (iTamanhoCadeia1 == iTamanhoCadeia2)
    {
        string stIgualdade = "nenhuma delas, massa né!";
        return stIgualdade;
    }
}
