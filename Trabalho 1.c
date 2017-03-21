#include <stdio.h>
#include <stdlib.h>

struct ponto{
    short int x;
    short int y;
    char tipo;
    short int status;
}

int main(void)
{
    int i, j, linhas, colunas, **mapa1, **mapa2;
    
    printf("\nBem vindo ao jogo Batalha Naval!");
    printf("\nCada jogador tem 1 porta-avioes, 1 encouracado, 1 contratorpedeiros e 1 submarinos.");
    printf("\nVence quem derrubar todos os navios inimigos primeiro");
    
    printf("\n\nForneca as dimensoes do campo de batalha (mínimo 14x14 e máximo 30x30)\n");
    do{
        printf("Linhas: ");
        scanf("%d", &linhas);
    }while(linhas < 10 || linhas > 30);
    do{
        printf("Colunas: ");
        scanf("%d", &colunas);
    }while(colunas < 10 || colunas > 30);
    
    mapa1 = (int *)malloc(linhas * sizeof(int));
    mapa2 = (int *)malloc(linhas * sizeof(int));
    if(mapa1 == NULL || mapa2 == NULL)
    {
        printf("\nA memoria nao pode ser alocada! Encerrando programa...");
        exit(1);
    }
    for(i = 0; i < linhas; ++i)
    {
        mapa1[i] = (int *)malloc(colunas * sizeof(int));
    }
}
