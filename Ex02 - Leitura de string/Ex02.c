/*--------------------------------------------------
 * Ex02 - Leitura de String
 * Autor: Fabrício Ribeiro
 * Para compilar: make
 * Para limpar: make clean
 *--------------------------------------------------*/
#include <stdio.h>

int main() {
    // Cria uma array (string) para armazenar até 99 caracteres + o terminador nulo \0
    char texto[100];

    printf("Digite uma frase e pressione Enter: ");
    
    // fgets lê o texto do teclado (stdin) de forma segura, evitando estouro de memória
    if (fgets(texto, sizeof(texto), stdin) != NULL) {
        printf("\nVocê digitou: %s", texto);
    }

    return 0;
}

