// ATIVIDADE 2 - LIFO
//EX.B) Verificação de parênteses

#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char expressao[MAX];
    char pilha[MAX];
    int topo = -1;

    printf("Digite a expressão matemática: ");
    fgets(expressao, MAX, stdin);

    for (int i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(') {
            pilha[++topo] = '('; // empilha
        } else if (expressao[i] == ')') {
            if (topo == -1) {
                printf("Parênteses desbalanceados.\n");
                return 0;
            } else {
                topo--; // desempilha
            }
        }
    }

    if (topo == -1) {
        printf("Parênteses balanceados.\n");
    } else {
        printf("Parênteses desbalanceados.\n");
    }

    return 0;
}
