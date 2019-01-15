//9. Cheques - Faça um programa para preencher cheques. A data de emissão é lida na forma "DD/MM/AA". O
//programa separa dia, mês e ano e preenche o nome do mês. Não esqueça de validar a data.

#include "biblaureano.h"

void iAnoBissexto (int iAno);
void stConfereDataMes (int iDia, int iMes, int iAno);

int main()
{
    string stData = readString ("Data (DD/MM/AA): ");

    while ( stData.size() < 8 || stData.at(2) != '/' && stData.at(5) != '/')
    {
        stData = readString ("Data (DD/MM/AA): ");
    }

    int iDia = (stData.at(0) - 48) * 10 + (stData.at(1) - 48);
    int iMes = (stData.at(3) - 48) * 10 + (stData.at(4) - 48);
    int iAno = (stData.at(6)-48)*10 + (stData.at(7)-48)*1;

    if (iAno < 14)
    {
        iAno = iAno + 2000;
    }
    else
    {
        iAno = iAno + 1900;
    }

    stConfereDataMes (iDia, iMes, iAno);

}

void stConfereDataMes (int iDia, int iMes, int iAno)
{
    string stMeses [12] = {"Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    int iDiasDosMeses [12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (iMes > 12 || iMes < 1)
    {
        cout << "ERRO! não existe este mês!";
        return;
    }

    if (iDiasDosMeses [iMes - 1] >= iDia)
    {
        cout << iDia << " de " << stMeses [iMes - 1] << " de " << iAno << endl;
    }
    else
    {
        cout << "ERRO! " << stMeses [iMes - 1] << " não contém o dia " << iDia;
    }

    if (iDia == 29 && iMes == 2)
    {
        iAnoBissexto(iAno);
    }
}

void iAnoBissexto (int iAno)
{
    int iCalculo1, iCalculo2, iResposta;

    iCalculo1 = iAno % 4;
    iCalculo2 = iAno % 400;

    if(iCalculo1 == 0 || iCalculo2 == 0)
    {
        //cout << iAno << " é um ano bissexto mesmo, jóia fera!";
    }
    else
    {
        cout << "ERRO! " << iAno << " não é um ano bissexto!";
    }
}
