//Exercicio3Funcoes_Feriadao.cpp
//Karl Michel Koerich

#include "biblaureano.h"

int iRetornaMaior (int iValor1, int iValor2);

int main()
{
    int iValor1 = readInt ("Valor 1: ");
    int iValor2 = readInt ("Valor 2: ");
    while (iValor1 == iValor2)
    {
        iValor1 = readInt ("Valor 1: ");
        iValor2 = readInt ("Valor 2: ");
    }

    int iResposta = iRetornaMaior(iValor1, iValor2);
    cout << iResposta;
}

int iRetornaMaior (int iValor1, int iValor2)
{
    if (iValor1 > iValor2)
    {
        return iValor1;
    }
    else if (iValor2 > iValor1)
    {
        return iValor2;
    }
}
