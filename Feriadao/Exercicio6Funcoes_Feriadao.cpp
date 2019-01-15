//Exercicio5Funcoes_Feriadao.cpp
//Karl Michel Koerich

#include "biblaureano.h"

double dExponencial (double dNumero, double dExpoente);

int main()
{
    double dNumero = readDouble ("Número: ");
    double dExpoente = readDouble ("Expoente: ");
    cout << dExponencial (dNumero, dExpoente);
}

double dExponencial (double dNumero, double dExpoente)
{
    double dResultado = pow(dNumero, dExpoente);
    return dResultado;
}
