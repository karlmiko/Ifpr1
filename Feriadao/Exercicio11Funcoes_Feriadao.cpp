//11. Validação de data - Escrever uma função que verifica se uma data no formato "DD/MM/AAAA"é válida. Além
//de verificar se o dia está entre 1 e 31 e o mês está entre 1 e 12, se o dia for 29/02 é chamada a função especificada
//anteriormente para verificar se o ano é bissexto.

#include "biblaureano.h"

void iAnoBissexto (int iAno);
void stConfereDataMes (int iDia, int iMes, int iAno);

int main()
{
    string stData = readString ("Data (DD/MM/AAAA): ");

    while ( stData.size() < 10 || stData.at(2) != '/' && stData.at(5) != '/')
    {
        stData = readString ("Data (DD/MM/AAAA): ");
    }

    int iDia = (stData.at(0) - 48) * 10 + (stData.at(1) - 48);
    int iMes = (stData.at(3) - 48) * 10 + (stData.at(4) - 48);
    int iAno = (stData.at(6)-48)*1000 + (stData.at(7)-48)*100 + (stData.at(8)-48)*10 + (stData.at(9)-48);

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
        cout << stMeses [iMes - 1] << " contém o dia " << iDia << endl;
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
        cout << iAno << " é um ano bissexto mesmo, jóia fera!";
    }
    else
    {
        cout << "Mas " << iAno << " não é um ano bissexto não champs!";
    }
}
