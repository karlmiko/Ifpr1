//Exercicio4Funcoes_Feriadao.cpp
//Karl Michel Koerich

#include "biblaureano.h"

int iRetornaMaior (int iValor1, int iValor2, int iValor3);

int main()
{
    int iValor1 = readInt ("Valor 1: ");
    int iValor2 = readInt ("Valor 2: ");
    int iValor3 = readInt ("Valor 3: ");

    while (iValor1 == iValor2  && iValor1 == iValor3)
    {
        iValor1 = readInt ("Valor 1: ");
        iValor2 = readInt ("Valor 2: ");
        iValor3 = readInt ("Valor 3: ");
    }

    int iResposta = iRetornaMaior(iValor1, iValor2, iValor3);
    cout << iResposta;
}

int iRetornaMaior (int iValor1, int iValor2, int iValor3)
{
    if (iValor1 > iValor2 && iValor1 > iValor3)
    {
        return iValor1;
    }
    else if (iValor2 > iValor1 && iValor2 > iValor3)
    {
        return iValor2;
    }
    else if (iValor3 > iValor1 && iValor3 > iValor2)
    {
        return iValor3;
    }
}
