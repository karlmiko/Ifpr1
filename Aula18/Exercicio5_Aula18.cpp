//Exercicio5_Aula18.cpp
//Karl Michel Koerich

#include "biblaureano.h"

int main()
{
    char cVetor[30];

    int iPreenchendo = 0;

    while (iPreenchendo < 30)
    {
        cVetor[iPreenchendo] = readChar ("Caracter: ");
        iPreenchendo++;
    }

    char cVerificaSeHa = readChar ("Verifique quantas vezes há o caracter: ");
    int iContandoAparicoes = 0;

    while (iPreenchendo >= 0)
    {
        if (cVerificaSeHa == cVetor[iPreenchendo])
        {
            iContandoAparicoes++;
            iPreenchendo--;
        }
        else
        {
            iPreenchendo--;
        }
    }

    cout << "O caracter " << cVerificaSeHa << " apareceu " << iContandoAparicoes << " vezes dentro do vetor!";
}
