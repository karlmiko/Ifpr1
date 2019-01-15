#include "biblaureano.h"

void JOGO();
void Instrucoes();

int main()
{
    desligaCursor(true);
    noecho(true);

    while (true)
    {

        int x = 0;

        int BANNER [7][73] =  {{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {1,0,0,1,0,0,1,0,0,0,1,1,1,1,0,0,1,1,1,1,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,0,0,1,1,1,1,1,0,0,1,1,1,1,1,1,0,1,1,1,1,1,0,0},
            {1,0,0,1,0,0,1,0,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0},
            {1,0,0,1,0,0,1,0,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,1,1,1,1,1,0,0,1,0,0,0,0,1,0},
            {1,0,0,1,0,0,1,0,0,1,0,0,0,0,1,0,1,1,1,1,1,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,0,1,1,1,1,1,0,0,1,1,1,1,1,0,0,1,0,0,0,0,0,0,1,1,1,1,1,0,0},
            {1,0,0,1,0,0,1,0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0},
            {0,1,1,0,1,1,0,0,0,0,1,1,1,1,0,0,1,0,0,0,0,1,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,0,1,0,0,0,0,1,0}
        };


        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 73; j++)
            {
                gotoXY(j+5,i+3);
                if (BANNER[i][j] == 1)
                {
                    mudaCor(YELLOW);
                    cout << "*" << endl;
                }
                else
                {
                    cout << " " << endl;
                }
            }
        }
        box (8,14,19,16, "***");
        box (33,14,48,16, "***");
        box (63,14,70,16, "***");
        gotoXY(20,24);
        cout << "USE THE LEFT/RIGHT BUTTONS AND PRESS \"z\"";

        limpaEfeito();

        gotoXY(10, 15);
        cout << "NEW GAME" << endl;
        gotoXY(35, 15);
        cout << "INSTRUCTIONS" << endl;
        gotoXY(65, 15);
        cout << "EXIT" << endl;

        int ColunaNAVE = 37;

        while (true)
        {
            Imagem NAVE (retornaConteudoArquivo ("NAVE-KarlMichel.txt"), ColunaNAVE, 21);
            NAVE.imprime();

            if (kbhit())
            {
                char Tecla = getch();

                switch (Tecla)
                {
                case K_RIGHT:
                    if (ColunaNAVE != 63)
                    {
                        NAVE.limpa();
                        ColunaNAVE+=26;
                    }
                    break;
                case K_LEFT:
                    if (ColunaNAVE != 11)
                    {
                        NAVE.limpa();
                        ColunaNAVE-=26;
                    }
                    break;
                case 'z':

                    int LinhaTIRO = 20;
                    string tirinho = "|";

                    while (LinhaTIRO != 15)
                    {
                        Imagem TIRO (tirinho, ColunaNAVE+3, LinhaTIRO);
                        TIRO.imprime();
                        espera(3);
                        TIRO.limpa();
                        LinhaTIRO--;
                    }

                    if (ColunaNAVE == 37)
                    {
                        NAVE.limpa();
                        Instrucoes();
                        x = 1;
                        break;
                    }
                    if (ColunaNAVE == 11)
                    {
                        limpaArea (1,1,79,24);
                        JOGO();
                        x = 1;
                        break;
                    }
                    if (ColunaNAVE == 63)
                    {
                        return 0;
                    }
                }
            }

            if (x == 1)
            {
               break;
            }


        }
    }
}

void Instrucoes()
{
    limpaArea(8,14,70,24);

    gotoXY(6,12);
    mudaCor(YELLOW);
    cout << "INSTRUCTIONS" << endl;
    box (68, 11, 75, 13, "***");
    limpaEfeito();
    gotoXY(6,14);
    cout << "- CONTROL THE SPACESHIP USING LEFT, UP, RIGHT, DOWN BUTTONS" << endl;
    gotoXY(6,15);
    cout << "- SHOOT USING \"z\"" << endl;
    gotoXY(6,16);
    cout << "- ANOTHER SPACESHIPS AREN'T YOUR FRIENDS, KILL OR RUN" << endl;
    gotoXY(6,17);
    cout << "- YOU HAVE ONLY ONE LIFE" << endl;
    gotoXY(6,18);
    cout << "- SHOOT THE LETTERS IN THE ORDER" << endl;
    gotoXY(6,19);
    cout << "- MAKE AS MANY POINTS AS YOU CAN, GOOD LUCK" << endl;
    gotoXY(70, 12);
    cout << "MENU" << endl;

    Imagem NAVE (retornaConteudoArquivo ("NAVE-KarlMichel.txt"), 68, 21);
    NAVE.imprime();
    int x = 0;

    while (true)
    {
        if(kbhit())
        {
            char Tecla = getch();

            if (Tecla == 'z')
            {
                int LinhaTIRO = 20;
                string tirinho = "|";
                x = 1;

                while (LinhaTIRO != 12)
                {
                    Imagem TIRO (tirinho, 71, LinhaTIRO);
                    TIRO.imprime();
                    espera(3);
                    TIRO.limpa();
                    LinhaTIRO--;
                }
            }
        }
        if (x == 1)
        {
            limpaArea(6,9,77,24);
            break;
        }
    }
}

void JOGO()
{
    desligaCursor(true);
    noecho(true);

    vector <string> arquivoLetras = retornaArquivoSprites ("ALFABETO-KarlMichel.txt", "*????????*");
    vector <Imagem> letras;
    string palavras = retornaConteudoArquivo ("PALAVRAS-KarlMichel.txt");
    string Psecreta = palavraAleatoria (palavras);

    gotoXY(10, 1);
    cout << "MAKE THE WORD: " << Psecreta << endl;
    int TamanhoPalavra = Psecreta.size();
    int PosicaoPalavra = 0;
    int Pontos = 0;
    gotoXY((25+TamanhoPalavra), 1);
    cout << " - POINTS: " << Pontos << endl;
    int Mais = 15;

    for (int i = 2; i < 24; i++)
    {
        for (int j = 0; j < 79; j++)
        {
            gotoXY(j,i);
            mudaCor (YELLOW);
            cout << "*" << endl;
        }
    }

    int TELA [6] = {0,1,2,3,4,5};

    int ColunaNAVE = 35, LinhaNAVE = 18, ColunaBicho = 13, LinhaBicho = 18;
    string bichinhu = "<H&W&H>";
    string bichaum = "<-Xxu|0|uxX->";
    Imagem BichoDoMal (bichinhu, ColunaBicho, LinhaBicho);
    int LinhaBichao = 18, ColunaBichao = 52;
    while (LinhaBichao == LinhaBicho)
    {
        LinhaBichao = randomico (9, 19);
    }
    Imagem Bichao (bichaum, ColunaBichao, LinhaBichao);
    BichoDoMal.imprime();
    Bichao.imprime();

    TEMPO w;
    w = tempoInicio();

    while(true)
    {
        Imagem NAVE (retornaConteudoArquivo ("NAVE-KarlMichel.txt"), ColunaNAVE, LinhaNAVE);
        NAVE.imprime();

        if (kbhit())
        {
            char Tecla = getch();

            switch (Tecla)
            {
            case K_RIGHT:
                if (ColunaNAVE != 59)
                {
                    ColunaNAVE++;
                }
                break;
            case K_LEFT:
                if (ColunaNAVE != 12)
                {
                    ColunaNAVE--;
                }
                break;
            case K_UP:
                if (LinhaNAVE != 9)
                {
                    LinhaNAVE--;
                }
                break;
            case K_DOWN:
                if (LinhaNAVE != 19)
                {
                    LinhaNAVE++;
                }
                break;
            case 'z':

                int LinhaTIRO = LinhaNAVE -1;
                string tirinho = "|";

                while (true)
                {
                    int x = 0;
                    Imagem TIRO (tirinho, ColunaNAVE+3, LinhaTIRO);
                    TIRO.imprime();

                    for (int i = 0; i < 7; i++)
                    {
                        if (TIRO.colisao(letras[i]))
                        {
                            int pegandoValorVETOR = TELA[i];
                            char letraDoVETOR = (char) pegandoValorVETOR + 65;
                            if (letraDoVETOR == Psecreta.at(PosicaoPalavra))
                            {
                                Pontos+=10;
                                gotoXY(10+Mais, 1);
                                cout << "*" << endl;
                                Mais++;
                                PosicaoPalavra++;
                                if (PosicaoPalavra == TamanhoPalavra)
                                {
                                    Pontos += 100;
                                    Psecreta = palavraAleatoria (palavras);
                                    limpaArea (10, 1, (25+TamanhoPalavra), 1);
                                    gotoXY(10, 1);
                                    cout << "MAKE THE WORD: " << Psecreta << endl;
                                    TamanhoPalavra = Psecreta.size();
                                    PosicaoPalavra = 0;
                                    Mais = 15;
                                }
                            }
                            else
                            {
                                Pontos-=10;
                            }
                            limpaArea(26+TamanhoPalavra,1,79,1);
                            gotoXY(25+TamanhoPalavra, 1);
                            cout << " - POINTS: " << Pontos << endl;
                            x = 1;
                            break;
                        }
                    }

                    if (x == 1)
                    {
                        break;
                    }

                    if (ColunaNAVE+3 <= ColunaBicho+6 && ColunaNAVE+3 >= ColunaBicho && LinhaBicho == LinhaTIRO)
                    {
                        Pontos+= 10;
                        limpaArea(26+TamanhoPalavra,1,79,1);
                            gotoXY(25+TamanhoPalavra, 1);
                            cout << " - POINTS: " << Pontos << endl;
                        limpaArea(ColunaBicho, LinhaBicho, ColunaBicho+6, LinhaBicho);
                        ColunaBicho = 13, LinhaBicho = LinhaNAVE;
                        break;
                    }

                    if (ColunaNAVE+3 <= ColunaBichao+12 && ColunaNAVE+3 >= ColunaBichao && LinhaBichao == LinhaTIRO)
                    {
                        Pontos+= 5;
                        limpaArea(26+TamanhoPalavra,1,79,1);
                            gotoXY(25+TamanhoPalavra, 1);
                            cout << " - POINTS: " << Pontos << endl;
                        limpaArea(ColunaBichao, LinhaBichao, ColunaBichao+12, LinhaBichao);
                        ColunaBichao = 52, LinhaBichao = LinhaBicho;
                        while (LinhaBichao == LinhaBicho)
                        {
                            LinhaBichao = randomico(9, 19);
                        }
                        break;
                    }

                    espera(3);
                    TIRO.limpa();
                    LinhaTIRO--;
                }
            }

            NAVE.limpa();
        }

        if (tempoPassado(w) > 20)
        {
            limpaArea(15,2,62,8);

            limpaArea(ColunaBicho, LinhaBicho, ColunaBicho + 6, LinhaBicho);
            limpaArea(ColunaBichao, LinhaBichao, ColunaBichao + 12, LinhaBichao);

            ColunaBicho++;
            ColunaBichao--;

            if(ColunaBicho == 59)
            {
                ColunaBicho = 13;
                LinhaBicho = LinhaNAVE;
            }
            if (ColunaBichao == 13)
            {
                ColunaBichao = 52;
                LinhaBichao = LinhaBicho;
                while (LinhaBichao == LinhaBicho)
                {
                    LinhaBichao = randomico (9, 19);
                }
            }

            Imagem BichoDoMal (bichinhu, ColunaBicho, LinhaBicho);
            BichoDoMal.imprime();
            Imagem Bichao (bichaum, ColunaBichao, LinhaBichao);
            Bichao.imprime();

            if (BichoDoMal.colisao(NAVE) || Bichao.colisao(NAVE))
            {
                gotoXY(29,6);
                cout << "PRESS \"z\" TO CONTINUE" << endl;
                gotoXY(35,5);
                cout << "GAME OVER!" << endl;
                while (true)
                {
                    if(kbhit())
                    {
                        char Tecla = getch();
                        if (Tecla == 'z')
                        {
                            break;
                        }
                    }
                }
                limpaArea(1,1,79,24);
                break;
            }

            for (int t = 0; t < 5; t++)
            {
                TELA[t] = TELA[(t+1)];
            }

            int h = TELA[5];
            h++;
            if (h == 26)
            {
                h = 0;
            }
            TELA[5] = h;

            int Col = 15;
            letras.clear();

            for (int i = 0; i < 6; i++)
            {
                h = TELA[i];
                letras.push_back (Imagem(arquivoLetras[h], Col, 2));
                letras[i].imprime();
                Col+= 8;
            }

            w = tempoInicio();
        }
    }
}
