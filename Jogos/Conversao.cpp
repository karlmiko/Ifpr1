//Convertendo

#include "biblaureano.h"

int main()
{
    int ascii, escolha;
    char caracter, caracterOriginal;

    while (true)
    {
        int escolha = readInt ("Char para ASCII - 1 / ASCII para Char - 2 / a para A - 3 / A para a - 4: ");

        if (escolha == 0)
        {
                break;
        }
        if (escolha == 1)
        {
            caracter = readChar ("Char para ASCII: ");
            ascii = (int) caracter;
            cout << "Char " << caracter << " para ASCII tem valor: " << ascii << endl;
        }
        if (escolha == 2)
        {
            ascii = readInt ("ASCII para char: ");
            caracter = (char) ascii;
            cout << "ASCII " << ascii << " para Char é " << caracter << endl;
        }
        if (escolha == 3)
        {
            caracterOriginal = readChar ("letra minuscula para MAIUSCULA: ");
            ascii = (int) caracterOriginal - 32;
            caracter = (char) ascii;
            cout << "minuscula - " << caracterOriginal << " - para MAIUSCULA: " << caracter << endl;
        }
        if (escolha == 4)
        {
            caracterOriginal = readChar ("letra MAIUSCULA para minuscula: ");
            ascii = (int) caracterOriginal + 32;
            caracter = (char) ascii;
            cout << "MAIUSCULA - " << caracterOriginal << " - para minuscula: " << caracter << endl;
        }
    }

    //short int valor = 10;
    //float resultado = 7.0;
    //int somaInteiro;
    //float somaFloat;
    //somaInteiro = (int) (valor/resultado); // converter o resultado de uma divisao para inteiro
    //somaFloat = valor/resultado; //lembrar que a divisão de um inteiro por um float sempre retorna um float
    //cout << "Valor convertido para int:" << somaInteiro << endl;
    //cout << "Valor que seria retornado (float):" << somaFloat << endl;
    //somaFloat = valor/(int)resultado; //convertendo o float para int antes da divisão
    //cout << "Valor retornado:" << somaFloat << endl;
    //cout << "Game over!!" << endl;

    return 0;
}
