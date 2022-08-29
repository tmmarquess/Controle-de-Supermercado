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
