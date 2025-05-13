// ATIVIDADE 3 - FIFO
//EX.A) Atendimento de senhas

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_FILA 5

// Estrutura da fila
typedef struct {
    int itens[TAMANHO_FILA];
    int frente;
    int tras;
} Fila;

// Inicializa a fila
void inicializarFila(Fila *f) {
    f->frente = 0;
    f->tras = -1;
}

// Verifica se a fila está cheia
int filaCheia(Fila *f) {
    return f->tras == TAMANHO_FILA - 1;
}

// Verifica se a fila está vazia
int filaVazia(Fila *f) {
    return f->frente > f->tras;
}

// Insere um elemento na fila
void enfileirar(Fila *f, int senha) {
    if (!filaCheia(f)) {
        f->tras++;
        f->itens[f->tras] = senha;
    } else {
        printf("Fila cheia!\n");
    }
}

// Remove um elemento da fila
int desenfileirar(Fila *f) {
    if (!filaVazia(f)) {
        int senha = f->itens[f->frente];
        f->frente++;
        return senha;
    } else {
        printf("Fila vazia!\n");
        return -1;
    }
}

int main() {
    Fila fila;
    inicializarFila(&fila);

    // Gerando e adicionando 5 senhas na fila
    for (int i = 1; i <= 5; i++) {
        printf("Gerando senha %d\n", i);
        enfileirar(&fila, i);
    }

    printf("\nIniciando atendimento:\n");
    
    // Atendendo os clientes
    while (!filaVazia(&fila)) {
        int senha = desenfileirar(&fila);
        printf("Atendendo senha %d\n", senha);
    }

    return 0;
}

