#include "biblaureano.h"

int main()
{
    while (true)
    {

        vector <Imagem> BichosDoMal;
        vector <int> LinhasBichosDM;
        string bichinhu = "<&-&>";
        int Coluna = 5, Linha;

        int xBichos = randomico (2,6);

        for (int i = 0; i < xBichos; i++)
        {
            while (true)
            {
                Linha = randomico (9, 19);

                int f = count (LinhasBichosDM.begin(), LinhasBichosDM.end(), Linha);

                if (f == 0)
                {
                    BichosDoMal.push_back (Imagem (bichinhu, Coluna, Linha));
                    LinhasBichosDM.push_back (Linha);
                    break;
                }
            }
        }

        while (Coluna < 69)
        {
            for (int i = 0; i < xBichos; i++)
            {
                BichosDoMal[i].imprime();
            }

            espera(30);

            for (int i = 0; i < xBichos; i++)
            {
                BichosDoMal[i].limpa();
            }

            Coluna++;
            BichosDoMal.clear();

            for (int i = 0; i < xBichos; i++)
            {
                BichosDoMal.push_back (Imagem (bichinhu, Coluna, LinhasBichosDM[i]));
            }
        }

        Coluna = 5;
    }
}
