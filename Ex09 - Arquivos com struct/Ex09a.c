/*--------------------------------------------------
 * Ex09 - Arquivos com struct
 * Autor: Fabrício Ribeiro
 * Para compilar: make
 * Para limpar: make clean
 *--------------------------------------------------*/
#include <stdio.h>

struct Cliente {
    char nome[50]; // Ajustado para suportar nomes reais (no exemplo anterior estava apenas char)
    int idade;
};

int main() {
    FILE *arquivo;
    
    // Criamos um cliente fictício para salvar
    struct Cliente c1 = {"Fulano de Tal", 30};

    // Abre o arquivo em modo de ESCRITA BINÁRIA ("wb")
    arquivo = fopen("clientes.dat", "wb");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return 1;
    }

    // Escreve 1 struct Cliente no arquivo
    fwrite(&c1, sizeof(struct Cliente), 1, arquivo);

    printf("Arquivo 'clientes.dat' gerado com sucesso!\n");

    fclose(arquivo);
    return 0;
}

