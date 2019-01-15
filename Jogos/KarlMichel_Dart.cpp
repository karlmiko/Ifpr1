//KarlMichel_Dardo.cpp

#include "biblaureano.h"

int main()
{
    noecho(true);
    int linhaDardo = 20, colunaAlvo = 30, linhaAlvo = 5, chances = 3, pontos = 0, tempo;
    char letra, jogando = 's';
    desligaCursor(true);
    Imagem alvo (retornaConteudoArquivo ("Alvoo.txt"),colunaAlvo,linhaAlvo);
    Imagem dardo (retornaConteudoArquivo ("Dardoo.txt"),40,linhaDardo);

    while (jogando == 's')
    {
        chances = 3;
        pontos = 0;
        string opcoes [ ] = {"MOLEZA","MEIA BOCA","SINISTRO","DEUS"} ;
        int opcao = mostraMenuV (10, 10, opcoes , 4 , RED, WHITE);

        if (opcao == 1)
        {
            tempo = 200;
            limparTela();
        }
         if (opcao == 2)
        {
            tempo = 150;
            limparTela();
        }
        if (opcao == 3)
        {
            tempo = 100;
            limparTela();
        }
         if (opcao == 4)
        {
            tempo = 50;
            limparTela();
        }

        while (chances > 0)
        {
            dardo.imprime();
            Imagem alvo (retornaConteudoArquivo ("Alvoo.txt"),colunaAlvo,linhaAlvo);
            alvo.imprime();
            colunaAlvo = randomico(25,45);
            linhaAlvo = randomico(5,10);
            espera(tempo);
            alvo.limpa();

            if (kbhit())
            {
                alvo.imprime();
                letra = getch();
                while (letra == 'f' || letra == 'F')
                {
                    Imagem dardo (retornaConteudoArquivo ("Dardoo.txt"),40,linhaDardo);
                    dardo.imprime();
                    espera(3);
                    dardo.limpa();
                    linhaDardo--;

                    if (linhaDardo == 1)
                    {
                        espera(100);
                        limparTela();
                        gotoXY(29,22);
                        chances--;
                        cout <<"CHANCES: " << chances << "   PONTOS: " << pontos;
                        linhaDardo = 20;
                        break;
                    }
                    if (dardo.colisao(alvo))
                    {
                        espera(100);
                        limparTela();
                        gotoXY(29,21);
                        chances--;

                        if (colunaAlvo == 40 || colunaAlvo == 39 || colunaAlvo == 38 || colunaAlvo == 30 || colunaAlvo == 29 || colunaAlvo == 28)
                        {
                            pontos = pontos + 10;
                            cout <<"CHANCES: " << chances << "   PONTOS: " << pontos;
                            linhaDardo = 20;
                            break;
                        }
                        if (colunaAlvo == 37 || colunaAlvo == 36 || colunaAlvo == 35 || colunaAlvo == 33 || colunaAlvo == 32 || colunaAlvo == 31)
                        {
                            pontos = pontos + 20;
                            cout <<"CHANCES: " << chances << "   PONTOS: " << pontos;
                            linhaDardo = 20;
                            break;
                        }
                        if (colunaAlvo == 34)
                        {
                            pontos = pontos + 50;
                            cout <<"CHANCES: " << chances << "   PONTOS: " << pontos;
                            linhaDardo = 20;
                            break;
                        }
                    }
                }
            }
        }

        limparTela();
        gotoXY(10,10);
        cout << "VÔCE FEZ " << pontos << " PONTOS!";
        gotoXY(10,12);
        jogando = readChar ("DESEJA JOGAR NOVAMENTE? (s/n) " );
        limparTela();
    }
}
