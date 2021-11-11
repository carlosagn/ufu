/*Criado por Carlos Augusto Gomes Neto  de matricula 11821BCC016 em 28/09/2020
O programa apresenta e calcula o imc, nome da pessoa
Acessando arquivos e structs */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct pessoa               //estrutura tipo pessoa
{
    char nome[MAX];
    float peso;
    float altura;
};

typedef struct pessoa Pessoa;

/*---------Prototipos---------*/
float imc(float p, float h);
void showIMC(float x);
void showP(struct pessoa z);

int
main()
{

    float x = 0;                            //vai guardar o valor do imc da funcao imc()
    Pessoa z;                               //variavel do tipo struct
    char nomearquivo[MAX];                  //string que guarda o nome do arquivo digitado
    FILE *f = NULL;                         //variavel do tipo file

    printf("Digite o nome do arquivo\n");   //usuario digita o arquivo que quer ler
    scanf("%s", nomearquivo);

    f = fopen(nomearquivo, "r");            //Leitura do arquivo

    if ( f == NULL)                         //caso o ponteiro nao aponte para algum lugar
    {
        fprintf(stderr, "Arquivo nao encontrado\n");        //Falha ao carregar arquivo
        exit(1);
    }

    fgets(z.nome, MAX, f);                      //leitura string
    fscanf( f ,"%f %f", z.peso, z.altura);      //leitura peso e altura

    x = imc(z.peso, z.altura);                  //chamada funcao que calcula imc
    showIMC(x);                                 //chamada funcao que apresenta imc
    showP(z);                                   //apresenta dados

    fclose (f);                             //fecha o arquivo

    return 0;
}

/*---------Funcoes-----------*/
float imc(float p, float h)
{
    return p/(h*h);
}

void showIMC(float x)
{
    if (x < 18,5)
        printf("Abaixo do peso\n");

    if ( x >= 18,5 && x < 25)
        printf("Peso normal\n");

    if ( x >= 25 && x < 30)
        printf("Acima do peso\n");

    if ( x >= 30)
        printf("Obeso\n");
}

void showP(struct pessoa z)
{
    printf("Nome:%s\nAltura:%f\n", z.nome, z.peso, z.altura);
}
