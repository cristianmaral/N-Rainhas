#include "N_Rainhas.h"
#include <stdio.h>
#include <stdlib.h>

/* Função que encapsula o problema das n Rainhas */
void problemaRainha(int n){
    int **tabuleiro = NULL;
    int colocacaoPeca = 0;
    tabuleiro = alocaTabuleiro(n);
    if(achaPosicaoRainha(tabuleiro, n, 0, &colocacaoPeca) == 1)
        mostraSolucao(tabuleiro, n, colocacaoPeca);
    else
        printf("Nao foi possivel achar uma solucao para o problema para N = %d !\n", n);
}

/* Função que encapsula o problema das n Rainhas para o Modo Análise, acrescentando a quantidade de tentativas até
   se encontrar o posicionamento das Rainhas */
void problemaRainhaModoAnalise(int n){
    int **tabuleiro = NULL;
    int colocacaoPeca = 0;
    int quantidadeTentativas = 0;
    tabuleiro = alocaTabuleiro(n);
    if(achaPosicaoRainhaModoAnalise(tabuleiro, n, 0, &colocacaoPeca, &quantidadeTentativas) == 1)
        mostraSolucaoModoAnalise(tabuleiro, n, colocacaoPeca, quantidadeTentativas);
    else
        printf("Nao foi possivel achar uma solucao para o problema para N = %d !\n", n);
}

/* Função para alocação dinâmica do Tabuleiro, valores inicializados com 0 */
int** alocaTabuleiro (int n) {
    int **tabuleiro;
    int i;

    tabuleiro = (int **)malloc(n * sizeof(int *));
    for (i=0; i<n; i++) {
        tabuleiro[i] = (int *)calloc(n, sizeof(int));
    }
    return tabuleiro;
}

/* Função que mostra o Tabuleiro com o posicionamento das Rainhas, 0 são posições livres e 1 são as posições que tem uma Rainha
   também é mostrada a quantidade de peças colocadas */
void mostraSolucao(int **tabuleiro, int n, int colocacaoPeca) {
    int i, j;
    int cont = 1;

    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            if(tabuleiro[i][j] == 1){
                printf("Posicao da Rainha numero %d\n", cont);
                printf("\tLinha: %d\n", i);
                printf("\tColuna: %d\n", j);
                ++cont;
            }
        }
    }
    printf("\nQuantidade de pecas colocadas (usadas e descartadas) : %d\n", colocacaoPeca);
}

/* Função de mostra o Tabuleiro com o acréscimo da quantidade de Tentativas até achar a solução */
void mostraSolucaoModoAnalise(int **tabuleiro, int n, int colocacaoPeca, int quantidadeTentativas) {
    int i, j;
    int cont = 1;

    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            if(tabuleiro[i][j] == 1){
                printf("Posicao da Rainha numero %d\n", cont);
                printf("\tLinha: %d\n", i);
                printf("\tColuna: %d\n", j);
                ++cont;
            }
        }
    }
    printf("\nQuantidade de pecas colocadas (usadas e descartadas) : %d\n", colocacaoPeca);
    printf("Quantidade de tentativas de colocar as pecas : %d\n", quantidadeTentativas);
}

/* Função que checa se a Rainha pode ser colocada na posição sem sofrer ameaça de outra Rainha */
int rainhaPodeEstar(int **tabuleiro, int n, int linha, int coluna) {
    int linhaAux, colunaAux, i = 0;

    /* Checa as posições a esquerda da linha atual para ver se a rainha pode ser colocada
       Não é preciso checar as peças á direita por que as rainhas estão sendo colocadas da esquerda para a direita */
    while(i < coluna){
        if (tabuleiro[linha][i] == 1)
            return -1;
        i++;
    }

    linhaAux = linha;
    colunaAux = coluna;

    /* Checa a Diagonal superior da linha e coluna atual para ver se a rainha pode ser colocada */
    while(linhaAux >= 0 && colunaAux >= 0){
        if (tabuleiro[linhaAux][colunaAux] == 1)
            return -1;
        linhaAux--;
        colunaAux--;
    }

    linhaAux = linha;
    colunaAux = coluna;

    /* Checa a Diagonal inferior da linha e da coluna atual para ver se a rainha pode ser colocada */
    while(linhaAux < n && colunaAux >= 0){
        if (tabuleiro[linhaAux][colunaAux] == 1)
            return -1;
        linhaAux++;
        colunaAux--;
    }
    return 1;
}

/* Função que checa se a Rainha pode ser colocada na posição sem sofrer ameaça de outra Rainha, com o acréscimo da quantidade
   de Tentativas */
int rainhaPodeEstarModoAnalise(int **tabuleiro, int n, int linha, int coluna, int *quantidadeTentativas) {
    int linhaAux, colunaAux, i = 0;

    /* Checa as posições a esquerda da linha atual para ver se a rainha pode ser colocada
       Não é preciso checar as peças á direita por que as rainhas estão sendo colocadas da esquerda para a direita */
    while(i < coluna){
        if (tabuleiro[linha][i] == 1){
            (*quantidadeTentativas)++;
            return -1;
        }
        i++;
    }

    linhaAux = linha;
    colunaAux = coluna;

    /* Checa a Diagonal superior da linha e coluna atual para ver se a rainha pode ser colocada */
    while(linhaAux >= 0 && colunaAux >= 0){
        if (tabuleiro[linhaAux][colunaAux] == 1){
            (*quantidadeTentativas)++;
            return -1;
        }
        linhaAux--;
        colunaAux--;
    }

    linhaAux = linha;
    colunaAux = coluna;

    /* Checa a Diagonal inferior da linha e da coluna atual para ver se a rainha pode ser colocada */
    while(linhaAux < n && colunaAux >= 0){
        if (tabuleiro[linhaAux][colunaAux] == 1){
            (*quantidadeTentativas)++;
            return -1;
        }
        linhaAux++;
        colunaAux--;
    }
    (*quantidadeTentativas)++;
    return 1;
}

/* Função para achar um posição dispónivel para colocar a rainha, então depois é checado se a Rainha sofre algum perigo se
   estiver nesta posição */
int achaPosicaoRainha(int **tabuleiro, int n, int coluna, int *colocacaoPeca) {
    int i;

    /* Se já foi checada todas as colunas */
    if (coluna >= n)
        return 1;

    /* Acha uma possível linha i para a coluna atual */
    for (i=0; i<n; i++) {
        /* Se é uma posição segura para colocar a rainha */
        if (rainhaPodeEstar(tabuleiro, n, i, coluna) == 1) {
            /* A Rainha é colocada pois é uma posição segura, começa o BackTracking */
            (*colocacaoPeca)++;
            tabuleiro[i][coluna] = 1;
            /* Recursão para achar uma linha para a proxíma coluna */
            if (achaPosicaoRainha(tabuleiro, n, coluna + 1, colocacaoPeca) == 1)
                return 1;
            tabuleiro[i][coluna] = 0;
        }
    }
    return -1;
}

/* Função para achar um posição dispónivel para colocar a rainha, então depois é checado se a Rainha sofre algum perigo se
   estiver nesta posição, computando a quantidade de Tentativas */
int achaPosicaoRainhaModoAnalise(int **tabuleiro, int n, int coluna, int *colocacaoPeca, int *quantidadeTentativas) {
    int i;

    /* Se já foi checada todas as colunas */
    if (coluna >= n)
        return 1;

    /* Acha uma possível linha i para a coluna atual */
    for (i=0; i<n; i++) {
        /* Se é uma posição segura para colocar a rainha */
        if (rainhaPodeEstarModoAnalise(tabuleiro, n, i, coluna, quantidadeTentativas) == 1) {
            (*colocacaoPeca)++;
            tabuleiro[i][coluna] = 1;
            /* Recursão para achar uma linha para a proxíma coluna */
            if (achaPosicaoRainhaModoAnalise(tabuleiro, n, coluna + 1, colocacaoPeca, quantidadeTentativas) == 1)
                return 1;
            tabuleiro[i][coluna] = 0;
        }
    }
    return -1;
}
