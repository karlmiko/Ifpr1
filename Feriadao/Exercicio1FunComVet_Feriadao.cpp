//1. Nome do mês - Escrever uma função que recebe número do mês e retorna seu nome por extenso.

#include "biblaureano.h"

string stNomeDoMes (int iNumeroDoMes);

int main()
{
    int iNumeroDoMes = 0;

    while (iNumeroDoMes < 1 || iNumeroDoMes > 12)
    {
        iNumeroDoMes = readInt ("Número de um mês: ");
    }

    cout << stNomeDoMes (iNumeroDoMes);
}

string stNomeDoMes (int iNumeroDoMes)
{
    string stMeses [12] = {"Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

    string stMesEscolhido = stMeses [iNumeroDoMes - 1];

    return stMesEscolhido;
}
