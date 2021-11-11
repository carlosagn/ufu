/*  Este programa apresenta uma matriz lendo suas informa��es em um arquivo.
    O programa inicialmente ir� abrir um arquivo que possui informa��es
    como numero de linhas da matriz, colunas e os elementos da mesma.
    Em seguida, atrav�s de fun��es, o programa ir� criar uma matriz transposta,
    imprimir a matriz original e a transposta e tamb�m informar o usu�rio se ela
    � sim�trica ou assim�trica.
	Carlos Augusto Gomes
	no ano de 2020.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX1 10
#define MAX2 100

//------Prot�tipo fun��es------
int loadA (float a[MAX1][MAX1], FILE *arquivo, int m, int n);
void transp( float a[MAX1][MAX1], float at[MAX1][MAX1], int m, int n);
int simetr( float a[MAX1][MAX1], float at[MAX1][MAX1], int m, int n);
void showA( float a[MAX1][MAX1], float at[MAX1][MAX1], int m, int n);


int
main()
{
    FILE *abrir = NULL;                 //variavel do tipo file
	float a[MAX1][MAX1];                //representa a matriz
    float at[MAX1][MAX1];               //representa a matriz transposta
    char arquivo[MAX2];                 //string que guarda o nome do arquivo digitado
    int m = 0;                          //�ndice 1 da matriz
    int n = 0;                          //�ndice 2 da matriz
    int r1 = 0;                         //representa o retorno da fun��o loadA
    int r2 = 0;                         //representa o retorno da funcao simetr


    printf("Digite o nome do arquivo: ");       //usu�rio digita nome do arquivo
    scanf("%s", arquivo);                       //armazena em um vetor o nome digitado
    abrir = fopen(arquivo,"r");                 //abertura do arquivo

	fscanf(abrir, "%d %d", &m, &n);             //captura dos indices da matriz no arquivo

    r1 = loadA ( a, abrir, m, n);        //chamada a fun��o loadA

    if(r1 == 0)
    {
        fprintf(stderr, "Falha ao abrir o arquivo");    //mensagem de erro
		exit(0);
    }

    transp( a, at, m, n);                //chamada a fun��o transp
    showA( a, at, m, n);                 //chamada a fun��o showA
    r2 = simetr( a, at, m, n);           //chamada a fun��o simetr
    fclose(abrir);                              //fecha o arquivo
	abrir == NULL;

    if (r2 == 1)
    {
        printf("Esta matriz � sim�trica\n");      //mensagem de simetria
        return 1;
    }

    if (r2 == 0)
    {
        printf("Esta matriz � assim�trica\n");    //mensagem de assimetria
        return 0;
    }

}

//loadA
//---------------
//Realiza leitura do arquivo para armazenar os elementos na matriz a[MAX1][MAX1].
//Se abrir o arquivo sem sucesso, aparece uma mensagem de erro e retorna 0.
//Se tiver sucesso, retorna 1.


int
loadA(float a[MAX1][MAX1], FILE *abrir, int m, int n)
{
	int u = 0;                   //numero de linhas
	int o = 0;                   //numero de colunas
	int i = 0;                   //contador de la�o 1
	int j = 0;                   //contador de la�o 2

	if(abrir == NULL)                                   //caso haja falha ao abrir o arquivo
		return 0;

	for (i = 0, j = 0;!feof(abrir);i++, j = 0)          //la�o para mudan�a de linha e para manter o pr�ximo la�o funcionando at� que o arquivo seja completamente lido
	{
		for (;j < n;j++)                                //para mudar de coluna
			fscanf(abrir, "%f", &a[i][j]);              //carregamento da matriz
		fscanf(abrir, " ");	                            //para evitar que o programa leia o fim do arquivo e d� erros
	}
	return 1;
}

//transp
//-------------
//Realiza a cria��o da matriz transposta
//Obs: n�o retorna nada pois � do tipo void

void
transp ( float a[MAX1][MAX1], float at[MAX1][MAX1], int m, int n)
{
    int i = 0;              //contador de la�o 1
    int j = 0;              //contador de la�o 2

    for ( i = 0; i < m; i++)
        {
            for ( j = 0; j < n; j++)
                at[j][i]=a[i][j];           //transformando linha de uma matriz em coluna de outra
        }
}

//simetr
//---------------
//Confere se a matriz a[MAX1][MAX1] � sim�trica ou assim�trica
//Se ela for sim�trica, retorna 1
//Se for assim�trica retorna 0

int
simetr ( float a[MAX1][MAX1], float at[MAX1][MAX1], int m, int n)
{
    int i = 0;              // contador de la�o 1
    int j = 0;              // contador de la�o 2
    int soma = 0;           //vari�vel auxiliar para achar simetria

    for ( i = 0; i < m; i++) 		            //verificando se os valores da matriz original s�o iguais aos da transposta
        {
            for ( j = 0; j < n; j++)
            {
                if ( a[i][j]==at[i][j])
                    soma++;                     //se os elementos for igual, soma++
            }
        }
    if ( soma == (m*n))  			            // verificando se a quantidade de itens iguais � igual a quantidade de elementos que existem na matriz
        return 1;

    else
        return 0;
}

//showA
//-----------
//Imprime para o usu�rio: matriz, matriz transposta, mensagem dizendo se � sim�trica ou assim�trica
//Obs: n�o retorna nada pois � do tipo void

void
showA( float a[MAX1][MAX1], float at[MAX1][MAX1], int m, int n)
{
    int i = 0;              //contador de la�o 1
    int j = 0;              //contador de la�o 2

    printf("\nA matriz �: \n");
        for ( i = 0; i < m; i++)             //impress�o da matriz
        {
            for ( j = 0; j < n; j++)
                printf("%.0f ", a[i][j]);
            printf("\n");
        }
    printf("\nE sua transposta �: \n");      //impress�o da matriz transposta
        for ( i = 0; i < n; i++)
        {
            for ( j = 0; j < m; j++)
                printf("%.0f ", at[i][j]);
            printf("\n");
        }
}
