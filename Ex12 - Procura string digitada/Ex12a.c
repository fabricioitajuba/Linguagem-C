/*--------------------------------------------------
 * Ex12a - Procurar uma string digitada
 * Autor: Fabrício Ribeiro
 * Para compilar: make
 * Para limpar: make clean
 *--------------------------------------------------*/

#include <stdio.h>
#include <string.h>

int main() {
    char texto_definido[] = "Aprender a programar abre muitas portas.";
    char termo_busca[50];
    int continuar = 1;

    while (continuar) {
        printf("\nDigite o termo de busca (ou 'sair' para encerrar): ");
        
        // 1. Lendo a string do teclado com fgets (pega espaços e o \n no final)
        fgets(termo_busca, sizeof(termo_busca), stdin);

        // 2. Removendo o '\n' que o fgets armazena no final da string
        termo_busca[strcspn(termo_busca, "\n")] = '\0';

        // Critério de parada do loop
        if (strcmp(termo_busca, "sair") == 0) {
            continuar = 0;
            break;
        }

        // 3. Buscando a string
        if (strstr(texto_definido, termo_busca) != NULL) {
            printf("Sucesso! '%s' foi encontrada.\n", termo_busca);
        } else {
            printf("Que pena! '%s' nao foi encontrada.\n", termo_busca);
        }
        
        // OBSERVAÇÃO SOBRE O BUFFER:
        // O fgets() já consome o \n. Porém, se o usuário digitar mais que 49 caracteres, 
        // o excesso continuará no buffer. Para garantir limpeza total em qualquer caso, 
        // você pode usar esta linha opcional se notar que o programa está pulando leituras:
        // while ((c = getchar()) != '\n' && c != EOF);
    }

    printf("Programa encerrado.\n");
    return 0;
}
