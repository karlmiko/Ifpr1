//3. Crítica de dia do mês - Alterar a função de data para que verifique se o dia está compatível com o mês. Por
//exemplo, novembro não possui dia 31. Para isso use também uma função.

#include "biblaureano.h"

void stConfereDataMes (int iDia, int iMes);

int main()
{
    int iDia = 0;
    while(iDia < 1 || iDia > 31)
    {
        iDia = readInt ("Dia: ");
    }

    int iMes = 0;
    while(iMes < 1 || iMes > 12)
    {
        iMes = readInt ("Mês: ");
    }

    stConfereDataMes (iDia, iMes);
}

void stConfereDataMes (int iDia, int iMes)
{
    string stMeses [12] = {"Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    int iDiasDosMeses [12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (iDiasDosMeses [iMes - 1] >= iDia)
    {
        cout << stMeses [iMes - 1] << " contém o dia " << iDia;
    }
    else
    {
        cout << "ERRO! " << stMeses [iMes - 1] << " não contém o dia " << iDia;
    }
}
