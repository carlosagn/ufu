#include <stdio.h>
#include <stdlib.h>

struct dados_pacientes {
    int idade;
    char nome[10];
    double peso;
    double altura;
    int estado_civil;
    float grau_miopia[2];
};

int main()
{
    struct dados_pacientes paciente;
    printf("Tamanho da struct: %u\n", sizeof paciente.idade);
    printf("Tamanho da struct: %u\n", sizeof paciente.nome);
    printf("Tamanho da struct: %u\n", sizeof paciente.peso);
    printf("Tamanho da struct: %u\n", sizeof paciente.altura);
    printf("Tamanho da struct: %u\n", sizeof paciente.estado_civil);
    printf("Tamanho da struct: %u\n", sizeof paciente.grau_miopia);
    printf("Tamanho da struct: %u", sizeof paciente);
}


