#include "N_Rainhas.h"
#include <stdio.h>
#include <stdlib.h>

int** alocaTabuleiro (int n) {
    int **tabuleiro;
    int i;

    tabuleiro = (int **)malloc(n * sizeof(int *));
    for (i=0; i<n; i++) {
        tabuleiro[i] = (int *)calloc(n, sizeof(int));
    }
    return tabuleiro;
}

void mostraSolucao(int **tabuleiro, int n) {
    int i, j;

    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int rainhaPodeEstar(int **tabuleiro, int n, int linha, int coluna) {
    int linhaAux, colunaAux, i = 0;

    /* Checa as posições a esquerda da linha atual para ver se a rainha pode ser colocada
    Não é preciso checar as peças á direita por que as rainhas estão sendo colocadas da esquerda para a direita*/
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

int achaPosicaoRainha(int **tabuleiro, int n, int coluna) {
    int i;

    if (coluna >= n)
        return 1;

    for (i=0; i<n; i++) {
        if (rainhaPodeEstar(tabuleiro, n, i, coluna) == 1) {
            tabuleiro[i][coluna] = 1;
            if (achaPosicaoRainha(tabuleiro, n, coluna + 1) == 1)
                return 1;
            tabuleiro[i][coluna] = 0;
        }
    }

    return -1;
}
