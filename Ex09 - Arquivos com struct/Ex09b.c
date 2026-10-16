#include <stdio.h>

struct Cliente {
    char nome[50];
    int idade;
};

int main() {
    FILE *arquivo;
    struct Cliente c1;

    // Abre o arquivo em modo de leitura binária ("rb")
    arquivo = fopen("clientes.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    // fread lê 1 elemento do tamanho da struct Cliente e joga na variável c1
    size_t lidos = fread(&c1, sizeof(struct Cliente), 1, arquivo);

    if (lidos == 1) {
        printf("Nome: %s\nIdade: %d\n", c1.nome, c1.idade);
    } else {
        printf("Erro ao ler os dados ou fim do arquivo.\n");
    }

    fclose(arquivo);
    return 0;
}
