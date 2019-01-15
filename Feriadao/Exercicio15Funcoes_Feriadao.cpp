//15. Linha vertical 2 - Alterar o procedimento acima para que receba também o caractere.

#include "biblaureano.h"

void vPreencheColuna (int x, char cObjeto);

int main()
{
    int x = 100;

    while ( x < 1 || x > 79 )
    {
        x = readInt ("Coluna: ");
    }

    char cObjeto = readChar ("Caracter: ");

    vPreencheColuna(x, cObjeto);
}

void vPreencheColuna(int x, char cObjeto)
{
    int y = 1;

    while (y < 25)
    {
        gotoXY(x,y);
        cout << cObjeto;
        espera(5);
        y++;
    }
}
