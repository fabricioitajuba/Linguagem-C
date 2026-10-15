/*--------------------------------------------------
 * Ex05 - CRUD em arquivo .txt
 * Autor: Fabrício Ribeiro
 * Para compilar: make
 * Para limpar: make clean
 * 
 * Create: não concluído
 * Read: não concluído
 * Update: não concluído
 * Delete: não concluído
 * List: não concluído
 *--------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <time.h>

int CRUD_Create(void);
void CRUD_Read(void);
void CRUD_Update(void);
void CRUD_Delete(void);
void CRUD_List(void);

struct Pessoa {
    char nome[34];
    char idade[3];
};

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
int CRUD_Create(void){

    char opcao, data_str[11], hora_str[9];

    struct Pessoa pessoa;
    time_t tempo_bruto;
    struct tm *info_tempo;

    printf("\nC - Criar um registro:\n\n");

    //while (getchar() != '\n'); 
    //getchar();

    // Limpa o lixo que outros menus ou comandos deixaram no teclado.
    while (getchar() != '\n' && getchar() != EOF); 

    // Leitura do Nome
    printf("Digite o nome: ");
    fgets(pessoa.nome, sizeof(pessoa.nome), stdin);
    pessoa.nome[strcspn(pessoa.nome, "\n")] = '\0'; // Remove o '\n'

    // Leitura da Idade como String
    printf("Digite a idade: ");
    fgets(pessoa.idade, sizeof(pessoa.idade), stdin);
    pessoa.idade[strcspn(pessoa.idade, "\n")] = '\0'; // Remove o '\n'

    // Obtém o tempo atual do sistema
    time(&tempo_bruto);

    // Converte para a estrutura de hora local do Linux
    info_tempo = localtime(&tempo_bruto);

    // Formata a DATA (Garante tamanho padrão de 10 caracteres)
    strftime(data_str, sizeof(data_str), "%d/%m/%Y", info_tempo);

    // Formata a HORA (Garante tamanho padrão de 8 caracteres)
    strftime(hora_str, sizeof(hora_str), "%H:%M:%S", info_tempo);

    printf("Deseja salvar o registro? (S/N): ");
    scanf(" %c", &opcao);

    if(opcao == 'S' || opcao == 's'){

        //Tenta abrir o arquivo "registros.txt" no modo de leitura e escrita
        FILE *arquivo = fopen("registros.txt", "r+");

        if(arquivo == NULL){

            //Caso não exista, cria o arquivo no modo de escrita e leitura
            arquivo = fopen("registros.txt", "w+");
            
            if(arquivo == NULL){
                //printf("Erro crítico: Não foi possível criar o arquivo.\n");
                return 1;
            }        
        }

        fseek(arquivo, 0, SEEK_END);
        
        fprintf(arquivo, "%s %s %-50s %-3s\n", data_str, hora_str, pessoa.nome, pessoa.idade);

        fclose(arquivo);

        printf("Registro salvo.\n");
    }
    else{
        printf("Registro não salvo.\n");
    }

}

/***************************************
 * Função para ler um registro
 ***************************************/
void CRUD_Read(void){

    printf("\nR - Ler um registro:\n");

    // Limpa o buffer residual e espera o próximo Enter do usuário
    while (getchar() != '\n'); 
    getchar();
}

/***************************************
 * Função para atualizar um registro
 ***************************************/
void CRUD_Update(void){

    printf("\nU - Atualizar um registro:\n");

    // Limpa o buffer residual e espera o próximo Enter do usuário
    while (getchar() != '\n'); 
    getchar();
}

/***************************************
 * Função para deletar um registro
 ***************************************/
void CRUD_Delete(void){

    printf("\nD - Deletar um registro:\n");

    // Limpa o buffer residual e espera o próximo Enter do usuário
    while (getchar() != '\n'); 
    getchar();
}

/***************************************
 * Função para listar os registros
 ***************************************/
void CRUD_List(void){

    printf("\nL - Listar registros:\n");

    // Limpa o buffer residual e espera o próximo Enter do usuário
    while (getchar() != '\n'); 
    getchar();
}