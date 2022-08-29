#include "Interface.c"

int main()
{
	system("title CONTROLE DE ESTOQUE");
	tabelaHash Estoque;
    iniciaTabela(&Estoque);
    produto prodNovo;
	
    int opcao;
    char lista[6][40]={"ADICIONAR PRODUTO", "REMOVER PRODUTO", "PESQUISAR PRODUTO", "LISTAR PRODUTOS", "SITUACAO DO SISTEMA", "LIMPAR ESTOQUE"};
    
    //1
    strcpy(prodNovo.nome, "feijao");
    strcpy(prodNovo.codigo, "45c1a1");
    prodNovo.preco = 5;
    prodNovo.quantidade = 3;
    
    inserir(&Estoque, prodNovo);
    
    //2
    strcpy(prodNovo.nome, "arroz");
    strcpy(prodNovo.codigo, "k75x1a");
    prodNovo.preco = 5;
    prodNovo.quantidade = 3;
    
    inserir(&Estoque, prodNovo);
    
    //3
    strcpy(prodNovo.nome, "acucar");
    strcpy(prodNovo.codigo, "48c2x1");
    prodNovo.preco = 5;
    prodNovo.quantidade = 3;
    
    inserir(&Estoque, prodNovo);
    
    //4
    strcpy(prodNovo.nome, "ovo");
    strcpy(prodNovo.codigo, "9ve4x1");
    prodNovo.preco = 5;
    prodNovo.quantidade = 3;
    
    inserir(&Estoque, prodNovo);
    
    //5
    strcpy(prodNovo.nome, "coco");
    strcpy(prodNovo.codigo, "9v01x1");
    prodNovo.preco = 5;
    prodNovo.quantidade = 3;
    
    inserir(&Estoque, prodNovo);
    
    //6
    strcpy(prodNovo.nome, "alface");
    strcpy(prodNovo.codigo, "104586");
    prodNovo.preco = 5;
    prodNovo.quantidade = 3;
    
    inserir(&Estoque, prodNovo);
    
    //7
    strcpy(prodNovo.nome, "tomate cereja");
    strcpy(prodNovo.codigo, "pv53q0");
    prodNovo.preco = 5;
    prodNovo.quantidade = 3;
    
    inserir(&Estoque, prodNovo);
    
    //8
    strcpy(prodNovo.nome, "bolacha waffle");
    strcpy(prodNovo.codigo, "4v9r41");
    prodNovo.preco = 5;
    prodNovo.quantidade = 3;
    
    inserir(&Estoque, prodNovo);
    //9
    strcpy(prodNovo.nome, "diamante negro");
    strcpy(prodNovo.codigo, "dkri20");
    prodNovo.preco = 5;
    prodNovo.quantidade = 3;
    
    inserir(&Estoque, prodNovo);
    
    //10
    strcpy(prodNovo.nome, "cebola");
    strcpy(prodNovo.codigo, "xy74v10");
    prodNovo.preco = 5;
    prodNovo.quantidade = 3;
    
    inserir(&Estoque, prodNovo);
    
    //11
    strcpy(prodNovo.nome, "manga");
    strcpy(prodNovo.codigo, "f1s0g3");
    prodNovo.preco = 5;
    prodNovo.quantidade = 3;
    
    inserir(&Estoque, prodNovo);
    
    //12
    strcpy(prodNovo.nome, "banana");
    strcpy(prodNovo.codigo, "0pb391");
    prodNovo.preco = 5;
    prodNovo.quantidade = 3;
    
    inserir(&Estoque, prodNovo);
    
    //13
    strcpy(prodNovo.nome, "paprica");
    strcpy(prodNovo.codigo, "xp3xz9");
    prodNovo.preco = 5;
    prodNovo.quantidade = 3;
    
    inserir(&Estoque, prodNovo);
    
    //14
    strcpy(prodNovo.nome, "biscoito toddy");
    strcpy(prodNovo.codigo, "c9v1m2");
    prodNovo.preco = 5;
    prodNovo.quantidade = 3;
    
    inserir(&Estoque, prodNovo);
    
    //15
    strcpy(prodNovo.nome, "pera");
    strcpy(prodNovo.codigo, "7bkxq3");
    prodNovo.preco = 5;
    prodNovo.quantidade = 3;
    
    inserir(&Estoque, prodNovo);
    
    //16
    strcpy(prodNovo.nome, "uva");
    strcpy(prodNovo.codigo, "y8cx21");
    prodNovo.preco = 5;
    prodNovo.quantidade = 3;
    
    inserir(&Estoque, prodNovo);
    
    //17
    strcpy(prodNovo.nome, "acucar mascavo");
    strcpy(prodNovo.codigo, "05v127");
    prodNovo.preco = 5;
    prodNovo.quantidade = 3;
    
    inserir(&Estoque, prodNovo);
    
    //18
    strcpy(prodNovo.nome, "sal");
    strcpy(prodNovo.codigo, "a0bn41");
    prodNovo.preco = 5;
    prodNovo.quantidade = 3;
    
    inserir(&Estoque, prodNovo);
    
    //19
    strcpy(prodNovo.nome, "sal grosso");
    strcpy(prodNovo.codigo, "l632sc");
    prodNovo.preco = 5;
    prodNovo.quantidade = 3;
    
    inserir(&Estoque, prodNovo);
    
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
        
        gotoxy(5, 25); system("pause");
        system("cls");
    }while(opcao != 0);

	return 0;
}
