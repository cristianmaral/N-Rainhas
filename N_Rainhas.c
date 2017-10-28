#include "N_Rainhas.h"
#include <stdio.h>
#include <stdlib.h>

/* Fun��o que encapsula o problema das n Rainhas */
void problemaRainha(int n){
    int **tabuleiro = NULL;
    int colocacaoPeca = 0;
    tabuleiro = alocaTabuleiro(n);
    if(achaPosicaoRainha(tabuleiro, n, 0, &colocacaoPeca) == 1)
        mostraSolucao(tabuleiro, n, colocacaoPeca);
    else
        printf("Nao foi possivel achar uma solucao para o problema para N = %d !\n", n);
}

/* Fun��o que encapsula o problema das n Rainhas para o Modo An�lise, acrescentando a quantidade de tentativas at�
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

/* Fun��o para aloca��o din�mica do Tabuleiro, valores inicializados com 0 */
int** alocaTabuleiro (int n) {
    int **tabuleiro;
    int i;

    tabuleiro = (int **)malloc(n * sizeof(int *));
    for (i=0; i<n; i++) {
        tabuleiro[i] = (int *)calloc(n, sizeof(int));
    }
    return tabuleiro;
}

/* Fun��o que mostra o Tabuleiro com o posicionamento das Rainhas, 0 s�o posi��es livres e 1 s�o as posi��es que tem uma Rainha
   tamb�m � mostrada a quantidade de pe�as colocadas */
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

/* Fun��o de mostra o Tabuleiro com o acr�scimo da quantidade de Tentativas at� achar a solu��o */
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

/* Fun��o que checa se a Rainha pode ser colocada na posi��o sem sofrer amea�a de outra Rainha */
int rainhaPodeEstar(int **tabuleiro, int n, int linha, int coluna) {
    int linhaAux, colunaAux, i = 0;

    /* Checa as posi��es a esquerda da linha atual para ver se a rainha pode ser colocada
       N�o � preciso checar as pe�as � direita por que as rainhas est�o sendo colocadas da esquerda para a direita */
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

/* Fun��o que checa se a Rainha pode ser colocada na posi��o sem sofrer amea�a de outra Rainha, com o acr�scimo da quantidade
   de Tentativas */
int rainhaPodeEstarModoAnalise(int **tabuleiro, int n, int linha, int coluna, int *quantidadeTentativas) {
    int linhaAux, colunaAux, i = 0;

    /* Checa as posi��es a esquerda da linha atual para ver se a rainha pode ser colocada
       N�o � preciso checar as pe�as � direita por que as rainhas est�o sendo colocadas da esquerda para a direita */
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

/* Fun��o para achar um posi��o disp�nivel para colocar a rainha, ent�o depois � checado se a Rainha sofre algum perigo se
   estiver nesta posi��o */
int achaPosicaoRainha(int **tabuleiro, int n, int coluna, int *colocacaoPeca) {
    int i;

    /* Se j� foi checada todas as colunas */
    if (coluna >= n)
        return 1;

    /* Acha uma poss�vel linha i para a coluna atual */
    for (i=0; i<n; i++) {
        /* Se � uma posi��o segura para colocar a rainha */
        if (rainhaPodeEstar(tabuleiro, n, i, coluna) == 1) {
            /* A Rainha � colocada pois � uma posi��o segura, come�a o BackTracking */
            (*colocacaoPeca)++;
            tabuleiro[i][coluna] = 1;
            /* Recurs�o para achar uma linha para a prox�ma coluna */
            if (achaPosicaoRainha(tabuleiro, n, coluna + 1, colocacaoPeca) == 1)
                return 1;
            tabuleiro[i][coluna] = 0;
        }
    }
    return -1;
}

/* Fun��o para achar um posi��o disp�nivel para colocar a rainha, ent�o depois � checado se a Rainha sofre algum perigo se
   estiver nesta posi��o, computando a quantidade de Tentativas */
int achaPosicaoRainhaModoAnalise(int **tabuleiro, int n, int coluna, int *colocacaoPeca, int *quantidadeTentativas) {
    int i;

    /* Se j� foi checada todas as colunas */
    if (coluna >= n)
        return 1;

    /* Acha uma poss�vel linha i para a coluna atual */
    for (i=0; i<n; i++) {
        /* Se � uma posi��o segura para colocar a rainha */
        if (rainhaPodeEstarModoAnalise(tabuleiro, n, i, coluna, quantidadeTentativas) == 1) {
            (*colocacaoPeca)++;
            tabuleiro[i][coluna] = 1;
            /* Recurs�o para achar uma linha para a prox�ma coluna */
            if (achaPosicaoRainhaModoAnalise(tabuleiro, n, coluna + 1, colocacaoPeca, quantidadeTentativas) == 1)
                return 1;
            tabuleiro[i][coluna] = 0;
        }
    }
    return -1;
}
