/*--------------------------------------------------
 * Ex13b - Alocação dinâmica de memória (struct)
 * Autor: Fabrício Ribeiro
 * Para compilar: make
 * Para limpar: make clean
 *--------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo a struct
typedef struct {
    char nome[50];
    int codigo;
    float preco;
} Produto;

int main() {
    // Criando um ponteiro para a struct Produto
    Produto *p;

    // 1. Alocando memória para UM elemento do tipo Produto
    p = (Produto *) malloc(sizeof(Produto));

    // 2. Verificando se a alocação funcionou
    if (p == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // 3. Atribuindo valores usando o operador SETA (->)
    // p->codigo é um atalho para (*p).codigo
    p->codigo = 101;
    p->preco = 29.99;
    strcpy(p->nome, "Teclado USB");

    // Exibindo os dados
    printf("Produto: %s\n", p->nome);
    printf("Código: %d\n", p->codigo);
    printf("Preço: R$ %.2f\n", p->preco);

    // 4. Liberando a memória alocada
    free(p);
    p = NULL; 

//Criando um Array Dinâmico de Structs
int quantidade = 3;
Produto *lista_produtos;

// Aloca espaço para 3 structs consecutivas na memória
lista_produtos = (Produto *) malloc(quantidade * sizeof(Produto));

if (lista_produtos != NULL) {
    // Acessando como um vetor tradicional (usa o ponto '.' porque lista_produtos[i] já é a struct)
    lista_produtos[0].codigo = 202;
    strcpy(lista_produtos[0].nome, "Mouse Sem Fio");
    lista_produtos[0].preco = 59.90;
    
    // Também poderia usar aritmética de ponteiros: (lista_produtos + 1)->codigo = 203;

    // Sempre liberar ao final
    free(lista_produtos);
}

    return 0;
}
