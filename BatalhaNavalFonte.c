#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define l 10
#define a 10
//declarando a matriz tabuleiro
char tabuleiro[l][a];

// Criando uma função para inicializar o tabuleiro caso necessario
void inicializar_tabuleiro(char tabuleiro[l][a]){
    for(int i= 0; i < l ; i++){
        for(int j = 0; j<a;j++){
            tabuleiro[i][j]= '0';
        }

    }
}

// Criando uma função para imprimir o tabuleiro
void imprimir_tabuleiro(char tabuleiro[l][a]){
    printf("  ");
    for(int j=0;j <a;j++){
        printf("  %c",'A'+ j);
    }
    printf("\n"); 

    for(int i=0;i<l;i++){
        printf(" %d ",i);
        for(int j=0;j < a;j++){
          printf(" %c ",tabuleiro[i][j]);

        }
        printf("\n");
    }
}
//Criando funções para posicionar os barcos
//primeiro barco na vertical
int colocar_vertical(int x, int y, int tamanho){
    if(x+ tamanho <= a){
        int ok = 1;
        for(int i= 0;i< tamanho; i++){
             if (tabuleiro[x+i][y] != '0') ok = 0;
        if (ok) {
            for (int i = 0; i < tamanho; i++) tabuleiro[x+i][y] = '3';
            return 1;
        }
    }
    }
    if(x - tamanho+ 1 >=0){
        int ok = 1;
        for(int i = 0; i < tamanho;i++){
        if (tabuleiro[x-i][y] != '0') ok = 0;
        if (ok) {
            for (int i = 0; i < tamanho; i++) tabuleiro[x-i][y] = '3';
            return 1;
        }
    }
    }
    return 0;
}

//segundo na horizontal
int colocar_horizontal(int x, int y, int tamanho) {
    // tenta pra direita
    if (y + tamanho <= l) {
        int ok = 1;
        for (int j = 0; j < tamanho; j++){
            if (tabuleiro[x][y+j] != '0') ok = 0;
        if (ok) {
            for (int j = 0; j < tamanho; j++) tabuleiro[x][y+j] = '3';
            return 1;
        }
    }
    }
    // tenta pra esquerda
    if (y - tamanho + 1 >= 0) {
        int ok = 1;
        for (int j = 0; j < tamanho; j++)
            if (tabuleiro[x][y-j] != '0') ok = 0;
        if (ok) {
            for (int j = 0; j < tamanho; j++) tabuleiro[x][y-j] = '3';
            return 1;
        }
    }
    return 0;
}

//tercero na diagonal
 int colocar_diagonal1(int x, int y, int tamanho) {
    // analisando a diagonal para baixo
    if (x + tamanho <= a && y + tamanho <= l) {
        int ok = 1;
        for (int i = 0; i < tamanho; i++)
            if (tabuleiro[x+i][y+i] != '0') ok = 0;
        if (ok) {
            for (int i = 0; i < tamanho; i++) tabuleiro[x+i][y+i] = '3';
            return 1;
        }
    }
    // analisando a diagonal para cima
    if (x - tamanho + 1 >= 0 && y - tamanho + 1 >= 0) {
        int ok = 1;
        for (int i = 0; i < tamanho; i++)
            if (tabuleiro[x-i][y-i] != '0') ok = 0;
        if (ok) {
            for (int i = 0; i < tamanho; i++) tabuleiro[x-i][y-i] = '3';
            return 1;
        }
    }
    return 0;
}   

//cuarto na diagonal
int colocar_diagonal2(int x, int y, int tamanho) {
    // analisar a diagonal para a entrada das coordenadas
    if (x + tamanho <= a && y - tamanho + 1 >= 0) {
        int ok = 1;
        for (int i = 0; i < tamanho; i++)
            if (tabuleiro[x+i][y-i] != '0') ok = 0;
        if (ok) {
            for (int i = 0; i < tamanho; i++) tabuleiro[x+i][y-i] = '3';
            return 1;
        }
    }
    // analisar a outra diagnal usando if
    if (x - tamanho + 1 >= 0 && y + tamanho <= a) {
        //declarando e inicialisando variavel para aplicação do efeito
        int ok = 1;
        //usando for para comprobar a diagonal
        for (int i = 0; i < tamanho; i++)
            if (tabuleiro[x-i][y+i] != '0') ok = 0;
        if (ok) {
            for (int i = 0; i < tamanho; i++) tabuleiro[x-i][y+i] = '3';
            return 1;
        }
    }
    return 0;
}


int main() {
    char tabuleiro[l][a]; 
    
    char letra;
    int numero;
    int coluna;
    int linha;
    

  
    // Imprimir o tabuleiro com letras e numeros como coordenadas sendo as letras encima e do lado os numeros
    printf("   Batalha Naval\n");
    printf("   =============\n");
    //Inicializando tabuleiro
    inicializar_tabuleiro(tabuleiro);
    imprimir_tabuleiro(tabuleiro);
    printf("A batalha Naval começou!\n");
    printf("Você tem 2 navios para posicionar no tabuleiro.\n");
     //Pedindo a entrada de dados
    printf("Digite a coordenada inicial do navio vertical (ex: B 3): \n");
    //Registrando a entrada dos dados
    scanf(" %c %d", &letra, &coluna);
      if((letra < 'A' || letra > 'J') || (numero < 0 || numero > 9)) {
                printf("Coordenadas inválidas. Tente novamente.\n");
                return 1;
            }
    //Transformando letra no  numeroda linha
    linha = toupper(letra) - 'A';
    //Logica de colocação do navio usando funções
    if (!colocar_vertical(coluna, linha, 3)) {
        printf("Nao coube vertical!\n");
    }else{
        colocar_vertical(coluna, linha, 3);
    }

    //imprimindo o tabuleiro atualizado
    imprimir_tabuleiro(tabuleiro);
        
     // colocando navio horizontal
    printf("\nDigite a coordenada inicial do navio horizontal (ex: C 5): ");
    //Registrando as coordenadas introdycidas
    scanf(" %c %d", &letra, &coluna);
    if((letra < 'A' || letra > 'J') || (numero < 0 || numero > 9)) {
                printf("Coordenadas inválidas. Tente novamente.\n");
                return 1;
            }
    //Transformando a letra no numero de linha
    linha = toupper(letra) - 'A';
    //Logica da colocação do navio na horizontal usando as funções previamente declaradas
    if (!colocar_horizontal(coluna, linha, 3)) {
        printf("Nao coube horizontal!\n");
    }else{
        colocar_horizontal(coluna, linha, 3);
    }
    //Imprimindo tabuleiro atualizado

    imprimir_tabuleiro(tabuleiro); // colocando navio horizontal
    
           
 // colocando navio nas diagonais
    printf("\nDigite a coordenada inicial do navio diagonal 1: ");
    //Guardando as coordenadas introducidas
    scanf(" %c %d", &letra, &coluna);
    if((letra < 'A' || letra > 'J') || (numero < 0 || numero > 9)) {
                printf("Coordenadas inválidas. Tente novamente.\n");
                return 1;
          
    // colocando mais um navio na diagonal  
    printf("\nDigite a coordenada inicial do navio diagonal 2: ");
    //Guardando as coordenadas introducidas
    scanf(" %c %d", &letra, &coluna);
    if((letra < 'A' || letra > 'J') || (numero < 0 || numero > 9)) {
                printf("Coordenadas inválidas. Tente novamente.\n");
                return 1;
            }
    //Convertendo a letra no numero de linha
    linha = toupper(letra) - 'A';
    //logica de colocação do navio usando funções
    if (!colocar_diagonal2(coluna, linha, 3)) {
        printf("Nao coube diagonal 2!\n");
    }else{
        colocar_diagonal2(coluna, linha, 3);
    }
    //Imprimindo o tabuleiro atualizado
    imprimir_tabuleiro(tabuleiro);  }
    
   
     return 0;

}