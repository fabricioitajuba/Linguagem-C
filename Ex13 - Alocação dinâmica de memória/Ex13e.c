/*--------------------------------------------------
 * Ex13e - Alocação dinâmica de memória (realocação byte)
 * Autor: Fabrício Ribeiro
 * Para compilar: make
 * Para limpar: make clean
 *--------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    // 1. Alocação inicial para 3 inteiros
    int *ptr = (int*) malloc(3 * sizeof(int));
    
    if (ptr == NULL) {
        printf("Erro na alocação inicial!\n");
        return 1;
    }

    // Inicializando os valores
    ptr[0] = 10; ptr[1] = 20; ptr[2] = 30;

    // 2. Queremos aumentar o espaço para 5 inteiros
    int novo_tamanho = 5;
    int *temp = (int*) realloc(ptr, novo_tamanho * sizeof(int));

    // 3. SEMPRE verifique se o realloc funcionou
    if (temp == NULL) {
        printf("Erro ao realocar memória! O bloco original ainda está intacto.\n");
        free(ptr); // Libera o original antes de fechar o programa
        return 1;
    }

    // Se deu certo, atualizamos nosso ponteiro principal
    ptr = temp;

    // Adicionando novos valores no espaço extra
    ptr[3] = 40; ptr[4] = 50;

    // Exibindo todos os valores
    for(int i = 0; i < novo_tamanho; i++) {
        printf("%d ", ptr[i]); // Saída: 10 20 30 40 50
    }

    // 4. Sempre libere a memória no final
    free(ptr);

    return 0;
}

