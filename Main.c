#include "Interface.c"


int main()
{
	system("title CONTROLE DE ESTOQUE");
	tabelaHash Estoque;
    iniciaTabela(&Estoque);
    produto prodNovo;
	
    int opcao;
    char lista[5][40]={"ADICIONAR PRODUTO", "REMOVER PRODUTO", "PESQUISAR PRODUTO", "LISTAR PRODUTOS", "LIMPAR ESTOQUE"};
    
    do{
    	desenhaBordas(35, 85, 4, 20);
       opcao = printMENU(lista);
       system("cls");
    
       if (opcao == 0){
       break;
       }
       
       if(opcao == 1)
        {
            prodNovo = printInserir();
            inserir(&Estoque, prodNovo);
        }
        
        if(opcao == 2)
        {
            printf("\n\nremover\n\n");
        }
        
         if(opcao == 3)
        {
            printBusca(&Estoque);
        }
        if(opcao == 4) {
        	printImprimir(Estoque);
        }

		if(opcao == 5) {
        	printf("\n\nlimpar\n\n");
        }
        
        gotoxy(35, 1); system("pause");
        system("cls");

    }while(opcao != 0);
    
  textColor(WHITE, BG_BLACK);
  gotoOpcao(24,1);
  
  return 0;
}
