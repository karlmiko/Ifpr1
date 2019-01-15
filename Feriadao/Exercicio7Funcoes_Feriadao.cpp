//Exercicio7Funcoes_Feriadao.cpp
//Karl Michel Koerich

//CORRRRRIGIIIIR

#include "biblaureano.h"

double dbDescobreValorFuturo(double dbCapital, double dbTaxaDeJuros, int iPrazo);
double dbDescobreCapitalNecessario(double dbValor, double dbTaxaDeJuros, int iPrazo);

int main()
{
    double dbCapital, dbValor, dbResposta = 0;

    int iOpcao = readInt ("1 - Valor Futuro / 2 - Capital Necessário: ");
    while(iOpcao != 1 && iOpcao != 2)
    {
        iOpcao = readInt ("1 - Valor Futuro / 2 - Capital Necessário: ");
    }

    if (iOpcao == 1)
    {
        dbCapital = readDouble ("Capital(apenas o valor): ");
    }
    else if(iOpcao == 2)
    {
        double dbValor = readDouble ("Valor Futuro(apenas o valor): ");
    }

    double dbTaxaDeJuros = readDouble ("Juros(apenas o valor): ");
    int iPrazo = readInt ("Prazo(em dias): ");

    if (iOpcao == 1)
    {
        dbResposta = dbDescobreValorFuturo(dbCapital, dbTaxaDeJuros, iPrazo);
    }
    else if (iOpcao == 2)
    {
        dbResposta = dbDescobreCapitalNecessario(dbValor,dbTaxaDeJuros,iPrazo);
    }

    cout << dbResposta;
}

double dbDescobreValorFuturo(double dbCapital, double dbTaxaDeJuros, int iPrazo)
{
    double dbCalculo1 = dbTaxaDeJuros + 1;
    double dbCalculo2 = pow (dbCalculo1, iPrazo);
    double dbCalculo3 = dbCalculo2 * dbCapital;

    return dbCalculo3;
}

double dbDescobreCapitalNecessario(double dbValor, double dbTaxaDeJuros, int iPrazo)
{
    double dbCalculo1 = dbTaxaDeJuros + 1;
    double dbCalculo2 = pow (dbCalculo1, iPrazo);
    double dbCalculo3 = dbValor / dbCalculo2;

    return dbCalculo3;
}
