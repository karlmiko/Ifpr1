
//NÃO ESTÁ FUNCIONANDO!!!




//5. Palavra embaralhada - Implementar um programa que, a partir de um banco de palavras, seleciona aleatoria-
//mente uma palavra, embaralha as letras e dá um tempo para o usuário adivinhar a palavra.

#include "biblaureano.h"

void stEmbaralhando (string stPalavra);

int main()
{
    string stPalavraAleatoria [12] = {"karl", "karl", "karl", "karl", "karl", "karl", "karl", "karl", "karl", "karl", "karl", "karl"};

    string stPalavra = stPalavraAleatoria [randomico(1,12)];

    stEmbaralhando (stPalavra);

}

void stEmbaralhando (string stPalavra)
{
    int iEspacosConferidos = 0;
    int iTamanhoPalavra = stPalavra.size();
    int iPosicoesNaPalavra = 0; //Andando dentro da palavra (da primeira letra e vai indo...)
    int iSomandoEspacosUsados = 0; // Soma os espacos usados dentro de iPosicoesJaUsadas até iTamanhoPalvra

    string stPalavraEmbaralhada; //String da palavra Embaralhada com o mesmo tamanho da palavra

    int iPosicoesJaUsadas [iTamanhoPalavra]; //Armazena os espacos da Palavra Embaralhada que já foram usadas

    while (iSomandoEspacosUsados <= iTamanhoPalavra)
    {
        int iPosicaoAleatoria = randomico(1,iTamanhoPalavra); //Sorteia uma posicao na Palavra embaralhada para a primeira letra e assim ai...

        while (iEspacosConferidos < iTamanhoPalavra)
        {
            if (iPosicaoAleatoria != iPosicoesJaUsadas[iEspacosConferidos])
            {
                iEspacosConferidos++;
            }
            else if (iPosicaoAleatoria != iPosicoesJaUsadas[iEspacosConferidos])
            {
                int iPosicaoAleatoria = randomico(1,iTamanhoPalavra);
                iEspacosConferidos = 0;
            }
        }

        stPalavraEmbaralhada.at(iPosicaoAleatoria -1) = stPalavra.at(iPosicoesNaPalavra); // Coloca a primeira letra da palavra no lugar randomico da embaralhada
        iSomandoEspacosUsados++;
        iPosicoesNaPalavra++;

    }

     cout << stPalavraEmbaralhada;
}
