/*--------------------------------------------------
 * Ex05 - CRUD em arquivo .txt
 * Autor: Fabrício Ribeiro
 * Para compilar: make
 * Para limpar: make clean
 *--------------------------------------------------*/
#include <stdio.h>

void CRUD_Create(void);
void CRUD_Read(void);
void CRUD_Update(void);
void CRUD_Delete(void);
void CRUD_List(void);

int main() {

    char opcao;

    do{

        // Limpa a tela do terminal
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
        printf(">>");

        scanf(" %c", &opcao);

        switch(opcao){
            case 'C':
            case 'c':
                CRUD_Create();                
                break;
            case 'R':
            case 'r':
                CRUD_Read();
                break;
            case 'U':
            case 'u':
                CRUD_Update();
                break;
            case 'D':
            case 'd':
                CRUD_Delete();
                break;
            case 'L':
            case 'l':
                CRUD_List();
                break;
            case 'Q':
            case 'q':
                printf("\nSaindo do programa... Ate logo!\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
                break;
        }

    }while(opcao != 'Q' && opcao != 'q'); // O loop continua rodando enquanto a opção não for Q

    return 0;
}

/***************************************
 * Função para criar um novo registro
 ***************************************/
void CRUD_Create(void){

    FILE *arquivo = fopen("registros.txt", "w+");

    if(arquivo == NULL){
        printf("Erro ao abrir ou criar o arquivo!\n");
        return 1;
    }

    printf("\nC - Criar um registro:\n");

    // Limpa o buffer residual e espera o próximo Enter do usuário
    while (getchar() != '\n'); 
    getchar();



}

/***************************************
 * Função para ler um novo registro
 ***************************************/
void CRUD_Read(void){

    printf("\nR - Ler um registro:\n");

    // Limpa o buffer residual e espera o próximo Enter do usuário
    while (getchar() != '\n'); 
    getchar();
}

/***************************************
 * Função para atualizar um novo registro
 ***************************************/
void CRUD_Update(void){

    printf("\nU - Atualizar um registro:\n");

    // Limpa o buffer residual e espera o próximo Enter do usuário
    while (getchar() != '\n'); 
    getchar();
}

/***************************************
 * Função para deletar um novo registro
 ***************************************/
void CRUD_Delete(void){

    printf("\nD - Deletar um registro:\n");

    // Limpa o buffer residual e espera o próximo Enter do usuário
    while (getchar() != '\n'); 
    getchar();
}

/***************************************
 * Função para listar um novo registro
 ***************************************/
void CRUD_List(void){

    printf("\nL - Listar registros:\n");

    // Limpa o buffer residual e espera o próximo Enter do usuário
    while (getchar() != '\n'); 
    getchar();
}