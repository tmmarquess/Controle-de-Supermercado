#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "TabelaHash.c"
#include <unistd.h>

void clear()
{
    const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
    write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}


int printMENU()
{
    int opcao;
    printf("=====================================\n");
    printf("SISTEMA DE ESTOQUE\n");
    printf("[1] ADICIONAR PRODUTO NO ESTOQUE\n");
    printf("[2] REMOVER PRODUTO DO ESTOQUE\n");
    printf("[3] LISTAR PRODUTOS EM ESTOQUE\n");
    printf("[4] PESQUISAR POR PRODUTO\n\n");
    printf("[0] SAIR\n");
    printf("=====================================\n");
    printf("OPCAO:  ");
    scanf("%d", &opcao);

    return opcao;
}

produto printInserir(no **tabela)
{
    char nome[30];
    char codigo[6];
    float preco;
    int quantidade;

    printf("================= INSERIR ================\n");
    printf("Nome: ");
    scanf("%s",nome);
    printf("\nCodigo: ");
    scanf("%s",codigo);
    printf("\nPreco: R$");
    scanf("%f",&preco);
    printf("\nQuantidade: ");
    scanf("%d", &quantidade);
    printf("\n========================================\n");

    produto prodNovo;
    strcpy(prodNovo.nome, nome);
    strcpy(prodNovo.codigo, codigo);
    prodNovo.preco = preco;
    prodNovo.quantidade = quantidade;
    inserir(tabela, prodNovo);

    return prodNovo;
}

void printBusca(no **tabela)
{
    char *chave[20];

    printf("================= BUSCAR ================\n");
    printf("\nCodigo: ");
    scanf("%s",chave);
    no *busca = buscaPorChave(tabela, chave);
    printf("\nRESULTADO:");
    if(busca == NULL)
    {
        printf("\nO ITEM NAO SE ENCONTRA NO ESTOQUE!\n");
    }
    else
    {
        printf("\tNome: %s\n", busca -> produto.nome);
        printf("\tCodigo: %s\n", busca -> produto.codigo);
        printf("\tQuantidade: %d\n", busca -> produto.quantidade);
        printf("\tPreco: %.2f\n", busca -> produto.preco);
        printf("==========================================\n");
    }

}