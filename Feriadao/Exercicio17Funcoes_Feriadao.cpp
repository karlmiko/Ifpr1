//Mensagem 1 - Escrever um procedimento que recebe valores de linha e coluna da tela e um texto, mostra o
//texto nas coordenadas recebidas e espera 5 segundos. Após, apaga a mensagem e termina.

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
    espera(500);
    limparTela();
}
