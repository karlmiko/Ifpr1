//2. Nome do dia - Idem acima, para o dia da semana.

#include "biblaureano.h"

string stNomeDoDia (int iNumeroDoDia);

int main()
{
    int iNumeroDoDia = 0;

    while (iNumeroDoDia < 1 || iNumeroDoDia > 7)
    {
        iNumeroDoDia = readInt ("Número de um dia: ");
    }

    cout << stNomeDoDia (iNumeroDoDia);
}

string stNomeDoDia (int iNumeroDoDia)
{
    string stDias [7] = {"Domingo", "Segunda", "Terca", "Quarta", "Quinta", "Sexta", "Sábado"};

    string stDiaEscolhido = stDias [iNumeroDoDia - 1];

    return stDiaEscolhido;
}
