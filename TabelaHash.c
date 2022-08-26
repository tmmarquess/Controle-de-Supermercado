#include "ListaEncadeada.c"
#include <math.h>
#define TAMANHO 19 //Tamanho do vetor estático da tabelaHash

//Definindo um tipo de dado tabelaHash
typedef no *tabelaHash[TAMANHO];

//Vetor Contendo todos os caracteres alfabéticos maiúsculos e minusculos
char caracteres[] =  {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

//Vetor contendo todos os caracteres numéricos
char numeros[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

//Iniciando a tabela com valores nulos
void iniciaTabela(tabelaHash *tabela){
    for(int i = 0; i < TAMANHO;i++){
        (*tabela)[i] = NULL;
    }
}

//retorna o tamanho de um vetor de Char AKA String
int getTamanho(char string[]){
    int i = 0;
    while (string[i] != '\0') //num vetor de Char, '\0' é o ultimo caractere
        i++;
    return i;
}

/*Calcula o valor do Hash a partir da String chave passada como parâmetro.
* o cálculo do Hash é feito a partir do index do caractere atual no vetor
* de caracteres (ou de numeros) multiplicado por 10 elevado à posição do 
* caractere na chave. Caso o caractere atual não esteja contido nos vetores,
* é utilizado no lugar do index, o seu código ASCII.
*/
int calculaHash(char chave[]){
    int letras = getTamanho(caracteres); //tamanho do vetor de caracteres
    int tamanho = getTamanho(chave); //tamanho da chave passada por parametro

    bool isNumero = false; //booleano que verifica se o index é um numero
    bool isLetra = false; //booleano que verifica se o index é uma letra

    int codigoHash = 0; //código hash a ser gerado

    for(int i = 0; i < tamanho; i++){ //percorre toda a String Chave
        for(int j = 0; j < 10; j++){//Percorre toda o vetor de numeros
            if(chave[i] == numeros[j]){//Se o index da chave for um numero
                isNumero = true;
                codigoHash += (j * pow(10, i));
                break;
            }
        }
        if(!isNumero){ // Se o index não for um numero
            for(int j = 0; j < letras; j++){ // percorre todo o vetor de caracteres
                if(chave[i] == caracteres[j]){//Se o index da chave for um caractere
                    isLetra = true;
                    codigoHash += (j * pow(10, i));
                    break;
                }
            }
            if(!isLetra){//Se o index não for uma letra, nem um numero
                int ascii = chave[i]; //pega o valor do char na tabela ASCII
                codigoHash += (ascii * pow(10, i));
            }
        }
        isNumero = isLetra = false;//reseta as variáveis
        
    }

    return codigoHash; //retorna o código hash gerado
}

/*Calcula o valor do Hash a partir da String chave passada como parâmetro.
* o Calculo do Hash é feito a partir do valor do caractere na tabela ASCII
* multiplicado por 10 elevado à posição do caractere na chave
*/
int calculaHash2(char chave[]){
    int tamanho = getTamanho(chave); //tamanho da chave passada por parametro
    int codigoHash = 0; //código hash a ser gerado
    for(int i = 0; i < tamanho; i++){ //percorre toda a String Chave
        int ascii = chave[i]; //pega o valor do char na tabela ASCII
        codigoHash += (ascii * pow(10, i));
    }
    return codigoHash; //retorna o código hash gerado
}

// Retorna um index correspondente ao tamanho da tabelaHash com base no hash gerado
int getIndex(int hash){
    return hash % TAMANHO;
}

/*Insere um produto na tabelaHash, calculado o hash a partir da chave, 
* gerando o index, e inserindo o produto no index correspondente
*/
void inserir(tabelaHash *tabela, produto prod){
    int hash = calculaHash(prod.codigo); 
    int index = getIndex(hash);

    if((*tabela)[index] != NULL){//verifica se há uma colisão no index retornado
        inserirNo(&((*tabela)[index]), prod); // se houver, insere na estrutura dinamica
    }else{ // se não houver, cria o nó e insere ele na posição
        no *novoItem = criarNo(prod);
        ((*tabela)[index]) = novoItem;
    }
}

// Imprime todos os produtos contidos na tabela
void imprimeTabela(tabelaHash tabela){
    for(int i = 0; i < TAMANHO; i++){ //Percorre todo o vetor da tabelaHash
        if(tabela[i] != NULL){ // se o item do vetor não for nulo, imprime a lista contida nele 
            printf("Index %d:\n", i);
            imprimeLista(tabela[i]);
        }
    }
}