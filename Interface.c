#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "TabelaHash.c"
#include <windows.h>


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
    SetConsoleTextAttribute(hConsole, 7);
}

void desenhaBordas()
{
	// cantos da borda
	gotoxy(35, 3);  printf(" %c", 201);
	gotoxy(75, 3);  printf(" %c", 187);
	gotoxy(35, 20); printf(" %c", 200);
	gotoxy(75, 20); printf(" %c", 188);
	
	//linha vertical | |
	for(int i = 4; i < 20; i++)
	{
		gotoxy(35, i); printf(" %c", 186);
		gotoxy(75, i); printf(" %c", 186);
	}
	
	//linha horizontal -- 
	for(int i=37; i < 76; i++)
	{
		gotoxy(i, 3);  printf("%c", 205);
		gotoxy(i, 20); printf("%c", 205);
	}

}


int printMENU()
{
    int opcao;
    gotoxy(46, 3);
    printf(" CONTROLE DE ESTOQUE \n");
    gotoxy(40, 5); printf("[1] ADICIONAR PRODUTO NO ESTOQUE\n");
    gotoxy(40, 6); printf("[2] REMOVER PRODUTO DO ESTOQUE\n");
    gotoxy(40, 7); printf("[3] LISTAR PRODUTOS EM ESTOQUE\n");
    gotoxy(40, 8); printf("[4] PESQUISAR POR PRODUTO\n\n");
    gotoxy(40, 9); printf("[0] SAIR\n");
    gotoxy(40, 11); printf("OPCAO:  ");
    scanf("%d", &opcao);

    return opcao;
}

produto printInserir()
{
    char nome[30];
    char codigo[6];
    float preco;
    int quantidade;
	
	gotoxy(46, 3);
    printf(" INSERIR \n");
    gotoxy(40, 5); printf("Nome: ");
    scanf("%s",nome);
    gotoxy(40, 6); printf("Codigo: ");
    scanf("%s",codigo);
    gotoxy(40, 7); printf("Preco: R$");
    scanf("%f",&preco);
    gotoxy(40, 8); printf("Quantidade: ");
    scanf("%d", &quantidade);

    produto prodNovo;
    strcpy(prodNovo.nome, nome);
    strcpy(prodNovo.codigo, codigo);
    prodNovo.preco = preco;
    prodNovo.quantidade = quantidade;

    return prodNovo;
}

void printBusca(tabelaHash *tabela)
{
    char chave[19];

    gotoxy(48, 3); printf(" BUSCAR PRODUTO \n");
    gotoxy(40, 4); printf("Codigo: ");
    scanf("%s",chave);
    no *busca = buscaPorChave(tabela, chave);
    if(busca == NULL)
    {
        gotoxy(40, 7); printColoured(12, "O ITEM ESTA FORA DE ESTOQUE!");
    }
    else
    {
        gotoxy(40, 7);  printf("Nome: %s\n", busca -> produto.nome);
        gotoxy(40, 8);  printf("Codigo: %s\n", busca -> produto.codigo);
        gotoxy(40, 9);  printf("Quantidade: %d\n", busca -> produto.quantidade);
        gotoxy(40, 10); printf("Preco: %.2f\n", busca -> produto.preco);
    }

}

void printImprimir(tabelaHash tabela)
{
	imprimeTabela(tabela);

}
