#include"TabelaHash.c"

int main(){
    tabelaHash teste;
    iniciaTabela(&teste);

    produto prodNovo;
    strcpy(prodNovo.nome, "Queijo");
    strcpy(prodNovo.codigo, "Laticinio");
    prodNovo.preco = 3.50;
    prodNovo.quantidade = 1;
    inserir(&teste, prodNovo);

    strcpy(prodNovo.nome, "Laranja");
    strcpy(prodNovo.codigo, "Frutas");
    prodNovo.preco = 5;
    prodNovo.quantidade = 10;
    inserir(&teste, prodNovo);

    strcpy(prodNovo.nome, "Maca");
    strcpy(prodNovo.codigo, "Frutas");
    prodNovo.preco = 7;
    prodNovo.quantidade = 10;
    inserir(&teste, prodNovo);

    strcpy(prodNovo.nome, "Paprica");
    strcpy(prodNovo.codigo, "temperos");
    prodNovo.preco = 1;
    prodNovo.quantidade = 3;

    inserir(&teste, prodNovo);
    strcpy(prodNovo.nome, "Farinha");
    strcpy(prodNovo.codigo, "graos");
    prodNovo.preco = 10;
    prodNovo.quantidade = 1;
    inserir(&teste, prodNovo);

    strcpy(prodNovo.nome, "Linhaca");
    strcpy(prodNovo.codigo, "graos");
    prodNovo.preco = 5;
    prodNovo.quantidade = 3;
    inserir(&teste, prodNovo);

    strcpy(prodNovo.nome, "Batata");
    strcpy(prodNovo.codigo, "legumes");
    prodNovo.preco = 5;
    prodNovo.quantidade = 3;
    inserir(&teste, prodNovo);


    remover(&teste, prodNovo.codigo);

    imprimeTabela(teste);

    //código para testar busca
    char batata[] = "temper";
    no *hihi = buscaPorChave(&teste,batata);
    if(hihi != NULL){
        printf("Nome: %s\n", hihi -> produto.nome);
        printf("Codigo: %s\n", hihi -> produto.codigo);
        printf("Quantidade: %d\n", hihi -> produto.quantidade);
        printf("Preco: %.2f\n", hihi -> produto.preco);
        printf("==========================================\n");
    }
}