/*--------------------------------------------------
 * Ex13 - Alocação dinâmica de memória (vetor)
 * Autor: Fabrício Ribeiro
 * Para compilar: make
 * Para limpar: make clean
 *--------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h> // Biblioteca necessária para usar malloc e free

int main() {
    int tamanho;
    int *vetor;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    // 1. Alocando a memória com malloc
    // sizeof(int) garante a portabilidade, pegando o tamanho correto do tipo em bytes
    vetor = (int *) malloc(tamanho * sizeof(int));

    // 2. IMPORTANTE: Verificar se a alocação foi bem-sucedida
    if (vetor == NULL) {
        printf("Erro: Memória insuficiente!\n");
        return 1; // Encerra o programa com erro
    }

    // 3. Utilizando a memória normalmente como um vetor
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = i * 10;
        printf("Vetor[%d] = %d\n", i, vetor[i]);
    }

    // 4. SEMPRE liberar a memória após o uso
    free(vetor);
    vetor = NULL; // Boa prática: evita ponteiros "fantasmas"

    return 0;
}

