// Matermind_KarlMichel.cpp
// Karl Michel Koerich
// Última atualizacão: 16/09/2013

#include "biblaureano.h" //versão 3.3

int iFuncaoMenu(); //Mostra a Introducão e o menu inicial
int vVerificaAcertos (int *iPalpite, int *iSenha); //Verifica se houve acertos no palpite
void vMostrandroASENHAcerta(int *iSenha); //Mostra a senha certa
void vMostraExplicacao(); //Mostra tabela referente ao número associado à cor
void vFuncaoRetornaCor(int iCorDaFuncao); //Retorna a cor quando solicitada

int main()
{
    while(true) //Loop eterno do jogo
    {

        int iPlay = iFuncaoMenu(); //Chama a funcão que determinara se o jogo deve comecar ou encerrar o programa

        if (iPlay == 2) //Se o valor retornado por iFuncaoMenu() for 2, termina o programa
        {
            return 0;
        }

        //Momento em que é sorteado uma SENHA

        vMostraExplicacao(); //Chama a funcao que mostrará as explicacoes dentro do jogo

        int iSomandoCoresSorteadas = 0; //Esta variável contará até 4 (quantidade de números que serão sorteados)
        int iSorteandoCores; //Esta variável é usada para gerar um número randômico
        int iConfereRepeticoes; //Esta variável armazenara a quantidade de vezes que repetirá um número
        vector <int> iVetorDoSorteio; //Este vetor armazenará a SENHA

        while (iSomandoCoresSorteadas <= 3)  //Enquanto não forem sorteados 4 números
        {

            iSorteandoCores = randomico (0,6); //Gera um número randômico

            iConfereRepeticoes = count(iVetorDoSorteio.begin(), iVetorDoSorteio.end(), iSorteandoCores); //Confere quantas vezes o número randômico aparece no vetor

            if ( iConfereRepeticoes > 0) //Se o já tiver o número no vetor
            {
                iSorteandoCores = randomico (0,6); //Sorteia um novo número
            }
            else //Mas se ainda não tiver o número no vetor
            {
                iVetorDoSorteio.push_back (iSorteandoCores); //Coloca esse número no fim do vetor
                iSomandoCoresSorteadas++; //Adiciona 1 à quantidade de números que devem ser sorteados
            }
        }

        int iSenha[4]; //Vetor que armazenará a senha
        int iPosicoesSenha = 0; //Posicões desse vetor

        vector <int>::iterator iPegandoDoVector; //O iterator para "andar" dentro do iVectorDoSorteio
        iPegandoDoVector = iVetorDoSorteio.begin(); //O iterador fica sendo igual a primeira casa do iVectorDoSorteio

        while (iPegandoDoVector != iVetorDoSorteio.end()) //Passando os valores do iVectorDoSorteio para iPalpite
        {

            iSenha[iPosicoesSenha] = *iPegandoDoVector;
            iPosicoesSenha++;
            iPegandoDoVector++;

        }

        //A partir daqui, o vetor "iSenha" tem armazenado a SENHA em suas respectivas posicões,
        //vamos agora perguntar para o jogador o seu palpite sobre a sequência da SENHA

        ////////////////////////////////////////////////////////////////////////////////////////

        //Perguntando o palpite para o jogador

        gotoXY(1,1); //Local da pergunta
        int iLinhaY = 22; //Variavel y para pocicao de apresentacao de cores
        int iColunaX = 21; //Variavel x para pocicao de apresentacao de cores
        int iSenhasTentadas = 0; // Aramazenará quantas senhas foram tentadas, até 10

        while(true)
        {
            string stPalpite = readString ("PALPITE: "); //Pergunta o palpite

            int iPdPalpite = 0; //Posicoes do Palpite

            while (iPdPalpite <= 3) //Confere se o tamnho do palpite é de 4 e se apenas possui os números possíveis
            {
                if (stPalpite.size() != 4)
                {
                    apagaLinha(1,1);
                    stPalpite = readString ("PALPITE: ");
                    iPdPalpite= 0;
                }
                if (stPalpite.at(iPdPalpite) !='0' && stPalpite.at(iPdPalpite) !='1' && stPalpite.at(iPdPalpite) !='2' && stPalpite.at(iPdPalpite) !='3' && stPalpite.at(iPdPalpite) !='4' && stPalpite.at(iPdPalpite) !='5')
                {
                    apagaLinha(1,1);
                    stPalpite = readString ("PALPITE: ");
                    iPdPalpite= 0;
                }
                else
                {
                    iPdPalpite++;
                }
            }

            ////////////////////////////////////////////////////////////////////////////////////////

            //Passsando agora os valores do Palpite(st) para o Palpite(int)

            int iPalpite[4]; //Palpite e seu tamanho (4)
            int iPosicoesPalpite = 0; //Posicoes do Palpite

            while (iPosicoesPalpite <= 3) //Enquanto não armazena de todas as posicoes
            {
                iPalpite[iPosicoesPalpite] = stPalpite.at(iPosicoesPalpite) - 48; // -48 pois estamos analizando o código ASC, e queremos o valor int
                iPosicoesPalpite++;
            }

            ////////////////////////////////////////////////////////////////////////////////////////

            //Fazendo aparecer as cores do palpite do usuário

            int iCoresJaUsadasDoUsuario = 0; //Numero de cores do Palpite que vão aparecer
            int iCorDaFuncao; //Variável que armazena o número do palpite em tal posicão

            while (iCoresJaUsadasDoUsuario <= 3) //Somando as cores que apareceram, até 4
            {
                gotoXY (iColunaX, iLinhaY); //Vai para o lugar
                iCorDaFuncao = stPalpite.at(iCoresJaUsadasDoUsuario) - 48; //iCorDaFuncao recebe um valor
                vFuncaoRetornaCor(iCorDaFuncao); //Chama a funcão que retornará a cor
                iColunaX = iColunaX + 3; //Aumenta a coluna
                iCoresJaUsadasDoUsuario++; //Soma o número de cores
            }

            ////////////////////////////////////////////////////////////////////////////////////////

            //Verificando se há acertos

            iPlay = vVerificaAcertos (iPalpite, iSenha); //Chama a funcao em que aparecerá os "+" e "-", se retornar 1, vai encerrar o jogo

            ////////////////////////////////////////////////////////////////////////////////////////

            //Encerrando, ou não, de acordo com o resultado

            apagaLinha(1,1); //Apaga alinha da pergunta
            iLinhaY = iLinhaY - 2; //Próxima linha em que aparecera as cores do usuário
            iColunaX = 21; //Próxima coluna;
            iSenhasTentadas++; //Somando as tentativas do usuário

            if(iSenhasTentadas == 10 || iPlay == 1) //Se já foram as 10 chances ou se o usuário acertou
            {
                gotoXY(11, 2);
                cout << "PRESSIONE UMA TECLA PARA VOLTAR";

                if(iSenhasTentadas == 10)
                {
                    gotoXY(32,4);
                    cout << " QUE PENA, VOCÊ PERDEU!";

                    gotoXY(2,7);
                    cout << "RESPOSTA CORRETA";

                    vMostrandroASENHAcerta(iSenha); //Mostra a senha na tela
                }
                else{}

                while (true) //Enquanto uma tecla não for apertada, o programa não avanca
                {
                    if (kbhit()) //Verifica se algo foi precionado
                    {
                        break;
                    }
                }

                break; //Termina o jogo, e volta para o comeco
            }
        }
    }
}

void vFuncaoRetornaCor(int iCorDaFuncao)
{
    if (iCorDaFuncao == 0)
    {
        mudaCor(YELLOW,YELLOW);
        cout << "  ";
        limpaEfeito();
        cout << " ";
    }
    else if (iCorDaFuncao == 1)
    {
        mudaCor(BLUE,BLUE);
        cout << "  ";
        limpaEfeito();
        cout << " ";
    }
    else if (iCorDaFuncao == 2)
    {
        mudaCor(PURPLE,PURPLE);
        cout << "  ";
        limpaEfeito();
        cout << " ";
    }
    else if (iCorDaFuncao == 3)
    {
        mudaCor(GREEN,GREEN);
        cout << "  ";
        limpaEfeito();
        cout << " ";
    }
    else if (iCorDaFuncao == 4)
    {
        mudaCor(RED,RED);
        cout << "  ";
        limpaEfeito();
        cout << " ";
    }
    else if (iCorDaFuncao == 5)
    {
        mudaCor(CYAN,CYAN);
        cout << "  ";
        limpaEfeito();
        cout << " ";
    }
    else{}
}

void vMostrandroASENHAcerta (int *iSenha)
{
    desligaCursor(true);
    int iCorDaFuncao;
    int iColunaResposta = 4; //Posicão que aparecerá a senha
    int iPegandoDaSenha = 0; //Posicão que aparecerá a senha

    while (iPegandoDaSenha <= 3) //Enquanto não aparecer toda a senha
    {
        gotoXY(iColunaResposta, 10);
        iCorDaFuncao = iSenha[iPegandoDaSenha];
        vFuncaoRetornaCor(iCorDaFuncao);
        iColunaResposta = iColunaResposta + 3;
        iPegandoDaSenha++;
    }
}

int vVerificaAcertos (int *iPalpite, int *iSenha)
{
    int iPosicoesPalpite = 0;
    int iPosicoesSenha = 0;
    int iMaizinhos = 0;
    int iMenozinhos = 0;
    vector <int> iCoresJaUsadas; //Armazenará as Cores que já foram conferidas
    int iTemOuNao;

    while(iPosicoesPalpite <= 3) //Enquanto não for conferido todas as posicoes do palpite
    {
        if (iPalpite[iPosicoesPalpite] == iSenha[iPosicoesSenha]) //Se posicao e cor forem iguais
        {
            iTemOuNao = count (iCoresJaUsadas.begin(), iCoresJaUsadas.end(), iPalpite[iPosicoesPalpite]); //Se já houver um Menozinho para essa cor, diminui um Menozinho

            if (iTemOuNao > 0)
            {
                iMenozinhos--;
            }

            iCoresJaUsadas.push_back(iPalpite[iPosicoesPalpite]); //Coloca a cor em iCoresJaUsadas
            iMaizinhos++;
            iPosicoesPalpite++;
        }
        else //Caso contrário confere se há a cor no palpite
        {
            iPosicoesSenha = 0;

            while (iPosicoesSenha <= 3)
            {

                if (iPalpite[iPosicoesPalpite] == iSenha[iPosicoesSenha])
                {
                    iTemOuNao = count (iCoresJaUsadas.begin(), iCoresJaUsadas.end(), iPalpite[iPosicoesPalpite]); //Vê se já não há a cor no iCoreJaUsadas

                    if (iTemOuNao == 0)
                    {
                        iCoresJaUsadas.push_back(iPalpite[iPosicoesPalpite]); //Se não..
                        iMenozinhos++;
                    }

                    iPosicoesPalpite++;
                    break;

                }
                else
                {
                    iPosicoesSenha++;
                }

                if (iPosicoesSenha == 4)
                {
                    iPosicoesPalpite++;
                }
            }
        }

        iPosicoesSenha = iPosicoesPalpite;
    }

    if (iMaizinhos == 4 && iMenozinhos == 0) //Se acertar a senha
    {
        cout << " PARABÉNS, VOCÊ GANHOU";
        return 1;
    }
    else //Se não acertar apenas retorna "+" e "-";
    {
        while (iMaizinhos > 0)
        {
            cout << " +";
            iMaizinhos--;
        }
        while (iMenozinhos > 0)
        {
            cout << " -";
            iMenozinhos--;
        }
    }
}

void vMostraExplicacao()
{
    int iLinhaEx = 5;

    gotoXY(57, iLinhaEx);
    cout << "\"+\" - COR E POSICÃO";
    iLinhaEx = iLinhaEx +2;
    gotoXY(57, iLinhaEx);
    cout << "\"-\" - APENAS COR";
    iLinhaEx = iLinhaEx +4;

    mudaCor(YELLOW);
    gotoXY(57, iLinhaEx);
    cout << "0 - AMARELO";
    iLinhaEx = iLinhaEx +2;

    mudaCor(BLUE);
    gotoXY(57, iLinhaEx);
    cout << "1 - AZUL";
    iLinhaEx = iLinhaEx +2;

    mudaCor(PURPLE);
    gotoXY(57, iLinhaEx);
    cout << "2 - ROXO";
    iLinhaEx = iLinhaEx +2;

    mudaCor(GREEN);
    gotoXY(57, iLinhaEx);
    cout << "3 - VERDE";
    iLinhaEx = iLinhaEx +2;

    mudaCor(RED);
    gotoXY(57, iLinhaEx);
    cout << "4 - VERMELHO";
    iLinhaEx = iLinhaEx +2;

    mudaCor(CYAN);
    gotoXY(57, iLinhaEx);
    cout << "5 - TURQUEZA";
    iLinhaEx = iLinhaEx+2;
    limpaEfeito();
}

int iFuncaoMenu()
{
    limparTela();

    Imagem iMIND (retornaConteudoArquivo("Mastermind_KarlMichel.txt"), 7, 3);
    mudaCor(CYAN);
    iMIND.imprime();
    limpaEfeito();

    desligaCursor(true);

    string stOpcoesUsuario [ ] = {"NOVO JOGO","FIM DE JOGO"} ;
    int iMenuInicial = mostraMenuH (30, 15, stOpcoesUsuario , 2 , CYAN, WHITE);

    if (iMenuInicial == 1)
    {
        limparTela();
        return 0;
    }
    else
    {
        limparTela();
        return 2;
    }

    desligaCursor(false);
}
