/*--------------------------------------------------
 * Ex09 - Arquivos com struct
 * Autor: Fabrício Ribeiro
 * Para compilar: make
 * Para limpar: make clean
 *--------------------------------------------------*/
#include <stdio.h>

#define nome_len 31 //30 string + 1 \0
#define idade_len 4 // 3 string + 1 \0

struct Cliente {
    char nome[nome_len];
    char idade[idade_len]
};

int main() {

    int i = 0;
    char ch;

    FILE *arquivo;
    
    // Criamos um cliente fictício para salvar
    //struct Cliente c1iente = {"Fulano de Tal", 30};
    struct Cliente cliente;

    printf("Digite o nome: ");   
    fgets(cliente.nome, nome_len, stdin);

    printf("Digite a idade: ");   
    fgets(cliente.idade, idade_len, stdin);    

    // Abre o arquivo em modo de ESCRITA BINÁRIA ("wb")
    arquivo = fopen("clientes.dat", "wb");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return 1;
    }

    // Escreve 1 struct Cliente no arquivo
    fwrite(&cliente, sizeof(struct Cliente), 1, arquivo);

    printf("Arquivo 'clientes.dat' gerado com sucesso!\n");

    fclose(arquivo);
    return 0;
}

