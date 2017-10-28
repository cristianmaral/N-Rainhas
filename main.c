#include "N_Rainhas.h"
#include <stdio.h>
#include <stdlib.h>

#define ANALISE
//#undef ANALISE

int main()
{
    int opcao, n;

    while (1) {
        printf("+--------------------------------------------+\n");
        #ifndef ANALISE
        printf("|           Programa das N Rainhas           |\n");
        #else
        printf("|    Programa das N Rainhas - Modo Analise   |\n");
        #endif
        printf("+--------------------------------------------+\n");
        printf("|                    MENU                    |\n");
        printf("+--------------------------------------------+\n");
        printf("| 1 -> Entrar com a dimensao do tabuleiro    |\n");
        printf("| 2 -> Processar e exibir respostas          |\n");
        printf("| 3 -> Sair do programa                      |\n");
        printf("+--------------------------------------------+\n\n");

        printf("Entre com a opcao desejada: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao) {
            case 1:
                printf("Entre com o valor de N: ");
                scanf("%d", &n);
                printf("\n");
                break;
            case 2:
                #ifndef ANALISE
                problemaRainha(n);
                #else
                problemaRainhaModoAnalise(n);
                #endif
                printf("\n");
                break;
            case 3:
                printf("Fim do programa das N Rainhas!\n");
                return 0;
            default:
                printf("Opcao invalida!\n\n");
        }
        printf("Pressione ENTER para continuar...");
        getchar();
        getchar();
        system("clear");
    }
    return 0;
}
