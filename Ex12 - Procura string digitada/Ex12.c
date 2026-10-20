/*--------------------------------------------------
 * Ex12 - Procurar uma string digitada
 * Autor: Fabrício Ribeiro
 * Para compilar: make
 * Para limpar: make clean
 *--------------------------------------------------*/

#include <stdio.h>
#include <string.h>

int main() {
    // 1. Definindo a string principal fixa
    char texto_definido[] = "Aprender a programar abre muitas portas.";
    char termo_busca[50];

    printf("Digite a palavra que deseja procurar: ");
    
    // 2. Lendo a string do teclado (usando %49s para evitar estouro de memória)
    scanf("%49s", termo_busca);

    // 3. Procurando o termo dentro do texto definido
    // A função strstr() retorna um ponteiro se achar, ou NULL se não achar
    if (strstr(texto_definido, termo_busca) != NULL) {
        printf("Sucesso! '%s' foi encontrada.\n", termo_busca);
    } else {
        printf("Que pena! '%s' nao foi encontrada.\n", termo_busca);
    }

    return 0;
}
