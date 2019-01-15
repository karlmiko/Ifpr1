//5. Soma em vetor 1 - Escrever um programa que, após preencher dois vetores com números inteiros aleatórios,
//soma os valores dos elementos correspondentes de dois vetores, armazenando o resultado num terceiro vetor.


#include "biblaureano.h"

int main()
{
    int iVetor1 [10];
    int iVetor2 [10];
    int iVetor3 [10];
    int iEspacos = 0;

    while (iEspacos < 10)
    {
        int iNumeroAleatorio = randomico(1,50);
        iVetor1 [iEspacos] = iNumeroAleatorio;
        iNumeroAleatorio = randomico(1,50);
        iVetor2 [iEspacos] = iNumeroAleatorio;
        iVetor3 [iEspacos] = iVetor1 [iEspacos] + iVetor2 [iEspacos];
        cout << iVetor3 [iEspacos] << endl;
        iEspacos++;
    }
}
