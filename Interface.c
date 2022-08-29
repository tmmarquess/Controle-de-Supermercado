#include "TabelaHash.c"
#include "art.c"

#define LINHA_1 6
#define COLUNA_1 10
#define QUANTIDADE 6

int printMENU(char lista[QUANTIDADE][40]){
     int opcao = 1, lin2, col2, linha, i, tamMaxOpcao, tecla;
     
     desenhaBordas(5, 45, 1, 20);
     tamMaxOpcao = strlen(lista[0]);
     gotoxy(15, 1); printf("  CONTROLE DE ESTOQUE  ");
     
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
           //if(i + 1== opcao)textColor(BLACK, BG_YELLOW);
            //definir(1,23,8,6+i+2,8+i+2,33);
           textColor(WHITE, BG_BLACK);
           gotoOpcao(linha,COLUNA_1+2 );
           //condicao da seta de navegacao
           if(i + 1== opcao){
            printf("%c", 175);
           }else{
            printf(" ", 175);
           }
           printf(" %s",lista[i]);
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
	desenhaBordas(5, 45, 1, 20);
    char nome[30];
    char codigo[6];
    float preco;
    int quantidade;
	
	gotoxy(10, 1);
    printf(" INSERIR \n");
    gotoxy(10, 8); printf("Nome: ");
    scanf("%s",nome);
    gotoxy(10, 9); printf("Codigo: ");
    scanf("%s",codigo);
    gotoxy(10, 10); printf("Preco: R$");
    scanf("%f",&preco);
    gotoxy(10, 11); printf("Quantidade: ");
    scanf("%d", &quantidade);

    produto prodNovo;
    strcpy(prodNovo.nome, nome);
    strcpy(prodNovo.codigo, codigo);
    prodNovo.preco = preco;
    prodNovo.quantidade = quantidade;


    definir(0,30,7,15,17,39);
    gotoxy(12,16);
    printf("DADOS DO PRODUTO SALVO");

    return prodNovo;
}

void printBusca(tabelaHash *tabela)
{
	desenhaBordas(5, 45, 1, 20);
    char chave[19];

    gotoxy(15, 1); printf(" BUSCAR PRODUTO \n");
    gotoxy(10, 7); printf("Codigo: ");
    scanf("%s",chave);
    no *busca = buscaPorChave(tabela, chave);
    if(busca == NULL)
    {
        gotoxy(10, 10); printColoured(12, "O ITEM ESTA FORA DE ESTOQUE!\n");
    }
    else
    {
    	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 2);
        gotoxy(10, 10);  printf("Nome: %s\n", busca -> produto.nome);
        gotoxy(10, 11);  printf("Codigo: %s\n", busca -> produto.codigo);
        gotoxy(10, 12);  printf("Quantidade: %d\n", busca -> produto.quantidade);
        gotoxy(10, 13); printf("Preco: R$%.2f\n", busca -> produto.preco);
    	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}

}

void printImprimir(tabelaHash *tabela)
{
	if(*tabela == NULL)
	{
		gotoxy(10, 7); printColoured(RED, "SEM PRODUTOS NO ESTOQUE");
	}
	else
	{
		imprimeTabela(tabela);	
	}
}

void printRemover(tabelaHash *tabela)
{
	desenhaBordas(5, 45, 1, 20);
    char chave[19];
    bool removed;

    gotoxy(15, 1); printf(" REMOVER PRODUTO ");
    gotoxy(10, 5); printf("Codigo: ");
    scanf("%s",chave);

    removed = remover(tabela, chave);
    if(removed == true)
    {
        gotoxy(10, 7); printColoured(BLUE, "PRODUTO REMOVIDO");
    }
    else
    {
    	gotoxy(10, 7); printColoured(RED, "PRODUTO NAO ENCONTRADO");
	}
}

void printStatus(tabelaHash *tabela)
{

	desenhaBordas(5, 45, 1, 20);
	gotoxy(15, 1); printf("  STATUS  ");
	if (empty(tabela)) {
		gotoxy(10, 5); printf("Tabela Vazia: TRUE");
	} else {
		gotoxy(10, 5); printf("Tabela Vazia: FALSE");
	}
	if (cheia(tabela)) {
		gotoxy(10, 7); printf("Tabela Cheia: TRUE");
	} else {
		gotoxy(10, 7); printf("Tabela Cheia: FALSE");
	}
	gotoxy(10, 9); printf("Quantidade de Itens: %d", tamanho(tabela));
	gotoxy(10, 11); printf("Fator de Carga: %.4f", fatorCarga(tabela));
}
     
     
void printLimpar(tabelaHash *tabela)
{
	desenhaBordas(5, 45, 1, 20);
	limpar(tabela);
	gotoxy(15, 1); printf(" LIMPAR TABELA ");
	gotoxy(10,7); printColoured(GREEN, "eSTOQUE ESVAZIADO!");
}

    
