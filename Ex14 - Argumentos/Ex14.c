/*--------------------------------------------------
 * Ex14 - Argumentos
 * Autor: Fabrício Ribeiro
 * Para compilar: make
 * Para limpar: make clean
 *--------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h> // Necessário para usar a função atoi

int main(int argc, char *argv[]) {
    // 1. Verifica se o usuário passou a quantidade correta de argumentos
    // O primeiro argumento (argv[0]) é sempre o próprio nome do programa.
    // Portanto, precisamos de 1 (nome) + 2 (números) = 3 argumentos.
    if (argc != 3) {
        printf("Uso correto: %s <numero1> <numero2>\n", argv[0]);
        return 1; // Retorna 1 indicando que houve um erro
    }

    // 2. Converte os argumentos de texto (strings) para números inteiros
    // argv[1] é o primeiro número e argv[2] é o segundo número
/*  int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    // 3. Faz a soma
    int soma = num1 + num2;

    // 4. Mostra o resultado na tela
    printf("A soma de %d e %d eh: %d\n", num1, num2, soma);
*/

    float num1 = atof(argv[1]);
    float num2 = atof(argv[2]);

    // 3. Faz a soma
    float soma = num1 + num2;

    // 4. Mostra o resultado na tela
    printf("A soma de %.2f e %.2f eh: %.2f\n", num1, num2, soma);    

    return 0; // Retorna 0 indicando que o programa rodou com sucesso
}

