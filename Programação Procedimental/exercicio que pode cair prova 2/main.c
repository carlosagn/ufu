#include <stdio.h>
#include <string.h>
#define MAX 100
#Feito por Carlos Augusto Gomes Neto

const int MAXN = 50; // tamanho máximo do nome ou directório do arquivo

struct dados
{
   char nome[MAX];
   float peso;
   float altura;
};
typedef struct dados Pessoa;

float imc(float p, float a);
void showIMC(float imc);
void showP(Pessoa p);
Pessoa mIMC(Pessoa p1, Pessoa p2);

int
main()
{
   FILE* st = NULL;
   Pessoa z;           //  struct que armazena os dados da pessoa
   Pessoa m;          //  struct que armazena os dados da pessoa com o menor IMC
   char n_arq[MAXN]; // nome ou directorio do arquivo a ser aberto
   float r = 0;     //  imc
   int i = 1;      // contator de pessoa da lista

   printf("Entre com o nome ou directorio do arquivo:\n");
   scanf("%s", n_arq);
   st = fopen(n_arq, "r");
   if(st == NULL)
   {
      fprintf(stderr, "ERRO: nome ou directorio invalido.");
      return 0;
   }

   fscanf(st, "%[^0-9]%f %f", &m.nome, &m.peso,&m.altura);
   m.nome[strcspn(m.nome, "\0") - 1] = '\0';
   printf("\nInformacoes sobre a %d a pessoa da lista:\n", i++);
   showP(m);
   r = imc(m.peso, m.altura);
   showIMC(r);

   while(!feof(st))
   {
      fscanf(st, "%[^0-9]%f %f", &z.nome, &z.peso, &z.altura);
      fscanf(st, " ");
      z.nome[strcspn(z.nome, "\0") - 1] = '\0';
      printf("\nInformacoes sobre a %da pessoa da lista:\n", i++);
      showP(z);
      r = imc(z.peso, z.altura);
      showIMC(r);
      m = mIMC(m, z);
   }
   fclose(st);

   printf("\n");
   printf("\nA pessoa que possui o menor valor de IMC eh:\n");
   showP(m);
   r = imc(m.peso, m.altura);
   showIMC(r);
   return 0;
}

//imc() retorna o IMC calculado; essa função recebe o peso e a altura./
float
imc(float p, float a)
{
   return p / (a * a);
}

//showIMC() apresenta o IMC e sua respectiva interpretação; essa função é do tipo void e recebe o IMC já calculado;/
void
showIMC(float imc)
{
    if(imc < 18)
    {
        printf("IMC: %.2f - abaixo do peso.\n", imc);
    }
    else if(imc < 25)
         {
            printf("IMC: %.2f - peso ideal.\n", imc);
         }
         else if(imc < 30)
              {
                printf("IMC: %.2f - sobrepeso.\n", imc);
              }
              else if(imc > 30)
                    {
                        printf("IMC: %.2f - obesidade.\n", imc);
                    }
}

//showP()apresenta os dados de uma pessoa, que foram capturados do arquivo tipo void e recebe uma pessoa z;/
void
showP(Pessoa p)
{
   printf("Nome: %s.\n", p.nome);
   printf("Peso: %.2f.\n", p.peso);
   printf("Altura: %.2f.\n", p.altura);
}

/* mIMC() retorna uma variável do tipo Pessoa e recebe duas variáveis p1 e p2 do tipo Pessoa.
Essa função compara o IMC de p1 contra o de p2 e retorna p1 ou p2, dependendo qual dessas variáveis tem o menor IMC.
*/

Pessoa
mIMC(Pessoa p1, Pessoa p2)
{
   if(imc(p1.peso, p1.altura) < imc(p2.peso, p2.altura))
   {
      return p1;
   }
   else
   {
   return p2;
   }

 }
