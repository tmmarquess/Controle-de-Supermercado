#include "TabelaHash.c"
#include "art.c"

#define LINHA_1 6
#define COLUNA_1 50
#define QUANTIDADE 5

int printMENU(char lista[QUANTIDADE][40]){
     int opcao = 1, lin2, col2, linha, i, tamMaxOpcao, tecla;
     
     tamMaxOpcao = strlen(lista[0]);
     gotoxy(57, 4); printf("  MENU  ");
     for(i = 1; i < QUANTIDADE; i++){
       if(strlen(lista[i]) > tamMaxOpcao){
          tamMaxOpcao = strlen(lista[i]); 
       }
     }
     
     lin2 = LINHA_1 + (QUANTIDADE*2 + 2);
     col2 = COLUNA_1 + tamMaxOpcao + 4;
     
     
     while(true){
     
        linha=LINHA_1 + 2;
        
        for(i = 0 ;i < QUANTIDADE; i++){           
           if(i + 1== opcao)textColor(BLACK, BG_YELLOW);
           else textColor(WHITE, BG_BLACK);
        gotoOpcao(linha,COLUNA_1+2);
        printf("%s",lista[i]);
        linha +=2;
        }
       
      
       tecla = getch();
       
        if(tecla==27){ //ESC
       		opcao=0; 
	   		break;
       	}
       // pressionou ENTER
       else if(tecla==13){ 
       		break;
       }
       //Seta para cima
       else if(tecla==72 && opcao>1){
            opcao--;
       
       }
       //Seta para baixo
       else if(tecla==80){
       	if(opcao< QUANTIDADE) opcao++;         
       }
     }
     return opcao;
}

produto printInserir()
{
	mostraCursor();
	desenhaBordas(35, 85, 4, 20);
    char nome[30];
    char codigo[6];
    float preco;
    int quantidade;
	
	gotoxy(55, 4);
    printf(" INSERIR \n");
    gotoxy(45, 8); printf("Nome: ");
    scanf("%s",nome);
    gotoxy(45, 9); printf("Codigo: ");
    scanf("%s",codigo);
    gotoxy(45, 10); printf("Preco: R$");
    scanf("%f",&preco);
    gotoxy(45, 11); printf("Quantidade: ");
    scanf("%d", &quantidade);

    produto prodNovo;
    strcpy(prodNovo.nome, nome);
    strcpy(prodNovo.codigo, codigo);
    prodNovo.preco = preco;
    prodNovo.quantidade = quantidade;

    return prodNovo;
}

void printBusca(tabelaHash *tabela)
{
	desenhaBordas(35, 85, 4, 20);
    char chave[19];

    gotoxy(52, 4); printf(" BUSCAR PRODUTO \n");
    gotoxy(45, 7); printf("Codigo: ");
    scanf("%s",chave);
    no *busca = buscaPorChave(tabela, chave);
    if(busca == NULL)
    {
        gotoxy(45, 10); printColoured(12, "O ITEM ESTA FORA DE ESTOQUE!\n");
    }
    else
    {
    	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 2);
        gotoxy(45, 10);  printf("Nome: %s\n", busca -> produto.nome);
        gotoxy(45, 11);  printf("Codigo: %s\n", busca -> produto.codigo);
        gotoxy(45, 12);  printf("Quantidade: %d\n", busca -> produto.quantidade);
        gotoxy(45, 13); printf("Preco: R$%.2f\n", busca -> produto.preco);
    	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}

}

void printImprimir(tabelaHash tabela)
{
	desenhaBordas(35, 85, 4, 20);
	imprimeTabela(tabela);

}
     

    
