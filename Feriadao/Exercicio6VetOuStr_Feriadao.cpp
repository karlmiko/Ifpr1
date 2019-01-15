//6. Pesquisa notas - Elaborar programa com opções para: ler 10 notas de 0 a 10, pesquisar se uma nota existe no
//vetor e mostrar o conteúdo do vetor. Na leitura, rejeitar notas fora da faixa válida.

#include "biblaureano.h"

int main()
{
    int iVetorNotas [10];
    int iEspacos = 0;

    while (iEspacos < 10)
    {
        int iNota = readInt ("Nota: ");
        if(iNota < 0 || iNota > 10)
        {
            int iNota = readInt ("Nota (0 a 10): ");
        }
            iVetorNotas [iEspacos] = iNota;
            iEspacos++;
    }

    int iPesquisaNoVetor = readInt ("Ver se uma nota existe: ");
    while ( iPesquisaNoVetor < 0 || iPesquisaNoVetor > 10)
    {
        int iPesquisaNoVetor = readInt ("Ver se uma nota existe: ");
    }

    iEspacos = 0;

    while (iEspacos < 10)
    {
        if (iVetorNotas [iEspacos] == iPesquisaNoVetor)
        {
            cout << "A nota " << iPesquisaNoVetor << " é encontrada no espaço " << iEspacos << endl;
            iEspacos++;
        }
        else if (iVetorNotas [iEspacos] != iPesquisaNoVetor)
        {
            iEspacos++;
        }
    }
}
