//2. Escrever um programa que leia 10 números int para dentro de um vetor. Após a leitura, o programa deve pedir
//para ser informado um número e deve dizer se este número foi lido anteriormente ou não. O programa termina
//quando for digitado o número 0 (zero).

#include "biblaureano.h"


int main()
{
    int iVetor[10];
    int iNumeroConfere = 1;
    int iPosicoesNoVetor = 0;
    int iConferindo = 0;

    while (iPosicoesNoVetor < 10)
    {
        iVetor[iPosicoesNoVetor] = readInt ("Int: ");
        iPosicoesNoVetor++;
        limparTela();
    }

    while (iNumeroConfere != 0)
    {
        iNumeroConfere = readInt ("Confira se foi digitado: ");
        iConferindo = 0;

        while (iConferindo < 10)
        {
            if (iVetor[iConferindo] == iNumeroConfere)
            {
                cout << iNumeroConfere << " está no vetor!" << endl;
                break;
            }
            else
            {
                iConferindo++;
                if(iConferindo == 10)
                {
                    cout << iNumeroConfere << " não está no vetor!" << endl;
                }
            }
        }
    }
}
