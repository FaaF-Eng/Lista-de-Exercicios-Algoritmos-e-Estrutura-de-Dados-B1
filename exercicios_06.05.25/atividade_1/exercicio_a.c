// ATIVIDADE 1 - ARRAYS
//EX.A) Soma dos elementos

#include <stdio.h>

int main() {
    int numeros[10];
    int soma = 0;

    // Solicita ao usuário que insira os 10 valores
    printf("Digite 10 números inteiros:\n");
    for (int i = 0; i < 10; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);
        soma += numeros[i]; // Soma os valores conforme são inseridos
    }

    // Exibe a soma total
    printf("A soma total dos números é: %d\n", soma);

    return 0;
}
