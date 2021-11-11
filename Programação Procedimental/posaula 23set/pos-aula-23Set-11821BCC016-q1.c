/*
Criado por Carlos Augusto Gomes Neto em 24/09/2020
Matr�cula: 11821BCC016
Este programa ir� gerar numeros aleatorios para cada prosi��o da matriz m
e atrav�s de uma fun��o
O carregamento, apresenta��o da matriz e da diagonal principal devem ser realizados
cada um por uma fun��o
O resultado esperado � apresenta��o dos elementos da matriz e a diagonal principal
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* --- var. externas --- */
const int N = 4;

/* --- prot�tipos --- */
void loadA( int n, int m[N][N] );
void showArrayBi( int n, int m[N][N]);
void dp( int n, int m[N][N]);

int
main()
{
    int m[N][N];                  //representa a matriz

    loadA( N , m);                //chamada a fun��o loadA
    showArrayBi( N , m);          //chamada a fun��o showArrayBi
    dp( N, m);                    //chamada a fun��o dp

    return 0;
}

/*loadA
--------
Carrega para cada posi��o da matriz um n�mero
Os par�metros da fun��o s�o: tamanho da matriz e a matriz a ser carregada*/

void loadA( int n, int m[N][N] )
{
    int i = 0;                      //contadores para percorrer a matriz
    int j = 0;

    srand(time(NULL));            //chamada a fun��o rand

    for ( i = 0; i < N; i++)
    {
        for ( j = 0; j < N; j++)
            m[i][j] = rand() % 11;  //a posi��o da matriz ser� preenchida por um n�mero alet�rio gerado pela rand
    }
}

/*showArrayBi
-------------
Imprime para o usu�rio cada elemento da matriz
Os par�metros da fun��o s�o: tamanho da matriz e a matriz a ser impressa*/

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
Apresenta para o usu�rio os elementos da diagonal principal
Os par�metros da fun��o s�o: tamanho da matriz e a matriz que ter� a diagonal impressa*/

void dp( int n, int m[N][N])
{
    int i = 0;                      //contadores para percorrer a matriz
    int j = 0;

    printf("\nA diagonal principal eh: \n");

    for ( i = 0; i < N; i++)
    {
        for ( j = 0; j < N; j++)
        {
            if ( i == j)            //condi��o para imprimir a diagonal principal
                printf("%d ", m[i][j]);
        }
    }
}
