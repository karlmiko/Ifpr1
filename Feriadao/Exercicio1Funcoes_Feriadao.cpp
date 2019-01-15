//Exercicio1Funcoes_Feriadao.cpp
//Karl Michel Koerich

#include "biblaureano.h"

bool bParImpar (int iValor);

int main()
{
    cout << "(0 é par e 1 é impar)" << endl;
    int iValor = readInt ("Valor inteiro: ");
    int iResposta = bParImpar(iValor);
    cout << iResposta;
}

bool bParImpar (int iValor)
{
    int iDivisao = iValor % 2;
    return iDivisao;
}
