//16

#include "biblaureano.h"

void vTexto (int x, int y);

int main()
{
    int x = readInt ("Coluna: ");
    int y = readInt ("Linha: ");

    vTexto(x, y);
}

void vTexto (int x, int y)
{
    string stTexto = readString ("Texto: ");
    gotoXY(x,y);
    cout << stTexto;
}
