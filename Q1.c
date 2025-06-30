#include <stdio.h>
#include <string.h>

#define NUM_PESSOAS 40
#define MAX_NOME 50

// Definindo a struct Pessoa
struct Pessoa {
    char nome[MAX_NOME];
    int dia;
    int mes;
};

int main() {
    struct Pessoa pessoas[NUM_PESSOAS];
    int i, mes;

    // Lendo os dados das 40 pessoas
    for (i = 0; i < NUM_PESSOAS; i++) {
        printf("Digite o nome da pessoa %d: ", i + 1);
        fgets(pessoas[i].nome, MAX_NOME, stdin);
        // Remover o caractere de nova linha, se presente
        pessoas[i].nome[strcspn(pessoas[i].nome, "\n")] = 0;

        printf("Digite o dia do aniversário: ");
        scanf("%d", &pessoas[i].dia);
        printf("Digite o mês do aniversário: ");
        scanf("%d", &pessoas[i].mes);
        // Limpar o buffer de entrada
        while (getchar() != '\n');
    }

    // Exibindo os aniversariantes de cada mês
    for (mes = 1; mes <= 12; mes++) {
        printf("\nAniversariantes do mes %d:\n", mes);
        for (i = 0; i < NUM_PESSOAS; i++) {
            if (pessoas[i].mes == mes) {
                printf("Nome: %s, Dia: %d\n", pessoas[i].nome, pessoas[i].dia);
            }
        }
    }

    return 0;
}