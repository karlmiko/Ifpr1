// Tetris_KarlMichel.cpp
// Karl Michel Koerich
// Última atualizacão: 12/10/2013

#include "biblaureano.h" //versão 3.3

void MostraTela (int matriz [24][18]);
void MenuInicial ();
void Instrucoes(int Pontos);

int PECA1_1 (int matriz [24][18], int LinhaInicial, int ColunaInicial);
int PECA1_2 (int matriz [24][18], int LinhaInicial, int ColunaInicial);

int PECA2_1 (int matriz [24][18], int LinhaInicial, int ColunaInicial);
int PECA2_2 (int matriz [24][18], int LinhaInicial, int ColunaInicial);
int PECA2_3 (int matriz [24][18], int LinhaInicial, int ColunaInicial);
int PECA2_4 (int matriz [24][18], int LinhaInicial, int ColunaInicial);

int PECA3_1 (int matriz [24][18], int LinhaInicial, int ColunaInicial);
int PECA3_2 (int matriz [24][18], int LinhaInicial, int ColunaInicial);

int PECA4_1 (int matriz [24][18], int LinhaInicial, int ColunaInicial);
int PECA4_2 (int matriz [24][18], int LinhaInicial, int ColunaInicial);

int PECA5_1 (int matriz [24][18], int LinhaInicial, int ColunaInicial);
int PECA5_2 (int matriz [24][18], int LinhaInicial, int ColunaInicial);
int PECA5_3 (int matriz [24][18], int LinhaInicial, int ColunaInicial);
int PECA5_4 (int matriz [24][18], int LinhaInicial, int ColunaInicial);

int PECA6_1 (int matriz [24][18], int LinhaInicial, int ColunaInicial);
int PECA6_2 (int matriz [24][18], int LinhaInicial, int ColunaInicial);
int PECA6_3 (int matriz [24][18], int LinhaInicial, int ColunaInicial);
int PECA6_4 (int matriz [24][18], int LinhaInicial, int ColunaInicial);

int PECA7 (int matriz [24][18], int LinhaInicial, int ColunaInicial);

int main()
{
    noecho(true);
    desligaCursor(true);

    while (true)
    {
        int Pontos = 0;

        while (true)
        {

            limpaEfeito();

            limpaArea(29,7, 73,15);

            MenuInicial ();



            string stOpcoesUsuario [ ] = {"NOVO JOGO","FIM DE JOGO"} ;
            int iMenuInicial = mostraMenuH (29, 8, stOpcoesUsuario , 2 , CYAN, WHITE);

            if (iMenuInicial == 1)
            {
                limparTela();
                break;
            }
            else
            {
                limparTela();
                return 0;
            }
        }

        int matriz [24][18];

        for (int i = 0; i < 24; i++)
        {
            for (int j = 0; j < 18; j++)
            {
                matriz [i][j] = 0;
            }
        }

        for (int j = 0; j < 18; j++)
        {
            matriz [23][j] = 1;
        }

        while (matriz [0][8] == 0)
        {
            limpaEfeito();

            Instrucoes(Pontos);

            int LinhaInicial = 1, ColunaInicial = 9;

            int pecaEscolhida = randomico (1,8);

            if (pecaEscolhida == 1)
            {
                PECA1_1 (matriz, LinhaInicial, ColunaInicial);
            }
            if (pecaEscolhida == 2)
            {
                PECA2_1 (matriz, LinhaInicial, ColunaInicial);
            }
            if (pecaEscolhida == 3)
            {
                PECA3_1 (matriz, LinhaInicial, ColunaInicial);
            }
            if (pecaEscolhida == 4)
            {
                PECA4_1 (matriz, LinhaInicial, ColunaInicial);
            }
            if (pecaEscolhida == 5)
            {
                PECA5_1 (matriz, LinhaInicial, ColunaInicial);
            }
            if (pecaEscolhida == 6)
            {
                PECA6_1 (matriz, LinhaInicial, ColunaInicial);
            }
            if (pecaEscolhida == 7)
            {
                PECA7 (matriz, LinhaInicial, ColunaInicial);
            }

            vector <int> ConfereUnsNaLinha;
            for (int x = 0; x < 18; x++)
            {
                ConfereUnsNaLinha.push_back(0);
            }

            vector <int> :: iterator MeuIterador;

            int L = 1, Linha;

            for (int i = 22; i >= 0; i--)
            {
                for (int j = 0; j < 18; j++)
                {
                    MeuIterador = ConfereUnsNaLinha.begin()+j;
                    *MeuIterador = matriz [i][j];
                }

                Linha = i;

                int CompletouALinha = count (ConfereUnsNaLinha.begin(), ConfereUnsNaLinha.end(), L);

                if (CompletouALinha == 18)
                {
                    Pontos++;

                    while (Linha > 0)
                    {
                        for (int x = 0; x < 18; x++)
                        {
                            matriz [Linha][x]  =  matriz [Linha-L][x];
                        }

                        Linha --;
                    }

                    for (int x = 0; x < 18; x++)
                    {
                        matriz [0][x]  =  0;
                    }

                }

                for (int j = 0; j < 18; j++)
                {
                    MeuIterador = ConfereUnsNaLinha.begin()+j;
                    *MeuIterador = 0;
                }
            }
        }
    }
}

void MenuInicial ()
{
    int Tetris [5][37] =  { { 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1} ,
        { 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0} ,
        { 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1} ,
        { 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1} ,
        { 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1}
    };

    int Coluna = 20, Linha = 2;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 37; j++)
        {
            int Numero = Tetris [i][j];

            if (Numero == 1)
            {
                Numero = randomico (1,8);

                if (Numero == 1)
                {
                    mudaCor(WHITE, WHITE);
                }
                if (Numero == 2)
                {
                    mudaCor(YELLOW,YELLOW);
                }
                if (Numero == 3)
                {
                    mudaCor(CYAN, CYAN);
                }
                if (Numero == 4)
                {
                    mudaCor(GREEN, GREEN);
                }
                if (Numero == 5)
                {
                    mudaCor(PURPLE, PURPLE);
                }
                if (Numero == 6)
                {
                    mudaCor(BLUE, BLUE);
                }
                if (Numero == 7)
                {
                    mudaCor(RED, RED);
                }

                gotoXY (Coluna+j, Linha+i);
                cout << "0";
            }
        }
    }
}

void Instrucoes(int Pontos)
{
    gotoXY(29, 8);
    cout << "PRESSIONE \"l\" PARA DESCER AUTOMATICAMENTE";
    gotoXY(29, 10);
    cout << "PRESSIONE \"a\" PARA MOVER PARA ESQUERDA";
    gotoXY(29, 12);
    cout << "PRESSIONE \"d\" PARA MOVER PARA DIREITA";
    gotoXY(29, 14);
    cout << "PRESSIONE \"w\" PARA GIRAR";
    gotoXY(29, 16);
    cout << "PONTOS: " << Pontos;
}

void MostraTela(int matriz[24][18])
{
    for (int i = 0; i < 23; i++)
    {
        for (int j = 0; j < 18; j++)
        {
            int Numero = matriz [i][j];

            if (Numero == 0)
            {
                mudaCor (BLACK, BLACK);
            }
            else
            {
                Numero = randomico (1,8);

                if (Numero == 1)
                {
                    mudaCor(WHITE, WHITE);
                }
                if (Numero == 2)
                {
                    mudaCor(YELLOW,YELLOW);
                }
                if (Numero == 3)
                {
                    mudaCor(CYAN, CYAN);
                }
                if (Numero == 4)
                {
                    mudaCor(GREEN, GREEN);
                }
                if (Numero == 5)
                {
                    mudaCor(PURPLE, PURPLE);
                }
                if (Numero == 6)
                {
                    mudaCor(BLUE, BLUE);
                }
                if (Numero == 7)
                {
                    mudaCor(RED, RED);
                }
            }

            gotoXY (j+1, i+1);
            cout << "0";
        }
    }
}

// 0
// 0
// 0
// 0

int PECA1_1 (int matriz [24][18], int LinhaInicial, int ColunaInicial)
{
    int ParaOuNao = matriz [LinhaInicial][(ColunaInicial-1)];
    int TEMPO = 30;

    while (ParaOuNao == 0)
    {
        MostraTela(matriz);
        MenuInicial();

        mudaCor (WHITE, WHITE);

        for (int i = 0; i < 4; i++)
        {
            if (LinhaInicial >= 1)
            {
                gotoXY (ColunaInicial, LinhaInicial);
                cout << "0" << endl;
            }

            LinhaInicial--;
        }

        LinhaInicial += 5;

        ParaOuNao = matriz [LinhaInicial][(ColunaInicial-1)];

        if (ParaOuNao != 0)
        {
            break;
        }

        espera (TEMPO);

        if (kbhit())
        {
            char TECLA = getch();

            if (TECLA == 'a' && matriz [(LinhaInicial-1)][(ColunaInicial-2)] == 0 && ColunaInicial > 1)
            {
                ColunaInicial --;
            }
            else if (TECLA == 'd' && matriz [(LinhaInicial-1)][ColunaInicial] == 0 && ColunaInicial < 18)
            {
                ColunaInicial++;
            }
            else if (TECLA == 'w' && matriz [LinhaInicial][(ColunaInicial+2)] == 0 && matriz [LinhaInicial][(ColunaInicial+1)] == 0 && matriz [LinhaInicial][ColunaInicial] == 0 && matriz [LinhaInicial][(ColunaInicial-1)] == 0 && ColunaInicial < 15)
            {
                PECA1_2 (matriz, LinhaInicial, ColunaInicial);
                return 0;
            }
            else if (TECLA == 'l')
            {
                TEMPO = 0;
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        matriz[(LinhaInicial-1)][(ColunaInicial-1)] = 1;
        LinhaInicial --;
    }
}

// 0000

int PECA1_2 (int matriz [24][18], int LinhaInicial, int ColunaInicial)
{
    int ParaOuNao1 = matriz [LinhaInicial][ColunaInicial];
    int ParaOuNao2 = matriz [LinhaInicial][(ColunaInicial+1)];
    int ParaOuNao3 = matriz [LinhaInicial][(ColunaInicial+2)];
    int ParaOuNao4 = matriz [LinhaInicial][(ColunaInicial+3)];
    int TEMPO = 30;

    while (ParaOuNao1 == 0 && ParaOuNao2 == 0 && ParaOuNao3 == 0 && ParaOuNao4 == 0)
    {
        MostraTela(matriz);
        MenuInicial();

        mudaCor (WHITE, WHITE);

        for (int i = 0; i < 4; i++)
        {
            if (LinhaInicial >= 1)
            {
                gotoXY (ColunaInicial, LinhaInicial);
                cout << "0" << endl;
            }

            ColunaInicial++;
        }

        ColunaInicial -= 4;
        LinhaInicial++;

        ParaOuNao1 = matriz [LinhaInicial][(ColunaInicial-1)];
        ParaOuNao2 = matriz [LinhaInicial][ColunaInicial];
        ParaOuNao3 = matriz [LinhaInicial][(ColunaInicial+1)];
        ParaOuNao4 = matriz [LinhaInicial][(ColunaInicial+2)];

        if (ParaOuNao1 != 0 || ParaOuNao2 != 0 || ParaOuNao3 != 0 || ParaOuNao4 != 0)
        {
            break;
        }

        espera (TEMPO);

        if (kbhit())
        {
            char TECLA = getch();

            if (TECLA == 'a' && matriz [(LinhaInicial-1)][(ColunaInicial-2)] == 0 && ColunaInicial > 1)
            {
                ColunaInicial --;
            }
            else if (TECLA == 'd' && matriz [(LinhaInicial-1)][(ColunaInicial+3)] == 0 && ColunaInicial < 15)
            {
                ColunaInicial++;
            }
            else if (TECLA == 'w' && matriz [(LinhaInicial-2)][(ColunaInicial-1)] == 0 && matriz [(LinhaInicial-3)][(ColunaInicial-1)] == 0 && matriz [(LinhaInicial-4)][(ColunaInicial-1)] == 0)
            {
                PECA1_1 (matriz, LinhaInicial, ColunaInicial);
                return 0;
            }
            else if (TECLA == 'l')
            {
                TEMPO = 0;
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        matriz[(LinhaInicial-1)][(ColunaInicial-1)] = 1;
        ColunaInicial++;
    }
}

//  0
// 000

int PECA2_1(int matriz [24][18], int LinhaInicial, int ColunaInicial)
{
    int ParaOuNao1 = matriz [LinhaInicial][ColunaInicial];
    int ParaOuNao2 = matriz [LinhaInicial][(ColunaInicial+1)];
    int ParaOuNao3 = matriz [LinhaInicial][(ColunaInicial+2)];
    int TEMPO = 30;

    while (ParaOuNao1 == 0 && ParaOuNao2 == 0 && ParaOuNao3 == 0)
    {
        MostraTela(matriz);
        MenuInicial();

        mudaCor (YELLOW, YELLOW);

        if (LinhaInicial >= 2)
        {
            gotoXY(ColunaInicial+1, LinhaInicial-1);
            cout << "0" << endl;
        }

        for (int i = 0; i < 3; i++)
        {
            if (LinhaInicial >= 1)
            {
                gotoXY (ColunaInicial, LinhaInicial);
                cout << "0" << endl;
            }

            ColunaInicial++;
        }

        ColunaInicial -= 3;
        LinhaInicial++;

        ParaOuNao1 = matriz [LinhaInicial][(ColunaInicial-1)];
        ParaOuNao2 = matriz [LinhaInicial][ColunaInicial];
        ParaOuNao3 = matriz [LinhaInicial][(ColunaInicial+1)];

        if (ParaOuNao1 != 0 || ParaOuNao2 != 0 || ParaOuNao3 != 0)
        {
            break;
        }

        espera (TEMPO);

        if (kbhit())
        {
            char TECLA = getch();

            if (TECLA == 'a' && ColunaInicial > 1 && matriz [LinhaInicial][(ColunaInicial-2)] == 0)
            {
                ColunaInicial --;
            }
            else if (TECLA == 'd' && ColunaInicial < 16 && matriz [LinhaInicial][(ColunaInicial+2)] == 0)
            {
                ColunaInicial++;
            }
            else if (TECLA == 'w' && matriz [LinhaInicial][(ColunaInicial-1)] == 0 && matriz [(LinhaInicial-2)][(ColunaInicial-1)] == 0)
            {
                PECA2_2 (matriz, LinhaInicial, ColunaInicial);
                return 0;
            }
            else if (TECLA == 'l')
            {
                TEMPO = 0;
            }
        }
    }

    matriz [(LinhaInicial-2)][ColunaInicial] = 1;

    for (int i = 0; i < 3; i++)
    {
        matriz[(LinhaInicial-1)][(ColunaInicial-1)] = 1;
        ColunaInicial++;
    }
}

//0
//00
//0

int PECA2_2(int matriz [24][18], int LinhaInicial, int ColunaInicial)
{
    int ParaOuNao1 = matriz [LinhaInicial][(ColunaInicial-1)];
    int ParaOuNao2 = matriz [(LinhaInicial-1)][ColunaInicial];
    int TEMPO = 30;

    while (ParaOuNao1 == 0 && ParaOuNao2 == 0)
    {
        MostraTela(matriz);
        MenuInicial();

        mudaCor (YELLOW, YELLOW);

        if (LinhaInicial >= 2)
        {
            gotoXY (ColunaInicial+1, LinhaInicial-1);
            cout << "0" << endl;
        }

        for (int i = 0; i < 3; i++)
        {
            if (LinhaInicial >= 1)
            {
                gotoXY (ColunaInicial, LinhaInicial);
                cout << "0" << endl;
            }

            LinhaInicial--;
        }

        LinhaInicial+= 4;

        int ParaOuNao1 = matriz [LinhaInicial][(ColunaInicial-1)];
        int ParaOuNao2 = matriz [(LinhaInicial-1)][ColunaInicial];

        if (ParaOuNao1 != 0 || ParaOuNao2 != 0)
        {
            break;
        }

        espera (TEMPO);

        if (kbhit())
        {
            char TECLA = getch();

            if (TECLA == 'a' && ColunaInicial > 1 && matriz [LinhaInicial][(ColunaInicial-2)] == 0)
            {
                ColunaInicial --;
            }
            else if (TECLA == 'd' && ColunaInicial < 17 && matriz [(LinhaInicial-1)][(ColunaInicial+1)] == 0 && matriz [LinhaInicial][ColunaInicial] == 0)
            {
                ColunaInicial++;
            }
            else if (TECLA == 'w' && matriz [(LinhaInicial+1)][ColunaInicial] == 0 && matriz [(LinhaInicial-1)][(ColunaInicial+1)] == 0)
            {
                PECA2_3 (matriz, LinhaInicial, ColunaInicial);
                return 0;
            }
            else if (TECLA == 'l')
            {
                TEMPO = 0;
            }
        }
    }

    matriz [(LinhaInicial-2)][ColunaInicial] = 1;

    for (int i = 0; i < 3; i++)
    {
        matriz[(LinhaInicial-1)][(ColunaInicial-1)] = 1;
        LinhaInicial--;
    }
}

//000
// 0

int PECA2_3(int matriz [24][18], int LinhaInicial, int ColunaInicial)
{
    int ParaOuNao1 = matriz [LinhaInicial][(ColunaInicial-1)];
    int ParaOuNao2 = matriz [LinhaInicial+1][ColunaInicial];
    int ParaOuNao3 = matriz [LinhaInicial][(ColunaInicial+1)];
    int TEMPO = 30;

    while (ParaOuNao1 == 0 && ParaOuNao2 == 0 && ParaOuNao3 == 0)
    {
        MostraTela(matriz);
        MenuInicial();

        mudaCor (YELLOW, YELLOW);

        for (int i = 0; i < 3; i++)
        {
            if (LinhaInicial >= 1)
            {
                gotoXY (ColunaInicial, LinhaInicial);
                cout << "0" << endl;
            }

            ColunaInicial++;
        }

        ColunaInicial-= 3;

        gotoXY ((ColunaInicial+1), (LinhaInicial+1));
        cout <<"0"<< endl;

        LinhaInicial++;

        int ParaOuNao1 = matriz [LinhaInicial][(ColunaInicial-1)];
        int ParaOuNao2 = matriz [LinhaInicial+1][ColunaInicial];
        int ParaOuNao3 = matriz [LinhaInicial][(ColunaInicial+1)];

        if (ParaOuNao1 != 0 || ParaOuNao2 != 0 || ParaOuNao3 != 0)
        {
            break;
        }

        espera (TEMPO);

        if (kbhit())
        {
            char TECLA = getch();

            if (TECLA == 'a' && ColunaInicial > 1 && matriz [LinhaInicial][(ColunaInicial-2)] == 0 && matriz [(LinhaInicial+1)][(ColunaInicial-1)] == 0)
            {
                ColunaInicial --;
            }
            else if (TECLA == 'd' && ColunaInicial < 16 && matriz [LinhaInicial][(ColunaInicial+2)] == 0 && matriz [(LinhaInicial+1)][(ColunaInicial+1)] == 0)
            {
                ColunaInicial++;
            }
            else if (TECLA == 'w' && matriz [(LinhaInicial+1)][(ColunaInicial-1)] == 0 && matriz [LinhaInicial][(ColunaInicial-2)] == 0)
            {
                PECA2_4 (matriz, LinhaInicial, ColunaInicial);
                return 0;
            }
            else if (TECLA == 'l')
            {
                TEMPO = 0;
            }
        }
    }

    matriz [LinhaInicial][ColunaInicial] = 1;

    for (int i = 0; i < 3; i++)
    {
        matriz[(LinhaInicial-1)][(ColunaInicial-1)] = 1;
        ColunaInicial++;
    }
}

// 0
//00
// 0

int PECA2_4(int matriz [24][18], int LinhaInicial, int ColunaInicial)
{
    int ParaOuNao1 = matriz [(LinhaInicial-1)][ColunaInicial-2];
    int ParaOuNao2 = matriz [LinhaInicial][(ColunaInicial-1)];
    int TEMPO = 30;

    while (ParaOuNao1 == 0 && ParaOuNao2 == 0)
    {
        MostraTela(matriz);
        MenuInicial();

        mudaCor (YELLOW, YELLOW);

        if (LinhaInicial >= 2)
        {
            gotoXY (ColunaInicial-1, LinhaInicial-1);
            cout <<"0" << endl;
        }

        for (int i = 0; i < 3; i++)
        {
            if (LinhaInicial >= 1)
            {
                gotoXY (ColunaInicial, LinhaInicial);
                cout << "0" << endl;
            }

            LinhaInicial--;
        }

        LinhaInicial+=4;

        int ParaOuNao1 = matriz [(LinhaInicial-1)][(ColunaInicial-2)];
        int ParaOuNao2 = matriz [LinhaInicial][(ColunaInicial-1)];

        if (ParaOuNao1 != 0 || ParaOuNao2 != 0)
        {
            break;
        }

        espera (TEMPO);

        if (kbhit())
        {
            char TECLA = getch();

            if (TECLA == 'a' && ColunaInicial > 2 && matriz [(LinhaInicial-1)][(ColunaInicial-3)] == 0 && matriz [LinhaInicial][(ColunaInicial-2)] == 0)
            {
                ColunaInicial --;
            }
            else if (TECLA == 'd' && ColunaInicial < 18 && matriz [LinhaInicial][ColunaInicial] == 0 && matriz [(LinhaInicial-1)][ColunaInicial] == 0)
            {
                ColunaInicial++;
            }
            else if (TECLA == 'w' && matriz [(LinhaInicial-1)][ColunaInicial] == 0 && matriz [LinhaInicial][(ColunaInicial+1)] == 0)
            {
                PECA2_1 (matriz, LinhaInicial, ColunaInicial);
                return 0;
            }
            else if (TECLA == 'l')
            {
                TEMPO = 0;
            }
        }
    }

    matriz [(LinhaInicial-2)][(ColunaInicial-2)] = 1;

    for (int i = 0; i < 3; i++)
    {
        matriz[(LinhaInicial-1)][(ColunaInicial-1)] = 1;
        LinhaInicial--;
    }
}

// 0
//00
//0

int PECA3_1(int matriz [24][18], int LinhaInicial, int ColunaInicial)
{
    int ParaOuNao1 = matriz [LinhaInicial][(ColunaInicial-1)];
    int ParaOuNao2 = matriz [LinhaInicial-1][ColunaInicial];
    int TEMPO = 30;

    while (ParaOuNao1 == 0 && ParaOuNao2 == 0)
    {
        MostraTela(matriz);
        MenuInicial();

        mudaCor (CYAN, CYAN);

        gotoXY(ColunaInicial, LinhaInicial);
        cout << "0" << endl;


        for (int i = 0; i < 2; i++)
        {
            if (LinhaInicial >=2)
            {
                gotoXY (ColunaInicial, LinhaInicial-1);
                cout << "0" << endl;
            }
            ColunaInicial++;
        }

        ColunaInicial-=2;

        if (LinhaInicial >= 3)
        {
            gotoXY(ColunaInicial+1, LinhaInicial-2);
            cout << "0" << endl;
        }

        LinhaInicial++;

        int ParaOuNao1 = matriz [LinhaInicial][(ColunaInicial-1)];
        int ParaOuNao2 = matriz [(LinhaInicial-1)][ColunaInicial];

        if (ParaOuNao1 != 0 || ParaOuNao2 != 0)
        {
            break;
        }

        espera (TEMPO);

        if (kbhit())
        {
            char TECLA = getch();

            if (TECLA == 'a' && ColunaInicial > 1 && matriz [(LinhaInicial+1)][(ColunaInicial-2)] == 0)
            {
                ColunaInicial --;
            }
            else if (TECLA == 'd' && ColunaInicial < 17 && matriz [(LinhaInicial+1)][ColunaInicial] == 0 && matriz [LinhaInicial][(ColunaInicial+1)] == 0)
            {
                ColunaInicial++;
            }
            else if (TECLA == 'w' && ColunaInicial < 17 && matriz [(LinhaInicial+1)][(ColunaInicial+1)] == 0 && matriz [(LinhaInicial+1)][ColunaInicial] == 0)
            {
                PECA3_2 (matriz, LinhaInicial, ColunaInicial);
                return 0;
            }
            else if (TECLA == 'l')
            {
                TEMPO = 0;
            }
        }
    }

    matriz [(LinhaInicial-2)][ColunaInicial] = 1;
    matriz [(LinhaInicial-3)][ColunaInicial] = 1;
    matriz [(LinhaInicial-1)][(ColunaInicial-1)] = 1;
    matriz [(LinhaInicial-2)][(ColunaInicial-1)] = 1;
}

//00
// 00

int PECA3_2(int matriz [24][18], int LinhaInicial, int ColunaInicial)
{
    int ParaOuNao1 = matriz [LinhaInicial][(ColunaInicial-1)];
    int ParaOuNao2 = matriz [LinhaInicial+1][ColunaInicial];
    int ParaOuNao3 = matriz [LinhaInicial+1][(ColunaInicial+1)];
    int TEMPO = 30;

    while (ParaOuNao1 == 0 && ParaOuNao2 == 0 && ParaOuNao3 == 0)
    {
        MostraTela(matriz);
        MenuInicial();

        mudaCor (CYAN, CYAN);


        for (int i = 0; i < 2; i++)
        {
            if (LinhaInicial >=2)
            {
                gotoXY (ColunaInicial, LinhaInicial);
                cout <<"0" << endl;
            }
            ColunaInicial++;
        }

        ColunaInicial-=2;

        for (int i = 0; i < 2; i++)
        {
            gotoXY(ColunaInicial+1, LinhaInicial+1);
            cout <<"0" << endl;
            ColunaInicial++;
        }

        ColunaInicial-=2;

        LinhaInicial++;

        int ParaOuNao1 = matriz [LinhaInicial][(ColunaInicial-1)];
        int ParaOuNao2 = matriz [LinhaInicial+1][ColunaInicial];
        int ParaOuNao3 = matriz [LinhaInicial+1][(ColunaInicial+1)];

        if (ParaOuNao1 != 0 || ParaOuNao2 != 0 || ParaOuNao3 != 0)
        {
            break;
        }

        espera (TEMPO);

        if (kbhit())
        {
            char TECLA = getch();

            if (TECLA == 'a' && ColunaInicial > 1 && matriz [LinhaInicial][(ColunaInicial-2)] == 0 && matriz [(LinhaInicial+1)][(ColunaInicial-1)] == 0)
            {
                ColunaInicial --;
            }
            else if (TECLA == 'd' && ColunaInicial < 16 && matriz [(LinhaInicial+1)][(ColunaInicial+2)] == 0)
            {
                ColunaInicial++;
            }
            else if (TECLA == 'w' && matriz [(LinhaInicial-3)][ColunaInicial] == 0)
            {
                PECA3_1 (matriz, LinhaInicial, ColunaInicial);
                return 0;
            }
            else if (TECLA == 'l')
            {
                TEMPO = 0;
            }
        }
    }

    matriz [(LinhaInicial-1)][(ColunaInicial-1)] = 1;
    matriz [(LinhaInicial-1)][ColunaInicial] = 1;
    matriz [LinhaInicial][ColunaInicial] = 1;
    matriz [LinhaInicial][(ColunaInicial+1)] = 1;
}

//0
//00
// 0

int PECA4_1(int matriz [24][18], int LinhaInicial, int ColunaInicial)
{
    int ParaOuNao1 = matriz [LinhaInicial][(ColunaInicial-1)];
    int ParaOuNao2 = matriz [LinhaInicial+1][ColunaInicial];
    int TEMPO = 30;

    while (ParaOuNao1 == 0 && ParaOuNao2 == 0)
    {
        MostraTela(matriz);
        MenuInicial();

        mudaCor (GREEN, GREEN);

        for (int i = 0; i < 2; i++)
        {
            if (LinhaInicial >=2)
            {
                gotoXY (ColunaInicial, LinhaInicial);
                cout <<"0" << endl;
            }
            LinhaInicial--;
        }

        LinhaInicial+=2;

        for (int i = 0; i < 2; i++)
        {
            if (LinhaInicial >=2)
            {
                gotoXY (ColunaInicial+1, LinhaInicial+1);
                cout << "0"<< endl;
            }
            LinhaInicial--;
        }


        LinhaInicial+= 3;

        int ParaOuNao1 = matriz [LinhaInicial][(ColunaInicial-1)];
        int ParaOuNao2 = matriz [(LinhaInicial+1)][ColunaInicial];

        if (ParaOuNao1 != 0 || ParaOuNao2 != 0)
        {
            break;
        }

        espera (TEMPO);

        if (kbhit())
        {
            char TECLA = getch();

            if (TECLA == 'a' && matriz [LinhaInicial][ColunaInicial-2] == 0 && ColunaInicial > 1)
            {
                ColunaInicial --;
            }
            else if (TECLA == 'd' && matriz [LinhaInicial+1][ColunaInicial+1] == 0 && ColunaInicial < 17)
            {
                ColunaInicial++;
            }
            else if (TECLA == 'w' && matriz [LinhaInicial+1][ColunaInicial+1] == 0 && ColunaInicial < 17)
            {
                PECA4_2 (matriz, LinhaInicial, ColunaInicial);
                return 0;
            }
            else if (TECLA == 'l')
            {
                TEMPO = 0;
            }
        }
    }

    matriz [(LinhaInicial-1)][(ColunaInicial-1)] = 1;
    matriz [(LinhaInicial-2)][(ColunaInicial-1)] = 1;
    matriz [(LinhaInicial-1)][ColunaInicial] = 1;
    matriz [LinhaInicial][ColunaInicial] = 1;

}

// 00
//00

int PECA4_2(int matriz [24][18], int LinhaInicial, int ColunaInicial)
{
    int ParaOuNao1 = matriz [LinhaInicial][(ColunaInicial-1)];
    int ParaOuNao2 = matriz [LinhaInicial][ColunaInicial];
    int ParaOuNao3 = matriz [LinhaInicial-1][(ColunaInicial+1)];
    int TEMPO =30;

    while (ParaOuNao1 == 0 && ParaOuNao2 == 0 && ParaOuNao3 == 0)
    {
        MostraTela(matriz);
        MenuInicial();

        mudaCor (GREEN, GREEN);


        for (int i = 0; i < 2; i++)
        {
            gotoXY (ColunaInicial, LinhaInicial);
            cout <<"0";
            ColunaInicial++;
        }

        ColunaInicial-=2;

        for (int i = 0; i < 2; i++)
        {
            gotoXY(ColunaInicial+1, LinhaInicial-1);
            cout <<"0" << endl;
            ColunaInicial++;
        }

        ColunaInicial-=2;

        LinhaInicial++;

        int ParaOuNao1 = matriz [LinhaInicial][(ColunaInicial-1)];
        int ParaOuNao2 = matriz [LinhaInicial][ColunaInicial];
        int ParaOuNao3 = matriz [LinhaInicial-1][(ColunaInicial+1)];

        if (ParaOuNao1 != 0 || ParaOuNao2 != 0 || ParaOuNao3 != 0)
        {
            break;
        }

        espera (TEMPO);

        if (kbhit())
        {
            char TECLA = getch();

            if (TECLA == 'a' && matriz [LinhaInicial-1][ColunaInicial-2] == 0 && ColunaInicial > 1)
            {
                ColunaInicial --;
            }
            else if (TECLA == 'd' && matriz [LinhaInicial-2][ColunaInicial+3] == 0 && ColunaInicial < 16)
            {
                ColunaInicial++;
            }
            else if (TECLA == 'w' && matriz [LinhaInicial-3][ColunaInicial-1] == 0)
            {
                PECA4_1 (matriz, LinhaInicial, ColunaInicial);
                return 0;
            }
            else if (TECLA == 'l')
            {
                TEMPO = 0;
            }
        }
    }

    matriz [(LinhaInicial-1)][(ColunaInicial-1)] = 1;
    matriz [(LinhaInicial-1)][ColunaInicial] = 1;
    matriz [LinhaInicial-2][ColunaInicial] = 1;
    matriz [LinhaInicial-2][(ColunaInicial+1)] = 1;
}

//00
//0
//0

int PECA5_1 (int matriz [24][18], int LinhaInicial, int ColunaInicial)
{
    int ParaOuNao1 = 0;
    int ParaOuNao2 = 0;
    int TEMPO = 30;

    while (ParaOuNao1 == 0 && ParaOuNao2 == 0)
    {
        MostraTela(matriz);
        MenuInicial();

        mudaCor (PURPLE, PURPLE);

        if (LinhaInicial >= 3)
        {
            gotoXY (ColunaInicial+1, LinhaInicial-2);
            cout <<"0";
        }

        for (int i = 0; i < 3; i++)
        {
            if (LinhaInicial >= 1)
            {
                gotoXY (ColunaInicial, LinhaInicial);
                cout << "0";
            }

            LinhaInicial--;
        }

        LinhaInicial+= 4;

        gotoXY (ColunaInicial, LinhaInicial);
        cout << "0";

        int ParaOuNao1 = matriz [LinhaInicial][(ColunaInicial-1)];
        int ParaOuNao2 = matriz [(LinhaInicial-2)][ColunaInicial];

        if (ParaOuNao1 != 0 || ParaOuNao2 != 0)
        {
            break;
        }

        espera (TEMPO);

        if (kbhit())
        {
            char TECLA = getch();

            if (TECLA == 'a' && ColunaInicial > 1 && matriz [LinhaInicial][(ColunaInicial-2)] == 0 && matriz [(LinhaInicial-1)][(ColunaInicial-2)] == 0)
            {
                ColunaInicial --;
            }
            else if (TECLA == 'd' && ColunaInicial < 17 && matriz [(LinhaInicial-2)][(ColunaInicial+1)] == 0 && matriz [LinhaInicial][ColunaInicial] == 0)
            {
                ColunaInicial++;
            }
            else if (TECLA == 'w' && ColunaInicial < 17 && matriz [LinhaInicial][(ColunaInicial+1)] == 0 && matriz [LinhaInicial][ColunaInicial] == 0)
            {
                PECA5_2 (matriz, LinhaInicial, ColunaInicial);
                return 0;
            }
            else if (TECLA == 'l')
            {
                TEMPO = 0;
            }
        }
    }

    matriz [(LinhaInicial-3)][ColunaInicial] = 1;

    for (int i = 0; i < 3; i++)
    {
        matriz[LinhaInicial-1][(ColunaInicial-1)] = 1;
        LinhaInicial--;
    }

}

//000
//  0

int PECA5_2(int matriz [24][18], int LinhaInicial, int ColunaInicial)
{
    int ParaOuNao1 = matriz [LinhaInicial][(ColunaInicial-1)];
    int ParaOuNao2 = matriz [LinhaInicial+1][ColunaInicial+1];
    int ParaOuNao3 = matriz [LinhaInicial][ColunaInicial];
    int TEMPO = 30;

    while (ParaOuNao1 == 0 && ParaOuNao2 == 0 && ParaOuNao3 == 0)
    {
        MostraTela(matriz);
        MenuInicial();

        mudaCor (PURPLE, PURPLE);

        for (int i = 0; i < 3; i++)
        {
            gotoXY (ColunaInicial, LinhaInicial);
            cout << "0" << endl;
            ColunaInicial++;
        }

        ColunaInicial-=3;

        gotoXY(ColunaInicial+2, LinhaInicial+1);
        cout << "0" << endl;

        LinhaInicial++;

        int ParaOuNao1 = matriz [LinhaInicial][(ColunaInicial-1)];
        int ParaOuNao2 = matriz [LinhaInicial+1][ColunaInicial+1];
        int ParaOuNao3 = matriz [LinhaInicial][ColunaInicial];

        if (ParaOuNao1 != 0 || ParaOuNao2 != 0 || ParaOuNao3 != 0)
        {
            break;
        }

        espera (TEMPO);

        if (kbhit())
        {
            char TECLA = getch();

            if (TECLA == 'a' && ColunaInicial > 1 && matriz [LinhaInicial][(ColunaInicial-2)] == 0 && matriz [(LinhaInicial+1)][ColunaInicial] == 0)
            {
                ColunaInicial --;
            }
            else if (TECLA == 'd' && ColunaInicial < 16 && matriz [(LinhaInicial+1)][(ColunaInicial+2)] == 0)
            {
                ColunaInicial++;
            }
            else if (TECLA == 'w' && ColunaInicial > 1 && matriz [LinhaInicial][(ColunaInicial-1)] == 0 && matriz [(LinhaInicial-2)][ColunaInicial] == 0)
            {
                PECA5_3 (matriz, LinhaInicial, ColunaInicial);
                return 0;
            }
            else if (TECLA == 'l')
            {
                TEMPO = 0;
            }
        }
    }

    matriz [LinhaInicial][(ColunaInicial+1)] = 1;

    for (int i = 0; i < 3; i++)
    {
        matriz[(LinhaInicial-1)][(ColunaInicial-1)] = 1;
        ColunaInicial++;
    }
}

// 0
// 0
//00

int PECA5_3(int matriz [24][18], int LinhaInicial, int ColunaInicial)
{
    int ParaOuNao1 = matriz [LinhaInicial][(ColunaInicial-1)];
    int ParaOuNao2 = matriz [LinhaInicial][(ColunaInicial-2)];
    int TEMPO = 30;

    while (ParaOuNao1 == 0 && ParaOuNao2 == 0)
    {
        MostraTela(matriz);
        MenuInicial();

        mudaCor (PURPLE, PURPLE);

        if (LinhaInicial >= 2)
        {
            gotoXY (ColunaInicial-1, LinhaInicial);
            cout <<"0";
        }

        for (int i = 0; i < 3; i++)
        {
            if (LinhaInicial >= 1)
            {
                gotoXY (ColunaInicial, LinhaInicial);
                cout << "0" << endl;
            }

            LinhaInicial--;
        }

        LinhaInicial+=4;

        int ParaOuNao1 = matriz [LinhaInicial][(ColunaInicial-1)];
        int ParaOuNao2 = matriz [LinhaInicial][(ColunaInicial-2)];

        if (ParaOuNao1 != 0 || ParaOuNao2 != 0)
        {
            break;
        }

        espera (TEMPO);

        if (kbhit())
        {
            char TECLA = getch();

            if (TECLA == 'a' && ColunaInicial > 2 && matriz [LinhaInicial][(ColunaInicial-3)] == 0)
            {
                ColunaInicial --;
            }
            else if (TECLA == 'd' && ColunaInicial < 18 && matriz [LinhaInicial][ColunaInicial] == 0)
            {
                ColunaInicial++;
            }
            else if (TECLA == 'w'&& ColunaInicial < 17 && matriz [LinhaInicial][(ColunaInicial+1)] == 0)
            {
                PECA5_4 (matriz, LinhaInicial, ColunaInicial);
                return 0;
            }
            else if (TECLA == 'l')
            {
                TEMPO = 0;
            }
        }
    }

    matriz [(LinhaInicial-1)][(ColunaInicial-2)] = 1;

    for (int i = 0; i < 3; i++)
    {
        matriz[(LinhaInicial-1)][(ColunaInicial-1)] = 1;
        LinhaInicial--;
    }
}

//0
//000

int PECA5_4(int matriz [24][18], int LinhaInicial, int ColunaInicial)
{
    int ParaOuNao1 = matriz [LinhaInicial][(ColunaInicial-1)];
    int ParaOuNao2 = matriz [LinhaInicial][ColunaInicial];
    int ParaOuNao3 = matriz [LinhaInicial][(ColunaInicial+1)];
    int TEMPO = 30;

    while (ParaOuNao1 == 0 && ParaOuNao2 == 0 && ParaOuNao3 == 0)
    {
        MostraTela(matriz);
        MenuInicial();

        mudaCor (PURPLE, PURPLE);

        if (LinhaInicial >= 2)
        {
            gotoXY(ColunaInicial, LinhaInicial-1);
            cout << "0";
        }

        for (int i = 0; i < 3; i++)
        {
            gotoXY (ColunaInicial, LinhaInicial);
            cout << "0" << endl;
            ColunaInicial++;
        }

        ColunaInicial -= 3;
        LinhaInicial++;

        ParaOuNao1 = matriz [LinhaInicial][(ColunaInicial-1)];
        ParaOuNao2 = matriz [LinhaInicial][ColunaInicial];
        ParaOuNao3 = matriz [LinhaInicial][(ColunaInicial+1)];

        if (ParaOuNao1 != 0 || ParaOuNao2 != 0 || ParaOuNao3 != 0)
        {
            break;
        }

        espera (TEMPO);

        if (kbhit())
        {
            char TECLA = getch();

            if (TECLA == 'a' && ColunaInicial > 1 && matriz [LinhaInicial][ColunaInicial-2] == 0 )
            {
                ColunaInicial --;
            }
            else if (TECLA == 'd' && ColunaInicial < 16 && matriz [LinhaInicial][ColunaInicial+2] == 0)
            {
                ColunaInicial++;
            }
            else if (TECLA == 'w' && matriz [LinhaInicial-3][ColunaInicial-2] == 0 && matriz [LinhaInicial-3][ColunaInicial-1] == 0)
            {
                PECA5_1 (matriz, LinhaInicial, ColunaInicial);
                return 0;
            }
            else if (TECLA == 'l')
            {
                TEMPO = 0;
            }
        }
    }

    matriz [(LinhaInicial-2)][(ColunaInicial-1)] = 1;

    for (int i = 0; i < 3; i++)
    {
        matriz[(LinhaInicial-1)][(ColunaInicial-1)] = 1;
        ColunaInicial++;
    }
}

//00
// 0
// 0

int PECA6_1 (int matriz [24][18], int LinhaInicial, int ColunaInicial)
{
    int ParaOuNao1 = 0;
    int ParaOuNao2 = 0;
    int TEMPO = 30;

    while (ParaOuNao1 == 0 && ParaOuNao2 == 0)
    {
        MostraTela(matriz);
        MenuInicial();

        mudaCor (BLUE, BLUE);

        if (LinhaInicial >= 3)
        {
            gotoXY (ColunaInicial-1, LinhaInicial-2);
            cout <<"0"<< endl;
        }

        for (int i = 0; i < 3; i++)
        {
            if (LinhaInicial >= 1)
            {
                gotoXY (ColunaInicial, LinhaInicial);
                cout << "0" << endl;
            }

            LinhaInicial--;
        }

        LinhaInicial+= 4;

        int ParaOuNao1 = matriz [LinhaInicial][(ColunaInicial-1)];
        int ParaOuNao2 = matriz [(LinhaInicial-2)][(ColunaInicial-2)];

        if (ParaOuNao1 != 0 || ParaOuNao2 != 0)
        {
            break;
        }

        espera (TEMPO);

        if (kbhit())
        {
            char TECLA = getch();

            if (TECLA == 'a' && ColunaInicial > 2 && matriz[LinhaInicial-2][ColunaInicial-3] == 0)
            {
                ColunaInicial --;
            }
            else if (TECLA == 'd' && ColunaInicial < 18 && matriz[LinhaInicial][ColunaInicial] == 0)
            {
                ColunaInicial++;
            }
            else if (TECLA == 'w' && ColunaInicial < 16 && matriz[LinhaInicial][(ColunaInicial+1)] == 0)
            {
                PECA6_2 (matriz, LinhaInicial, ColunaInicial);
                return 0;
            }
            else if (TECLA == 'l')
            {
                TEMPO = 0;
            }
        }
    }

    matriz [(LinhaInicial-3)][(ColunaInicial-2)] = 1;

    for (int i = 0; i < 3; i++)
    {
        matriz[LinhaInicial-1][(ColunaInicial-1)] = 1;
        LinhaInicial--;
    }

}

//  0
//000

int PECA6_2(int matriz [24][18], int LinhaInicial, int ColunaInicial)
{
    int ParaOuNao1 = matriz [LinhaInicial][(ColunaInicial-1)];
    int ParaOuNao2 = matriz [LinhaInicial][ColunaInicial+1];
    int ParaOuNao3 = matriz [LinhaInicial][ColunaInicial];
    int TEMPO = 30;

    while (ParaOuNao1 == 0 && ParaOuNao2 == 0 && ParaOuNao3 == 0)
    {
        MostraTela(matriz);
        MenuInicial();

        mudaCor (BLUE, BLUE);

        for (int i = 0; i < 3; i++)
        {
            gotoXY (ColunaInicial, LinhaInicial);
            cout << "0";
            ColunaInicial++;
        }

        ColunaInicial-=3;

        gotoXY(ColunaInicial+2, LinhaInicial-1);
        cout << "0" << endl;

        LinhaInicial++;

        int ParaOuNao1 = matriz [LinhaInicial][(ColunaInicial-1)];
        int ParaOuNao2 = matriz [LinhaInicial][ColunaInicial+1];
        int ParaOuNao3 = matriz [LinhaInicial][ColunaInicial];

        if (ParaOuNao1 != 0 || ParaOuNao2 != 0 || ParaOuNao3 != 0)
        {
            break;
        }

        espera (TEMPO);

        if (kbhit())
        {
            char TECLA = getch();

            if (TECLA == 'a' && ColunaInicial > 1 && matriz[LinhaInicial][ColunaInicial-2] == 0)
            {
                ColunaInicial --;
            }
            else if (TECLA == 'd' && ColunaInicial < 16 && matriz[LinhaInicial][ColunaInicial+2] == 0)
            {
                ColunaInicial++;
            }
            else if (TECLA == 'w' && matriz[LinhaInicial-2][ColunaInicial-1] == 0 && matriz[LinhaInicial-3][ColunaInicial-1] == 0)
            {
                PECA6_3 (matriz, LinhaInicial, ColunaInicial);
                return 0;
            }
            else if (TECLA == 'l')
            {
                TEMPO = 0;
            }
        }
    }

    matriz [(LinhaInicial-2)][(ColunaInicial+1)] = 1;

    for (int i = 0; i < 3; i++)
    {
        matriz[(LinhaInicial-1)][(ColunaInicial-1)] = 1;
        ColunaInicial++;
    }
}

//0
//0
//00

int PECA6_3 (int matriz [24][18], int LinhaInicial, int ColunaInicial)
{
    int ParaOuNao1 = matriz [LinhaInicial][(ColunaInicial-1)];
    int ParaOuNao2 = matriz [LinhaInicial][ColunaInicial];
    int TEMPO =30;

    while (ParaOuNao1 == 0 && ParaOuNao2 == 0)
    {
        MostraTela(matriz);
        MenuInicial();

        mudaCor (BLUE, BLUE);

        if (LinhaInicial >= 2)
        {
            gotoXY (ColunaInicial+1, LinhaInicial);
            cout <<"0" << endl;
        }

        for (int i = 0; i < 3; i++)
        {
            if (LinhaInicial >= 1)
            {
                gotoXY (ColunaInicial, LinhaInicial);
                cout << "0" << endl;
            }

            LinhaInicial--;
        }

        LinhaInicial+=4;

        int ParaOuNao1 = matriz [LinhaInicial][(ColunaInicial-1)];
        int ParaOuNao2 = matriz [LinhaInicial][ColunaInicial];

        if (ParaOuNao1 != 0 || ParaOuNao2 != 0)
        {
            break;
        }

        espera (TEMPO);

        if (kbhit())
        {
            char TECLA = getch();

            if (TECLA == 'a' && ColunaInicial > 1 && matriz [LinhaInicial][(ColunaInicial-2)] == 0)
            {
                ColunaInicial --;
            }
            else if (TECLA == 'd' && ColunaInicial < 17 && matriz [LinhaInicial][ColunaInicial+1] == 0)
            {
                ColunaInicial++;
            }
            else if (TECLA == 'w'&& ColunaInicial < 17 && matriz [LinhaInicial][(ColunaInicial+1)] == 0)
            {
                PECA6_4 (matriz, LinhaInicial, ColunaInicial);
                return 0;
            }
            else if (TECLA == 'l')
            {
                TEMPO = 0;
            }
        }
    }

    matriz [(LinhaInicial-1)][ColunaInicial] = 1;

    for (int i = 0; i < 3; i++)
    {
        matriz[(LinhaInicial-1)][(ColunaInicial-1)] = 1;
        LinhaInicial--;
    }
}

// 000
// 0

int PECA6_4(int matriz [24][18], int LinhaInicial, int ColunaInicial)
{
    int ParaOuNao1 = matriz [LinhaInicial+1][(ColunaInicial-1)];
    int ParaOuNao2 = matriz [LinhaInicial][ColunaInicial];
    int ParaOuNao3 = matriz [LinhaInicial][(ColunaInicial+1)];
    int TEMPO = 30;

    while (ParaOuNao1 == 0 && ParaOuNao2 == 0 && ParaOuNao3 == 0)
    {
        MostraTela(matriz);
        MenuInicial();

        mudaCor (BLUE, BLUE);

        gotoXY(ColunaInicial, LinhaInicial+1);
        cout << "0" << endl;

        for (int i = 0; i < 3; i++)
        {
            gotoXY (ColunaInicial, LinhaInicial);
            cout << "0" << endl;
            ColunaInicial++;
        }

        ColunaInicial -= 3;
        LinhaInicial++;

        ParaOuNao1 = matriz [LinhaInicial+1][(ColunaInicial-1)];
        ParaOuNao2 = matriz [LinhaInicial][ColunaInicial];
        ParaOuNao3 = matriz [LinhaInicial][(ColunaInicial+1)];

        if (ParaOuNao1 != 0 || ParaOuNao2 != 0 || ParaOuNao3 != 0)
        {
            break;
        }

        espera (TEMPO);

        if (kbhit())
        {
            char TECLA = getch();

            if (TECLA == 'a' && ColunaInicial > 1 && matriz [LinhaInicial+1][ColunaInicial-2] == 0)
            {
                ColunaInicial --;
            }
            else if (TECLA == 'd' && ColunaInicial < 16 && matriz [LinhaInicial][ColunaInicial+2] == 0)
            {
                ColunaInicial++;
            }
            else if (TECLA == 'w' && matriz [LinhaInicial-3][ColunaInicial-1] == 0 && matriz [LinhaInicial-3][ColunaInicial-2] == 0)
            {
                PECA6_1 (matriz, LinhaInicial, ColunaInicial);
                return 0;
            }
            else if (TECLA == 'l')
            {
                TEMPO = 0;
            }
        }
    }

    matriz [LinhaInicial][(ColunaInicial-1)] = 1;

    for (int i = 0; i < 3; i++)
    {
        matriz[(LinhaInicial-1)][(ColunaInicial-1)] = 1;
        ColunaInicial++;
    }
}

//00
//00

int PECA7(int matriz [24][18], int LinhaInicial, int ColunaInicial)
{
    int ParaOuNao1 = matriz [LinhaInicial][(ColunaInicial-1)];
    int ParaOuNao2 = matriz [LinhaInicial][ColunaInicial];
    int TEMPO =30;

    while (ParaOuNao1 == 0 && ParaOuNao2 == 0)
    {
        MostraTela(matriz);
        MenuInicial();

        mudaCor (RED, RED);

        if (LinhaInicial >= 2)
        {
            gotoXY (ColunaInicial, LinhaInicial-1);
            cout << "00" << endl;
        }

        gotoXY (ColunaInicial, LinhaInicial);
        cout << "00" << endl;


        LinhaInicial++;

        int ParaOuNao1 = matriz [LinhaInicial][(ColunaInicial-1)];
        int ParaOuNao2 = matriz [LinhaInicial][ColunaInicial];

        if (ParaOuNao1 != 0 || ParaOuNao2 != 0)
        {
            break;
        }

        espera (TEMPO);

        if (kbhit())
        {
            char TECLA = getch();

            if (TECLA == 'a' && ColunaInicial > 1 && matriz [LinhaInicial][ColunaInicial-2] == 0)
            {
                ColunaInicial --;
            }
            else if (TECLA == 'd' && ColunaInicial < 17 && matriz [LinhaInicial][ColunaInicial+1] == 0)
            {
                ColunaInicial++;
            }
            else if (TECLA == 'l')
            {
                TEMPO = 0;
            }
        }
    }

    matriz [LinhaInicial-2][ColunaInicial-1] = 1;
    matriz [LinhaInicial-2][ColunaInicial] = 1;
    matriz [LinhaInicial-1][ColunaInicial-1] = 1;
    matriz [LinhaInicial-1][ColunaInicial] = 1;
}
