#include "Interface.c"

int main()
{
	system("title CONTROLE DE ESTOQUE");
	tabelaHash Estoque;
    iniciaTabela(&Estoque);
    produto prodNovo;
	
    int opcao;
    char lista[5][40]={"ADICIONAR PRODUTO", "REMOVER PRODUTO", "PESQUISAR PRODUTO", "LISTAR PRODUTOS", "SITUACAO DO SISTEMA"};
    
    do{
       opcao = printMENU(lista);
       system("cls");
       
       if(opcao == 1)
        {
            prodNovo = printInserir();
            inserir(&Estoque, prodNovo);
        }
        
        if(opcao == 2)
        {
            printRemover(&Estoque);
        }
        
         if(opcao == 3)
        {
            printBusca(&Estoque);
        }
        if(opcao == 4) {
        	printImprimir(Estoque);
        }

		if(opcao == 5) {
        	printStatus();
        }
        
        gotoxy(35, 1); system("pause");
        system("cls");
    }while(opcao != 0);

	return 0;
}
