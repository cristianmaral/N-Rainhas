#ifndef N_RAINHAS_H_INCLUDED
#define N_RAINHAS_H_INCLUDED

int** alocaTabuleiro (int n);
void mostraSolucao(int **tabuleiro, int n);
int rainhaPodeEstar(int **tabuleiro, int n, int linha, int coluna);
int achaPosicaoRainha(int **tabuleiro, int n, int coluna);

#endif // N_RAINHAS_H_INCLUDED
