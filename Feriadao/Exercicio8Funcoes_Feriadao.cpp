//Exercicio8Funcoes_Feriadao.cpp
//Karl Michel Koerich

#include "biblaureano.h"

int iAnoBissexto (int iAno);

int main()
{
    int iAno = readInt ("Vamos ver se esse ano foi ou vai ser bissexto? Insira o ano: ");
    cout << "Se 1, é bissexto, se 0, não!" << endl;
    cout << iAnoBissexto (iAno);
}

int iAnoBissexto (int iAno)
{
    int iCalculo1, iCalculo2, iResposta;

    iCalculo1 = iAno % 4;
    iCalculo2 = iAno % 400;

    if(iCalculo1 == 0 || iCalculo2 == 0)
    {
        iResposta = 1;
    }
    else
    {
        iResposta = 0;
    }

    return iResposta;
}
