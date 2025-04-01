#include <stdio.h>

// Exercício 1: Classificação de idade
void classificacao_idade() {
    int idade;
    printf("Informe a idade: ");
    scanf("%d", &idade);
    
    if (idade < 18)
        printf("Menor de idade\n");
    else if (idade <= 64)
        printf("Adulto\n");
    else
        printf("Idoso\n");
}

// Exercício 2: Cálculo de Média e Avaliação de Desempenho
void avaliacao_desempenho() {
    float nota1, nota2, nota3, media;
    printf("Informe as três notas: ");
    scanf("%f %f %f", &nota1, &nota2, &nota3);
    
    media = (nota1 + nota2 + nota3) / 3;
    printf("Média: %.2f\n", media);
    
    if (media >= 7)
        printf("Aprovado\n");
    else if (media >= 5)
        printf("Recuperação\n");
    else
        printf("Reprovado\n");
}

// Exercício 3: Calculadora Simples
void calculadora() {
    float num1, num2, resultado;
    char operacao;
    printf("Informe dois números e a operação (+, -, *, /): ");
    scanf("%f %f %c", &num1, &num2, &operacao);
    
    if (operacao == '+')
        resultado = num1 + num2;
    else if (operacao == '-')
        resultado = num1 - num2;
    else if (operacao == '*')
        resultado = num1 * num2;
    else if (operacao == '/') {
        if (num2 != 0)
            resultado = num1 / num2;
        else {
            printf("Erro: divisão por zero!\n");
            return;
        }
    } else {
        printf("Operação inválida!\n");
        return;
    }
    printf("Resultado: %.2f\n", resultado);
}

// Exercício 4: Tabuada de um Número
void tabuada() {
    int numero;
    printf("Informe um número inteiro: ");
    scanf("%d", &numero);
    
    for (int i = 1; i <= 10; i++)
        printf("%d x %d = %d\n", numero, i, numero * i);
}

// Exercício 5: Números Pares entre 1 e N
void numeros_pares() {
    int N;
    printf("Informe um número inteiro positivo: ");
    scanf("%d", &N);
    
    for (int i = 1; i <= N; i++) {
        if (i % 2 == 0)
            printf("%d\n", i);
    }
}

int main() {
    int escolha;
    
    do {
        printf("\nEscolha um exercício (1-5) ou 0 para sair: ");
        scanf("%d", &escolha);
        
        switch (escolha) {
            case 1: classificacao_idade(); break;
            case 2: avaliacao_desempenho(); break;
            case 3: calculadora(); break;
            case 4: tabuada(); break;
            case 5: numeros_pares(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while (escolha != 0);
    
    return 0;
}
