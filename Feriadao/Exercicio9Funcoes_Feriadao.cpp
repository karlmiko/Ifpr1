//Exercicio9Funcoes_Feriadao.cpp
//Karl Michel Koerich

#include "biblaureano.h"

string stMaiorMenor (string stMenor);

int main()
{
    string stCadeia1 = readString ("Cadeia 1: ");
    string stCadeia2 = readString ("Cadeia 2: ");
    string stMenor;

    if (stCadeia1.size() > stCadeia2.size())
    {
        stMenor = stCadeia2;
    }

    if (stCadeia2.size() > stCadeia1.size())
    {
        stMenor = stCadeia1;
    }

    cout << stMaiorMenor (stMenor);
}

string stMaiorMenor (string stMenor)
{

    char cLetraVerificada;
    int iCodigoAscDaLetra;
    int iCodigoAscMenorPraMaior = 97;
    string stMenorOrdemAlfabetica;
    int iTamanhoMenor = stMenor.size() - 1; //Guarda o tamanho da string
    int iAcumulandoLetrasUsadas = 0;

    while (iAcumulandoLetrasUsadas <= iTamanhoMenor)
    {
        cLetraVerificada = (char) iCodigoAscMenorPraMaior;
        if (stMenor.find(cLetraVerificada) == string :: npos)
        {
            iCodigoAscMenorPraMaior++;
        }
        else
        {
            stMenorOrdemAlfabetica = stMenorOrdemAlfabetica + cLetraVerificada;
            iAcumulandoLetrasUsadas++;
            iCodigoAscMenorPraMaior++;
        }
    }

    return stMenorOrdemAlfabetica;
}
