#include "Interface.c"

void insereItens(tabelaHash *tabela);

int main()
{
	system("title CONTROLE DE tabela");
	tabelaHash Estoque;
    iniciaTabela(&Estoque);
    produto prodNovo;
    insereItens(&Estoque);
	
    int opcao;
    char lista[6][40]={"ADICIONAR PRODUTO", "REMOVER PRODUTO", "PESQUISAR PRODUTO", "LISTAR PRODUTOS", "SITUACAO DO SISTEMA", "LIMPAR ESTOQUE"};
    
    
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
        	printStatus(&Estoque);
        }
        
        if(opcao == 6)
        {
        	printLimpar(&Estoque);
		}
        
        gotoxy(50, 1); system("pause");
        system("cls");
    }while(opcao != 0);

	return 0;
}

void insereItens(tabelaHash *tabela)
{
	produto prodNovo;
	
	//1
    strcpy(prodNovo.nome, "Feijao da Vo");
    strcpy(prodNovo.codigo, "45c1a1");
    prodNovo.preco = 12;
    prodNovo.quantidade = 10;
    
    inserir(tabela, prodNovo);
    
    //2
    strcpy(prodNovo.nome, "Arroz Integral");
    strcpy(prodNovo.codigo, "k75x1a");
    prodNovo.preco = 10;
    prodNovo.quantidade = 30;
    
    inserir(tabela, prodNovo);
    
    //3
    strcpy(prodNovo.nome, "Coco Ralado");
    strcpy(prodNovo.codigo, "48c2x1");
    prodNovo.preco = 7;
    prodNovo.quantidade = 12;
    
    inserir(tabela, prodNovo);
    
    //4
    strcpy(prodNovo.nome, "Cartela de Ovo");
    strcpy(prodNovo.codigo, "9ve4j1");
    prodNovo.preco = 31;
    prodNovo.quantidade = 5;
    
    inserir(tabela, prodNovo);
    
    //5
    strcpy(prodNovo.nome, "Cacau em Po");
    strcpy(prodNovo.codigo, "9v01x1");
    prodNovo.preco = 40;
    prodNovo.quantidade = 13;
    
    inserir(tabela, prodNovo);
    
    //6
    strcpy(prodNovo.nome, "Alface");
    strcpy(prodNovo.codigo, "104586");
    prodNovo.preco = 2;
    prodNovo.quantidade = 6;
    
    inserir(tabela, prodNovo);
    
    //7
    strcpy(prodNovo.nome, "Tomate Cereja");
    strcpy(prodNovo.codigo, "pv53q0");
    prodNovo.preco = 0.75;
    prodNovo.quantidade = 35;
    
    inserir(tabela, prodNovo);
    
    //8
    strcpy(prodNovo.nome, "Bolacha Waffle");
    strcpy(prodNovo.codigo, "4v9r41");
    prodNovo.preco = 2.5;
    prodNovo.quantidade = 9;
    
    inserir(tabela, prodNovo);
    //9
    strcpy(prodNovo.nome, "Diamante Negro");
    strcpy(prodNovo.codigo, "dkri20");
    prodNovo.preco = 16;
    prodNovo.quantidade = 3;
    
    inserir(tabela, prodNovo);
    
    //10
    strcpy(prodNovo.nome, "Cebola Roxa");
    strcpy(prodNovo.codigo, "xy74v10");
    prodNovo.preco = 5;
    prodNovo.quantidade = 3;
    
    inserir(tabela, prodNovo);
    
    //11
    strcpy(prodNovo.nome, "Manga Rosa");
    strcpy(prodNovo.codigo, "f1s0g3");
    prodNovo.preco = 5;
    prodNovo.quantidade = 3;
    
    inserir(tabela, prodNovo);
    
    //12
    strcpy(prodNovo.nome, "Banana Prata");
    strcpy(prodNovo.codigo, "0pb391");
    prodNovo.preco = 3.5;
    prodNovo.quantidade = 30;
    
    inserir(tabela, prodNovo);
    
    //13
    strcpy(prodNovo.nome, "Paprica Doce");
    strcpy(prodNovo.codigo, "xp3xz9");
    prodNovo.preco = 1.75;
    prodNovo.quantidade = 7;
    
    inserir(tabela, prodNovo);
    
    //14
    strcpy(prodNovo.nome, "Biscoito Toddy");
    strcpy(prodNovo.codigo, "c9v1m2");
    prodNovo.preco = 5;
    prodNovo.quantidade = 3;
    
    inserir(tabela, prodNovo);
    
    //15
    strcpy(prodNovo.nome, "Pera");
    strcpy(prodNovo.codigo, "7bkxq3");
    prodNovo.preco = 5;
    prodNovo.quantidade = 10;
    
    inserir(tabela, prodNovo);
    
    //16
    strcpy(prodNovo.nome, "Uva Passa");
    strcpy(prodNovo.codigo, "y8cx21");
    prodNovo.preco = 4.75;
    prodNovo.quantidade = 2;
    
    inserir(tabela, prodNovo);
    
    //17
    strcpy(prodNovo.nome, "Acucar Mascavo");
    strcpy(prodNovo.codigo, "05v127");
    prodNovo.preco = 15;
    prodNovo.quantidade = 3;
    
    inserir(tabela, prodNovo);
    
    //18
    strcpy(prodNovo.nome, "Sal de Cozinha");
    strcpy(prodNovo.codigo, "a0bn41");
    prodNovo.preco = 14;
    prodNovo.quantidade = 3;
    
    inserir(tabela, prodNovo);
    
    //19
    strcpy(prodNovo.nome, "Sal Grosso");
    strcpy(prodNovo.codigo, "l632sc");
    prodNovo.preco = 12.99;
    prodNovo.quantidade = 3;
    
    inserir(tabela, prodNovo);
    
}
