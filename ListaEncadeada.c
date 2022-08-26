#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

//Criando a Struct que armazena os dados de um produto
typedef struct produto
{
    char nome[30];
    char codigo[6];
    float preco;
    int quantidade;
}produto;

// Criando a Struct que armazena uma lista de produtos
typedef struct no
{
    produto produto; // Armazena o produto
    struct no *prox; // Aponta para o próximo produto da lista
}no;

/* Função para criar a lista. É passado como parâmetro o primeiro
*  produto a ser armazenado na lista. Essa função retorna um 
*  ponteiro do tipo ListaDeCompras com o primeiro valor inicializado.
*/
no* criarNo(produto prod){
    no* item = (no*) malloc(sizeof(no));
    item -> produto = prod;
    item -> prox = NULL;
    return item;
}

bool vazia(no *primeiroItem){
    return primeiroItem == NULL;
}

/* Função para inserir um item no fim da lista, recebe como parâmetro o primeiro
*  item da lista em que o produto será adicionado, e o produto a se adicionar
*/
void inserirNo(no **primeiroItem, produto prod){

    if(vazia((*primeiroItem))){
        printf("Lista nao iniciada!\n");
        return;
    }

    no *novoItem = criarNo(prod);
    no *atual = (*primeiroItem);

    while (atual -> prox != NULL)
        atual = atual -> prox;

    atual -> prox = novoItem;
}

/* Função para retirar itens da lista, recebe como parâmetro o primeiro 
*  item da lista a se retirar o item, e o index do item a ser retirado
*/
void retirar(no **primeiroItem, int index){

    if(vazia(*primeiroItem)){
        return;
    }

    int qntDeItens = 0;
    no *atual = (*primeiroItem);
    //Verifica a quantidade de itens na lista
    while (atual != NULL)
    {
        qntDeItens += 1;
        atual = atual -> prox;
    }
    atual = (*primeiroItem);

    // verifica se o index a se retirar está contido na lista
    if(index < qntDeItens && index >= 0){
        if(index == 0){
            no *aux = (*primeiroItem);
            (*primeiroItem) = (*primeiroItem) -> prox;
            free(aux);
        }else{
            for(int i = 0; i < index-1; i++){
                atual = atual -> prox;
            }
            no *aux = atual -> prox;
            if(aux == NULL){
                atual -> prox = aux;
            }else{
                atual -> prox = aux -> prox;
            }
            free(aux);
        }
    }
}

// Imprime no console todos os itens cadastrados na lista recebida por parametro
void imprimeLista(no *primeiroItem){
    if(vazia(primeiroItem)){
        printf("Lista Vazia!\n");
    }else{
        no *atual = primeiroItem;
        while(atual != NULL){
            printf("Nome: %s\n", atual -> produto.nome);
            printf("Codigo: %s\n", atual -> produto.codigo);
            printf("Quantidade: %d\n", atual -> produto.quantidade);
            printf("Preco: %.2f\n", atual -> produto.preco);
            printf("==========================================\n");

            atual = atual -> prox;
        }
    }
}