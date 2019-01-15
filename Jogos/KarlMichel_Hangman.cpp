//karlMichel_forca.cpp

#include "biblaureano.h"

void finalizacao();

int main()
{
    string cabeca = retornaConteudoArquivo ("cabeca.txt");
    Imagem cabeca1(cabeca,48,4);

    string corpo = retornaConteudoArquivo ("corpo.txt");
    Imagem corpo1(corpo,48,8);

    string bracoDireito = retornaConteudoArquivo ("bracodireito.txt");
    Imagem bracoD(bracoDireito,53,9);

    string bracoEsquerdo = retornaConteudoArquivo ("bracoesquerdo.txt");
    Imagem bracoE(bracoEsquerdo,45,9);

    string pernaDireita = retornaConteudoArquivo ("pernadireita.txt");
    Imagem pernaD(pernaDireita,50,12);

    string pernaEsquerda = retornaConteudoArquivo ("pernaesquerda.txt");
    Imagem pernaE(pernaEsquerda,47,12);

    string Aforca = retornaConteudoArquivo ("forca.txt");
    Imagem forca(Aforca,40,2);

    string senhor = retornaConteudoArquivo ("vergaGrande.txt");
    Imagem verga (senhor, 1,1);

    char continuar = 's';

    while (continuar = 's')
    {
        limparTela();
        verga.imprime();

        string palavrasNormal = retornaConteudoArquivo ("palavrasN.txt");
        string secretaNormal = palavraAleatoria (palavrasNormal);

        int nivel = 0;
        int letrasDaPalavra = 0;
        gotoXY (1,20);
        char letra;
        int espacos, pUsadas, vidas, tamanho;

        while (true)
        {
            nivel = readInt ("NIVEL: ");
            if ( nivel == 1 ||  nivel == 2 || nivel == 3 || nivel == 4)
            {
                break;
            }
        }

        if ( nivel == 1)
        {
            vidas = 6;
        }
        if ( nivel == 2)
        {
            vidas = 4;
        }
        if (nivel == 3)
        {
            vidas = 2;
        }
        if (nivel == 4)
        {
            vidas = 1;
        }

        limparTela();
        forca.imprime();
        pUsadas = 1;
        string palavra = secretaNormal;
        tamanho = palavra.size();

        while ( vidas > 0 && letrasDaPalavra < tamanho)
        {
            espacos = 1;
            gotoXY(1,2);

            while ( espacos <= tamanho)
            {
                cout <<"_";
                espacos++;
            }

            gotoXY(1,4);
            letra = readChar ("Letra: ");

            if (palavra.find(letra) == string :: npos)
            {
                gotoXY(30,pUsadas);
                cout << letra;
                pUsadas++;
                vidas--;
                gotoXY(1,5);
                cout <<"Vidas: " << vidas;
            }
            else
            {
                int posicao = 0;
                while (posicao <= tamanho)
                {
                    char letrasPosicionadas = palavra[posicao];
                    if (letrasPosicionadas == letra)
                    {
                        int pLetras = posicao + 1;
                        gotoXY (pLetras, 1);
                        cout << letra;
                        letrasDaPalavra++;
                        posicao++;
                    }
                    else
                    {
                        posicao++;
                    }
                }
            }

            if ( nivel == 1)
            {
                if(vidas == 5)
                {
                    cabeca1.imprime();
                }
                if(vidas == 4)
                {
                    corpo1.imprime();
                }
                if(vidas == 3)
                {
                    bracoD.imprime();
                }
                if(vidas == 2)
                {
                    bracoE.imprime();
                }
                if(vidas == 1)
                {
                    pernaD.imprime();
                }
                if(vidas == 0)
                {
                    pernaE.imprime();
                }
            }

            if ( nivel == 2)
            {
                if(vidas == 3)
                {
                    cabeca1.imprime();
                }
                if(vidas == 2)
                {
                    corpo1.imprime();
                }
                if(vidas == 1)
                {
                    bracoD.imprime();
                    bracoE.imprime();
                }
                if(vidas == 0)
                {
                    pernaD.imprime();
                    pernaE.imprime();
                }
            }

            if ( nivel == 3)
            {
                if(vidas == 1)
                {
                    cabeca1.imprime();
                    corpo1.imprime();
                    bracoD.imprime();
                }
                if(vidas == 0)
                {
                    bracoE.imprime();
                    pernaD.imprime();
                    pernaE.imprime();
                }
            }

            if ( nivel == 4)
            {
                if(vidas == 0)
                {
                    cabeca1.imprime();
                    corpo1.imprime();
                    bracoD.imprime();
                    bracoE.imprime();
                    pernaD.imprime();
                    pernaE.imprime();
                }
            }
        }

        gotoXY (1,8);
        continuar = readChar ("Deseja jogar novamente? (s/n)");
        if (continuar != 's')
        {
            finalizacao();
            break;
        }
    }
}

void finalizacao()
{
    limparTela();
    gotoXY (30,10);
    cout << "FIM DE JOGO"<< endl;
}

