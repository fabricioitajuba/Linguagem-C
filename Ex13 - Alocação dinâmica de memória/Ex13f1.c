/*--------------------------------------------------
 * Ex13f1 - Realocação dinâmica de memória (podemos aumentar ou diminuir)
 * Autor: Fabrício Ribeiro
 * Para compilar: make
 * Para limpar: make clean
 *--------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int tamanho;

    tamanho = 2;

    // Alocação inicial do vetor para 2 números inteiros
    int *vetor = (int*) malloc(tamanho * sizeof(int));
    
    if (vetor == NULL) {
        printf("Erro de memória inicial.\n");
        return 1;
    }

    vetor[0] = 0;
    vetor[1] = 1;

    // Exibindo o vetor alocado
    printf("\n--- Elementos no vetor ---\n");
    for (int i = 0; i < tamanho; i++) {
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }

    tamanho = 5;

    // Realocação segura usando ponteiro temporário
    int *temp = (int*) realloc(vetor, tamanho * sizeof(int));
            
    if(temp == NULL){
        printf("Erro ao expandir o vetor!\n");
        free(vetor); // Libera o que já tínhamos antes de sair
        return 1;
    }
            
    vetor = temp; // Atualiza o vetor para o novo endereço ampliado

    vetor[2] = 2;
    vetor[3] = 3;
    vetor[4] = 4;

    // Exibindo o vetor inteiro realocado
    printf("\n--- Elementos no vetor final ---\n");
    for (int i = 0; i < tamanho; i++) {
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }

    // Libera a memória no final do programa
    free(vetor);

    return 0;
}
