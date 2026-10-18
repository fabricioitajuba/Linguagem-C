/*--------------------------------------------------
 * Ex10 - Cadastro de notas
 * Autor: Fabrício Ribeiro
 * Para compilar: make
 * Para limpar: make clean
 *--------------------------------------------------*/
#include <stdio.h>

#define nome_len 41 //40 string + 1 "\0"

int verifica_arquivo(void);
int insere_notas(void);
int consulta_notas(void);

struct Aluno{
    int id;
    char nome[nome_len];
    float nota1, nota2, media;
};

//Programa principal
int main(){

    verifica_arquivo();
    insere_notas();
    consulta_notas();
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

    printf("Digite o nome: ");   
    fgets(aluno.nome, nome_len, stdin);

    printf("Digite a nota 1: ");   
    scanf("%f", &aluno.nota1);

    printf("Digite a nota 2: ");   
    scanf("%f", &aluno.nota2);

    aluno.media = (aluno.nota1*2 + aluno.nota2*3) / 5;

    printf("O valor da média é: %.2f ", aluno.media);

    FILE *arquivo;

    arquivo = fopen("alunos.dat", "ab");

    if(arquivo == NULL){
        printf("Erro ao criar o arquivo!\n");
        return 1;
    }

    //Calcula o id com base no tamanho do arquivo
    aluno.id = (ftell(arquivo) / sizeof(struct Aluno)) + 1;

    fwrite(&aluno, sizeof(struct Aluno), 1, arquivo);

    printf("\nDados inseridos com sucesso!\n");

    fclose(arquivo);

}

//Função para consultar registros
int consulta_notas(void){

    struct Aluno aluno;
    int indice;

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