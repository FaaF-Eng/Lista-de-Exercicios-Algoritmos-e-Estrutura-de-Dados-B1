// ATIVIDADE 3 - FIFO
//EX.C) Filtrando pessoas por prioridade
#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct {
    int idades[TAM];
    int frente;
    int tras;
    int contador;
} Fila;

void inicializar(Fila *f) {
    f->frente = 0;
    f->tras = -1;
    f->contador = 0;
}

int vazia(Fila *f) {
    return f->contador == 0;
}

int cheia(Fila *f) {
    return f->contador == TAM;
}

void enfileirar(Fila *f, int idade) {
    if (!cheia(f)) {
        f->tras = (f->tras + 1) % TAM;
        f->idades[f->tras] = idade;
        f->contador++;
    }
}

int desenfileirar(Fila *f) {
    if (!vazia(f)) {
        int idade = f->idades[f->frente];
        f->frente = (f->frente + 1) % TAM;
        f->contador--;
        return idade;
    }
    return -1;
}

int main() {
    Fila fila, preferencial, normal;
    inicializar(&fila);
    inicializar(&preferencial);
    inicializar(&normal);

    int idades[] = {45, 62, 30, 70, 50, 80, 25, 61, 40, 63};
    for (int i = 0; i < TAM; i++) {
        enfileirar(&fila, idades[i]);
    }

    while (!vazia(&fila)) {
        int idade = desenfileirar(&fila);
        if (idade >= 60)
            enfileirar(&preferencial, idade);
        else
            enfileirar(&normal, idade);
    }

    while (!vazia(&preferencial)) {
        int idade = desenfileirar(&preferencial);
        printf("Atendendo pessoa com idade %d (preferencial)\n", idade);
    }

    while (!vazia(&normal)) {
        int idade = desenfileirar(&normal);
        printf("Atendendo pessoa com idade %d\n", idade);
    }

    return 0;
}
