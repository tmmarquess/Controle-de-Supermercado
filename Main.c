#include "Interface.c"


int main(){
    tabelaHash Estoque;
    iniciaTabela(&Estoque);
    produto prodNovo;
    int opcao;

    do
    {
        opcao = printMENU();
        system("cls");
        if(opcao == 1)
        {
            prodNovo = printInserir(&Estoque);
        }
        if(opcao == 3) {
            imprimeTabela(&Estoque);
        }
        if(opcao == 4)
        {
            printBusca(&Estoque);
        }
        system("pause");
        system("cls");

    }while(opcao != 0);
}
