#include <stdio.h>

int main(void)
{
    int i, j, k, vetor[10], mat[3][4], aux;

    printf("Este programa registra e ordena um vetor de 10 inteiros e uma matriz 3x4 de inteiros.\n\n");

    printf("Forneca os 10 elementos do vetor\n\n");
    for(i = 0; i < 10; ++i)
    {
        printf("Posicao %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    for(i = 0; i < 9; ++i)
        for(j = i + 1; j < 10; ++j)
            if(vetor[i] > vetor[j])
            {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }

    printf("\nVetor ordenado:\n\n");
    for(i = 0; i < 10; ++i)
        printf("%d\t", vetor[i]);

    printf("\n\nForneca os 12 elementos da matriz\n\n");
    for(i = 0; i < 3; ++i)
    {
        for(j = 0; j < 4; ++j)
        {
            printf("Posicao [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
        printf("\n");
    }

    for(k = 0; k < 3; ++k)
        for(i = 0; i < 3; ++i)
            for(j = i + 1; j < 4; ++j)
                if(mat[k][i] > mat[k][j])
                {
                    aux = mat[k][i];
                    mat[k][i] = mat[k][j];
                    mat[k][j] = aux;
                }

    printf("Matriz ordenada:\n\n");
    for(i = 0; i < 3; ++i)
    {
        for(j = 0; j < 4; ++j)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }

    return(0);
}
