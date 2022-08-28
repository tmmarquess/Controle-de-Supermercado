#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

#define WHITE 1

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void printColoured(int color_id, char string[])
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, color_id);
    printf("%s\n", string);
    SetConsoleTextAttribute(hConsole, WHITE);
    
}

void textColor(int color_id)
{
	HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, color_id);
}


void desenhaBordas()
{
	// cantos da borda
	gotoxy(36, 3);  printf("\xdb");
	gotoxy(75, 3);  printf("\xdb");
	gotoxy(36, 20); printf("\xdb");
	gotoxy(75, 20); printf("\xdb");
	
	/*linha vertical | |
	for(int i = 4; i < 20; i++)
	{
		gotoxy(35, i); printf(" %c", 186);
		gotoxy(75, i); printf(" %c", 186);
	}
	*/
	
	for(int i = 4; i < 20; i++)
	{
		gotoxy(36, i); printf("\xdb");
		gotoxy(75, i); printf("\xdb");
	}
	//linha horizontal -- 
	for(int i=37; i < 76; i++)
	{
		gotoxy(i, 3);  printf("\xdb");
		gotoxy(i, 20); printf("\xdb");
	}

}

void Title()
{
	printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb      \xdb\xdb\xdb\xdb \n");
	printf("\xdb              \xdb\xdb \n");
	printf(" \n");
	printf(" \n");
	printf(" \n");
	printf(" \n");
	printf(" \n");
}
