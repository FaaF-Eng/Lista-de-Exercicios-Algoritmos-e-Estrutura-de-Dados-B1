// ATIVIDADE 3 - FIFO
//EX.B) Fila circular de impressora

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 4

typedef struct {
    int itens[TAMANHO];
    int frente;
    int tras;
    int contador;
} FilaCircular;

void inicializarFila(FilaCircular *f) {
    f->frente = 0;
    f->tras = -1;
    f->contador = 0;
}

int filaCheia(FilaCircular *f) {
    return f->contador == TAMANHO;
}

int filaVazia(FilaCircular *f) {
    return f->contador == 0;
}

void enfileirar(FilaCircular *f, int doc) {
    if (!filaCheia(f)) {
        f->tras = (f->tras + 1) % TAMANHO;
        f->itens[f->tras] = doc;
        f->contador++;
    } else {
        printf("Fila cheia! Não é possível adicionar o documento %d\n", doc);
    }
}

int desenfileirar(FilaCircular *f) {
    if (!filaVazia(f)) {
        int doc = f->itens[f->frente];
        f->frente = (f->frente + 1) % TAMANHO;
        f->contador--;
        return doc;
    } else {
        printf("Fila vazia! Nada para imprimir.\n");
        return -1;
    }
}

int main() {
    FilaCircular fila;
    inicializarFila(&fila);

    int proximoDocumento = 1;

    // Adiciona 4 documentos inicialmente
    for (int i = 0; i < TAMANHO; i++) {
        printf("Adicionando documento %d à fila\n", proximoDocumento);
        enfileirar(&fila, proximoDocumento++);
    }

    // Simula 6 ciclos de impressão e adição
    for (int i = 0; i < 6; i++) {
        printf("\nCiclo %d:\n", i + 1);

        // Imprimir (remover da fila)
        int impresso = desenfileirar(&fila);
        if (impresso != -1) {
            printf("Imprimindo documento %d\n", impresso);
        }

        // Adicionar novo documento
        printf("Adicionando documento %d à fila\n", proximoDocumento);
        enfileirar(&fila, proximoDocumento++);
    }

    return 0;
}
