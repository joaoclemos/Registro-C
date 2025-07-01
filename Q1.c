#include <stdio.h>
#include <string.h>

#define NUM_PESSOAS 40
#define MAX_NOME 50

typedef struct pessoa {
    char nome[MAX_NOME];
    int dia;
    int mes;
} pessoa;

int main() {
    pessoa lista[NUM_PESSOAS];
    
    for (int i = 0; i < NUM_PESSOAS; i++) {
        printf("Insira os dados (%d):\n", i + 1);
        printf("Nome: ");
        scanf(" %49[^\n]", lista[i].nome);
        printf("Dia: ");
        scanf("%d", &lista[i].dia);
        printf("Mês: ");
        scanf("%d", &lista[i].mes);
        while (getchar() != '\n');
    }
    
    for (int mes = 1; mes <= 12; mes++) {
        printf("\nAniversariantes do mes %d:\n", mes);
        for (int i = 0; i < NUM_PESSOAS; i++) {
            if (lista[i].mes == mes) {
                printf("Nome: %s, Dia: %d\n", lista[i].nome, lista[i].dia);
            }
        }
    }

    return 0;
}