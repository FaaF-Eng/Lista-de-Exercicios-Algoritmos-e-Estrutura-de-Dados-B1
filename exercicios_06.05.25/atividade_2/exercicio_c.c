// ATIVIDADE 2 - LIFO
//EX.C) Inversão de palavra

#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char palavra[MAX];
    char pilha[MAX];
    int topo = -1;

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    // Empilha cada caractere da palavra
    for (int i = 0; palavra[i] != '\0'; i++) {
        pilha[++topo] = palavra[i];
    }

    // Desempilha e exibe a palavra invertida
    printf("Palavra invertida: ");
    while (topo >= 0) {
        printf("%c", pilha[topo--]);
    }
    printf("\n");

    return 0;
}
