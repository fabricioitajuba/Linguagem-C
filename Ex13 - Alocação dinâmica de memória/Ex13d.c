/*--------------------------------------------------
 * Ex13d - Alocação dinâmica de memória (arquivo)
 * Autor: Fabrício Ribeiro
 * Para compilar: make
 * Para limpar: make clean
 *--------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    // 1. Abrir o arquivo em modo de leitura ("r")
    FILE *arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // 2. Descobrir o tamanho do arquivo em bytes
    fseek(arquivo, 0, SEEK_END); // Move o ponteiro para o final do arquivo
    long tamanho = ftell(arquivo); // Pega a posição atual (que é o tamanho total)
    fseek(arquivo, 0, SEEK_SET); // Retorna o ponteiro para o início do arquivo

    // 3. Alocar memória dinamicamente no Heap
    // Adicionamos +1 para armazenar o '\0' e garantir que funcione como uma string válida em C
    char *buffer = (char *)malloc((tamanho + 1) * sizeof(char));
    
    // Validar se a alocação foi bem-sucedida
    if (buffer == NULL) {
        printf("Erro de falta de memória!\n");
        fclose(arquivo);
        return 1;
    }

    // 4. Ler os dados do arquivo e enviar para o espaço alocado
    // fread(ponteiro_destino, tamanho_do_elemento, quantidade, ponteiro_do_arquivo)
    size_t bytesLidos = fread(buffer, sizeof(char), tamanho, arquivo);
    
    // Adiciona o caractere de fim de string na última posição
    buffer[bytesLidos] = '\0'; 

    // 5. Exibir os dados armazenados na memória alocada
    printf("Conteudo lido do arquivo:\n%s\n", buffer);

    // 6. Limpar os recursos (Essencial para evitar vazamento de memória)
    free(buffer);
    fclose(arquivo);

    return 0;
}
