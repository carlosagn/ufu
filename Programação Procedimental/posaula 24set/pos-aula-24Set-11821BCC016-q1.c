/*Criado por Carlos Augusto Gomes Neto em 24/09/2020
O programa dever� receber caracteres pelo usu�rio e retornar quantos caracteres foram digitados,
os caracteres em sequ�ncia invertida e o produto entre determinado caracteres ( n�o consegui)
O carregamento do array, a impress�o invertida e o produto ser�o feito por fun��es
O resultado esperado � o que foi citado acima */

#include <stdio.h>
#include <stdlib.h>

/* --- var. externas --- */
const int MAX = 50;

/* --- prot�tipos --- */
int loadA( int a[MAX]);
void inv ( int a[MAX], int x );

int
main()
{
    int a[MAX];                 //representa o array
    int x = 0;                  //armazena o resultado que ser� retornado de loadA

    x = loadA (a);              //chamada a fun��o loadA
    printf("Quantidade de caracteres armazenados: %d\n", x);

    if ( x == MAX)
    {
        fprintf(stderr, "\nAVISO: tamanho maximo atingido");
    }

    inv( a, x);                 //chamada para a fun��o inv

    return 0;
}

/*loadA
--------
fun��o que ir� carregar o vetor com o que for digitado pelo usu�rio.
A fun��o captura cada digito com o getchar() e ir� retornar quantos elementos
o usu�rio digitou
A fun��o tem como parametro o vetor que armazenar� os digitos
A expectativa � que retorne um n�mero inteiro*/

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

/*fun�ao que ir� imprimir os elementos do vetor a[MAX] na ordem inversa
Essa fun��o ir� percorrer cada elemento do vetor de traz pra frente
impresso um por um
A fun��o tem como par�metro o vetor e o tamanho dele
A expectativa � que seja impresso os elementos na forma invertida*/

void inv ( int a[MAX], int x )
{
    int i = 0;          //contador de la�o
    int y = 0;          //auxiliar para o la�o
    y = x;              //receber� o tamanho do vetor e poderei modific�-lo

    printf("Elementos na ordem inversa:");
    while ( i <= x)
    {
        printf("%c", a[y]);
        i++;
        y--;
    }
}




