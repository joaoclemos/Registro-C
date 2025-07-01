#include <stdio.h>
#include <string.h>

#define NUM_CLIENTES 2
#define MAX_NOME 50
#define MAX_TELEFONE 20
#define MAX_ENDERECO 100

typedef struct cliente {
    char nome[MAX_NOME];
    char telefone[MAX_TELEFONE];
    char endereco[MAX_ENDERECO];
} cliente;

int main() {
    cliente lista[NUM_CLIENTES];

    // Leitura dos dados
    for (int i = 0; i < NUM_CLIENTES; i++) {
        printf("Insira os dados (%d):\n", i + 1);
        printf("Nome: ");
        scanf(" %49[^\n]", lista[i].nome); // Lê nome com espaços
        while (getchar() != '\n'); // Limpa buffer
        printf("Endereco: ");
        scanf(" %99[^\n]", lista[i].endereco); // Lê endereço com espaços
        while (getchar() != '\n'); // Limpa buffer
        printf("Telefone: ");
        scanf(" %19[^\n]", lista[i].telefone); // Lê telefone com espaços
        while (getchar() != '\n'); // Limpa buffer
    }

    // Exibição do relatório
    printf("\nRelatório de Clientes Cadastrados:\n");
    printf("----------------------------------\n");
    for (int i = 0; i < NUM_CLIENTES; i++) {
        printf("Cliente %d:\n", i + 1);
        printf("Nome: %s\n", lista[i].nome);
        printf("Endereço: %s\n", lista[i].endereco);
        printf("Telefone: %s\n", lista[i].telefone);
        printf("----------------------------------\n");
    }

    return 0;
}