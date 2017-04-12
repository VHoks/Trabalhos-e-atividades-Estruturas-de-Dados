#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 10

int queue[TAM_MAX];
short int head = 0;
short int tail = -1;

int vazio(void)
{
    if(head >= TAM_MAX)
        return(1);
    else
        return(0);
}

int cheio(void)
{
    if(tail >= TAM_MAX)
        return(1);
    else
        return(0);
}

int enqueue(int num)
{
    if(!cheio())
    {
        ++tail;
        queue[tail] = num;
    }
    else
    {
        printf("A memoria da fila esta lotada!\n\n");
        exit(1);
    }
}

int dequeue(void)
{
    int n;

    if(!vazio())
    {
        n = queue[head];
        ++head;
        return(n);
    }
    else
    {
        printf("A memoria da pilha esta vazia!\n\n");
        exit(1);
    }
}

int main(void)
{
    short int num;
    short int i = 0, j = 0;
    srand((unsigned)time(NULL));

    printf("Este programa enfileira %d numeros aleatorios e os imprime enquanto os retira da fila.\n", TAM_MAX);
    
    while(!cheio())
    //for(i = 0; i < TAM_MAX ; ++i)
    {
        num = (rand() % 101) + 1;
        enqueue(num);
        printf("%do numero: %d\n", i + 1, num);
        ++i;
    }

    printf("\nSaindo da fila:\n");

    while(!vazio())
    {
        num = dequeue();
        printf("%do numeros a sair: %d\n", j + 1, num);
    }

    printf("\nFila vazia: %s", vazio()? "SIM" : "NAO");

    return(0);
}
