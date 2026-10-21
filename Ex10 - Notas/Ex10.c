/*--------------------------------------------------
 * Ex10 - Cadastro de notas
 * Autor: Fabrício Ribeiro
 * Para compilar: make
 * Para limpar: make clean
 *--------------------------------------------------*/
#include <stdio.h>
#include <string.h>

#define nome_len 41 //40 string + 1 "\0"

int verifica_arquivo(void);
int insere_notas(void);
int consulta_notas(void);
int alterara_notas(void);
int deleta_notas(void);
int listar_notas(void);

struct Aluno{
    int id;
    char nome[nome_len];
    float nota1, nota2, media;
};

//Programa principal
int main(){

    char opcao;
    int retorno;

    verifica_arquivo();

    do{

        // Limpa a tela do terminal
        printf("\e[1J\e[H"); 

        // Exibe o menu na tela
        printf("---------------------------------------\n");
        printf("### Controle de notas 1.0, 18/10/2026\n");
        printf("---------------------------------------\n");
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
                retorno = insere_notas();                
                break;
            case 'R':
            case 'r':
                retorno = consulta_notas();
                break;
            case 'U':
            case 'u':
                retorno = alterara_notas();
                break;
            case 'D':
            case 'd':
                retorno = deleta_notas();
                break;
            case 'L':
            case 'l':
                retorno = listar_notas();
                break;
            case 'Q':
            case 'q':
                printf("\nSaindo do programa...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
                break;
        }

    }while(opcao != 'Q' && opcao != 'q'); // O loop continua rodando enquanto a opção não for Q

    return 0;
    
}

//Verifica se o arquivo de registro de dados existe
//Caso não exista, será criado.
int verifica_arquivo(void){

    FILE *arquivo = fopen("alunos.dat", "rb");

    if(arquivo == NULL){

        //Caso não exista, cria o arquivo no modo de escrita e leitura
        arquivo = fopen("alunos.dat", "wb");
            
        if(arquivo == NULL){
            printf("Erro crítico: Não foi possível criar o arquivo.\n");
            return 1;
        }        
    }

    fclose(arquivo);
}

//Função para inserir notas
int insere_notas(void){

    struct Aluno aluno;
    char opcao;

    while (getchar() != '\n' && getchar() != EOF);

    printf("Digite o nome: ");   
    fgets(aluno.nome, nome_len, stdin);

    printf("Digite a nota 1: ");   
    scanf("%f", &aluno.nota1);

    printf("Digite a nota 2: ");   
    scanf("%f", &aluno.nota2);

    aluno.media = (aluno.nota1*2 + aluno.nota2*3) / 5;

    printf("O valor da média é: %.2f ", aluno.media);

    printf("\nDeseja salvar o registro? (S/N)");
    scanf(" %c", &opcao);

    if(opcao == 'S' || opcao == 's'){
        
        FILE *arquivo;

        arquivo = fopen("alunos.dat", "ab");

        if(arquivo == NULL){
            printf("Erro ao criar o arquivo!\n");
            return 1;
        }

        //Calcula o id com base no tamanho do arquivo
        aluno.id = (ftell(arquivo) / sizeof(struct Aluno)) + 1;

        printf("\nID = %d ", aluno.id);

        fwrite(&aluno, sizeof(struct Aluno), 1, arquivo);

        fclose(arquivo);

        printf("\nDados salvo com sucesso!\n");
    }
    else{
        printf("\nDados não salvos!\n");
    }

    while (getchar() != '\n'); 
    getchar();

    return 0;
}

//Função para consultar registros
int consulta_notas(void){

    struct Aluno aluno;
    int indice;

    while (getchar() != '\n' && getchar() != EOF);

    printf("\nQual registro deseja consultar? ");
    scanf("%d", &indice);

    long offset = (indice - 1) * sizeof(struct Aluno);

    FILE *arquivo = fopen("alunos.dat", "rb");
    
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    if(fseek(arquivo, offset, SEEK_SET) != 0){
        printf("Erro ao posicionar no arquivo (Linha inexistente).\n");
        fclose(arquivo);
        return 1;
    }

    fread(&aluno, sizeof(struct Aluno), 1, arquivo);

    printf("Id: %d\n", aluno.id);
    printf("Nome: %s", aluno.nome);
    printf("Nota 1: %.2f\n", aluno.nota1);
    printf("Nota 2: %.2f\n", aluno.nota2);
    printf("Media: %.2f\n", aluno.media);

    fclose(arquivo);

    while (getchar() != '\n'); 
    getchar();

    return 0;
}

//Função para alterar registros
int alterara_notas(void){

    //Lê o registro

    struct Aluno aluno;
    int indice;
    char opcao;

    while (getchar() != '\n' && getchar() != EOF);

    printf("\nQual registro deseja alterar? ");
    scanf("%d", &indice);

    long offset = (indice - 1) * sizeof(struct Aluno);

    FILE *arquivo = fopen("alunos.dat", "rb");
    
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    if(fseek(arquivo, offset, SEEK_SET) != 0){
        printf("Erro ao posicionar no arquivo (Linha inexistente).\n");
        fclose(arquivo);
        return 1;
    }

    fread(&aluno, sizeof(struct Aluno), 1, arquivo);

    printf("Id: %d\n", aluno.id);
    printf("Nome: %s", aluno.nome);
    printf("Nota 1: %.2f\n", aluno.nota1);
    printf("Nota 2: %.2f\n", aluno.nota2);
    printf("Media: %.2f\n", aluno.media);

    fclose(arquivo);

    //Altera o registro

    while (getchar() != '\n' && getchar() != EOF);

    printf("Digite o novo nome: ");   
    fgets(aluno.nome, nome_len, stdin);

    printf("Digite a nova nota 1: ");   
    scanf("%f", &aluno.nota1);

    printf("Digite a nova nota 2: ");   
    scanf("%f", &aluno.nota2);

    aluno.media = (aluno.nota1*2 + aluno.nota2*3) / 5;

    printf("O valor da média é: %.2f ", aluno.media);

    printf("\nDeseja salvar o registro? (S/N)");
    scanf(" %c", &opcao);

    if(opcao == 'S' || opcao == 's'){

        arquivo = fopen("alunos.dat", "r+b");

        if(arquivo == NULL){
            printf("Erro ao atualizar o arquivo!\n");
            return 1;
        }

        aluno.id = indice;

        if(fseek(arquivo, offset, SEEK_SET) != 0){
            printf("Erro ao posicionar no arquivo (Linha inexistente).\n");
            fclose(arquivo);
            return 1;
        }

        fwrite(&aluno, sizeof(struct Aluno), 1, arquivo);

        printf("\nDados alterados com sucesso!\n");

        fclose(arquivo);

    }
    else{
        printf("\nDados não alterados!\n");
    }

    while (getchar() != '\n'); 
    getchar();

    return 0;
}

//Função para deletar registros
int deleta_notas(void){

    //Lê o registro

    struct Aluno aluno;
    int indice;
    char opcao;

    while (getchar() != '\n' && getchar() != EOF);

    printf("\nQual registro deseja deletar? ");
    scanf("%d", &indice);

    long offset = (indice - 1) * sizeof(struct Aluno);

    FILE *arquivo = fopen("alunos.dat", "rb");
    
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    if(fseek(arquivo, offset, SEEK_SET) != 0){
        printf("Erro ao posicionar no arquivo (Linha inexistente).\n");
        fclose(arquivo);
        return 1;
    }

    fread(&aluno, sizeof(struct Aluno), 1, arquivo);

    printf("Id: %d\n", aluno.id);
    printf("Nome: %s", aluno.nome);
    printf("Nota 1: %.2f\n", aluno.nota1);
    printf("Nota 2: %.2f\n", aluno.nota2);
    printf("Media: %.2f\n", aluno.media);

    fclose(arquivo);

    //Deleta o registro

    while (getchar() != '\n' && getchar() != EOF);

    printf("\nDeseja deletar o registro? (S/N)");
    scanf(" %c", &opcao);

    if(opcao == 'S' || opcao == 's'){

        //aluno.nome = '\0';
        memset(aluno.nome, ' ', sizeof(aluno.nome));
        aluno.nome[nome_len]= '\n';
        aluno.nota1 = 0;
        aluno.nota2 = 0;
        aluno.media = 0;

        arquivo = fopen("alunos.dat", "r+b");

        if(arquivo == NULL){
            printf("Erro ao deletar o registro!\n");
            return 1;
        }

        aluno.id = indice;

        if(fseek(arquivo, offset, SEEK_SET) != 0){
            printf("Erro ao posicionar no arquivo (Linha inexistente).\n");
            fclose(arquivo);
            return 1;
        }

        fwrite(&aluno, sizeof(struct Aluno), 1, arquivo);

        printf("\nDados deletados com sucesso!\n");

        fclose(arquivo);

    }
    else{
        printf("\nDados não deletados!\n");
    }

    while (getchar() != '\n'); 
    getchar();

    return 0;
}

//Listra todos os registro na tela
int listar_notas(void){

    struct Aluno aluno;
    int indice, q_registros;
    long offset;

    printf("\nQual a quantidade de registros por tela? ");
    scanf("%d", &q_registros);

    printf("\e[1J\e[H");

    FILE *arquivo = fopen("alunos.dat", "rb");
    
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    //Calcula o número máximo de registros
    fseek(arquivo, 0, SEEK_END);
    long registros = ftell(arquivo) / sizeof(struct Aluno);

    printf("Quantidade de registros = %ld\n", registros);

    printf("--------------------------------------------------------------------\n");
    printf("ID |                  NOME                 | NOTA1 | NOTA2 | MEDIA |\n");
    printf("--------------------------------------------------------------------\n");

    for(indice = 1; indice <= registros; indice ++){

        offset = (indice - 1) * sizeof(struct Aluno);
        
        if(fseek(arquivo, offset, SEEK_SET) != 0){
            printf("Erro ao posicionar no arquivo (Linha inexistente).\n");
            fclose(arquivo);
            return 1;
        }

        fread(&aluno, sizeof(struct Aluno), 1, arquivo);

        aluno.nome[strcspn(aluno.nome, "\n")] = '\0';
        //printf("%03d %s %.2f %.2f %.2f\n", aluno.id, aluno.nome, aluno.nota1, aluno.nota2, aluno.media);
        printf("%03d %-40s %6.2f %6.2f %6.2f\n", aluno.id, aluno.nome, aluno.nota1, aluno.nota2, aluno.media);
    } 

    fclose(arquivo);

    printf("\nPressione qualquer tecla para continuar!\n");

    while (getchar() != '\n'); 
    getchar();

    return 0;

}