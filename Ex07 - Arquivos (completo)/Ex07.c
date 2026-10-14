/*--------------------------------------------------
 * Ex07 - Abre arquivo e cria se não existir
 * Autor: Fabrício Ribeiro
 * Para compilar: make
 * Para limpar: make clean
 *--------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    // 1. Tenta abrir o arquivo no modo r+ (Leitura e Escrita de arquivos JÁ existentes)
    FILE *arquivo = fopen("meu_arquivo.txt", "r+");

    // 2. Se retornar NULL, significa que o arquivo NÃO existe (ou você não tem permissão)
    if (arquivo == NULL) {
        printf("O arquivo não existe. Criando um novo...\n");
        
        // 3. Abre no modo w+ para CRIAÇÃO (Leitura e Escrita de arquivos novos)
        arquivo = fopen("meu_arquivo.txt", "w+");
        
        if (arquivo == NULL) {
            printf("Erro crítico: Não foi possível criar o arquivo.\n");
            return 1;
        }
        
        // Escreve um dado inicial no arquivo recém-criado
        //fprintf(arquivo, "Texto inicial do arquivo novo.\n");
    } else {
        printf("Arquivo existente aberto com sucesso para leitura e escrita!\n");
    }

    // 1. Posiciona o ponteiro no FINAL do arquivo
    // 0 = zero bytes de deslocamento a partir do final (SEEK_END)
    fseek(arquivo, 0, SEEK_END);

    // 1. Escrevendo no arquivo
    fprintf(arquivo, "Esse é o texto que será inserido!\n");

    // 1. Posiciona o ponteiro no FINAL do arquivo
    // 0 = zero bytes de deslocamento a partir do final (SEEK_END)
    fseek(arquivo, 0, SEEK_SET);

    // 3. Lendo o conteúdo do arquivo
    char linha[100];
    printf("--- Conteúdo do arquivo criado ---\n");
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }

    // Sempre feche o arquivo ao terminar
    fclose(arquivo);
    return 0;
}
