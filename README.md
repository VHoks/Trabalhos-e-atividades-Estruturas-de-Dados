#include <stdio.h>

int main(void)
{
  int i, j, vetor[10], mat[3][4], aux;
  
  printf("Este programa registra e ordena um vetor de 10 inteiros e uma matriz 3x4 de inteiros.\n\n");
  printf("Forneca os 10 elementos do vetor:\n");
  
  for(i = 0; i < 10; ++i)
  {
    printf("Posicao %d: ", i + 1);
    scanf("%d", &vetor[i]);
  }
  
  for(i = 0; i < 9; ++i)
  {
    for(j = i + 1; j < 10; ++j)
    {
      if(vetor[i] > vetor[j])
      {
        aux = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = aux;
      }
    }
  }
  
  printf("\nVetor ordenado:\n");
  for(i = 0; i < 10; ++i)
    printf("%d\t", vetor[i]);
  
  return(0);
}
