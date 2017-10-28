#ifndef N_RAINHAS_H_INCLUDED
#define N_RAINHAS_H_INCLUDED

/* Fun��o global para aloca��o do Tabuleiro */
int** alocaTabuleiro (int n);
/* Fun��es do Modo Normal */
void problemaRainha(int n);
void mostraSolucao(int **tabuleiro, int n, int colocacaoPeca);
int rainhaPodeEstar(int **tabuleiro, int n, int linha, int coluna);
int achaPosicaoRainha(int **tabuleiro, int n, int coluna, int *colocacaoPeca);
/* Fun��es do Modo An�lise */
void problemaRainhaModoAnalise(int n);
void mostraSolucaoModoAnalise(int **tabuleiro, int n, int colocacaoPeca, int quantidadeTentativas);
int rainhaPodeEstarModoAnalise(int **tabuleiro, int n, int linha, int coluna, int *quantidadeTentativas);
int achaPosicaoRainhaModoAnalise(int **tabuleiro, int n, int coluna, int *colocacaoPeca, int *quantidadeTentativas);

#endif // N_RAINHAS_H_INCLUDED
