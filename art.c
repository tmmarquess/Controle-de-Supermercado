#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

  enum{BLACK,                 //0
       BLUE,                  //1
       GREEN,                 //2
       CYAN,                  //3
       RED,                   //4
       MAGENTA,               //5
       BROWN,                 //6
       LIGHTGRAY,             //7
       DARKGRAY,              //8
       LIGHTBLUE,             //9
       LIGHTGREEN,            //10
       LIGHTCYAN,             //11
       LIGHTRED,              //12
       LIGHTMAGENTA,          //13
       YELLOW,                //14
       WHITE                  //15
       
       };  

  enum{BG_BLACK=0,                 //0
       BG_BLUE=16,                  //1
       BG_GREEN=32,                 //2
       BG_CYAN=48,                  //3
       BG_RED=64,                   //4
       BG_MAGENTA=80,               //5
       BG_BROWN=96,                 //6
       BG_LIGHTGRAY=112,             //7
       BG_DARKGRAY=128,              //8
       BG_LIGHTBLUE=144,             //9
       BG_LIGHTGREEN=160,            //10
       BG_LIGHTCYAN=176,             //11
       BG_LIGHTRED=192,              //12
       BG_LIGHTMAGENTA=208,          //13
       BG_YELLOW=224,                //14
       BG_WHITE=240                  //15       
       };   

void textColor(int letra, int fundo){
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), letra + fundo);
     }

void escondeCursor(){
  CONSOLE_CURSOR_INFO cursor = {1, FALSE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void mostraCursor(){
  CONSOLE_CURSOR_INFO cursor = {1, TRUE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}


void gotoOpcao(int linha, int coluna){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){coluna-1,linha-1});
     escondeCursor(); 
}

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void printColoured(int color, char string[])
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
    printf("%s\n", string);
    SetConsoleTextAttribute(hConsole, WHITE);
    
}

void desenhaBordas(int x1, int x2,  int y1, int y2)
{
	gotoxy(x1, y1);  printf("\xdb");
	gotoxy(x2, y1);  printf("\xdb");
	gotoxy(x1, y2); printf("\xdb");
	gotoxy(x2, y2); printf("\xdb");

	//linha horizontal -- 
	for(int i= x1+1; i < (x2 + 1); i++)
	{
		gotoxy(i, y1);  printf("\xdb");
		gotoxy(i, y2); printf("\xdb");
	}
	
		//linha vertical | |
	for(int i = y1+1; i < y2; i++)
	{
		gotoxy(x1, i); printf("\xdb");
		gotoxy(x2, i); printf("\xdb");
	}

}
/* Fun��o Para criar espa�amentos */
void espacamneto(int tamanho, char codigo){
    int i;
    for(i = 0; i <= tamanho; i++)
        printf("%c", codigo);
    return;
}


/* Barrinhas laterais */
void barras(int tamanho, char codigo,int TT, int a,int a2,int z){
    int i, j;

    for(i = 0, j = z; i < tamanho; i++, j++){

        gotoxy(a,j);
        printf("%c", codigo);
        espacamneto(TT, ' ');
        gotoxy(a2,j);
        printf("%c\n", codigo);
    }
return;
}

// caixinha
void criar_caixinha(int canto1,int canto2,int canto3,int canto4,
                    int CODcima, int CODlado,int tamanho,int TT,
                    int x,int y, int y2,int a2, int z){
    z = y2 - tamanho;
    gotoxy(x,y);
    printf("%c", canto1); espacamneto(TT, CODcima); printf("%c\n", canto2);
    barras(tamanho,CODlado, TT,x,a2,z );
    gotoxy(x,y2);
    printf("%c",canto3); espacamneto(TT, CODcima); printf("%c\n", canto4);
}

// funcao para definir
void definir(int TAM_barras, int espacamento, int x_su, int  y_su, int y_infe, int xbarra_esquer){

    int z;
    int canto1 = 201;
    int canto2 = 187;
    int canto3 = 200;
    int canto4 = 188;

    int CODcima = 205;
    int CODlado = 186;
    // tamanho das barras
    int tamanho = TAM_barras;
    //espacamneto
    int TT = espacamento;
    // barras superior
    int x =  x_su ; int y =  y_su;

    // barra inferior
    int y2 = y_infe;

    // barras laterais esquerda
    int a2 = xbarra_esquer;
criar_caixinha(canto1, canto2, canto3, canto4,CODcima, CODlado, tamanho, TT,
                x,y,y2,a2,z);
}
