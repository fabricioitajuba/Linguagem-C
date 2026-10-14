/*--------------------------------------------------
 * Ex05 - CRUD em arquivo .txt
 * Autor: Fabrício Ribeiro
 * Para compilar: make
 * Para limpar: make clean
 *--------------------------------------------------*/
#include <stdio.h>
//#include <stdlib.h>

int main() {

    // Limpa a tela do terminal
    //system("clear"); 
    printf("\e[1J\e[H"); 

    // Exibe o menu na tela
    printf("---------------------------------\n");
    printf("### CRUD versao 1.0, 13/10/2026\n");
    printf("---------------------------------\n");
    printf("\n- O que Voce deseja?\n\n");
    printf("C - Criar um registro;\n");
    printf("R - Ler um registro;\n");
    printf("U - Atualizar um registro;\n");
    printf("D - Deletar um registro;\n");
    printf("L - Listar todos os registros;\n");
    printf("Q - Sair;\n");

    int opcao;

    do {
        
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
            case 'Q':
            case 'q':
                printf("\nSaindo do programa... Ate logo!\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente com 1, 2 or 3.\n");
                break;
        }

    } while (opcao != 'Q' && opcao != 'q'); // O loop continua rodando enquanto a opção não for Q

    return 0;
}

