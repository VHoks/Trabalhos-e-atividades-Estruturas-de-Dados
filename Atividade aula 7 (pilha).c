#include <stdio.h>
#include <stdlib.h>
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
    if(top >= TAM_MAX - 1)
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
    short int num;
    short int i, j;
    srand((unsigned)time(NULL));

    printf("Este programa empilha %d numeros aleatorios e os imprime enquanto os desempilha.\n", TAM_MAX);

    while(!cheio())
    //for(i = 0; !cheio(); ++i)
    {
        num = (rand() % 101) + 1;
        push(num);
        printf("%do numero: %d\n", i + 1, num);
        ++i;
    }

    printf("\nSaindo da pilha:\n");
    while(!vazio())
    //for(j = 0; !vazio(); ++j)
    {
        num = pop();
        printf("%do numero a sair: %d\n", j + 1, num);
        ++j;
    }

    printf("\nPilha vazia: %s", vazio()? "SIM" : "NAO");

    return(0);
}
