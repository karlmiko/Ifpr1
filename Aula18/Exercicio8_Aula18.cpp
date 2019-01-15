//8. Faça um programa que leia dois vetores de caracteres, com 10 elementos cada, e intercale em um terceiro vetor.
//Imprima o vetor resultante.

#include "biblaureano.h"


int main()
{
    char cCadeia1 [10];
    int iColocandoDentro = 0;

    while (iColocandoDentro < 10)
    {
        cCadeia1[iColocandoDentro] = readChar ("Letras da 1a Cadeia: ");
        limparTela();
        iColocandoDentro++;
    }

    char cCadeia2 [10];
    iColocandoDentro = 0;

    while (iColocandoDentro < 10)
    {
        cCadeia2[iColocandoDentro] = readChar ("Letras da 2a Cadeia: ");
        limparTela();
        iColocandoDentro++;
    }

    iColocandoDentro = 0;
    string stCadeiaTotal;

    while (iColocandoDentro < 10)
    {

        int iSobra = iColocandoDentro % 2;

        if (iSobra == 0)
        {
            stCadeiaTotal = stCadeiaTotal + cCadeia1[iColocandoDentro];
            iColocandoDentro++;
        }
        else
        {
            stCadeiaTotal = stCadeiaTotal + cCadeia2 [iColocandoDentro];
            iColocandoDentro++;
        }
    }

    cout << stCadeiaTotal;
}
