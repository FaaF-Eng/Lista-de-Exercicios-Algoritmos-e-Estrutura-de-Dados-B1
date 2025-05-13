// ATIVIDADE 1 - ARRAYS
//EX.B) Maior e menor valor

#include <stdio.h>

int main() {
    int numeros[6];
    int maior, menor;
    int pos_maior = 0, pos_menor = 0;

    // Leitura dos números
    printf("Digite 6 números inteiros:\n");
    for (int i = 0; i < 6; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    // Inicializa maior e menor com o primeiro elemento
    maior = menor = numeros[0];

    // Verifica maior e menor
    for (int i = 1; i < 6; i++) {
        if (numeros[i] > maior) {
            maior = numeros[i];
            pos_maior = i;
        }
        if (numeros[i] < menor) {
            menor = numeros[i];
            pos_menor = i;
        }
    }

    // Exibe resultados
    printf("Maior número: %d (posição %d)\n", maior, pos_maior);
    printf("Menor número: %d (posição %d)\n", menor, pos_menor);

    return 0;
}
