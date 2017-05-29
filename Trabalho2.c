/*
Universidade de Brasília - UnB
Instituto de Ciências Exatas - IE
Departamento de Ciências da Computação - CIC
Disciplina: Estruturas de Dados - Turma B
Professor Gustavo Van Erven
Aluno: Vitor Hideki Hokino (16/0148294)
*/

/* Diretivas de pre-processamento para funcao que limpa a tela */
#if defined(__MINGW32__) || defined(_MSC_VER)
#define limpar_tela() system("cls")
#else
#define limpar_tela() system("clear")
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista{
    char nome[50];
    char email[50];
    char telefone[25];
    struct lista *prox;
};
typedef struct lista Lista;

/* Inicializa a lista */
Lista *inicializa(void)
{
    return(NULL);
}

/* Confere se a lista está vazia, retornando 0 caso falso e 1 caso verdadeiro */
int vazia(Lista *l)
{
    if(l != NULL)
        return(0);
    else
    {
        printf("\nA lista está vazia! Escolha outra opção.");
        return(1);
    }
}

/* Insere elementos no inicio da lista */
Lista *insere(Lista *l, char input_nome[], char input_email[], char input_telefone[])
{
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    strcpy(novo->nome, input_nome);
    strcpy(novo->email, input_email);
    strcpy(novo->telefone, input_telefone);
    novo->prox = l;
    return(novo);
}

/* Ordena a lista com selection sort */
/* OBS: A FUNCAO ESTA BUGADA! AO RETORNAR "l", AS REFERENCIAS DE LOCALIZACAO DOS DADOS ESTAO INDEVIDAMENTE TROCADAS OU SAO INVALIDAS */
Lista *ordenar(Lista *l)
{
    Lista *index = l; /* Armazena a posicao em que a procura comeca e para onde o menor elemento nao-ordenado sera movido */
    Lista *p = index->prox; /* Percorre a lista procurando os menores elementos */
    Lista *min = l; /* Armazena a posicao do menor elemento nao-ordenado */
    
    if(p->prox == NULL)
    {
        printf("\nSao necessarios ao menos dois contatos para ordenar a lista!");
        return(l);
    }
    
    while(index->prox != NULL)
    {
        min = index; /* Define a posicao do primeiro elemento nao ordenado */
        p = index->prox;
        while(p != NULL)
        {
            if(strcasecmp(min->nome, p->nome) > 0) /* Procura pelo elemento nao-ordenado de menor nome */
                min = p; /* Renova o menor elemento caso necessario */
            p = p->prox; /* Aponta a procura para o proximo elemento */
        }
        /* Realiza a troca do menor elemento com o index ao chegar no final da lista */
        Lista *aux = (Lista*)malloc(sizeof(Lista)); /* Elemento auxiliar para realizar a troca */
        strcpy(aux->nome, index->nome);
        strcpy(aux->email, index->email);
        strcpy(aux->telefone, index->telefone);
        strcpy(index->nome, min->nome);
        strcpy(index->nome, min->nome);
        strcpy(index->nome, min->nome);
        strcpy(min->nome, aux->nome);
        strcpy(min->nome, aux->nome);
        strcpy(min->nome, aux->nome);
        free(aux);
        index = index->prox; /* Passa o index para o proximo elemento */
    }
    free(min);
    return(l);
}

/* Lista todos os contatos, imprimindo as informacoes na tela */
void listar(Lista *l)
{
    Lista *p;
    for(p = l; p != NULL; p = p->prox)
    {
        printf("\nNome: %s", p->nome);
        printf("\nEmail: %s", p->email);
        printf("\nTelefone: %s", p->telefone);
        putchar('\n');
    }
}

/* Busca o contato pela informacao fornecida e retorna-o.
   Caso o contato nao seja encontrado, mostra-se msg de erro, e a funcao retorna NULL */
Lista *buscar(Lista *l)
{
    Lista *p;
    char search[50];
    
    printf("\nForneca nome, email ou numero de telefone do contato: ");
    scanf("%50[^\n]", search);
        
    for(p = l; p != NULL; p = p->prox)
        if(strncasecmp(search, p->nome, 50) == 0 || strncasecmp(search, p->email, 50) == 0 || strncasecmp(search, p->telefone, 25) != 0)
            return(p);
            
    printf("\nO contato nao foi encontrado!\n");
    return(NULL);
}

/* Remove um contato da lista */
Lista *remover(Lista *l)
{
    Lista *ant = NULL;
    Lista *p = l;
    char input[50];
    
    printf("\nForneca um dado de algum contato para encontra-lo e deleta-lo: ");
    scanf("%50[^\n]", input);
    
    /* Percorre a lista ate achar o contato com a informacao dada ou chegar ao fim da lista */
    while(p != NULL && strncasecmp(input, p->nome, 50) != 0 && strncasecmp(input, p->nome, 50) == 0 && strncasecmp(input, p->nome, 50) == 0)
    {
        ant = p;
        p = p->prox;
    }
    
    if(p == NULL)
    {
        printf("\nO contato nao foi encontrado!\n");
        return(p);
    }
    else if(ant == NULL)
        l = p->prox; /* Remove no inicio da lista */
    else
        ant->prox = p->prox; /* Remove depois do inicio da lista */
    free(p);
    return(l);
}

Lista *editar(Lista *l)
{
    Lista *p;
    char input[50];
    short int escolha;
    
    printf("\nForneca nome, email ou numero de telefone do contato: ");
    scanf("%50[^\n]", input);
    
    for(p = l; p != NULL && strncasecmp(input, p->nome, 50) != 0 && strncasecmp(input, p->email, 50) != 0 && strncasecmp(input, p->telefone, 25) != 0; p = p->prox);
    
    if(p == NULL)
    {
        printf("\nContato nao foi encontrado!\n");
        return(l);
    }
    
    printf("\n1.Nome: %s", p->nome);
    printf("\n2.Email: %s", p->email);
    printf("\n3.Numero de telefone: %s", p->telefone);
    do{
        printf("\n\nQual dado deseja alterar? ");
        scanf("%d", &escolha);
        getchar();
        if(escolha < 1 || escolha > 3)
            printf("\nOPCAO INVALIDA! Informe um numero de 1 ate 3.\n");
    }while(escolha < 1 || escolha > 3);
    
    switch(escolha)
    {
        case 1:
        {
            printf("Forneca o novo nome: ");
            scanf("%50[^\n]", input);
            strcpy(p->nome, input);
            break;
        }
        case 2:
        {
            printf("Forneca o novo email: ");
            scanf("%50[^\n]", input);
            strcpy(p->email, input);
            break;
        }
        case 3:
        {
            printf("Forneca o novo numero de telefone: ");
            scanf("%25[^\n]", input);
            strcpy(p->telefone, input);
            break;
        }
        default:
            return(p);
    }
}

Lista *liberar(Lista *l)
{
    while(l != NULL)
    {
        Lista *t = l->prox;
        free(l);
        l = t;
    }
    printf("\nTodos os contatos foram apagados.");
    return(l);
}

int main(void)
{
    char input_nome[50];
    char input_email[50];
    char input_telefone[25];
    char buffer[50];
    char escolha_apagar;
    short int escolha, escolha2;
    
    Lista *l; /* Declara uma lista nao-inicializada */
    l = inicializa(); /* Inicializa a lista */
    Lista *aux = (Lista*)malloc(sizeof(Lista));
    /* Ponteiro auxiliar de lista para armazenar o contato buscado em algumas funcoes e contar o tamanho da lista na ordenacao */
    
    do{
        printf("Este programa eh uma lista de contatos que armazena nome, email e numero de telefone.\n\n");
        printf("1. Inserir contato\n");
        printf("2. Ordenar contatos\n");
        printf("3. Listar todos os contatos\n");
        printf("4. Buscar e mostrar contato\n");
        printf("5. Editar contato\n");
        printf("6. Remover contato\n");
        printf("7. Apagar a agenda\n");
        printf("8. SAIR\n\n");
        printf("O que deseja fazer? ");
        scanf("%d", &escolha);
        getchar();
        switch(escolha)
        {
            case 1:
            {
                printf("\nNome: ");
                scanf(" %50[^\n]", input_nome);
                printf("Email: ");
                scanf(" %50[^\n]", input_email);
                printf("Numero de telefone: ");
                scanf(" %25[^\n]", input_telefone);
                getchar();
                l = insere(l, input_nome, input_email, input_telefone);
                break;
            }
            case 2:
            {
                if(!vazia(l))
                    l = ordenar(l);
                break;
            }
            case 3:
            {
                if(!vazia(l))
                    listar(l);
                break;
            }
            case 4:
            {
                if(!vazia(l))
                {
                    aux = buscar(l);
                    if(aux != NULL)
                    {
                        printf("\nNome: %s", aux->nome);
                        printf("\nEmail: %s", aux->email);
                        printf("\nNumero de telefone: %s", aux->telefone);
                    }
                }
                break;
            }
            case 5:
            {
                if(!vazia(l))
                    l = editar(l);
                break;
            }
            case 6:
            {
                if(!vazia(l))
                    l = remover(l);
                break;
            }
            case 7:
            {
                if(!vazia(l))
                    l = liberar(l);
                break;
            }
            case 8:
            {
                printf("\n\nEncerrando programa.");
                break;
            }
            default:
                printf("\n\nOPCAO INVALIDA!");
        }
        printf("\n\nPressione ENTER para prosseguir...");
        getchar();
        limpar_tela();
    }while(escolha != 8);
    
    return(0);
}
