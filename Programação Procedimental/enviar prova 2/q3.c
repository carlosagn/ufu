//Nome: Carlos Augusto Gomes Neto
//Matrícula: 11821BCC016
//O programa a seguir irá realizar a leitura de um arquivo, irá escrever em outro arquivo o mesmo conteudo
//porém substituindo todo caractere ' ' por '*'.
//Após isso, o arquivo que foi escrito com a mudança será lido e mostrado na tela do usuário letra por letra

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int
main()
{
    FILE *f1 = NULL;                //variavel tipo file 1
    FILE *f2 = NULL;                //variavel tipo file 2
    char c = 0;                     //representa o caractere lido do f1
    char ch = 0;                    //representa o caractere lido do f2
    char nome[MAX];                 //representa o nome do arquivo digitado pelo usuário

    printf("Digite o nome do arquivo:\n");
    scanf("%s", nome);              //armazena no array nome o nome do arquivo

    f1 = fopen( nome, "r");         //abertura arquivo 1 para leitura
    f2 = fopen( "text1.txt", "w");  //abertura arquivo 2 para escrever

    if ( f1 == NULL || f2 == NULL)      //caso nao encontre o arquivo
    {
        printf("Erro ao abrir o arquivo\n");        //mensagem de erro
        exit(1);
    }

    c = fgetc(f1);
    while( c != EOF)            //ao ler um caractere do arquivo 1, imprimi-o no arquivo 2 com ou sem mudanças
    {
        if (c == ' ')
        {
            fputc('*',f2);      //se encontrar ' ', substituira por *
            c = fgetc(f1);
        }
        else
        {
            fputc(c,f2);        //se nao encontrar ' ' apenas copia o caractere para outro arquivo
            c = fgetc(f1);
        }
    }

    fclose(f2);         //fecha o arquivo 2 para abri lo em formato de leitura
    f2 = NULL;          //libera memoria

    f2 = fopen( "text1.txt", "r");      //abertura do arquivo 2 em formato de leitura

    if ( f2 == NULL)
    {
        printf("Erro ao abrir o arquivo\n");        //mensagem de erro caso nao encontre o arquivo
        exit(1);
    }

    ch = fgetc(f2);
    while( ch != EOF)                   //imprime o caractere lido para o usuario
    {
        printf("%c", ch);
        ch = fgetc(f2);
    }

    fclose(f1);             //fecha arquivo 1
    f1 = NULL;              //libera memoria do ponteiro

    fclose(f2);             //fecha arquivo 2
    f2 = NULL;              //libera memoria do ponteiro

    return 0;
}
