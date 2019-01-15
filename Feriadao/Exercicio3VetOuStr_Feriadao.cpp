//Exercicio3VetOuStr_Feriadao.cpp


//3. Maior e menor - Escrever um programa que preencha um vetor de 100 elementos com valores inteiros aleatórios,
//e identifique o maior e o menor número gerados, e respectivas posições.

#include "biblaureano.h"

int main()
{
    int iNumeroAleatorio;
    int iCemValores [100];
    int iEspacos = 0;
    int iValorMaior = 0;
    int iValorMenor = 100;
    int iEspacoValorMaior;
    int iEspacoValorMenor;

    while (iEspacos <= 100)
    {
        iNumeroAleatorio = randomico(1,100);
        iCemValores [iEspacos] = iNumeroAleatorio;

        if (iNumeroAleatorio > iValorMaior)
        {
            iValorMaior = iNumeroAleatorio;
            iEspacoValorMaior = iEspacos;
        }
        if (iNumeroAleatorio < iValorMenor)
        {
            iValorMenor = iNumeroAleatorio;
            iEspacoValorMenor = iEspacos;
        }

        iEspacos++;
    }

    cout << "O maior valor randomico é " << iValorMaior << " e está na posição " << iEspacoValorMaior << endl;
    cout << "O menor valor randomico é " << iValorMenor << " e está na posição " << iEspacoValorMenor << endl;
}
