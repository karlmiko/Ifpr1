//7. Nome do dia - Construa um programa que lê um número de 1 a 7 e informa o dia da semana correspondente,
//sendo domingo o dia de número 1. Se o número estiver fora da faixa válida, é mostrada uma mensagem de
//erro.

#include "biblaureano.h"

int main()
{
    string stDiasDaSemana[7] = {"Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado"};

    int iDiaDaSemana = readInt ("Dia da semana (Número): ");
    if (iDiaDaSemana > 7 || iDiaDaSemana < 1)
    {
        iDiaDaSemana = readInt ("Dia da semana (Número): ");
    }

    cout << stDiasDaSemana [iDiaDaSemana - 1];
}
