//8 Vet Ou Str


#include "biblaureano.h"

int iColocaNaPosicao (string stCadeia1, string stCadeia2, string stCadeia3, string stCadeia4, string stCadeia5);

int main()
{
    string stCadeia1 = readString ("1 - Cadeia: ");
    string stCadeia2 = readString ("2 - Cadeia: ");
    string stCadeia3 = readString ("3 - Cadeia: ");
    string stCadeia4 = readString ("4 - Cadeia: ");
    string stCadeia5 = readString ("5 - Cadeia: ");

    iColocaNaPosicao (stCadeia1, stCadeia2, stCadeia3, stCadeia4, stCadeia5);

}

int iColocaNaPosicao (string stCadeia1, string stCadeia2, string stCadeia3, string stCadeia4, string stCadeia5)
{
    int iRifa1 = (stCadeia1.at(0)-48)*10000 +(stCadeia2.at(0)-48)*1000 +(stCadeia3.at(0)-48)*100 +(stCadeia4.at(0)-48)*10 +(stCadeia5.at(0)-48);
    int iRifa2 = (stCadeia1.at(1)-48)*10000 +(stCadeia2.at(1)-48)*1000 +(stCadeia3.at(1)-48)*100 +(stCadeia4.at(1)-48)*10 +(stCadeia5.at(1)-48);
    int iRifa3 = (stCadeia1.at(2)-48)*10000 +(stCadeia2.at(2)-48)*1000 +(stCadeia3.at(2)-48)*100 +(stCadeia4.at(2)-48)*10 +(stCadeia5.at(2)-48);
    int iRifa4 = (stCadeia1.at(3)-48)*10000 +(stCadeia2.at(3)-48)*1000 +(stCadeia3.at(3)-48)*100 +(stCadeia4.at(3)-48)*10 +(stCadeia5.at(3)-48);
    int iRifa5 = (stCadeia1.at(4)-48)*10000 +(stCadeia2.at(4)-48)*1000 +(stCadeia3.at(4)-48)*100 +(stCadeia4.at(4)-48)*10 +(stCadeia5.at(4)-48);

    cout << "Rifa 1 - "<< iRifa1 << endl;
    cout << "Rifa 2 - "<< iRifa2 << endl;
    cout << "Rifa 3 - "<< iRifa3 << endl;
    cout << "Rifa 4 - "<< iRifa4 << endl;
    cout << "Rifa 5 - "<< iRifa5 << endl;
}
