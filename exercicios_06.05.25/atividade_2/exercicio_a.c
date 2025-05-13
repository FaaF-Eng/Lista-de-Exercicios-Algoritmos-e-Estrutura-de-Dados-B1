// ATIVIDADE 2 - LIFO
//EX.A) Simulando navegador

#include <stdio.h>
#include <string.h>

#define TAMANHO 5
#define TAM_MAX 100

int main() {
    char pilha[TAMANHO][TAM_MAX];
    int topo = -1;
    char opcao;

    // Empilha as 5 páginas
    printf("Digite os nomes de 5 páginas visitadas:\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("Página %d: ", i + 1);
        fgets(pilha[++topo], TAM_MAX, stdin);
        pilha[topo][strcspn(pilha[topo], "\n")] = '\0'; // remove o \n do final
    }

    // Simula o botão "voltar"
    printf("\n--- Simulando 'voltar' nas páginas ---\n");
    while (topo >= 0) {
        printf("Você está em: %s\n", pilha[topo]);
        printf("Deseja voltar para a página anterior? (s/n): ");
        scanf(" %c", &opcao);

        if (opcao == 's' || opcao == 'S') {
            topo--; // Desempilha
        } else {
            break;
        }
    }

    if (topo < 0) {
        printf("Você voltou até a primeira página. Fim da pilha.\n");
    } else {
        printf("Você parou na página: %s\n", pilha[topo]);
    }

    return 0;
}
