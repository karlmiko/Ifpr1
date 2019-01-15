//Exercicio5Funcoes_Feriadao.cpp
//Karl Michel Koerich

#include "biblaureano.h"

int iExponencial (int iNumero, int iExpoente);

int main()
{
    int iNumero = readInt ("Número: ");
    int iExpoente = readInt ("Expoente: ");
    cout << iExponencial (iNumero, iExpoente);
}

int iExponencial (int iNumero, int iExpoente)
{
    int iNumeroDeMultiplicacoes = 1;
    int iResultado = 1;

    while (iNumeroDeMultiplicacoes <= iExpoente)
    {
        iResultado = iResultado * iNumero;
        iNumeroDeMultiplicacoes++;
    }

    return iResultado;
}

