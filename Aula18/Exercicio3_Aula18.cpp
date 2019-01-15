//Exercicio3_Aula18.cpp
// Karl Michel Koerich

#include "biblaureano.h"

int main()
{
    float flVetor1[10];
    float flVetor2[10];
    float flVetor3[10];

    int iPreenchendo = 0;


    while (iPreenchendo < 10)
    {
        flVetor1[iPreenchendo] = readFloat ("Float1: ");
        iPreenchendo++;
    }

    iPreenchendo = 0;

    while (iPreenchendo < 10)
    {
        flVetor2[iPreenchendo] = readFloat ("Float2: ");
        iPreenchendo++;
    }

    iPreenchendo = 0;

    while (iPreenchendo < 10)
    {
        flVetor3[iPreenchendo] = flVetor1[iPreenchendo] * flVetor2[iPreenchendo];
        cout << flVetor3[iPreenchendo] << endl;
        iPreenchendo++;
    }
}
