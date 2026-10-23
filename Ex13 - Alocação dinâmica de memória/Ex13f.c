/*--------------------------------------------------
 * Ex13f - Alocação dinâmica de memória (realocação int)
 * Autor: Fabrício Ribeiro
 * Para compilar: make
 * Para limpar: make clean
 *--------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int capacidade = 2; // Tamanho inicial do vetor
    int total_elementos = 0;
    
    // Alocação inicial do vetor para 2 números inteiros
    int *vetor = (int*) malloc(capacidade * sizeof(int));
    
    if (vetor == NULL) {
        printf("Erro de memória inicial.\n");
        return 1;
    }

    // Simulando a inserção de 5 elementos em um vetor que só tem espaço para 2
    for (int i = 1; i <= 5; i++) {
        
        // Se o vetor estiver cheio, precisamos realocar (aumentar)
        if (total_elementos == capacidade) {
            capacidade += 2; // Aumenta a capacidade total em +2 vagas
            
            // Realocação segura usando ponteiro temporário
            int *temp = (int*) realloc(vetor, capacidade * sizeof(int));
            
            if (temp == NULL) {
                printf("Erro ao expandir o vetor!\n");
                free(vetor); // Libera o que já tínhamos antes de sair
                return 1;
            }
            
            vetor = temp; // Atualiza o vetor para o novo endereço ampliado
            printf("\n[LOG] Vetor cheio! Realocado para o tamanho total de %d itens.\n", capacidade);
        }

        // Insere o elemento no vetor
        vetor[total_elementos] = i * 10; // Salva 10, 20, 30, 40, 50...
        total_elementos++;
    }

    // Exibindo o vetor inteiro realocado
    printf("\n--- Elementos no vetor final ---\n");
    for (int i = 0; i < total_elementos; i++) {
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }

    // Libera a memória no final do programa
    free(vetor);

    return 0;
}


