#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo;
    // Criamos um buffer de 4 posições (3 para os bytes + 1 para o terminador '\0' caso seja texto)
    char buffer[4] = {0}; 

    // 1. Abre o arquivo em modo de leitura binária ("rb")
    arquivo = fopen("exemplo.txt", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    // 2. Move o ponteiro para a posição 5 a partir do início do arquivo (SEEK_SET)
    // O byte na posição 5 será o próximo a ser lido (lembrando que a contagem começa no 0)
    if (fseek(arquivo, 5, SEEK_SET) != 0) {
        printf("Erro ao mover o ponteiro no arquivo!\n");
        fclose(arquivo);
        return 1;
    }

    // 3. Lê 3 elementos, cada um com tamanho de 1 byte, e guarda no buffer
    size_t bytesLidos = fread(buffer, 1, 3, arquivo);

    // 4. Mostra o resultado
    printf("Bytes lidos com sucesso: %zu\n", bytesLidos);
    printf("Conteúdo lido: \"%s\"\n", buffer);

    // 5. Fecha o arquivo
    fclose(arquivo);
    return 0;
}
