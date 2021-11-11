/*     Este programa cria e apresenta uma matriz
	de números aleatórios, de 0 a 10 e
	com base na hora de execução do programa,
	de ordem especificada pelo usuário. Além disso,
	cria e apresenta a sua respectiva matriz transposta
	e as comparam, apresentando se são simétricas
	ou assimétricas.
	Criado por Arthur Resende,
	Carlos Augusto Gomes,
	Henrique Braga e
	Pedro Guarnieri,
	no ano de 2020.
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX1 10
#define MAX2 100

int
main()
{
    int a[MAX1][MAX1];                  //representa a matriz
    int at[MAX1][MAX1];                 //representa a matriz transposta
    int i = 0;                          //contador de laço 1
    int j = 0;                          //contador de laço 2
    int m = 0;                          //índice 1 da matriz
    int n = 0;                          //índice 2 da matriz
    int soma = 0;                       /*contador para condição de simetria*/

    srand(time(NULL));

    printf("Digite m: \n");             //captura valor para m
    scanf("%d", &m);

    printf("Digite n: \n");             //captura valor para n
    scanf("%d", &n);

    if ( m < 2 || m > 10 || n < 2 || n > 10)        /*condição para m e n*/
        printf("Valores inválidos para m ou n\n");
    else                                            /*condição correta*/
    {
        printf("Gerando valores aleatórios para a matriz:\n\n");
        for ( i = 0; i < m; i++)
        {
            for ( j = 0; j < n; j++)
                a[i][j] = rand() % 11;
        }

        for ( i = 0; i < m; i++)                    /*elaboração da matriz transposta*/
        {
            for ( j = 0; j < n; j++)
                at[j][i]=a[i][j];
        }
        printf("\nA matriz é: \n");
        for ( i = 0; i < m; i++)                    /*impressão da matriz*/
        {
            for ( j = 0; j < n; j++)
                printf("%d ", a[i][j]);
            printf("\n");
        }
        printf("\nA matriz transposta é: \n");      /*impressão da matriz transposta*/
        for ( i = 0; i < n; i++)
        {
            for ( j = 0; j < m; j++)
                printf("%d ", at[i][j]);
            printf("\n");
        }
        for ( i = 0; i < m; i++) 		    /*verificando se os valores da matriz original são iguais aos da transposta*/
        {
            for ( j = 0; j < n; j++)
            {
                if ( a[i][j]==at[i][j])
                    soma++;
            }
        }
        if ( soma == (m*n))  			    /* verificando se a quantidade de itens iguais é igual a quantidade de elementos que existem na matriz*/
            printf("Matriz é simétrica");
        else
            printf("Matriz assimétrica");
    }

    return 0;
}
