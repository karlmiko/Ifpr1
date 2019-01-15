/*Média ponderada - Escrever um programa que calcula médias ponderadas para uma quantidade de fatores de
até 15. O programa lê vários pares [número, peso] até que seja lido um número negativo. É calculada então a
média, somando-se os produtos de cada número por seu peso e dividindo-se o resultado pela soma dos pesos.*/

#include "biblaureano.h"

int main()
{
    int iQuinzeValores [15];
    int iEspacos15Valores = 0;
    int iNumeroLido, iPeso, iDivisao = 0, iTotal = 0;
    float iMediaPonderada;

    while (iEspacos15Valores <= 15)
    {
        iNumeroLido = readInt ("Número: ");
        if(iNumeroLido < 0)
        {
            break;
        }

        iPeso = readInt ("Peso do Número: ");

        iTotal = iTotal + (iNumeroLido * iPeso);

        iDivisao = iDivisao + iPeso;
    }

    iMediaPonderada = iTotal/iDivisao;
    cout << "A média ponderada dos números é " << iMediaPonderada;
}
