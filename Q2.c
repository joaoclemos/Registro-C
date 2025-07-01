#include <stdio.h>
#include <string.h>

#define NUM_LOJAS 15
#define MAX_NOME 50
#define MAX_TELEFONE 20

typedef struct loja {
    char nome[MAX_NOME];
    char telefone[MAX_TELEFONE];
    float preco;
} loja;

int main() {
    loja lista[NUM_LOJAS];
    float media = 0.0; // Inicializado como float

    // Leitura dos dados
    for (int i = 0; i < NUM_LOJAS; i++) {
        printf("Insira os dados (%d):\n", i + 1);
        printf("Nome: ");
        scanf(" %49[^\n]", lista[i].nome); // Lê nome com espaços
        while (getchar() != '\n'); // Limpa buffer
        printf("Telefone: ");
        scanf(" %19[^\n]", lista[i].telefone); // Lê telefone com espaços
        while (getchar() != '\n'); // Limpa buffer
        printf("Preco: ");
        scanf("%f", &lista[i].preco); // Lê preço como float
        while (getchar() != '\n'); // Limpa buffer
        media += lista[i].preco;
    }

    // Cálculo da média
    media = media / 15.0; // Divisão com float para precisão

    // Exibição da média
    printf("\nMédia dos preços: %.2f\n", media);

    // Exibição das lojas com preço abaixo da média
    printf("\nLojas abaixo da média:\n");
    for (int loja = 0; loja < NUM_LOJAS; loja++) {
        if (lista[loja].preco < media) {
            printf("Nome: %s, Telefone: %s\n", lista[loja].nome, lista[loja].telefone);
        }
    }

    return 0;
}