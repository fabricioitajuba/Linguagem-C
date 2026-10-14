/*--------------------------------------------------
 * Ex04 - Abre arquivo e cria se não existir
 * Autor: Fabrício Ribeiro
 * Para compilar: make
 * Para limpar: make clean
 *--------------------------------------------------*/
#include <stdio.h>

int main() {
    // Nome do arquivo que queremos gerenciar
    const char *nome_arquivo = "dados.txt";
    const char *frase = "Olá! Esta é uma frase gravada automaticamente pelo programa em C.\n";
    FILE *arquivo;

    // 1. Tenta abrir para leitura e escrita (o arquivo precisa já existir)
    arquivo = fopen(nome_arquivo, "r+");

    // 2. Se retornou NULL, significa que o arquivo não existe
    if (arquivo == NULL) {
        printf("O arquivo '%s' nao existe. Criando um novo...\n", nome_arquivo);
        
        // Abre com "w+", que cria o arquivo automaticamente para leitura e escrita
        arquivo = fopen(nome_arquivo, "w+");
        
        if (arquivo == NULL) {
            printf("Erro crítico: Nao foi possivel criar o arquivo.\n");
            return 1; // Retorna erro caso o sistema impeça a criação (ex: falta de permissão)
        }
        printf("Arquivo '%s' criado com sucesso!\n", nome_arquivo);
    } else {
        printf("O arquivo '%s' ja existia e foi aberto com sucesso!\n", nome_arquivo);
    }

    // 3. Insere a frase no arquivo
    // fputs grava a string apontada no fluxo do arquivo aberto
    if (fputs(frase, arquivo) != EOF) {
        printf("Frase inserida com sucesso no arquivo!\n");
    } else {
        printf("Erro ao tentar escrever no arquivo.\n");
    }

    // 4. Fecha o arquivo com segurança
    fclose(arquivo);
    printf("Arquivo fechado com seguranca.\n");

    return 0;
}
