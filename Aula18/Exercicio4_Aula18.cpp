//Exercicio4_Aula18.cpp
//Karl Michel Koerich

#include "biblaureano.h"

int main()
{
    char cVetor[50];
    int iPreenchendo = 0;

    while (iPreenchendo < 50)
    {
        cVetor[iPreenchendo] = readChar ("Caracter: ");
        iPreenchendo++;
    }

    while (iPreenchendo >= 0)
    {
        cout << cVetor[iPreenchendo];
        iPreenchendo--;
    }
}
