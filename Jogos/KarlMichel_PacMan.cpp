#include "biblaureano.h"


void MexendoPacMan (int tabuleiro [21][28], int Pontos);

int Fantasminha1 (int tabuleiro [21][28], int ColunaF1, int LinhaF1);
int Fantasminha2 (int tabuleiro [21][28], int ColunaF2, int LinhaF2);
int Fantasminha3 (int tabuleiro [21][28], int ColunaF3, int LinhaF3);
int Fantasminha4 (int tabuleiro [21][28], int ColunaF4, int LinhaF4);

void MostraTela(int tabuleiro [21][28], int Pontos);

int main()
{
    noecho(true);
    desligaCursor(true);

    while (true)
    {
        int tabuleiro [21][28] =  { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} ,
            {   1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1} ,
            {   1, 3, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 3, 1} ,
            {   1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1} ,
            {   1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1} ,
            {   1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1} ,
            {   1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1} ,
            {   4, 4, 4, 4, 4, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 4, 4, 4, 4, 4} ,
            {   1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 2, 2, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1} ,
            {   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
            {   1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1} ,
            {   4, 4, 4, 4, 4, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 4, 4, 4, 4, 4} ,
            {   1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1} ,
            {   1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1} ,
            {   1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1} ,
            {   1, 3, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 3, 1} ,
            {   1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1} ,
            {   1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1} ,
            {   1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1} ,
            {   1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1} ,
            {   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
        };

        int Pontos = 0;

        limpaArea (32,4,75, 23);

        MostraTela(tabuleiro, Pontos);

        string stOpcoesUsuario [ ] = {"NEW GAME","HOW TO PLAY", "EXIT"} ;
        int iMenuInicial = mostraMenuV (34, 8, stOpcoesUsuario , 3 , GREEN, WHITE);

        if (iMenuInicial == 2)
        {
            limpaArea(32,4,75,23);

            while (true)
            {
                gotoXY (32,2);
                cout << "HOW TO PLAY" << endl;
                gotoXY (32,4);
                cout << "- USE THE RIGHT, UP, LEFT, DOWN BUTTONS" << endl;
                gotoXY (34,5);
                cout << "TO MOVE THE PACMAN" << endl;
                gotoXY (32,7);
                cout << "- DONT LET THE GHOSTS EAT YOU" << endl;
                gotoXY (32,9);
                cout << "- IF YOU EAT THIS: \"o\", YOU WILL" << endl;
                gotoXY (34,10);
                cout << "WIN 30 ESPECIAL SECONDS" << endl;
                gotoXY (34,11);
                cout << "TO EAT THE GHOSTS, WHEN YOU EAT A" << endl;
                gotoXY (34,12);
                cout << "GHOST, YOU GET MORE 200 POINTS" << endl;
                gotoXY (32,14);
                cout << "- EVERY \".\" GIVES YOU 10 POINTS" << endl;
                gotoXY (32,16);
                cout << "- YOU HAVE 3 LIVES, GOOD LUCK" << endl;
                gotoXY (32,18);
                cout << "PRESS ANY BUTTON TO LIVE THE INSTRUCTIONS" << endl;

                if (kbhit())
                {
                    break;
                }
            }

            limpaArea(32,2,75,18);
        }

        if (iMenuInicial == 3)
        {
            return 0;
        }
        if (iMenuInicial == 1)
        {
            MexendoPacMan(tabuleiro, Pontos);

            gotoXY (32,16);
            cout << "GAME OVER" << endl;

            gotoXY (32,18);
            cout << "PRESS ANY BUTTON TO LIVE THIS GAME" << endl;
            while(true)
            {
                if(kbhit())
                {
                    break;
                }
            }
        }
    }
}

void MostraTela(int tabuleiro [21][28], int Pontos)
{
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 28; j++)
        {
            if (tabuleiro [i][j] == 1)
            {
                gotoXY(j+1, i+1);
                mudaCor(GREEN, GREEN);
                cout << "#" << endl;
                limpaEfeito();
            }
            if (tabuleiro [i][j] == 2 || tabuleiro [i][j] == 4)
            {
                gotoXY(j+1, i+1);
                cout << " " << endl;
            }
            if (tabuleiro [i][j] == 0)
            {
                gotoXY(j+1, i+1);
                cout << "." << endl;
            }
            if (tabuleiro [i][j] == 3)
            {
                gotoXY(j+1, i+1);
                cout << "o" << endl;
            }
        }
    }

    gotoXY (34, 20);
    cout << "POINTS: " << Pontos << endl;
}

void MexendoPacMan (int tabuleiro [21][28], int Pontos)
{
    int TEMPO = 32, Especial = 0, PontinhosProxNivel = 0, PassosEspecial = 0, ColunaPac = 14, LinhaPac = 16, PodeAndar = 0, SoVai = 8, ColunaF1 = 12, LinhaF1 = 10, ColunaF2 = 13, LinhaF2 = 10, ColunaF3 = 14, LinhaF3 = 10, ColunaF4 = 15, LinhaF4 = 10;
    desligaCursor (true);
    noecho(true);
    int Vidas = 3;

    while (Vidas > 0)
    {
        gotoXY(34, 21);
        cout << "LIFES: " << Vidas << endl;

        PodeAndar = 0;

        while (PodeAndar == 0 || PodeAndar == 2)
        {
            if (PontinhosProxNivel == 250)
            {
                for (int i = 0; i < 21; i++)
                {
                    for (int j = 0; j < 28; j++)
                    {
                        if (tabuleiro [i][j] == 2)
                        {
                            tabuleiro [i][j] = 0;
                        }

                    }
                }

                tabuleiro [2][1] = 3;
                tabuleiro [15][1] = 3;
                tabuleiro [2][26] = 3;
                tabuleiro [15][26] = 3;

                TEMPO -= 4, Especial = 0, PontinhosProxNivel = 0, PassosEspecial = 0, ColunaPac = 14, LinhaPac = 16, PodeAndar = 0, SoVai = 8, ColunaF1 = 12, LinhaF1 = 10, ColunaF2 = 13, LinhaF2 = 10, ColunaF3 = 14, LinhaF3 = 10, ColunaF4 = 15, LinhaF4 = 10;
            }

            MostraTela(tabuleiro, Pontos);

            gotoXY(ColunaPac, LinhaPac);

            if (Especial == 0)
            {
                mudaCor (YELLOW);
            }
            else
            {
                int CorR = randomico (1,7);

                switch (CorR)
                {
                case 1:
                    mudaCor(WHITE);
                    break;
                case 2:
                    mudaCor(PURPLE);
                    break;
                case 3:
                    mudaCor(GREEN);
                    break;
                case 4:
                    mudaCor(RED);
                    break;
                case 5:
                    mudaCor(CYAN);
                    break;
                case 6:
                    mudaCor(BLACK);
                    break;
                }
            }

            cout << "#" << endl;
            limpaEfeito();

            if (PassosEspecial == 125)
            {
                Especial = 0;
            }

            int PosicaoF1 = Fantasminha1(tabuleiro, ColunaF1, LinhaF1);

            switch (PosicaoF1)
            {
            case 1:
                ColunaF1--;
                break;
            case 11:
                ColunaF1 = 28;
                break;
            case 2:
                LinhaF1--;
                break;
            case 3:
                ColunaF1++;
                break;
            case 33:
                ColunaF1 = 1;
                break;
            case 4:
                LinhaF1++;
                break;
            }

            int PosicaoF2 = Fantasminha2 (tabuleiro, ColunaF2, LinhaF2);

            switch (PosicaoF2)
            {
            case 1:
                ColunaF2--;
                break;
            case 11:
                ColunaF2 = 28;
                break;
            case 2:
                LinhaF2--;
                break;
            case 3:
                ColunaF2++;
                break;
            case 33:
                ColunaF2 = 1;
                break;
            case 4:
                LinhaF2++;
                break;
            }

            int PosicaoF3 = Fantasminha3 (tabuleiro, ColunaF3, LinhaF3);

            switch (PosicaoF3)
            {
            case 1:
                ColunaF3--;
                break;
            case 11:
                ColunaF3 = 28;
                break;
            case 2:
                LinhaF3--;
                break;
            case 3:
                ColunaF3++;
                break;
            case 33:
                ColunaF3 = 1;
                break;
            case 4:
                LinhaF3++;
                break;
            }

            int PosicaoF4 = Fantasminha4 (tabuleiro, ColunaF4, LinhaF4);

            switch (PosicaoF4)
            {
            case 1:
                ColunaF4--;
                break;
            case 11:
                ColunaF4 = 28;
                break;
            case 2:
                LinhaF4--;
                break;
            case 3:
                ColunaF4++;
                break;
            case 33:
                ColunaF4 = 1;
                break;
            case 4:
                LinhaF4++;
                break;
            }

            espera(TEMPO);

            if (SoVai == 1)
            {
                PodeAndar = tabuleiro [LinhaPac-1][ColunaPac-2];

                if (PodeAndar != 1 || ColunaPac == 1)
                {
                    if (tabuleiro [LinhaPac-1][ColunaPac-1] == 0 || tabuleiro [LinhaPac-1][ColunaPac-1] == 3)
                    {
                        if (tabuleiro [LinhaPac-1][ColunaPac-1] == 3)
                        {
                            PassosEspecial = 0;
                            Especial = 1;
                        }

                        tabuleiro [LinhaPac-1][ColunaPac-1] = 2;
                        PontinhosProxNivel++;
                        Pontos += 10;
                    }

                    if (ColunaPac == 1)
                    {
                        ColunaPac = 28;
                    }
                    else
                    {
                        ColunaPac--;
                    }
                }
                else
                {
                    SoVai = 0;
                }
            }

            if (SoVai == 2)
            {
                PodeAndar = tabuleiro [LinhaPac-2][ColunaPac-1];

                if (PodeAndar != 1)
                {
                    if (tabuleiro [LinhaPac-1][ColunaPac-1] == 0 || tabuleiro [LinhaPac-1][ColunaPac-1] == 3)
                    {
                        if (tabuleiro [LinhaPac-1][ColunaPac-1] == 3)
                        {
                            PassosEspecial = 0;
                            Especial = 1;
                        }

                        tabuleiro [LinhaPac-1][ColunaPac-1] = 2;
                        PontinhosProxNivel++;
                        Pontos += 10;
                    }

                    LinhaPac--;
                }
                else
                {
                    SoVai = 0;
                }
            }

            if (SoVai == 3)
            {
                PodeAndar = tabuleiro [LinhaPac-1][ColunaPac];

                if (PodeAndar != 1 || ColunaPac == 28)
                {
                    if (tabuleiro [LinhaPac-1][ColunaPac-1] == 0 || tabuleiro [LinhaPac-1][ColunaPac-1] == 3)
                    {
                        if (tabuleiro [LinhaPac-1][ColunaPac-1] == 3)
                        {
                            PassosEspecial = 0;
                            Especial = 1;
                        }

                        tabuleiro [LinhaPac-1][ColunaPac-1] = 2;
                        PontinhosProxNivel++;
                        Pontos += 10;
                    }

                    if (ColunaPac == 28)
                    {
                        ColunaPac = 1;
                    }
                    else
                    {
                        ColunaPac++;
                    }

                }
                else
                {
                    SoVai = 0;
                }
            }

            if (SoVai == 4)
            {
                PodeAndar = tabuleiro [LinhaPac][ColunaPac-1];

                if (PodeAndar != 1)
                {
                    if (tabuleiro [LinhaPac-1][ColunaPac-1] == 0 || tabuleiro [LinhaPac-1][ColunaPac-1] == 3)
                    {
                        if (tabuleiro [LinhaPac-1][ColunaPac-1] == 3)
                        {
                            PassosEspecial = 0;
                            Especial = 1;
                        }

                        tabuleiro [LinhaPac-1][ColunaPac-1] = 2;
                        PontinhosProxNivel++;
                        Pontos += 10;
                    }

                    LinhaPac++;
                }
                else
                {
                    SoVai = 0;
                }
            }

            if (Especial == 1)
            {
                PassosEspecial++;
            }

            if (kbhit())
            {
                char Tecla = getch();

                if (Tecla == K_RIGHT)
                {
                    PodeAndar = tabuleiro [LinhaPac-1][ColunaPac-2];

                    if (PodeAndar != 1)
                    {
                        SoVai = 1;
                    }
                }

                if (Tecla == K_UP)
                {
                    PodeAndar = tabuleiro [LinhaPac-2][ColunaPac-1];

                    if (PodeAndar != 1)
                    {
                        SoVai = 2;
                    }
                }

                if (Tecla == K_LEFT)
                {
                    PodeAndar = tabuleiro [LinhaPac-1][ColunaPac];

                    if (PodeAndar != 1)
                    {
                        SoVai = 3;
                    }
                }

                if (Tecla == K_DOWN)
                {
                    PodeAndar = tabuleiro [LinhaPac][ColunaPac-1];

                    if (PodeAndar == 0 || PodeAndar == 2)
                    {
                        SoVai = 4;
                    }
                }
            }

            if (ColunaPac == ColunaF1 && LinhaPac == LinhaF1)
            {
                if (Especial == 0)
                {
                    Vidas--;
                    Pontos -= 10;
                    ColunaPac = 14, LinhaPac = 16, PodeAndar = 0, SoVai = 8, ColunaF1 = 12, LinhaF1 = 10, ColunaF2 = 13, LinhaF2 = 10, ColunaF3 = 14, LinhaF3 = 10, ColunaF4 = 15, LinhaF4 = 10;
                    espera(48);
                    break;

                }
                else if (Especial == 1)
                {
                    Pontos += 200, ColunaF1 = 12, LinhaF1 = 10;
                }
            }

            if (ColunaPac == ColunaF2 && LinhaPac == LinhaF2)
            {
                if (Especial == 0)
                {
                    Vidas--;
                    Pontos -= 10;
                    ColunaPac = 14, LinhaPac = 16, PodeAndar = 0, SoVai = 8, ColunaF1 = 12, LinhaF1 = 10, ColunaF2 = 13, LinhaF2 = 10, ColunaF3 = 14, LinhaF3 = 10, ColunaF4 = 15, LinhaF4 = 10;
                    espera(48);
                    break;

                }
                else if (Especial == 1)
                {
                    Pontos += 200, ColunaF2 = 13, LinhaF2 = 10;
                }
            }

            if (ColunaPac == ColunaF3 && LinhaPac == LinhaF3)
            {
                if (Especial == 0)
                {
                    Vidas--;
                    Pontos -= 10;
                    ColunaPac = 14, LinhaPac = 16, PodeAndar = 0, SoVai = 8, ColunaF1 = 12, LinhaF1 = 10, ColunaF2 = 13, LinhaF2 = 10, ColunaF3 = 14, LinhaF3 = 10, ColunaF4 = 15, LinhaF4 = 10;
                    espera(48);
                    break;

                }
                else if (Especial == 1)
                {
                    Pontos += 200, ColunaF3 = 15, LinhaF3 = 10;
                }
            }

            if (ColunaPac == ColunaF4 && LinhaPac == LinhaF4)
            {
                if (Especial == 0)
                {
                    Vidas--;
                    Pontos -= 10;
                    ColunaPac = 14, LinhaPac = 16, PodeAndar = 0, SoVai = 8, ColunaF1 = 12, LinhaF1 = 10, ColunaF2 = 13, LinhaF2 = 10, ColunaF3 = 14, LinhaF3 = 10, ColunaF4 = 15, LinhaF4 = 10;
                    espera(48);
                    break;

                }
                else if (Especial == 1)
                {
                    Pontos += 200, ColunaF4 = 16, LinhaF4 = 10;
                }
            }
        }
    }
}

int Fantasminha1 (int tabuleiro [21][28], int ColunaF1, int LinhaF1)
{
    gotoXY(ColunaF1, LinhaF1);
    mudaCor (RED);
    cout << "@" << endl;
    limpaEfeito();

    int PodeAndar;

    while (true)
    {
        int SoVai = randomico (1,5);

        if (SoVai == 1)
        {
            PodeAndar = tabuleiro [LinhaF1-1][ColunaF1-2];

            if (PodeAndar != 1 || ColunaF1 == 1)
            {
                if (ColunaF1 == 1)
                {
                    SoVai = 11;
                    return SoVai;
                }
                else
                {
                    return SoVai;
                }
            }
        }

        if (SoVai == 2)
        {
            PodeAndar = tabuleiro [LinhaF1-2][ColunaF1-1];

            if (PodeAndar != 1)
            {
                return SoVai;
            }
        }

        if (SoVai == 3)
        {
            PodeAndar = tabuleiro [LinhaF1-1][ColunaF1];

            if (PodeAndar != 1 || ColunaF1 == 28)
            {
                if (ColunaF1 == 28)
                {
                    SoVai = 33;
                    return SoVai;
                }
                else
                {
                    return SoVai;
                }
            }
        }

        if (SoVai == 4)
        {
            PodeAndar = tabuleiro [LinhaF1][ColunaF1-1];

            if (PodeAndar != 1)
            {
                return SoVai;
            }
        }
    }
}

int Fantasminha2 (int tabuleiro [21][28], int ColunaF2, int LinhaF2)
{
    gotoXY(ColunaF2, LinhaF2);
    mudaCor (CYAN);
    cout << "@" << endl;
    limpaEfeito();

    int PodeAndar;

    while (true)
    {
        int SoVai = randomico (1,5);

        if (SoVai == 1)
        {
            PodeAndar = tabuleiro [LinhaF2-1][ColunaF2-2];

            if (PodeAndar != 1 || ColunaF2 == 1)
            {
                if (ColunaF2 == 1)
                {
                    SoVai = 11;
                    return SoVai;
                }
                else
                {
                    return SoVai;
                }
            }
        }

        if (SoVai == 2)
        {
            PodeAndar = tabuleiro [LinhaF2-2][ColunaF2-1];

            if (PodeAndar != 1)
            {
                return SoVai;
            }
        }

        if (SoVai == 3)
        {
            PodeAndar = tabuleiro [LinhaF2-1][ColunaF2];

            if (PodeAndar != 1 || ColunaF2 == 28)
            {
                if (ColunaF2 == 28)
                {
                    SoVai = 33;
                    return SoVai;
                }
                else
                {
                    return SoVai;
                }
            }
        }

        if (SoVai == 4)
        {
            PodeAndar = tabuleiro [LinhaF2][ColunaF2-1];

            if (PodeAndar != 1)
            {
                return SoVai;
            }
        }
    }
}

int Fantasminha3 (int tabuleiro [21][28], int ColunaF3, int LinhaF3)
{
    gotoXY(ColunaF3, LinhaF3);
    mudaCor (PURPLE);
    cout << "@" << endl;
    limpaEfeito();

    int PodeAndar;

    while (true)
    {
        int SoVai = randomico (1,5);

        if (SoVai == 1)
        {
            PodeAndar = tabuleiro [LinhaF3-1][ColunaF3-2];

            if (PodeAndar != 1 || ColunaF3 == 1)
            {
                if (ColunaF3 == 1)
                {
                    SoVai = 11;
                    return SoVai;
                }
                else
                {
                    return SoVai;
                }
            }
        }

        if (SoVai == 2)
        {
            PodeAndar = tabuleiro [LinhaF3-2][ColunaF3-1];

            if (PodeAndar != 1)
            {
                return SoVai;
            }
        }

        if (SoVai == 3)
        {
            PodeAndar = tabuleiro [LinhaF3-1][ColunaF3];

            if (PodeAndar != 1 || ColunaF3 == 28)
            {
                if (ColunaF3 == 28)
                {
                    SoVai = 33;
                    return SoVai;
                }
                else
                {
                    return SoVai;
                }
            }
        }

        if (SoVai == 4)
        {
            PodeAndar = tabuleiro [LinhaF3][ColunaF3-1];

            if (PodeAndar != 1)
            {
                return SoVai;
            }
        }
    }
}

int Fantasminha4 (int tabuleiro [21][28], int ColunaF4, int LinhaF4)
{
    gotoXY(ColunaF4, LinhaF4);
    mudaCor (BLUE);
    cout << "@" << endl;
    limpaEfeito();

    int PodeAndar;

    while (true)
    {
        int SoVai = randomico (1,5);

        if (SoVai == 1)
        {
            PodeAndar = tabuleiro [LinhaF4-1][ColunaF4-2];

            if (PodeAndar != 1 || ColunaF4 == 1)
            {
                if (ColunaF4 == 1)
                {
                    SoVai = 11;
                    return SoVai;
                }
                else
                {
                    return SoVai;
                }
            }
        }

        if (SoVai == 2)
        {
            PodeAndar = tabuleiro [LinhaF4-2][ColunaF4-1];

            if (PodeAndar != 1)
            {
                return SoVai;
            }
        }

        if (SoVai == 3)
        {
            PodeAndar = tabuleiro [LinhaF4-1][ColunaF4];

            if (PodeAndar != 1 || ColunaF4 == 28)
            {
                if (ColunaF4 == 28)
                {
                    SoVai = 33;
                    return SoVai;
                }
                else
                {
                    return SoVai;
                }
            }
        }

        if (SoVai == 4)
        {
            PodeAndar = tabuleiro [LinhaF4][ColunaF4-1];

            if (PodeAndar != 1)
            {
                return SoVai;
            }
        }
    }
}
