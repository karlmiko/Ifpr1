/**
    \section LICENÇA
    Copyright (C) 2011-2013 Marcos Laureano, Gabriel Candido e Thiago Romano

    Este arquivo é parte do programa Biblaureano.

    Biblaureano é um software livre; você pode redistribui-lo e/ou
    modifica-lo dentro dos termos da Licença Pública Geral GNU como
    publicada pela Fundação do Software Livre (FSF); na versão 2 da
    Licença, ou (na sua opnião) qualquer versão.

    Este programa é distribuido na esperança que possa ser  util,
    mas SEM NENHUMA GARANTIA; sem uma garantia implicita de ADEQUAÇÂO a qualquer
    MERCADO ou APLICAÇÃO EM PARTICULAR. Veja a
    Licença Pública Geral GNU para maiores detalhes.

    Você deve ter recebido uma cópia da Licença Pública Geral GNU
    junto com este programa, se não, escreva para a Fundação do Software
    Livre(FSF) Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

/**
* @file biblaureano.h
* @author Marcos Laureano <marcos.laureano@ifpr.edu.br>
* @author Gabriel Candido <gabiru.vinicius@gmail.com>
* @author Thiago Romano
* \brief Protótipos da Biblaureano.
*/

#include <string>
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <fstream>
#include <iomanip>

using namespace std;

/** \enum COR
* \brief Enumerador com as possíveis cores para alterar o texto e seu fundo.
* @remarks Varia de acordo com o SO.
* @remarks QTY_COR é a quantidade de cores possíveis. Usado para randomização de cores.
* @see mudaCor()
*/
enum COR {
#if defined(_WIN32)
BLACK = 0, BLUE, GREEN, CYAN, RED, PURPLE, YELLOW, WHITE, QTY_COR
#elif defined (unix)
BLACK, RED, GREEN, YELLOW, BLUE, PURPLE, CYAN, WHITE, QTY_COR
#endif
};

#if defined (_WIN32)
#define K_UP    72 /**<Valor ASCII referente a seta para cima do teclado */
#define K_DOWN  80 /**<Valor ASCII referente a seta para baixo do teclado */
#define K_LEFT  75 /**<Valor ASCII referente a seta para a esquerda do teclado */
#define K_RIGHT 77 /**<Valor ASCII referente a seta para a direita do teclado */
#elif defined (unix)
#define K_UP    65 /**<Valor ASCII referente a seta para cima do teclado */
#define K_DOWN  66 /**<Valor ASCII referente a seta para baixo do teclado */
#define K_LEFT  68 /**<Valor ASCII referente a seta para a esquerda do teclado */
#define K_RIGHT 67 /**<Valor ASCII referente a seta para a direita do teclado */
#endif
#define END_FILE_CHARACTER 0x04 /**<Valor hexadecimal referente ao caractere de fim de arquivo */
#define TEMPO clock_t /**<Definição para uso do termo TEMPO no lugar de clock_t, para melhor entendimento do código */

/** \brief Classe para manipulação de pontos na tela.
* Contém métodos básicos para manipulação de caracteres como pontos na tela.
* @see Imagem
*/
class Ponto
{
   private:
      int x, y;
      string caractere;
      COR corFrente, corFundo;
   public:
      Ponto( int px, int py, string pcaracter );
      Ponto( int px, int py, string pcaracter, COR pcor );
      Ponto( int px, int py, string pcaracter, COR pcor, COR pcorFundo );
      int getX();
      int getY();
      COR getCor();
      COR getCorFundo();
      void colore();
      string getChar();
      void setCor(COR pcor);
      void setCor(COR pcor, COR pcorFundo );
      void imprime(int px = 0, int py = 0);
      void limpa(int px = 0, int py = 0);
};

/** \brief Classe para manipulação de imagens em modo texto, como sprites.
* Contém métodos para manipulação de imagens como pontos na tela.
* @see Ponto
*/
class Imagem
{
   private:
      vector <Ponto> pontos;
      int x, y;
      int xMin, yMin, xMax, yMax;
      int altura, largura;
   public:
      Imagem();
      Imagem(string sprite);
      Imagem(string sprite, int px, int py);
      void imprime(int px, int py);
      void imprime();
      void limpa(int px, int py);
      void limpa();
      void mudaCor(COR pCor);
      void mudaCor(COR pCor, COR pCorFundo);
      bool colisao( Imagem i);
      bool colisao( Imagem i, int x1, int y1, int x2, int y2 );
      int getX();
      int getY();
      vector <Ponto> getPontos();
      void setX(int px);
      void setY(int py);
      int incrementaX();
      int incrementaY();
      int decrementaX();
      int decrementaY();
      void setaPontos(vector <Ponto> ppontos);
      void setLimites( int _xMin, int _yMin, int _xMax, int _yMax);
      int getColisaoX( Imagem i);
      int getColisaoY( Imagem i);
      int getAltura();
      int getLargura();
};

void mudaCor(COR NumeroCorLetra);
void mudaCor(COR NumeroCorLetra, COR NumeroCorFundo);
void limpaEfeito();

extern "C"
{
    extern int kbhit();
    extern int getch( );
}
int verificaKB(char & tecla);

void limparTela(void);
void gotoXY(int x, int y);
void desligaCursor(bool Liga);
void apagaLinha(int yInicial, int yFinal);
void mudaTamanhoTerminal(int x, int y);
void noecho(bool liga);

long randomico( int inicial = 0, int final = 0);
time_t tempoDecorrido( time_t Entrada = 0);
void espera(long int tempo);
clock_t tempoInicio();
int tempoPassado(clock_t inicio);

int readInt(string mensagem = "");
float readFloat(string mensagem = "");
double readDouble(string mensagem = "");
bool readBool(string mensagem = "");
string readString( string mensagem = "");
char readChar(string mensagem = "");

string numeroToString( int valor );
string numeroToString( double valor );
string numeroToString( float valor );

void box(int xInicial, int yInicial, int xFinal, int yFinal, string sequencia="+-|");
void circulo( int x, int y, int raio);

string retornaConteudoArquivo(string nomeArquivo);
vector<string> retornaArquivoSprites(string nomeArquivo, string separador="*????????*");
vector<Imagem> retornaImagens(string nomeArquivo, string separador="*????????*");
/*Varias imagens**/
void animaSprites(vector<string> sprites, int x, int y, int tempo = 100);
/*Uma imagem**/
void imprimeSprite( string sprite, int x = 1, int y = 1);
vector <Imagem> criaImagens( const string imagens[], int x=1, int y=1, int tamanho=1);
vector <Imagem> criaImagens( const vector <string> imagens, int x=1, int y=1);
vector <Imagem> criaImagens( const string imagem, int x=1, int y=1);

#if defined (_WIN32)
void limpaArea( int xInicial=1, int yInicial=1, int xFinal=80, int yFinal=25);
#elif defined (unix)
void limpaArea( int xInicial=0, int yInicial=0, int xFinal=79, int yFinal=24);
#endif

string palavraAleatoria( string palavras );

int mostraMenuV(int x, int y, string opcoes[], int qtd, COR ativo=BLUE, COR inativo = WHITE);
int mostraMenuH(int x, int y, string opcoes[], int qtd, COR ativo=BLUE, COR inativo = WHITE);

string geraLetraRandomico(int qtd);
string geraLetraRandomicoMaiscula(int qtd);
string geraLetraRandomicoMinuscula(int qtd);

Imagem modificaCorPontos( Imagem aColorir, Imagem referencia);

//void tocaMusica(char * caminhoMusica);
