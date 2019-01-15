#include "biblaureano.h"

void MexeFrota(int ColunaAvioes [2][3]);

int main()
{
    mudaTamanhoTerminal(121,24);

    int posicaoCanhao1 = 1, posicaoCanhao2 = 1;
    noecho(true);
    desligaCursor(true);

    int ColunaAvioes [2][3] = {{1, 1, 1},
                               {116, 113, 118}};

    while (true)
    {
        if (posicaoCanhao1 == 1)
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    gotoXY(j+10, i+20);
                    cout << "||" << endl;
                }
            }
        }
        if (posicaoCanhao1 == 2)
        {
            int dez = 14;

            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    gotoXY(j+dez, i+20);
                    cout << "||" << endl;
                }
                dez--;
            }
        }

        if (posicaoCanhao2 == 1)
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    gotoXY(j+108, i+20);
                    cout << "||" << endl;
                }
            }
        }
        if (posicaoCanhao2 == 2)
        {
            int seis = 104;
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    gotoXY(j+seis, i+20);
                    cout << "||" << endl;
                }
                seis++;
            }
        }

        MexeFrota(ColunaAvioes);

        if (kbhit())
        {
            char Tecla = getch();

            switch (Tecla)
            {
                case K_RIGHT: posicaoCanhao2 = 2;
                break;
                case K_LEFT: posicaoCanhao2 = 1;
                break;
                case 'a': posicaoCanhao1 = 1;
                break;
                case 'd': posicaoCanhao1 = 2;
                break;
            }

            limpaArea(10,20,120,24);

        }
    }
}

void MexeFrota(int ColunaAvioes [2][3])
{
    Imagem Aviao1EpD (retornaConteudoArquivo ("KarlMichel-Aviao1D.txt"), ColunaAvioes [0][0], 8);
    Imagem Aviao2EpD (retornaConteudoArquivo ("KarlMichel-Aviao2D.txt"), ColunaAvioes [0][1], 3);
    Imagem Aviao3EpD (retornaConteudoArquivo ("KarlMichel-Aviao3D.txt"), ColunaAvioes [0][2], 2);
    Imagem Aviao1DpE (retornaConteudoArquivo ("KarlMichel-Aviao1.txt"), ColunaAvioes [1][0], 8);
    Imagem Aviao2DpE (retornaConteudoArquivo ("KarlMichel-Aviao2.txt"), ColunaAvioes [1][1], 3);
    Imagem Aviao3DpE (retornaConteudoArquivo ("KarlMichel-Aviao3.txt"), ColunaAvioes [1][2], 2);

    Aviao1EpD.imprime();
    Aviao2EpD.imprime();
    Aviao3EpD.imprime();
    Aviao1DpE.imprime();
    Aviao2DpE.imprime();
    Aviao3DpE.imprime();
}
