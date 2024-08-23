/*
 * Autor: Felipe Matias de Freitas da Silva
 * E-mail: fmfs@cesar.school
 * Data de criação: 23/08/2024
 * Última modificação: [23/08/2024  | 13:34]
 */

#include <stdio.h>

void converterParaBinario(int num) {
    int binario[32];
    int i = 0;
    int original_num = num;

    printf("\nNúmero decimal original: %d\n", num);

    printf("\nPassos para conversão para binário:\n");
    while (num > 0) {
        printf("\nNúmero atual: %d\n", num);
        printf("\nResto da divisão por 2: %d\n", num % 2);
        binario[i] = num % 2;
        num = num / 2;
        i++;
    }

    printf("\nColetando de trás para frente. Passos concluídos. Número em binário:\n");
    printf("\nBinário: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binario[j]);
    printf("\n");
}

int main() {
    int numero;

    printf("Digite um número decimal: ");
    scanf("%d", &numero);

    converterParaBinario(numero);

    return 0;
}
