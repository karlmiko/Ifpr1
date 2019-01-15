//14. Linha vertical 1 - Desenvolva um procedimento que recebe um número de coluna de tela e preenche a coluna
//com caracteres ’O’.


#include "biblaureano.h"

void vPreencheColuna (int x);

int main()
{
    int x = 100;

    while ( x < 1 || x > 79 )
    {
        x = readInt ("Coluna: ");
    }

    vPreencheColuna(x);
}

void vPreencheColuna(int x)
{
    int y = 1;

    while (y < 25)
    {
        gotoXY(x,y);
        cout <<"O";
        espera(5);
        y++;
    }
}

