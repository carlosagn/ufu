//Nome: Carlos Augusto Gomes Neto
//Matrícula: 11821BCC016                Data: 02/10/2020
//O programa irá ler um arquivo e imprimir ao usuário tudo o que ler

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int
main()
{
    FILE *f = NULL;                         //variavel tipo file
    char nome[MAX];                         //array que armazena o nome do arquivo digitado pelo usuário
    char conteudo[MAX];                     //armazena conteudo lido

    printf("Digite o nome do arquivo: \n");
    scanf("%s", nome);                      //guarda o nome do arquivo em um array

    f = fopen( nome, "r");                  //abre o arquivo

    if ( f == NULL)                         //caso não consiga abrir imprime mensagem de erro
        printf("ERRO! O arquivo não foi aberto!\n");

    while(fgets(conteudo, MAX, f) != NULL)  //leitura do conteúdo do arquivo
    printf("%s", conteudo);                 //imprime o array que armazenou o conteudo do arquivo


    fclose(f);                              //fechamento do arquivo
    f = NULL;                               //libera a memoria do ponteiro
    return 0;
}
