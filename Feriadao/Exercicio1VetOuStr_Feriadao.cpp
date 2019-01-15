//1 Vet ou Str

#include "biblaureano.h"

int main()
{
    string x = readString ("Multiplicar esse número por 11(2 dígitos): ");
    int total = (x.at(0)-48) + (x.at(1)-48);
    int totalzao = (x.at(0)-48)*100 + (total*10) + (x.at(1)-48);
    cout << totalzao;
}

