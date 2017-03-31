#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    short int i;
    unsigned int tam;
    
    do{
    printf("\nInforme o tamanho da pilha (max 15): ");
    scanf("%u", &tam);
    }while(tam < 0 || tam > 15);
    
    int *pilha = (int *)malloc(tam * sizeof(int));
    
    for(i = 0; i
}
