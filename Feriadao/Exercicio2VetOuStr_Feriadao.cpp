// 4 Vetores ou strings - use a imaginação

// 2. Média - Escrever um programa que leia até 20 números inteiros para um vetor e calcule a média dos valores.

#include "biblaureano.h"

int main()
{
    int iNumerosInteiros [20];
    int iEspacos = 0;
    char cColocarValorSN = 's';
    int iNumeroLido;
    int iTotal = 0;

    while (cColocarValorSN == 's')
    {
        iNumeroLido = readInt ("Numero inteiro: ");
        iTotal = iTotal + iNumeroLido;
        iNumerosInteiros[iEspacos] = iNumeroLido;
        iEspacos++;
        cColocarValorSN = readChar ("Deseja colocar outro inteiro? (s/n) ");
    }

    iTotal = iTotal / iEspacos;
    cout << "A média dos números é " << iTotal;
}
