//Exercicio2Funcoes_Feriadao.cpp
//Karl Michel Koerich

#include "biblaureano.h"

void bAprovadoOuNao (int iNota);

int main()
{
    int iNota = readInt ("Nota do aluno (0 a 10): ");
    while ( iNota < 0 || iNota > 10)
    {
        iNota = readInt ("Nota do aluno (0 a 10): ");
    }

    bAprovadoOuNao(iNota);
}

void bAprovadoOuNao(int iNota)
{
    if(iNota >= 7)
    {
        cout <<"Aprovado!";
    }
    else
    {
        cout <<"Reprovado!";
    }
}
