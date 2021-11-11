/*
Criado por Carlos Augusto Gomes Neto em 24/09/2020
Matrícula: 11821BCC016
Este programa irá gerar numeros aleatorios para cada prosição da matriz m
e através de uma função
O carregamento, apresentação da matriz e da diagonal principal devem ser realizados
cada um por uma função
O resultado esperado é apresentação dos elementos da matriz e a diagonal principal
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* --- var. externas --- */
const int N = 4;

/* --- protótipos --- */
void loadA( int n, int m[N][N] );
void showArrayBi( int n, int m[N][N]);
void dp( int n, int m[N][N]);

int
main()
{
    int m[N][N];                  //representa a matriz

    loadA( N , m);                //chamada a função loadA
    showArrayBi( N , m);          //chamada a função showArrayBi
    dp( N, m);                    //chamada a função dp

    return 0;
}

/*loadA
--------
Carrega para cada posição da matriz um número
Os parâmetros da função são: tamanho da matriz e a matriz a ser carregada*/

void loadA( int n, int m[N][N] )
{
    int i = 0;                      //contadores para percorrer a matriz
    int j = 0;

    srand(time(NULL));            //chamada a função rand

    for ( i = 0; i < N; i++)
    {
        for ( j = 0; j < N; j++)
            m[i][j] = rand() % 11;  //a posição da matriz será preenchida por um número aletório gerado pela rand
    }
}

/*showArrayBi
-------------
Imprime para o usuário cada elemento da matriz
Os parâmetros da função são: tamanho da matriz e a matriz a ser impressa*/

void showArrayBi( int n, int m[N][N])
{
    int i = 0;                      //contadores para percorrer a matriz
    int j = 0;

    printf("A matriz eh: ");

    for ( i = 0; i < N; i++)
    {
        printf("\n");

        for ( j = 0; j < N; j++)
            printf("%d ", m[i][j]);
    }
}

/*dp
-------
Apresenta para o usuário os elementos da diagonal principal
Os parâmetros da função são: tamanho da matriz e a matriz que terá a diagonal impressa*/

void dp( int n, int m[N][N])
{
    int i = 0;                      //contadores para percorrer a matriz
    int j = 0;

    printf("\nA diagonal principal eh: \n");

    for ( i = 0; i < N; i++)
    {
        for ( j = 0; j < N; j++)
        {
            if ( i == j)            //condição para imprimir a diagonal principal
                printf("%d ", m[i][j]);
        }
    }
}
