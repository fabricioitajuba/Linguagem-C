/*--------------------------------------------------
 * Ex03 - Leitura de teclado
 * Autor: Fabrício Ribeiro
 * Para compilar: make
 * Para limpar: make clean
 *--------------------------------------------------*/
#include <stdio.h>

int main() {
    int opcao;

    do {
        // Exibe o menu na tela
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Imprimir mensagem A\n");
        printf("2. Imprimir mensagem B\n");
        printf("3. Sair do programa\n");
        printf("Escolha uma opcao: ");
        
        // Lê a opção digitada pelo usuário
        if (scanf("%d", &opcao) != 1) {
            // Limpa o buffer caso o usuário digite uma letra por engano (evita loop infinito)
            while (getchar() != '\n');
            printf("\nErro: Por favor, digite um numero valido.\n");
            continue;
        }

        // Executa a ação baseada na escolha
        switch (opcao) {
            case 1:
                printf("\n[Mensagem A] Voce selecionou a primeira opcao!\n");
                break;
            case 2:
                printf("\n[Mensagem B] Esta e a segunda mensagem do sistema.\n");
                break;
            case 3:
                printf("\nSaindo do programa... Ate logo!\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente com 1, 2 or 3.\n");
                break;
        }

    } while (opcao != 3); // O loop continua rodando enquanto a opção não for 3

    return 0;
}

