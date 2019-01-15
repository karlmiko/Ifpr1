//Escrever um programa que leia 20 números double para um vetor e calcule a média dos valores digitados.

#include "biblaureano.h"

int main()
{
    double dbVetor[20];

    int iPosicoesNoVetor = 0;
    double dbTotal;

    while (iPosicoesNoVetor < 20)
    {
        dbVetor[iPosicoesNoVetor] = readDouble ("Double: ");
        dbTotal = dbTotal + dbVetor[iPosicoesNoVetor];
        iPosicoesNoVetor++;
        limparTela();
    }

    cout << dbTotal / 20;
}
