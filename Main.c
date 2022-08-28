#include "Interface.c"


int main(){
    tabelaHash Estoque;
    iniciaTabela(&Estoque);
    produto prodNovo;
    int opcao;
        
    do
    {
    	desenhaBordas();
        opcao = printMENU();
        system("cls");
        if(opcao == 1)
        {
        	desenhaBordas();
            prodNovo = printInserir();
            inserir(&Estoque, prodNovo);
        }
        if(opcao == 3) {
        	printImprimir(Estoque);
        }
        if(opcao == 4)
        {
        	desenhaBordas();
            printBusca(&Estoque);
        }
    gotoxy(40, 1); system("pause");
    system("cls");

    }while(opcao != 0);
    
    return 0;
}
