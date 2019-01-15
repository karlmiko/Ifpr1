//10. Leitura de cadeia - Implementar uma função que recebe uma linha e uma coluna e lê uma string na respectiva
//posição da tela, retornando o valor lido.

#include "biblaureano.h"

string stRetornaString();

int main()
{
    cout << stRetornaString();

}

string stRetornaString()
{
    int y = readInt ("Linha: ");
    int x = readInt ("Coluna: ");

    string stCadeia = readString ("Cadeia: ");

    limparTela();

    gotoXY(x,y);

    return stCadeia;
}
