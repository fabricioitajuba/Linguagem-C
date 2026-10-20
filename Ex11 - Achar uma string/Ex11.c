/*--------------------------------------------------
 * Ex11 - Achar uma string
 * Autor: Fabrício Ribeiro
 * Para compilar: make
 * Para limpar: make clean
 *--------------------------------------------------*/

#include <stdio.h>
#include <string.h>

int main() {
    char texto[] = "A linguagem C e muito poderosa.";
    char busca[] = "C e muito";
    
    // Executa a busca da substring
    char *resultado = strstr(texto, busca);
    
    if (resultado != NULL) {
        // Descobre o índice numérico calculando a diferença entre os ponteiros
        int posicao = resultado - texto;
        printf("Substring encontrada!\n");
        printf("Texto a partir da ocorrencia: \"%s\"\n", resultado);
        printf("Comeca no indice: %d\n", posicao);
    } else {
        printf("Substring nao encontrada.\n");
    }
    
    return 0;
}
