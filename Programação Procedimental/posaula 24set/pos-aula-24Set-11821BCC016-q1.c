/*Criado por Carlos Augusto Gomes Neto em 24/09/2020
O programa deverá receber caracteres pelo usuário e retornar quantos caracteres foram digitados,
os caracteres em sequência invertida e o produto entre determinado caracteres ( não consegui)
O carregamento do array, a impressão invertida e o produto serão feito por funções
O resultado esperado é o que foi citado acima */

#include <stdio.h>
#include <stdlib.h>

/* --- var. externas --- */
const int MAX = 50;

/* --- protótipos --- */
int loadA( int a[MAX]);
void inv ( int a[MAX], int x );

int
main()
{
    int a[MAX];                 //representa o array
    int x = 0;                  //armazena o resultado que será retornado de loadA

    x = loadA (a);              //chamada a função loadA
    printf("Quantidade de caracteres armazenados: %d\n", x);

    if ( x == MAX)
    {
        fprintf(stderr, "\nAVISO: tamanho maximo atingido");
    }

    inv( a, x);                 //chamada para a função inv

    return 0;
}

/*loadA
--------
função que irá carregar o vetor com o que for digitado pelo usuário.
A função captura cada digito com o getchar() e irá retornar quantos elementos
o usuário digitou
A função tem como parametro o vetor que armazenará os digitos
A expectativa é que retorne um número inteiro*/

int loadA( int a[MAX])
{
    int i = 0;              //contador
    int caractere = 0;      //auxiliar para fazer a leitura

    do
    {
        caractere = getchar();
        a[i] = caractere;
        i++;
    }
    while ( caractere !='\n');

    a[i -1] = '\0';

    return i-1;
}

/*funçao que irá imprimir os elementos do vetor a[MAX] na ordem inversa
Essa função irá percorrer cada elemento do vetor de traz pra frente
impresso um por um
A função tem como parâmetro o vetor e o tamanho dele
A expectativa é que seja impresso os elementos na forma invertida*/

void inv ( int a[MAX], int x )
{
    int i = 0;          //contador de laço
    int y = 0;          //auxiliar para o laço
    y = x;              //receberá o tamanho do vetor e poderei modificá-lo

    printf("Elementos na ordem inversa:");
    while ( i <= x)
    {
        printf("%c", a[y]);
        i++;
        y--;
    }
}




