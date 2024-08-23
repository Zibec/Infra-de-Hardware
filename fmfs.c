/*
 * Autor: Felipe Matias de Freitas da Silva
 * E-mail: fmfs@cesar.school
 * Data de criação: 23/08/2024
 * Última modificação: [Data da última modificação]
 */

#include <stdio.h>

void converterParaBinario(int num) {
    int binario[32];
    int i = 0;

    while (num > 0) {
        binario[i] = num % 2;
        num = num / 2;
        i++;
    }
    
    printf("Binário: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binario[j]);
    printf("\n");
}

int main() {
    int numero;

    printf("Numero decimal\n");
    scanf("%d", &numero);

    converterParaBinario(numero);

    return 0;
}
