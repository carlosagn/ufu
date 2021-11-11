//Nome: Carlos Augusto Gomes Neto
//Matr�cula: 11821BCC016       Data: 02/10/2020
//O programa ir� perguntar o usuario o que ele deseja gravar em um arquivo
//O resultado esperado � que seja gravado no arquivo tudo o que o usu�rio digitou

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int
main()
{
    FILE *f = NULL;             //variavel tipo file
    char nome[MAX];             //array que guarda nome do arquivo
    char guardar[MAX];          //array que armazena o que o usu�rio digitar no arquivo
    int i = 0;                  //contador la�o
    int tam = 0;                //tamanho do que o usu�rio digitou

    printf("Digite o nome do arquivo:\n");              //usuario digita o nome do arquivo
    scanf("%s", nome);                                  //nome guardado em um array

    f = fopen( nome, "w");                              //abertura do arquivo

    if ( f == NULL)
        printf("Erro ao abrir o arquivo");              //erro ao abrir, fim programa

    printf("Digite o que quer gravar no arquivo:\n");   //conteudo que usuario quer escrever no arquivo
    scanf(" %[^\n]s", guardar);

    tam = strlen(guardar);                  //tamanho do que o usu�rio digitou

    for(i=0; i<tam; i++)
        putc(guardar[i], f);                //escrevendo no arquivo o conteudo

    fclose(f);                          //fecha arquivo
    f = NULL;                           //libera memoria do ponteiro
    return 0;
}
