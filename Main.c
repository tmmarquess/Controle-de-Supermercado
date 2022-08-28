#include "Interface.c"


int main(){
	
	system("title SISTEMA DE CONTROLE DE MERCADO");
    tabelaHash Estoque;
    iniciaTabela(&Estoque);
    produto prodNovo;
    int opcao;
    
    Title();
    system("pause");
    
    do
    {
    	textColor(3);
    	desenhaBordas();
        opcao = printOpcoes();
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
       
    gotoxy(35, 1); system("pause");
    system("cls");

    }while(opcao != 0);
    
    return 0;
}
