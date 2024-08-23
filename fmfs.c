/*
 * Autor: Felipe Matias de Freitas da Silva
 * E-mail: fmfs@cesar.school
 * Data de criação: 23/08/2024
 * Última modificação: [23/08/2024 | 20:27] Questão 2
 * Função para representar número de base 10 para com sinal com 16 bits concluída
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

    printf("\nPassos para conversão para octal:\n");
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

int main() {
    int opcao;
    int numero;

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
