#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define TAM_MAX 10

int stack[TAM_MAX];
short int top = -1;

int vazio(void)
{
    if(top == -1)
        return(1);
    else
        return(0);
}

int cheio(void)
{
    if(top >= TAM_MAX)
        return(1);
    else
        return(0);
}

int push(int n)
{
    if(!cheio())
    {
        ++top;
        stack[top] = n;
    }
    else
    {
        printf("A memoria da pilha esta lotada!\n\n");
        exit(1);
    }
}

int pop(void)
{
    int n;

    if(!vazio())
    {
        n = stack[top];
        --top;
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
    int num;
    short int i;
    srand((unsigned)time(NULL));

    printf("Este programa empilha 10 numeros aleatorios e os imprime enquanto os desempilha.\n");

    for(i = 0; i < TAM_MAX; ++i)
    {
        num = (rand() % 101) + 1;
        push(num);
        printf("%do numero: %d\n", i + 1, num);
    }

    printf("\nPilha:\n");

    while(!vazio())
    {
        num = pop();
        printf("%d\n", num);
    }

    printf("\nPilha vazia: %s", vazio()? "SIM" : "NAO");

    return(0);
}
