/*
 * Autor: Felipe Matias de Freitas da Silva
 * E-mail: fmfs@cesar.school
 * Data de criação: 23/08/2024
 * Última modificação: [26/08/2024 | 00:48] Questão 3
 * Função para representar número de base 10 float concluida.
 */

#include <stdio.h>
#include <math.h>

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

    printf("\nColetando de trás para frente. Passos concluídos.\n");
    printf("\nBinário: ");
    for (int j = i - 1; j >= 0; j--){
        printf("%d", binario[j]);
    }
    printf("\n\n");
}

void converterParaOctal(int num) {
    int octal[32];
    int i = 0;
    int original_num = num;

    printf("\nNúmero decimal original: %d\n", num);

    printf("\nPassos para conversão para octal:\n");
    while (num > 0) {
        printf("\nNúmero atual: %d\n", num);
        printf("\nResto da divisão por 8: %d\n", num % 8);
        octal[i] = num % 8;
        num = num / 8;
        i++;
    }

    printf("\nColetando de trás para frente. Passos concluídos.\n");
    printf("\nOctal: ");
    for (int j = i - 1; j >= 0; j--){
        printf("%d", octal[j]);
    }
    printf("\n\n");

}

void converterParaHexa(int num){
    int hexa[32];
    int i = 0;
    int original_num = num;

    printf("\nNúmero decimal original: %d\n", num);

    printf("\nPassos para conversão para hexadecimal:\n");
    while(num > 0){
        printf("\nNúmero atual: %d\n", num);
        printf("\nResto da divisão por 16: %d\n", num % 16);
        hexa[i] = num % 16;
        num = num / 16;
        i++;
    }

    printf("\nColetando de trás para frente. Passos concluídos.\n");
    printf("\nHexadecimal: ");
    for(int j = i - 1; j >= 0; j--){
        if(hexa[j] == 10){
            printf("A");
        }else if(hexa[j] == 11){
            printf("B");
        }else if(hexa[j] == 12){
            printf("C");
        }else if(hexa[j] == 13){
            printf("D");
        }else if(hexa[j] == 14){
            printf("E");
        }else if(hexa[j] == 15){
            printf("F");
        }else{
            printf("%d", hexa[j]);
        }
    }
    printf("\n\n");
}

void converterParaBCD(int num) {
    char *bcdList[10] = {
    "0000", // 0
    "0001", // 1
    "0010", // 2
    "0011", // 3
    "0100", // 4
    "0101", // 5
    "0110", // 6
    "0111", // 7
    "1000", // 8
    "1001"  // 9
    };

    int original_num = num;

    printf("\nNúmero decimal original: %d\n", num);

    printf("\nPassos para conversão para BCD:\n");
    
    int cont = 0;
    while (num > 0) {
        num /= 10;
        cont++;
    }

    num = original_num;
    int array[cont];

    for(int i = cont - 1; i >= 0; i--){
        array[i] = num % 10;
        num /= 10;
    }
    
    printf("\n");
    for(int i = 0; i < cont; i++){
        printf("%s",bcdList[array[i]]);
    }
    printf("\n");
}

void complementoDois(int num){
    
    int binario[16] = {0};
    int cont = 0;
    int original_num = num;

    if(num < 0) {
        num = num * -1;
    }
    
    while (num > 0) {
        printf("\nNúmero atual: %d\n", num);
        printf("\nResto da divisão por 2: %d\n\n", num % 2);
        binario[cont] = num % 2;
        num = num / 2;
        cont++;
    }

    if(original_num >= 0){
        printf("Binário representado por 16 bits: \n\n");
        
        for (int j = 15; j >= 0; j--){
            printf("%d", binario[j]);
        }
    }else{
        printf("Binário representado por 16 bits: \n\n");
        
        for (int j = 15; j >= 0; j--){
            printf("%d", binario[j]);
        }
        
        printf("\n\nSomando 1...\n\n");

        for (int j = 0; j < 16; j++) {
            
            if(binario[j] == 0){
                binario[j] = 1;
            }else{
                binario[j] = 0;
            }
        }

        int aux = 1;
        for (int j = 0; j < 16; j++) {
            int soma = binario[j] + aux;
            binario[j] = soma % 2;
            aux = soma / 2;
        }

        printf("Resultado: \n\n");

        for (int j = 15; j >= 0; j--){
            printf("%d", binario[j]);
        }
    }
    
    printf("\n\n");

}

void converterParaFloat(double num){
    double intPart, fracPart;
    char sinal;

    printf("Número original: %.5f\n", num);

    if (num < 0) {
        sinal = '1';
        num = -num;  
    } else {
        sinal = '0';
    }
    printf("Sinal (1 bit): %c\n\n", sinal);

    fracPart = modf(num, &intPart);
    printf("Parte inteira: %.0f\n", intPart);
    printf("Parte fracionária: %.5f\n\n", fracPart);

    int binario[32] = {0};  // Array para armazenar a parte inteira em binário
    int contador = 0;
    int original_num = (int)intPart;
    int bits = 31;

    while (original_num > 0) {
        binario[bits] = original_num % 2;
        original_num = original_num / 2;
        contador++;
        bits--;
    }

    printf("Parte inteira em binário: ");
    if (intPart == 0) {
        printf("0\n");
    } else {
        for (int i = 32 - contador; i < 32; i++) {
            printf("%d", binario[i]);
        }
        printf("\n");
    }

    int binarioFracao[32] = {0};  // Array para armazenar a parte fracionária em binário
    int contadorFracao = 0;

    while (fracPart > 0 && contadorFracao < 23) {
        fracPart *= 2;
        if (fracPart >= 1) {
            binarioFracao[contadorFracao] = 1;
            fracPart -= 1;
        } else {
            binarioFracao[contadorFracao] = 0;
        }
        contadorFracao++;
    }

    printf("Parte fracionária em binário: ");
    for (int i = 0; i < contadorFracao; i++) {
        printf("%d", binarioFracao[i]);
    }
    printf("\n\n");

    int arrayPosVirgula[23] = {0};

    int aux = contador - 1;  // Sem contar com o primeiro 1
    for (int j = 0; j < contador - 1; j++) {
        arrayPosVirgula[j] = binario[32 - aux];
        aux--;
    }

    aux = contador - 1;
    for (int j = 0; j < contadorFracao; j++) {
        arrayPosVirgula[aux] = binarioFracao[j];
        aux++;
    }

    printf("Mantissa normalizada: 1.");
    for (int j = 0; j < 23; j++) {
        printf("%d", arrayPosVirgula[j]);
    }
    printf("\n\n");

    int expoenteNotacaoCientifica = contador - 1;

    int expoente[8] = {0};
    int vies = expoenteNotacaoCientifica + 127;
    printf("Expoente com viés (127) + (%d): %d\n", expoenteNotacaoCientifica, vies);

    int contadorExpoente = 7;
    while (vies > 0) {
        expoente[contadorExpoente] = vies % 2;
        vies = vies / 2;
        contadorExpoente--;
    }

    printf("\nExpoente (8 bits): ");
    for (int j = 0; j < 8; j++) {
        printf("%d", expoente[j]);
    }
    printf("\n");

    // Resumo final
    printf("\nResumo:\n");
    printf("Sinal: %c\n", sinal);
    printf("Expoente: ");
    for (int j = 0; j < 8; j++) {
        printf("%d", expoente[j]);
    }
    printf("\nExpoente com viés: %d", expoenteNotacaoCientifica + 127);
    printf("\nFração: ");
    for (int j = 0; j < 23; j++) {
        printf("%d", arrayPosVirgula[j]);
    }
    printf("\nNúmero inteiro: %c ",sinal);
    for(int i = 0; i < 8; i++){
        printf("%d", expoente[i]);
    }
    printf(" ");
    for(int i = 0; i < 23; i++){
        printf("%d", arrayPosVirgula[i]);
    }
    printf("\n");
}
int main() {
    int opcao;
    int numero;
    double num;

    while(opcao != 4) {
        printf("=========================\n");
        printf("Escolha a sua opção:\n\n");
        printf("(1) Conversão de base 10 para: base 2, base 8, base 16 ou código BCD. \n");
        printf("(2) Conversão de base 10 para base com sinal com 16 bits. \n");
        printf("(3) Conversão de real em decimal para float e double. \n");
        printf("(4) Sair do programa.\n\n--->");

        scanf("%d", &opcao);
 
        switch (opcao) {
            case 1: 
                printf("Escolha a sua opção: \n");

                printf("(1) Converter decimal em binário.\n");
                printf("(2) Converter decimal em octal.\n");
                printf("(3) Converter decimal em hexadecimal.\n");
                printf("(4) Converter decimal em BCD.\n\n--->");

                scanf("%d", &numero);

                if(numero == 1){
                    printf("Digite um número em decimal: ");
                    scanf("%d", &numero);

                    converterParaBinario(numero);
                }else if(numero == 2){
                    printf("Digite um número em decimal: ");
                    scanf("%d", &numero);

                    converterParaOctal(numero);
                }else if(numero == 3){
                    printf("Digite um número em decimal: ");
                    scanf("%d", &numero);

                    converterParaHexa(numero);

                }else if(numero == 4){
                    printf("Digite um número em decimal: ");
                    scanf("%d", &numero);
                    
                    converterParaBCD(numero);
                }else{
                    printf("Opção inválida!");
                }
                break;
            case 2: 
                printf("Digite um número em decimal: ");
                scanf("%d", &numero);

                complementoDois(numero);
                break;
            case 3: 
                printf("Escolha a sua opção: \n");
                printf("(1) Converter decimal em float.\n");
                printf("(2) Converter decimal em double.\n\n--->");
                scanf("%d", &numero);
                    
                if(numero == 1){
                    printf("Digite um número real: \n\n");
                    scanf("%lf", &num);

                    converterParaFloat(num);
                }else if(numero == 2){

                }else{
                    printf("Opção inválida");
                }
                break;
            case 4:
                printf("\nFim do programa!\n");
                break;
            default:
                printf("Opção inválida! Por favor, escolha uma opção entre 1 e 4.\n");
        }
    }

    return 0;
}
