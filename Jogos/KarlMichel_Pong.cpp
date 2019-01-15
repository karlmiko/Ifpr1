//KarlMichelKoerich_PONG.cpp

#include "biblaureano.h"

int main()
{
    int colunaBolinha = 39;
    int linhaBolinha = randomico (3,20);
    int tempo = 10;
    int ok = 1;
    int pontosJ1 = 0, pontosJ2 = 0;
    int linhaBarra1 = 10, linhaBarra2 = 10;
    int grausDpE = 1, grausEpD = 1;
    int anulaLinhaDpE = 0;
    int anulaLinhaEpD = 0;
    string jogador1 = readString ("Nome do Jogador 1: ");
    string jogador2 = readString ("Nome do Jogador 2: ");
    limparTela();
    Imagem bolinha (retornaConteudoArquivo("Bolinha.txt"), colunaBolinha, linhaBolinha);
    Imagem raquete1 ( retornaConteudoArquivo("Raquetee.txt"),2,linhaBarra1 );
    Imagem raquete2 ( retornaConteudoArquivo("Raquetee.txt"),78,linhaBarra2 );
    noecho(true);
    desligaCursor(true);

    while (true)
    {
        //Bolinha vai para a direita!
        while (colunaBolinha <= 79)
        {
            gotoXY (24,1);
            cout << jogador1 << ": " << pontosJ1 << "    " << jogador2 << ": " << pontosJ2;
            Imagem bolinha (retornaConteudoArquivo("Bolinha.txt"), colunaBolinha, linhaBolinha);
            Imagem raquete1 ( retornaConteudoArquivo("Raquetee.txt"), 2,linhaBarra1);
            Imagem raquete2 ( retornaConteudoArquivo("Raquetee.txt"), 78,linhaBarra2);
            raquete1.imprime();
            raquete2.imprime();
            bolinha.imprime();
            if (bolinha.colisao(raquete2))
            {
                if (linhaBolinha == linhaBarra2 || linhaBolinha == linhaBarra2 + 6)
                {
                    grausDpE = 1;
                }
                if (linhaBolinha == linhaBarra2 + 1 || linhaBolinha == linhaBarra2 + 5)
                {
                    grausDpE = 2;
                }
                if (linhaBolinha == linhaBarra2 + 2 || linhaBolinha == linhaBarra2 + 4)
                {
                    grausDpE = 3;
                }
                if (linhaBolinha == linhaBarra2 + 3)
                {
                    anulaLinhaDpE  = 1;
                }

                break;
            }
            espera(tempo);
            bolinha.limpa();
            colunaBolinha = colunaBolinha + grausEpD;

            if (linhaBolinha >= 1 && ok == 1 && anulaLinhaEpD == 0)
            {
                linhaBolinha--;
            }
            if (linhaBolinha == 1 && anulaLinhaEpD == 0)
            {
                ok--;
            }
            if (linhaBolinha <= 24 && ok == 0 && anulaLinhaEpD == 0)
            {
                linhaBolinha++;
            }
            if (linhaBolinha == 24 && anulaLinhaEpD == 0)
            {
                ok++;
            }
            if (colunaBolinha == 79)
            {
                espera(100);
                pontosJ1++;
                if (pontosJ1 == 3 || pontosJ2 == 3)
                {
                    limparTela();
                    gotoXY(24,1);
                    mudaCor(WHITE);
                    cout << "PARABÉNS "<< jogador1 << ", VOCÊ GANHOU DO OUTRO BABACA!";
                    espera(600);
                    limparTela();
                    return 0;
                }
                colunaBolinha = 39;
                linhaBolinha = randomico (3,20);
                Imagem bolinha (retornaConteudoArquivo("Bolinha.txt"), colunaBolinha, linhaBolinha);
            }

            //Fazendo as barras se mexerem...!
            if (kbhit())
            {
                char tecla = getch();

                if (tecla == 'w' || tecla == 'W')
                {
                    linhaBarra1--;
                    if (linhaBarra1 == 0)
                    {
                        linhaBarra1++;
                    }
                    raquete1.limpa();
                }
                if (tecla == 's' || tecla == 'S' )
                {
                    linhaBarra1++;
                    if (linhaBarra1 == 19)
                    {
                        linhaBarra1--;
                    }
                    raquete1.limpa();
                }
                if (tecla == 'i' || tecla == 'I' )
                {
                    linhaBarra2--;
                    if (linhaBarra2 == 0)
                    {
                        linhaBarra2++;
                    }
                    raquete2.limpa();
                }
                if (tecla == 'j' || tecla == 'J' )
                {
                    linhaBarra2++;
                    if (linhaBarra2 == 19)
                    {
                        linhaBarra2--;
                    }
                    raquete2.limpa();
                }
            }
        }

        anulaLinhaEpD = 0;

        //Bolinha indo para a esquerda!
        while (colunaBolinha >= 1)
        {
            gotoXY (24,1);
            cout << jogador1 << ": " << pontosJ1 << "    " << jogador2 << ": " << pontosJ2;
            Imagem bolinha (retornaConteudoArquivo("Bolinha.txt"), colunaBolinha, linhaBolinha);
            Imagem raquete1 ( retornaConteudoArquivo("Raquetee.txt"), 2,linhaBarra1);
            Imagem raquete2 ( retornaConteudoArquivo("Raquetee.txt"), 78,linhaBarra2);
            raquete1.imprime();
            raquete2.imprime();
            bolinha.imprime();
            if (bolinha.colisao(raquete1))
            {
                if (linhaBolinha == linhaBarra1 || linhaBolinha == linhaBarra1 + 6)
                {
                    grausEpD = 1;
                }
                if (linhaBolinha == linhaBarra1 + 1 || linhaBolinha == linhaBarra1 + 5)
                {
                    grausEpD = 2;
                }
                if (linhaBolinha == linhaBarra1 + 2 || linhaBolinha == linhaBarra1 + 4)
                {
                    grausEpD = 3;
                }
                if (linhaBolinha == linhaBarra1 + 3)
                {
                    anulaLinhaEpD  = 1;
                }

                break;
            }
            espera(tempo);
            bolinha.limpa();
            colunaBolinha = colunaBolinha - grausDpE;
            if (linhaBolinha <= 24 && ok == 0 && anulaLinhaDpE== 0)
            {
                linhaBolinha++;
            }
            if (linhaBolinha == 24 && anulaLinhaDpE== 0)
            {
                ok++;
            }
            if (linhaBolinha >= 1 && ok == 1 && anulaLinhaDpE== 0)
            {
                linhaBolinha--;
            }
            if (linhaBolinha == 1 && anulaLinhaDpE== 0)
            {
                ok--;
            }
            if (colunaBolinha == 1)
            {
                espera(100);
                pontosJ2++;
                if (pontosJ2 == 3 || pontosJ1 == 3)
                {
                    limparTela();
                    gotoXY(24,1);
                    mudaCor(WHITE);
                    cout << "PARABÉNS " << jogador2 << ", VOCÊ GANHOU DO OUTRO BABACA!";
                    espera(600);
                    limparTela();
                    return 0;
                }
                colunaBolinha = 39;
                linhaBolinha = randomico (3,20);
                Imagem bolinha (retornaConteudoArquivo("Bolinha.txt"), colunaBolinha, linhaBolinha);
            }

            //Fazendo as Barras se mexerem..!
            if (kbhit())
            {
                char tecla = getch();

                if (tecla == 'w' || tecla == 'W')
                {
                    linhaBarra1--;
                    if (linhaBarra1 == 0)
                    {
                        linhaBarra1++;
                    }
                    raquete1.limpa();
                }
                if (tecla == 's' || tecla == 'S' )
                {
                    linhaBarra1++;
                    if (linhaBarra1 == 19)
                    {
                        linhaBarra1--;
                    }
                    raquete1.limpa();
                }
                if (tecla == 'i' || tecla == 'I' )
                {
                    linhaBarra2--;
                    if (linhaBarra2 == 0)
                    {
                        linhaBarra2++;
                    }
                    raquete2.limpa();
                }
                if (tecla == 'j' || tecla == 'J' )
                {
                    linhaBarra2++;
                    if (linhaBarra2 == 19)
                    {
                        linhaBarra2--;
                    }
                    raquete2.limpa();
                }
            }
        }

        anulaLinhaDpE = 0;
    }
}
