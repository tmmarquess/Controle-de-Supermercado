#include <string.h>

#include "TabelaHash.c"
#include "art.c"



int printOpcoes()
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
        gotoxy(40, 7); printColoured(12, "O ITEM ESTA FORA DE ESTOQUE!\n");
    }
    else
    {
    	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 2);
        gotoxy(40, 7);  printf("Nome: %s\n", busca -> produto.nome);
        gotoxy(40, 8);  printf("Codigo: %s\n", busca -> produto.codigo);
        gotoxy(40, 9);  printf("Quantidade: %d\n", busca -> produto.quantidade);
        gotoxy(40, 10); printf("Preco: %.2f\n", busca -> produto.preco);
    	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}

}

void printImprimir(tabelaHash tabela)
{
	imprimeTabela(tabela);

}

void printTelaInicial()
{
	
}
