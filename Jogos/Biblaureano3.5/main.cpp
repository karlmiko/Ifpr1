/**
    \section LICENÇA
    Biblaureano: biblioteca para o auxílio no desenvolvimento de jogos.

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
* @file main.cpp
* @author Marcos Laureano <marcos.laureano@ifpr.edu.br>
* @author Gabriel Candido <gabiru.vinicius@gmail.com>
* @author Thiago Romano
* \brief Biblioteca para auxiliar os alunos no decorrer dos cursos tecnicos em Informatica e em Programacao de Jogos Digitais do IFPR - Campus Salgado Filho.
*/

#include "biblaureano.h"

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <limits>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <iostream>

#elif defined (unix)
#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits> //para limpar o buffer
#include <fstream>
#include <ctime>
#include <string.h>
#include <stdlib.h>

#endif

using namespace std;

//Classe Ponto
//Construtores
/** \brief Construtor da classe Ponto usando argumentos de coordenadas e caracter
* Inicializa uma nova instância da classe Ponto.
* \param[in] px Coordenada horizontal do ponto.
* \param[in] py Coordenada vertical do ponto.
* \param[in] pcaracter Caractere do ponto.
* @see Ponto::Ponto( int px, int py, string pcaracter, COR pcor )
* @see Ponto::Ponto( int px, int py, string pcaracter, COR pcor, COR pcorFundo )
*/
Ponto::Ponto( int px, int py, string pcaracter )
{
   corFrente = corFundo = QTY_COR;
   x = px;
   y = py;
   caractere  = pcaracter;
}
/** \brief Construtor da classe Ponto usando argumentos de coordenadas, caracter e cor
* Inicializa uma nova instância da classe Ponto.
* \param[in] px Coordenada horizontal do ponto.
* \param[in] py Coordenada vertical do ponto.
* \param[in] pcaracter Caractere que será impresso naquele ponto.
* \param[in] pcor Cor do texto daquele ponto. Pode ser omitido.
* @see Ponto::Ponto( int px, int py, string pcaracter )
* @see Ponto::Ponto( int px, int py, string pcaracter, COR pcor, COR pcorFundo )
*/
Ponto::Ponto( int px, int py, string pcaracter, COR pcor )
{
   corFundo = QTY_COR;
   corFrente = pcor;
   x = px;
   y = py;
   caractere  = pcaracter;
}
/** \brief Construtor da classe Ponto usando argumentos de coordenadas, caracter e cor
* Inicializa uma nova instância da classe Ponto.
* \param[in] px Coordenada horizontal do ponto.
* \param[in] py Coordenada vertical do ponto.
* \param[in] pcaracter Caractere que será impresso naquele ponto.
* \param[in] pcor Cor do texto daquele ponto. Pode ser omitido.
* \param[in] pcorFundo Cor do fundo do ponto. Pode ser omitido.
* @see Ponto::Ponto( int px, int py, string pcaracter )
* @see Ponto::Ponto( int px, int py, string pcaracter, COR pcor )
*/
Ponto::Ponto( int px, int py, string pcaracter, COR pcor, COR pcorFundo )
{
   corFundo = pcorFundo;
   corFrente = pcor;
   x = px;
   y = py;
   caractere  = pcaracter;
}

//Gets e Sets
/** \brief Retorna o valor da coordenada X do ponto.
* @return Um inteiro com a coordenada X do ponto.
*/
int Ponto::getX(){ return x;}
/** \brief Retorna o valor da coordenada Y do ponto.
* @return Um inteiro com a coordenada Y do ponto.
*/
int Ponto::getY(){ return y;}
/** \brief Retorna a cor do texto do ponto.
* @return Um valor do tipo COR com a cor do texto.
*/
COR Ponto::getCor(){ return corFrente;}
/** \brief Retorna a cor do fundo do ponto.
* @return Um valor do tipo COR com a cor do fundo do ponto.
*/
COR Ponto::getCorFundo(){ return corFundo;}
/** \brief Retorna o caractere daquele ponto.
* @return Um a string contendo o caractere do ponto.
*/
string Ponto::getChar(){ return caractere;}
/** \brief Altera a cor do texto daquele ponto.
* \param[in] pcor Variável do tipo COR contendo a nova cor do ponto.
* @see Ponto::setCor(COR pcor, COR pcorFundo )
* @see Ponto::colore()
*/
void Ponto::setCor(COR pcor){ corFrente = pcor;}
/** \brief Altera a cor do texto e do fundo daquele ponto.
* \param[in] pcor Variável do tipo COR contendo a nova cor do ponto.
* \param[in] pcorFundo Variável do tipo COR contendo a nova cor de fundo do ponto.
* @see Ponto::setCor(COR pcor)
* @see Ponto::colore()
*/
void Ponto::setCor(COR pcor, COR pcorFundo )
{
   corFrente = pcor;
   corFundo =  pcorFundo;
}

/** \brief Atualiza a cor do ponto.
* Só atualiza se a cor foi alterada anteriormente pelos métodos setCor(COR pcor) ou setCor(COR pcor, COR pcorFundo)
* @see Ponto::setCor(COR pcor)
* @see Ponto::setCor(COR pcor, COR pcorFundo )
*/
void Ponto::colore()
{
   if( corFrente != QTY_COR && corFundo != QTY_COR)
      mudaCor(corFrente, corFundo);
   else if( corFrente != QTY_COR )
      mudaCor(corFrente);
}
/** \brief Limpa a área em que o ponto foi impressa.
* \param[in] px Coordenada X de início do sprite. Caso seja omitido o valor padrão é 0.
* \param[in] py Coordenada Y de início do sprite. Caso seja omitido o valor padrão é 0.
* @remarks Os parâmetros são usados no caso de haver vários pontos, dessa forma, informando px e py, a função calcula o deslocamento que deve fazer para apagar o local correto.
*/
void Ponto::limpa(int px, int py)
{
    gotoXY(px+x,py+y);
    cout << " ";
    cout.flush();
}

/** \brief Imprime o ponto na tela.
* \param[in] px Coordenada X de inicio do sprite. Caso seja omitido o valor padrão é 0.
* \param[in] py Coordenada Y de início do sprite. Caso seja omitido o valor padrão é 0.
* @remarks Os parâmetros são usados no caso de haver vários pontos, dessa forma, informando px e py, a função calcula o deslocamento que o ponto deve sofrer para ser impresso no local correto.
*/
void Ponto::imprime(int px, int py)
{
    colore();
    gotoXY(px+x,py+y);
    cout << caractere;
    cout.flush();
    limpaEfeito();
    return;
}

//Classe Imagem
//Construtores
/** \brief Construtor da classe Imagem sem argumentos
*/
Imagem::Imagem()
{
    x=0;
    y=0;
    altura=0;
    largura=0;
    xMin=0;
    yMin=0;
    xMax=0;
    yMax=0;
}
/** \brief Construtor da classe Imagem usando como argumento uma string com o sprite.
* Inicializa uma nova instância da classe Imagem.
* \param[in] sprite Sprite que forma a imagem.
* @see Imagem::Imagem(string sprite, int px, int py)
*/
Imagem::Imagem(string sprite)
{
   int posicao = -1;
   int inicial =0;
   int lY = 0;
   int maiorX = 0;
   if(sprite.find("\n") == string::npos ) sprite += "\n";
   while( (posicao = sprite.find("\n", posicao+1)) != string::npos){
      string linha = sprite.substr(inicial, posicao-inicial);
      int lX=0;
      for( int i = 0; i < linha.size(); ++i){
         if( linha[i]!= ' ' && linha[i]!='\n')
         {
            string c(1,linha[i]);
            Ponto p(lX,lY,c);
            pontos.push_back(p);
         }
         ++lX;
      }
      if( lX > maiorX ){ maiorX = lX;}

      inicial = posicao+1;
      ++lY;
   }
   altura = lY;
   largura = maiorX;

}

/** \brief Construtor da classe Imagem usando como argumentos uma string com o sprite e as coordenadas da imagem.
* Inicializa uma nova instância da classe Imagem.
* \param[in] sprite Sprite que forma a imagem.
* \param[in] px Coordenada X de início da imagem.
* \param[in] py Coordenada Y de início da imagem.
* @see Imagem::Imagem(string sprite)
*/
Imagem::Imagem(string sprite, int px, int py)
{
   x = px;
   y = py;
   int posicao = -1;
   int inicial =0;
   int lY = 0;
   int maiorX = 0;
   if(sprite.find("\n") == string::npos ) sprite += "\n";
   while( (posicao = sprite.find("\n", posicao+1)) != string::npos){
      string linha = sprite.substr(inicial, posicao-inicial);
      int lX=0;
      for( int i = 0; i < linha.size(); ++i){
         if( linha[i]!= ' ' && linha[i]!='\n')
         {
            string c(1,linha[i]);
            Ponto p(lX,lY,c);
            pontos.push_back(p);
         }
         ++lX;
      }
      if( lX > maiorX ){ maiorX = lX;}
      inicial = posicao+1;
      ++lY;
   }
   altura = lY;
   largura = maiorX;
}

//Gets e Sets
/** \brief Retorna a coordenada horizontal da imagem.
* @return Um inteiro com a coordenada X da imagem.
*/
int Imagem::getX(){ return x;}
/** \brief Retorna a coordenada vertical da imagem.
* @return Um inteiro com a coordenada Y da imagem.
*/
int Imagem::getY(){ return y;}
/** \brief Altera a coordenada horizontal da imagem.
* \param[in] px Um inteiro com a nova coordenada X da imagem.
*/
void Imagem::setX(int px){ x = px;}
/** \brief Retorna a coordenada vertical da imagem.
* \param[in] py Um inteiro com a coordenada Y da imagem.
*/
void Imagem::setY(int py){ y = py;}
/** \brief Retorna os pontos da imagem.
* @return Um vetor de Pontos que formam o sprite.
*/
vector <Ponto> Imagem::getPontos(){return pontos;}
/** \brief Altera a imagem
* \param[in] ppontos Vetor com os novos pontos da imagem.
*/
void Imagem::setaPontos(vector <Ponto> ppontos){ pontos = ppontos;}

/** \brief Aumenta a coordena horizontal da imagem em um.*/
int Imagem::incrementaX(){
   if( (x+1) <= xMax ) ++x;
   return x;
}
/** \brief Aumenta a coordena vertical da imagem em um.*/
int Imagem::incrementaY(){
   if( (y+1) <= yMax ) ++y;
   return y;
}
/** \brief Diminui a coordena horizontal da imagem em um.*/
int Imagem::decrementaX(){
   if( (x-1) >= xMin ) --x;
   return x;
}
/** \brief Diminui a coordena vertical da imagem em um.*/
int Imagem::decrementaY(){
   if( (y-1) >=yMin) --y;
   return y;
}

/** \brief Seta as coordenadas limites que a imagem pode ter.
* \param[in] _xMin Coordenada mínima no eixo X da imagem. Determina o quão à esquerda a imagem pode ficar.
* \param[in] _yMin Coordenada mínima no eixo Y da imagem. Determina o quão para cima a imagem pode ficar.
* \param[in] _xMax Coordenada máxima no eixo X da imagem. Determina o quão à direita a imagem pode ficar.
* \param[in] _yMax Coordenada máxima no eixo Y da imagem. Determina o quão para baixo a imagem pode ficar.
*/
void Imagem::setLimites( int _xMin, int _yMin, int _xMax, int _yMax)
{
   xMin=_xMin;
   yMin=_yMin;
   xMax=_xMax,
   yMax=_yMax;
   return;
}

/** \brief Verifica em qual coluna houve colisão.
* \param[in] i Imagem com a qual será feito o teste de colisão
* @return -1 se não houve colisão, caso contrário retorna a posição no eixo X em que houve a mesma.
*/
int Imagem::getColisaoX( Imagem i )
{
    vector <Ponto> imagemPontos = i.getPontos();
    int pix = i.getX();
    int piy = i.getY();
    for( int i=0; i< pontos.size(); ++i)
    {
       for( int j=0; j<imagemPontos.size(); ++j)
       {
          if( (getX()+pontos[i].getX()) == (pix+imagemPontos[j].getX()) &&
              (getY()+pontos[i].getY()) == (piy+imagemPontos[j].getY()) )
          {
             return getX()+pontos[i].getX();
          }
       }
    }
    return -1;
}

/** \brief Verifica em qual linha houve colisão.
* \param[in] i Imagem com a qual será feito o teste de colisão
* @return -1 se não houve colisão, caso contrário retorna a posição no eixo Y em que houve a mesma.
*/
int Imagem::getColisaoY( Imagem i )
{
    vector <Ponto> imagemPontos = i.getPontos();
    int pix = i.getX();
    int piy = i.getY();
    for( int i=0; i< pontos.size(); ++i)
    {
       for( int j=0; j<imagemPontos.size(); ++j)
       {
          if( (getX()+pontos[i].getX()) == (pix+imagemPontos[j].getX()) &&
              (getY()+pontos[i].getY()) == (piy+imagemPontos[j].getY()) )
          {
             return getY()+pontos[i].getY();
          }
       }
    }
    return -1;
}

/** \brief Altera as coordenadas da imagem e a imprime no novo posicionamento.
* \param[in] px Nova coordenada horizontal da imagem.
* \param[in] py Nova coordenada vertical da imagem.
* @see Imagem::imprime()
*/
void Imagem::imprime(int px, int py)
{
   x=px;
   y=py;
   for( int i = 0; i < pontos.size(); ++i)
   {
      pontos[i].imprime(px,py);
   }
   gotoXY(1,1);
   return;
}
/** \brief Imprime a imagem na sua posicao atual.
* @see Imagem::imprime(int px, int py)
*/
void Imagem::imprime()
{
   for( int i = 0; i < pontos.size(); ++i)
   {
      pontos[i].imprime(x,y);
   }
   gotoXY(1,1);
   return;
}

/** \brief Muda a cor da imagem.
* \param[in] pCor Nova cor do texto da imagem.
* @see Imagem::mudaCor(COR pCor, COR pCorFundo)
*/
void Imagem::mudaCor(COR pCor)
{
   for( int i = 0; i < pontos.size(); ++i)
   {
      pontos[i].setCor(pCor);
   }
   return;
}
/** \brief Muda a cor da imagem.
* \param[in] pCor Nova cor do texto da imagem.
* \param[in] pCorFundo Nova cor do fundo da imagem.
* @see Imagem::mudaCor(COR pCor)
*/
void Imagem::mudaCor(COR pCor, COR pCorFundo)
{
   for( int i = 0; i < pontos.size(); ++i)
   {
      pontos[i].setCor(pCor, pCorFundo);
   }
   return;
}

/** \brief Apaga a imagem da tela.
* @see Imagem::limpa(int px, int py)
*/
void Imagem::limpa()
{
   for( int i = 0; i < pontos.size(); ++i)
   {
      pontos[i].limpa(x,y);
   }
   return;
}
/** \brief Apaga a imagem conforme as novas coordenadas.
* \param[in] px Nova coordenada horizontal.
* \param[in] py Nova coordenada vertical.
* @see Imagem::limpa()
*/
void Imagem::limpa(int px, int py)
{
   for( int i = 0; i < pontos.size(); ++i)
   {
      pontos[i].limpa(px,py);
   }
   return;
}

/** \brief Verifica se houve colisão de imagens.
* \param[in] i Imagem com a qual será feito o teste de colisão.
* @return true se houve colisão e false caso contrário.
* @see Imagem::colisao( Imagem i, int x1, int y1, int x2, int y2 )
*/
bool Imagem::colisao( Imagem i )
{
    vector <Ponto> imagemPontos = i.getPontos();
    int pix = i.getX();
    int piy = i.getY();
    for( int i=0; i< pontos.size(); ++i)
    {
       for( int j=0; j<imagemPontos.size(); ++j)
       {
          if( (getX()+pontos[i].getX()) == (pix+imagemPontos[j].getX()) &&
              (getY()+pontos[i].getY()) == (piy+imagemPontos[j].getY()) )
          {
             return true;
          }
       }
    }
    return false;
}
//coordenadas da 1 imagem e coordenadas da 2 imagem
/** \brief Verifica se houve colisão de imagens.
* \param[in] i Imagem com a qual será feito o teste de colisão.
* \param[in] x1 Coordenada horizontal da primeira imagem.
* \param[in] y1 Coordenada vertical da primeira imagem.
* \param[in] x2 Coordenada horizontal da segunda imagem.
* \param[in] y2 Coordenada vertical da segunda imagem.
* @return true se houve colisão e false caso contrário.
* @see Imagem::colisao( Imagem i )
*/
bool Imagem::colisao( Imagem i, int x1, int y1, int x2, int y2 )
{
    vector <Ponto> imagemPontos = i.getPontos();
    for( int i=0; i< pontos.size(); ++i)
    {
       for( int j=0; j<imagemPontos.size(); ++j)
       {
          if( (x1+pontos[i].getX()) == (x2+imagemPontos[j].getX()) &&
              (y1+pontos[i].getY()) == (y2+imagemPontos[j].getY()) )
          {
             return true;
          }
       }
    }
    return false;
}

/** \brief Retorna a altura da imagem
* @return Altura da imagem
*/
int Imagem::getAltura(){ return altura; }

/** \brief Retorna a largura da imagem
* @return Largura da imagem
*/
int Imagem::getLargura(){ return largura; }

/** \brief Muda a cor do texto.
* Altera a cor de qualquer texto que venha depois da chamada dessa funcao, a nao ser que ela seja chamada novamente ou os efeitos de cor sejam limpados.
* @param[in] NumeroCorLetra Cor desejada para o texto, de acordo com o enumerador COR.
* @see mudaCor(COR NumeroCorLetra, COR NumeroCorFundo )
* @see limpaEfeito()
*/
void mudaCor(COR NumeroCorLetra )
{
    #if defined (_WIN32)
    {
        static HANDLE handle= GetStdHandle(STD_OUTPUT_HANDLE);//handle para o output
        int colorAttribute = 0;
        colorAttribute = (colorAttribute << 4) | NumeroCorLetra | 8;//15 para acender bits de intensidade
        SetConsoleTextAttribute( handle, colorAttribute);//seta atributos do texto para handle com colorAttribute caracteristicas
        return;
    }
    #elif defined (unix)
    {
        string Cor = "\033[;03";//3x seta texto
        std::stringstream out;        //conversão int para string
        out << NumeroCorLetra;             //conversão int para string
        Cor += out.str() + "m";
        cout << "\033[;0m";//\033->ESC  [-> CSI, control sequenco introduce, ECMA-48, m-> seta display
         //zero reseta os parametros
        cout << Cor;//seta parametros
        return;
    }
    #endif
}

/** \brief Muda a cor do texto e do fundo.
* Altera a cor de qualquer texto e fundo que venham depois da chamada dessa funcao, a nao ser que ela seja chamada novamente ou os efeitos de cor sejam limpados.
* @param[in] NumeroCorLetra Cor desejada para o texto, de acordo com o enumerador COR.
* @param[in] NumeroCorFundo Cor desejada para o fundo, de acordo com o enumerador COR.
* @see mudaCor(COR NumeroCorLetra )
* @see limpaEfeito()
*/
void mudaCor(COR NumeroCorLetra, COR NumeroCorFundo )
{

    #if defined (_WIN32)
    {
        static HANDLE handle= GetStdHandle(STD_OUTPUT_HANDLE);
        int colorAttribute = NumeroCorFundo;
        colorAttribute = (colorAttribute << 4) | NumeroCorLetra| 136;//136 para acender bits de intensidade
            //8 ultimos bits-> texto, 0000 0000
                                    //fundo texto
        SetConsoleTextAttribute( handle, colorAttribute);
        return;
    }
    #elif defined (unix)
    {
        string Cor = "\033[4";//4x seta fundo
        std::stringstream Fundo;        //conversão int para string
        Fundo << NumeroCorFundo;             //conversão int para string
        Cor += Fundo.str();

        std::stringstream Letra;        //conversão int para string
        Letra << NumeroCorLetra;             //conversão int para string
        Cor += ";03" + Letra.str() + "m";//3x seta texto
        cout << "\033[;0m";//reseta
        cout << Cor;//seta
    }
    #endif
    return;
}

/** \brief Limpa efeitos do texto.
* Reseta qualquer alteracao da cor do texto e fundo, feitas anteriormente pelas funcoes mudaCor().
* @see mudaCor(COR NumeroCorLetra, COR NumeroCorFundo )
* @see mudaCor(COR NumeroCorLetra )
*/
void limpaEfeito()
{
    #if defined (_WIN32)
    static HANDLE handle= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, 15);//15=fundo preto(0000) texto branco(1111)
    #elif defined (unix)
    cout <<"\033[;0m";//reseta
    #endif
    return;
}

/** \brief Verifica se alguma tecla foi pressionada.
* Nao para a execucao de um programa, pois nao aguarda uma operacao de I/O.
* @see getch( )
* @see verificaKB()
* @return True se qualquer tecla foi pressionada, caso contrário retorna false.
*/
int kbhit()
{
   #if defined (_WIN32)
   return _kbhit();
   #elif defined (unix)
   struct termios oldt, newt;
   int ch;
   int oldf;
   tcgetattr(STDIN_FILENO, &oldt);//pega atributos da STDIN_FILENO e coloca na oldt
   newt = oldt;
   newt.c_lflag &= ~(ICANON | ECHO);//desabilita echo e canonical mode

   tcsetattr(STDIN_FILENO, TCSANOW, &newt);//seta newt na STDIN_FILENO agora(TCSANOW)

   oldf = fcntl(STDIN_FILENO, F_GETFL, 0);//fcntl manipulacao de descriptors de arquivos
         //F_GETFL pega as flags de STDIN_FILENO, zero pois F_GETFL é void
   fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
      //F_SETFL seta as flags do terceiro argumento em STDIN_FILENO
      //

   ch = getchar();//le o prox char da stdin

   tcsetattr(STDIN_FILENO, TCSANOW, &oldt);//seta antigo
   fcntl(STDIN_FILENO, F_SETFL, oldf);//seta antigo

   if(ch != EOF)
   {
      ungetc(ch, stdin);//coloca ch de volta na stdin
      return 1;
   }
   return 0;
   #endif
}

/** \brief Verifica se alguma tecla foi pressionada.
* Espera por uma operacao de I/O, parando o programa.
* @see kbhit()
* @see verificaKB()
* @return A tecla pressionada.
*/
int getch()
{
    #if defined (_WIN32)
    return _getch();
    #elif defined (unix)
      struct termios oldt, newt;
      int ch;
      tcgetattr( STDIN_FILENO, &oldt );//pega atts da STDIN_FILENO
      newt = oldt;
      newt.c_lflag &= ~( ICANON | ECHO );//desabilita echo e canonical mode
      tcsetattr( STDIN_FILENO, TCSANOW, &newt );//seta agora
      ch = getchar();//le char
      tcsetattr( STDIN_FILENO, TCSANOW, &oldt );//seta antigo
      return ch;
    #endif
}

/** \brief Verifica se alguma tecla foi pressionada.
* Para a execução do programa. Útil quando você deve esperar que o usário digite algo, economizando processamento.
* @param[out] tecla Tecla pressionada. Caso nenhuma tecla for pressionada seu valor nao e alterado.
* @see getch( )
* @see kbhit()
* @return true se alguma tecla foi pressionada ou false, caso contrario.
*/
int verificaKB(char & tecla)
{
   #if defined (_WIN32)
   tecla = _getch();
   return 1;

   #elif defined (unix)

   struct termios oldstuff;
   struct termios newstuff;

   tcgetattr(STDIN_FILENO, &oldstuff);//pega atts STDIN_FILENO
   newstuff = oldstuff;
   newstuff.c_lflag &= ~(ICANON | ECHO);//desabilita echo e canonical mode
   tcsetattr(STDIN_FILENO, TCSANOW, &newstuff);//seta agora
   tecla = getchar();//le char
   tcsetattr(STDIN_FILENO, TCSANOW, &oldstuff);//seta antigo

   if (tecla == END_FILE_CHARACTER)
   {
      tecla = EOF;
   }
   return tecla != EOF;//EOF==0, entao retorna true
   #endif
}

/** \brief Limpa a tela.*/
void limparTela(void)
{
    #if defined (_WIN32)
    system("cls");
    #elif defined (unix)
    cout << "\033[2J\033[0;0f";//2J apaga tela, o;of posiciona cursor na linha 0; coluna 0
    #endif
   return;
}

/** \brief Seta a posicao do cursor do teclado.
* @param[in] x Posicao do cursor no eixo X (coluna).
* @param[in] y Posicao do cursor no eixo Y (linha).
*/
void gotoXY(int x, int y)
{
    #if defined (_WIN32)
    COORD coord;//struct de coordenadas
    coord.X = x;//altera coords
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//seta coordenadas
    #elif defined (unix)
    cout << "\033[" << y << ";" << x << "f";//f posiciona
    cout.flush();
    #endif
}

/** \brief Altera a visibilidade do cursor do teclado.
* @param[in] Liga Se true, seta o cursor como invisivel, se false, seta como visível.
*/
void desligaCursor(bool Liga)
{
   #if defined (_WIN32)
   HANDLE output=GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO cursor;
   GetConsoleCursorInfo(output, &cursor);
   cursor.bVisible=!Liga;
   SetConsoleCursorInfo(output, &cursor);
   #elif defined (unix)
   if( Liga )
   {
      cout << "\033[?25l";//25 visibilidade cursor, l reset mode
   }
   else
   {
      cout << "\033[?25h";//25 visibilidade cursor, h set mode
   }
   #endif
}

/** \brief Apaga um intervalo de linhas.
* @param[in] yInicial Primeira valor do intervalo de linhas a serem apagadas.
* @param[in] yFinal Ultimo valor do intervalo de linhas a serem apagadas.
* @remarks Caso yInicial e yFinal sejam iguais apaga somente a linha informada pelos dois argumentos.
*/
void apagaLinha(int yInicial, int yFinal)
{
   for( int y=yInicial; y<=yFinal; ++y)
   {
      #if defined (_WIN32)
      gotoXY(0,y);

      CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
      GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleInfo);//pega informacoes do output
      int tamLinha=consoleInfo.dwSize.X;//grava o tamanho da linha

      for (int x=0; x<=tamLinha; x++)//apaga tantos caracteres quanto for o tamanho da linha
      {
          cout << ' ';
      }

      #elif defined (unix)
      gotoXY(1,y);
      cout << (char)27<<"[2K"; //apaga a linha
      #endif
   }

   return;
}

/** \brief Muda o tamanho da janela do programa.
* @param[in] x Novo numero de colunas da janela.
* @param[in] y Novo numero de linhas da janela.
*/
void mudaTamanhoTerminal(int x, int y)
{
    #if defined (_WIN32)
    string command="mode con cols="+numeroToString(x)+" lines="+numeroToString(y);//mode altera dispositivos do sistema
        //con eh o console, cols colunas e lines linhas
    system(command.c_str());//transforma em uma c-string e envia como comando do console

    #elif defined (unix)
    if( x && y)
    {
        cout << "\033[8;" << numeroToString(y) << ";"
            << numeroToString(x) <<"t"<<endl;
    }
    #endif
    return;
}

/** \brief Retira o echo do output.
* @param[in] liga Se true, seta para nao mostrar as teclas pressionadas durante a execucao do programa. O contrario e obtido com false.
* @remarks No sistema Windows nao e necessario o uso dessa funcao.
*/
void noecho(bool liga)
{
    #if defined (unix)
    static struct termios  terminal;
    static struct termios  original;

    if( liga )
    {
        tcgetattr (0, &terminal);//zero=STDIN_FILENO
        original = terminal;
        terminal.c_lflag&=~(ECHO|ICANON);//desabilita echo e canonical mode
        terminal.c_cc[VMIN]=1;//read retorna quando VMIN(1) bytes de leitura for atingido
        terminal.c_cc[VTIME]=0;
        tcsetattr (0, TCSAFLUSH, &terminal);//seta atts
    }
    else
    {
        tcsetattr (0, TCSAFLUSH, &original);//seta antigo
    }
    #endif
    return;
}

/** \brief Gera um numero randomicamente.
* @param[in] inicial Numero minimo a ser retornado.
* @param[in] final Numero maximo a ser retornado. Se for omitido, nao ha limite maximo.
* @remarks Se ambos os parametros forem omitidos, entao o intervalo de numeros que podem ser retornados e o proprio limite da variavel.
* @return Um long int com o numero gerado randomicamente.
*/
long randomico( int inicial, int final )
{
   static bool ligado = true;
   int numero;

   if(ligado)//se ligado=true inicializa os randomicos
   {
      srand(time(0));
      ligado = false;
   }

   if( final == 0)//se nao tiver max
      numero = rand();
   else
      numero = rand()%(final-inicial);//final-inicial garante o intervalo de numeros

   return numero+inicial;//num+inicial garante o min
}

/** \brief Calcula o tempo que se passou.
* Inicia uma contagem de tempo em segundos ou retorna o tempo que se passou.
* @param[in] Entrada Opcional, se nao for passado a funcao ira iniciar a contagem (ou reseta-la). Se for passado calculará o tempo decorrido desde a chamada que iniciou a contagem.
* @return O tempo decorrido, em segundos, desde a chamada que iniciou a contagem.
*/
time_t tempoDecorrido( time_t Entrada)
{
    static time_t HoraAntes;
    if( Entrada == 0 )//se entrada for zero inicializa a contagem
    {
        HoraAntes = time(NULL);
    }
    else
    {
        return time(NULL) - HoraAntes;//se nao retorna o tempo atual-tempo de inicio=tempo decorrido
    }
    return HoraAntes;
}

/** \brief Pausa a execucao do programa.
* @param[in] tempo Tempo, em milissegundos, que o programa sera pausado.
*/
void espera(long int tempo)
{
    #if defined (_WIN32)
    Sleep (tempo*10);
    #elif defined (unix)
    usleep (10000*tempo);
    #endif
}

/** \brief Usada para iniciar a contagem do tempo
* @return Uma variável do tipo TEMPO que armazena o momento em que a contagem foi iniciada. É usada como parâmetro na função tempoPassado(clock_t inicio).
*/
clock_t tempoInicio(){ return clock(); }

/** \brief Calcula quanto tempo se passou desde o início da contagem
* \param[in] inicio Variável do tipo tempo que armazena quando a contagem foi iniciada. Deve ser inicializada com a função tempoInicio()
* @return O tempo que se passou, sendo que o retorno igual a 100 representa um segundo.
*/
int tempoPassado(clock_t inicio)
{
   clock_t fim = clock()-inicio;
   return  ((float)fim/CLOCKS_PER_SEC)*100;
}

/** \brief Le um inteiro do teclado.
* Le outro inteiro ate que o mesmo seja valido.
* @param[in] mensagem Mensagem a ser mostrada na tela antes da leitura.
* @return O inteiro lido.
*/
int readInt(string mensagem)
{
   int numero;
   bool inputFlag = true;
   while( inputFlag )
   {
      if( !mensagem.empty())
         cout << mensagem;
      cin >> numero;
      if( cin.fail() )
      {
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      }
      else
         inputFlag = false;
   }
   cin.clear();
   cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

   return numero;
}

/** \brief Le um float do teclado.
* Le outro float ate que o mesmo seja valido.
* @param[in] mensagem Mensagem a ser mostrada na tela antes da leitura.
* @return O float lido.
*/
float readFloat(string mensagem)
{
   float numero;
   bool inputFlag = true;
   while( inputFlag )
   {
      if( !mensagem.empty())
         cout << mensagem;
      cin >> numero;
      if( cin.fail() )
      {
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      }
      else
         inputFlag = false;
   }
   cin.clear();
   cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

   return numero;
}

/** \brief Le um double do teclado.
* Le outro valor ate que o mesmo seja valido.
* @param[in] mensagem Mensagem a ser mostrada na tela antes da leitura.
* @return O double lido.
*/
double readDouble(string mensagem)
{
   double numero;
   bool inputFlag = true;
   while( inputFlag )
   {
      if( !mensagem.empty())
         cout << mensagem;
      cin >> numero;
      if( cin.fail() )
      {
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      }
      else
         inputFlag = false;
   }
   cin.clear();
   cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

   return numero;
}

/** \brief Le um valor booleano do teclado.
* Le outro bool ate que o mesmo seja valido.
* @param[in] mensagem Mensagem a ser mostrada na tela antes da leitura.
* @return O bool lido.
*/
bool readBool(string mensagem)
{
   bool logico;
   bool inputFlag = true;
   while( inputFlag )
   {
      if( !mensagem.empty())
         cout << mensagem;
      cin >> logico;
      if( cin.fail() )
      {
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      }
      else
         inputFlag = false;
   }
   cin.clear();
   cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

   return logico;
}

/** \brief Le uma string do teclado.
* Le outra string ate que a mesma seja valida.
* @param[in] mensagem Mensagem a ser mostrada na tela antes da leitura.
* @return A string lida.
*/
string readString(string mensagem)
{
   string str;
   bool inputFlag = true;
   while( inputFlag )
   {
      if( !mensagem.empty())//se houver mensagem, imprime
         cout << mensagem;
      getline(cin,str, '\n');//grava a linha atraves do cin na var str ate encontrar o char \n
      if( cin.fail() )//cin.fail() retorna flags de erro: badbit->  failbit->
      {
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      }
      else
         inputFlag = false;
   }
   //cin.clear();
   //cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

   return str;
}

/** \brief Le um caractere do teclado.
* Le outro caractere ate que o mesmo seja valido.
* @param[in] mensagem Mensagem a ser mostrada na tela antes da leitura.
* @return O caractere lido.
*/
char readChar(string mensagem)
{
   char caractere;
   bool inputFlag = true;
   while( inputFlag )
   {
      if( !mensagem.empty())
         cout << mensagem;
      cin >> caractere;
      if( cin.fail() )
      {
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      }
      else
         inputFlag = false;
   }
   cin.clear();
   cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

   return caractere;
}

/** \brief Converte um numero para string.
* @param[in] valor Inteiro a ser convertido.
* @return Uma string contendo o valor convertido.
*/
string numeroToString( int valor )
{
   std::stringstream out;//stringstream->classe para trabalhar com strings
   out << valor;//out recebe valor
   return out.str();//retorna out convertido em string
}

/** \brief Converte um numero para string.
* @param[in] valor Double a ser convertido.
* @return Uma string contendo o valor convertido.
*/
string numeroToString( double valor )
{
   std::stringstream out;
   out << valor;
   return out.str();
}

/** \brief Converte um numero para string.
* @param[in] valor Float a ser convertido.
* @return Uma string contendo o valor convertido.
*/
string numeroToString( float valor )
{
   std::stringstream out;
   out << valor;
   return out.str();
}

/** \brief Desenha um quadrilatero na tela.
* @param[in] xInicial Coluna onde o quadrilatero começa (Canto superior esquerdo).
* @param[in] yInicial Linha onde o quadrilatero começa (Canto superior esquerdo).
* @param[in] xFinal Coluna onde o quadrilatero termina (Canto inferior direito).
* @param[in] yFinal Coluna onde o quadrilatero termina (Canto inferior direito).
* @param[in] sequencia String de tres caracteres que determina o desenho do quadrilatero: O primeiro caractere e usado nos quatro cantos do box. O segundo caractere e usado nas linhas inferior e superior. O terceiro caractere e usado nas linhas laterais. Caso nao seja passado o padrao e "+-|".
*/
void box(int xInicial, int yInicial, int xFinal, int yFinal, string sequencia)
{
   enum BORDAS {CANTO, SUP_INF, LATERAL};
   for( int x = xInicial; x<=xFinal;++x)//controla colunas
   {
      for( int y = yInicial; y<=yFinal;++y)//controla linhas
      {
         if( (x == xInicial && y==yInicial) ||
             (x == xFinal   && y==yFinal  ) ||
             (x == xInicial && y==yFinal  ) ||
             (x == xFinal   && y==yInicial))
         {
            gotoXY(x,y); //colocado aqui por questões de performance
            cout << sequencia[CANTO];//"+";
         }
         else if ( y == yInicial || y == yFinal)
         {
            gotoXY(x,y); //colocado aqui por questões de performance
            cout << sequencia[SUP_INF]; //"-";
         }
         else if( x == xInicial || x == xFinal )
         {
            gotoXY(x,y); //colocado aqui por questões de performance
            cout << sequencia[LATERAL]; //"|";
         }
      }
   }
   return;
}

/** \brief Desenha um circulo na tela.
* @param[in] x Coluna do centro do circulo.
* @param[in] y Linha do centro do circulo.
* @param[in] raio Tamanho do raio do circulo.
*/
void circulo( int x, int y, int raio)
{
   if( raio < 4) raio = 4;
   else if( raio > 10) raio =12;
   for( int angulo=0;angulo<=360;++angulo)
   {
      float xPos=ceil(x+cos(angulo*3.1415F/180.0F)*(raio+1));//ceil retorna o menor inteiro que seja maior que o valor passado(1.5 retorna 2)
      float yPos=ceil(y+sin(angulo*3.1415F/180.0F)*(raio-1.5));
      gotoXY( (int)xPos,(int)yPos);
      cout << ".";
   }
   return;
}

/** \brief Retorna o conteudo de um arquivo.
* Podem acontecer falhas de acordo com o tipo do arquivo.
* @param[in] nomeArquivo String contendo o caminho e nome do arquivo.
* @return Uma string contendo todas as linhas do arquivo.
* @see retornaArquivoSprites(string nomeArquivo, string separador)
*/
string retornaConteudoArquivo(string nomeArquivo)
{
   std::ifstream leitura(nomeArquivo.c_str());//abre o arquivo
   string linhas = "";

   if (leitura)
   {
	   while (leitura.good ())//enquanto nao houver erro na leitura, como badbit ou failbit
	   {
         string temp;
         getline (leitura, temp); //le linha por linha
	      temp += "\n"; //colocar o final de linha
	      linhas += temp;
	   }
   }
   else
   {
      linhas = "Arquivo não existe!!";
   }
   leitura.close();//fecha o arquivo
	return linhas;
}

/** \brief Retorna as sprites contidas em um arquivo de texto simples.
* \param[in] nomeArquivo String contendo o caminho e nome do arquivo que possui os sprites.
* \param[in] separador String que funcionará como separador de sprites. Toda vez que houver esse separador a função irá considerar um novo sprite. O padrão é "*????????*"
* @return Um vetor de strings contendo os sprites.
* @see retornaConteudoArquivo(string nomeArquivo)
* @see retornaImagens(string nomeArquivo, string separador)
*/
vector<string> retornaArquivoSprites(string nomeArquivo, string separador)
{
   std::ifstream leitura(nomeArquivo.c_str());
   string linhas = "";
   vector<string>sprites;

   if (leitura)
   {
	   while (leitura.good ())
	   {
         string temp;
         getline (leitura, temp); //le linha por linha
         if( temp == separador)
         {
            sprites.push_back(linhas);
            linhas="";
         }
	      else
	      {
	         temp += "\n"; //colocar o final de linha
	         linhas += temp;
         }
	   }
   }
   else
   {
      linhas = "Arquivo não existe!!";
   }
   leitura.close();
	return sprites;
}

/** \brief Retorna as imagens criadas a partir de um arquivo de texto simples.
* \param[in] nomeArquivo String contendo o caminho e nome do arquivo que possui os sprites.
* \param[in] separador String que funcionará como separador de imagens. Toda vez que houver esse separador a função irá considerar um novo imagens. O padrão é "*????????*"
* @return Um vetor de strings contendo as imagens.
* @remarks Possui a mesma utilidade que a função retornaArquivoSprites(string nomeArquivo, string separador), porém retorna um vetor do tipo Imagem e não do tipo string
*/
vector<Imagem> retornaImagens(string nomeArquivo, string separador)
{
   vector<string> imagens = retornaArquivoSprites(nomeArquivo, separador);
   vector<Imagem> minhasImagens;
   for(int i = 0; i<imagens.size(); ++i)
   {
      minhasImagens.push_back(Imagem(imagens[i]));
   }
   return minhasImagens;
}
/** \brief Imprime uma sequencia de sprites.
* Faz uma animação de diversos sprites.
* \param[in] sprites Vetor com os sprites.
* \param[in] x Coordenada horizontal de início dos sprites.
* \param[in] y Coordenada vertical de início dos sprites.
* \param[in] tempo Intervalo de tempo que os sprites levam para ser alterados. Caso seja omitido o valor padrão é 1 segundo
* @see imprimeSprite( string sprite, int x, int y)
* @see retornaArquivoSprites(string nomeArquivo, string separador)
*/
void animaSprites(vector<string> sprites, int x, int y, int tempo)
{
   for( int i=0; i<sprites.size(); ++i)
   {
      imprimeSprite(sprites[i], x, y);
      if( kbhit() ) return;
      espera(100);
   }
   return;
}

/** \brief Imprime um sprite na tela
* O sprite é um arquivo de texto simples contendo strings de caracteres formando imagens.
* @param[in] sprite String
* @param[in] x Coordenada horizontal de início do sprite. Se não for informado seu valor padrão é um.
* @param[in] y Coordenada vertical de início do sprite. Se não for informado seu valor padrão é um.
* @see animaSprites(vector<string> sprites, int x, int y, int tempo)
* @see retornaConteudoArquivo(string nomeArquivo)
*/
void imprimeSprite( string sprite, int x, int y)
{
   int pos;
   //quebra os \n para reposicionar e não dar erro
   while( (pos = sprite.find("\n")) != string::npos)//enquanto houver \n no sprite
   {
      gotoXY(x,y);//vai para pos de inicio
      string sprite_parcial = sprite.substr(0,pos+1);
      cout << sprite_parcial;
      ++y;
      sprite.erase( 0,pos+1);
   }
   gotoXY(x,y); //imprime última parte que não tem /n
   cout << sprite;
   cout.flush();
   return;
}

/** \brief Cria um vetor de imagens.
* \param[in] imagens Vetor de strings contendo as imagens.
* \param[in] x Posição no eixo X da imagem.
* \param[in] y Posição no eixo Y da imagem.
* \param[in] tamanho Quantidade de imagens no vetor.
* @return Um vector de Imagens com as imagens criadas.
*/
vector <Imagem> criaImagens( const string imagens[], int x, int y, int tamanho){
   vector <Imagem> i;
   for( int j=0; j<tamanho; ++j){
     Imagem _t(imagens[j],x,y);
     i.push_back( _t );
   }
   return i;
}

/** \brief Cria um vetor de imagens.
* \param[in] imagens Vector de strings contendo as imagens.
* \param[in] x Posição no eixo X da imagem.
* \param[in] y Posição no eixo Y da imagem.
* @return Um vector de Imagens com as imagens criadas.
*/
vector <Imagem> criaImagens( const vector <string> imagens, int x, int y){
   vector <Imagem> i;
   for( int j=0; j<imagens.size(); ++j){
     Imagem _t(imagens[j],x,y);
     i.push_back( _t );
   }
   return i;
}

/** \brief Cria um vetor com uma imagem.
* \param[in] imagem Nome do arquivo com as imagens. Deve ser usado o separador padrão da função retornaArquivoSprites().
* \param[in] x Posição no eixo X da imagem.
* \param[in] y Posição no eixo Y da imagem.
* @return Um vector de Imagem com a imagem criada.
*/
vector <Imagem> criaImagens( const string imagem, int x, int y){
   vector <Imagem> i;
   vector <string> imagens = retornaArquivoSprites(imagem);
   for( int j=0; j<imagens.size(); ++j){
     Imagem _t(imagens[j],x,y);
     i.push_back( _t );
   }
   return i;
}

/** \brief Limpa uma área da tela
* @param[in] xInicial Coordenada x do canto superior esquerdo da área a ser apagada. Se não for informado seu valor padrão é um - Windows - .
* @param[in] yInicial Coordenada y do canto superior esquerdo da área a ser apagada. Se não for informado seu valor padrão é um.
* @param[in] xFinal Coordenada x do canto inferior direito da área a ser apagada. Se não for informado seu valor padrão é 79.
* @param[in] yFinal Coordenada y do canto inferior direito da área a ser apagada. Se não for informado seu valor padrão é 24.
* @remarks Caso nenhum parâmetro seja informado ele apaga a tela inteira, se essa estiver com o tamanho padrão.
*/
void limpaArea( int xInicial, int yInicial, int xFinal, int yFinal)
{
   for( int x = xInicial; x<=xFinal; ++x)
   {
      for( int y = yInicial; y<=yFinal; ++y)
      {
         gotoXY(x,y);
         cout << " ";
      }
   }
   cout.flush();
   return;
}


/** \brief Randomiza uma palavra de um arquivo.
* \param[in] palavras String contendo as palavras a serem randomizadas, separadas por um caractere de quebra de linha ('\n').
* @return Uma string contendo a palavra aleatória.
*/
string palavraAleatoria( string palavras )
{
   int pos;
   vector <string> s;
   //quebra os \n para reposicionar e não dar erro
   while( (pos = palavras.find("\n")) != string::npos)
   {
      string p = palavras.substr(0,pos);
      palavras.erase( 0,pos+1);
      if( p!="\n" && !p.empty()) s.push_back(p);
   }
   pos = randomico(1,s.size()-1);
   return s[pos-1];
}

/** \brief Mostra um menu vertical na tela.
* \param[in] x Coordenada horizontal do menu.
* \param[in] y Coordenada vertical do menu.
* \param[in] opcoes Vetor de strings contendo as opções do menu.
* \param[in] qtd Quantidade de opções do menu.
* \param[in] ativo Cor da opção atualmente selecionada. Caso seja omitido o valor padrão é azul.
* \param[in] inativo Cor das opções não selecionadas. Caso seja omitido o valor padrão é branco.
* @return Um inteiro contendo a posição da opção escolhida.
*/
int mostraMenuV(int x, int y, string opcoes[], int qtd, COR ativo, COR inativo)
{
   int newY = y;
   mudaCor(inativo);
   for( int i=0; i<qtd; ++i)
   {
      gotoXY(x,newY);
      cout << opcoes[i];
      ++newY;
   }
   int pos = 0;
   newY = y;
   while(true)
   {
      char tecla;
      gotoXY( x, newY);
      mudaCor(ativo);
      cout << opcoes[pos];
      if( verificaKB(tecla) )
      {
         mudaCor(inativo);
         gotoXY( x, newY);
         cout << opcoes[pos];
         if( tecla == K_UP)
         {
            if( pos == 0)
            {
               pos = qtd-1;
               newY = y+qtd-1;
            }
            else
            {
               --pos;
               --newY;
            }
         }
         else if( tecla == K_DOWN )
         {
            if( pos == qtd-1)
            {
               pos = 0;
               newY = y;
            }
            else
            {
               ++pos;
               ++newY;
            }
         }
         #if defined (_WIN32)
         else if((int)tecla==13) return pos+1;
         #elif defined (unix)
         else if( tecla == '\n') return pos+1;
         #endif
      }
   }
   return 0;
}
/** \brief Mostra um menu horizontal na tela.
* \param[in] x Coordenada horizontal do menu.
* \param[in] y Coordenada vertical do menu.
* \param[in] opcoes Vetor de strings contendo as opções do menu.
* \param[in] qtd Quantidade de opções do menu.
* \param[in] ativo Cor da opção atualmente selecionada. Caso seja omitido o valor padrão é azul.
* \param[in] inativo Cor das opções não selecionadas. Caso seja omitido o valor padrão é branco.
* @return Um inteiro contendo a posição da opção escolhida.
*/
int mostraMenuH(int x, int y, string opcoes[], int qtd, COR ativo, COR inativo)
{
   int newX = x;
   mudaCor(inativo);
   int lastX;
   for( int i=0; i<qtd; ++i)
   {
      gotoXY(newX,y);
      cout << opcoes[i];
      lastX = newX;
      newX+=opcoes[i].size() + 2;
   }
   int pos = 0;
   newX = x;
   while(true)
   {
      char tecla;
      gotoXY( newX, y);
      mudaCor(ativo);
      cout << opcoes[pos];

      if( verificaKB(tecla) )
      {
         mudaCor(inativo);
         gotoXY( newX, y);
         cout << opcoes[pos];
         if( tecla == K_RIGHT)
         {
            if( pos == qtd-1)
            {
               pos = 0;
               newX = x;
            }
            else
            {
               newX+=opcoes[pos++].size()+2;
            }
         }
         else if( tecla == K_LEFT)
         {
            if( pos == 0)
            {
               pos = qtd-1;
               newX = lastX;//posicao da ultima opcao
            }
            else
            {
               --pos;
               newX -= (opcoes[pos].size() + 2);
            }
         }
         #if defined (_WIN32)
         else if((int)tecla==13) return pos+1;
         #elif defined (unix)
         else if( tecla == '\n') return pos+1;
         #endif
      }
   }
   return 0;
}

/** \brief Gera letras randômicas.
* \param[in] qtd Quantidade de letras a serem geradas.
* @return Uma string com as letras geradas.
*/
string geraLetraRandomico(int qtd)
{
   int vezes = 0;
   string s;
   while( vezes < qtd )
   {
     int c;
     do
     {
        c = randomico(65,122);
     }while(c>90 && c < 97);
     s+=string(1,c);
     ++vezes;
   }
   return s;
}
/** \brief Gera letras maiúsculas randômicas.
* \param[in] qtd Quantidade de letras a serem geradas.
* @return Uma string com as letras geradas.
*/
string geraLetraRandomicoMaiscula(int qtd)
{
   int vezes = 0;
   string s;
   while( vezes < qtd )
   {
     int c;
     c = randomico(65,90);
     s+=string(1,c);
     ++vezes;
   }
   return s;
}
/** \brief Gera letras minúsculas randômicas.
* \param[in] qtd Quantidade de letras a serem geradas.
* @return Uma string com as letras geradas.
*/
string geraLetraRandomicoMinuscula(int qtd)
{
   int vezes = 0;
   string s;
   while( vezes < qtd )
   {
     int c;
     c = randomico(97,122);
     s+=string(1,c);
     ++vezes;
   }
   return s;
}

/** \brief Colore uma image, permite mais de uma cor na mesma imagem
* @param[in] aColorir Imagem base para ser colorida
* @param[in] referencia Imagem, igual ao parâmetro aColorir, porém ao invés dos caracteres desejados, insere-se números de 1(um) a 8(oito), referentes a cor desejada para aquele ponto, conforme o enumerador COR
* @return Imagem com a cor dos pontos já setadas
*/
Imagem modificaCorPontos( Imagem aColorir, Imagem referencia)
{
   vector <Ponto> pColorir = aColorir.getPontos();
   vector <Ponto> pReferencia = referencia.getPontos();
   if( pColorir.size() == pReferencia.size() ){//garante que é a mesma imagem
      for( int i=0; i< pColorir.size(); ++i){
         if( pReferencia[i].getChar() == "1"){ //BLACK
            pColorir[i].setCor(BLACK);
         }
         else if ( pReferencia[i].getChar() == "2"){ //BLUE
            pColorir[i].setCor(BLUE);
         }
         else if ( pReferencia[i].getChar() == "3"){ //GREEN
            pColorir[i].setCor(GREEN);
         }
         else if ( pReferencia[i].getChar() == "4"){ //CYAN
            pColorir[i].setCor(CYAN);
         }
         else if ( pReferencia[i].getChar() == "5"){ //RED
            pColorir[i].setCor(RED);
         }
         else if ( pReferencia[i].getChar() == "6"){//PURPLE
            pColorir[i].setCor(PURPLE);
         }
         else if ( pReferencia[i].getChar() == "7"){ //YELLOW
            pColorir[i].setCor(YELLOW);
         }
         else if ( pReferencia[i].getChar() == "8"){ //WHITE
            pColorir[i].setCor(WHITE);
         }
         pColorir[i].colore();
      }

      aColorir.setaPontos( pColorir );

   }
   return aColorir;
}
/*
void tocaMusica(char * caminhoMusica)
{
    #if defined (_WIN32)
    PlaySound(TEXT(caminhoMusica), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    #elif defined (unix)
    char * buffer;
    buffer = (char*) malloc(strlen (caminhoMusica) + 24);
    sprintf (buffer, "aplay -c 1 -t wav -q %s &", caminhoMusica);
    system (buffer);
    free (buffer);
    #endif
}*/
