#include "N_Rainhas.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **tabuleiro = NULL;
    int opcao, n;

    while (1) {
        printf("+--------------------------------------------+\n");
        printf("|           Programa das N Rainhas           |\n");
        printf("+--------------------------------------------+\n");
        printf("|                    MENU                    |\n");
        printf("+--------------------------------------------+\n");
        printf("| 1 -> Entrar com a dimensao do tabuleiro    |\n");
        printf("| 2 -> Processar e exibir respostas          |\n");
        printf("| 3 -> Sair do programa                      |\n");
        printf("+--------------------------------------------+\n\n");

        printf("Entre com a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Entre com o valor de N: ");
                scanf("%d", &n);
                printf("\n");
                break;
            case 2:
                tabuleiro = alocaTabuleiro(n);
                achaPosicaoRainha(tabuleiro, n, 0);
                mostraSolucao(tabuleiro, n);
                printf("\n");
                break;
            case 3:
                printf("Fim do programa das N Rainhas!\n");
                return 0;
            default:
                printf("Opcao invalida!\n\n");
        }
    }

    return 0;
}
