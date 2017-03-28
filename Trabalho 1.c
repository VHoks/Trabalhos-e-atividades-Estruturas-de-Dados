#include <stdio.h>
#include <stdlib.h>

/* Diretivas de pre-processamento para função que limpa o console */
#if defined(__MINGW32__) || defined(_MSC_VER)
#define limpar_tela() system("cls")
#else
#define limpar_tela() system("clear")
#endif

/* Macros dos tamanhos da matriz e dos nomes dos jogadores*/
#define TAM_MAPA 15
#define TAM_NOME 30

/* Estrutura modelo dos navios */
typedef struct ponto{
    short int x; /* Coordenada 'X' da parte do navio */
    short int y; /* Coordenada 'Y' da parte do navio */
    short int status; /* Variavel que guarda o status da parte do navio (operante = 0 ou destruida = 1) */
}navio;

/* Variaveis globais */
unsigned int pontos_p1 = 0, pontos_p2 = 0; /* Pontos dos jogadores */

short int nav_destruidos_mapa1 = 0, nav_destruidos_p2 = 0; /* Quantidade de navios destruidos por cada jogador */

char nome_p1[TAM_NOME], nome_p2[TAM_NOME]; /* Nome dos jogadores */

char mapa_p1[TAM_MAPA][TAM_MAPA], mapa_p2[TAM_MAPA][TAM_MAPA]; /* Mapa dos jogadores */

navio porta_aviao_mapa1[5], encouracado_mapa1[4], contratorpedeiro_mapa1[3], submarino_mapa1[2], porta_aviao_mapa2[5], encouracado_mapa2[4], contratorpedeiro_mapa2[3], submarino_mapa2[2]; /* Vetores de estruturas que correspondem aos navios */

void montar_mapas(void)
{
    short int i, j;
    
    for(i = 0; i < TAM_MAPA; ++i)
        for(j = 0; j < TAM_MAPA; ++j)
        {
            mapa_p1[i][j] = '~';
            mapa_p2[i][j] = '~';
        }
}

void preparar_navios(void)
{
    short int i;
    
    for(i = 0; i < 5; ++i)
        porta_aviao.status = 0
}

void imprimir_instrucoes(void)
{
    printf("\nBem vindo ao jogo Batalha Naval!");
    printf("\nO campo de batalha tem dimensão de 15 X 15 espaços.");
    printf("\nCada jogador tem um de cada dos seguintes navios:\nPorta-aviao - 5 espaços\nEncouracado - 4 espaços\nContratorpedeiro - 3 espaços\nSubmarino - 2 espaços\n");
    printf("\nVence quem derrubar todos os navios inimigos primeiro");
}

void obter_nomes(void)
{
    printf("\n\nNome do jogador 1: ");
    fgets(nome_p1, TAM_NOME, stdin);
    printf("\nNome do jogador 2: ");
    fgets(nome_p2, TAM_NOME, stdin);
}

int jogo()
{
    int x, y;
}

int main(void)
{    
    montar_mapas();
    preparar_navios();
    imprimir_instrucoes();
    obter_nomes();
    
    do{
        jogo();
    }while();
    
}
