/*--------------------------------------------------
 * Ex08 - Servidor HTTP em C
 * Autor: Fabrício Ribeiro
 * Para compilar: make
 * Para limpar: make clean
 * Para executar: ./Ex08
 *--------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORTA 8080

int main() {
    int servidor_fd, novo_socket;
    struct sockaddr_in endereco;
    int opt = 1;
    int addrlen = sizeof(endereco);

    // 1. Resposta HTTP padrão que será enviada ao navegador
    char *resposta_http = 
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html; charset=UTF-8\r\n"
        "Connection: close\r\n"
        "\r\n"
        "<!DOCTYPE html>"
        "<html><head><title>Servidor C</title></head>"
        "<body><h1>Servidor HTTP Funcional em C no Linux!</h1>"
        "<p>Resposta gerada direto da memoria.</p></body></html>";

    // 2. Criando o descritor do socket (IPv4, TCP)
    if ((servidor_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Falha ao criar o socket");
        exit(EXIT_FAILURE);
    }

    // Previne erros de "Porta já em uso" ao reiniciar o servidor
    setsockopt(servidor_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // Configurando o IP e a Porta
    endereco.sin_family = AF_INET;
    endereco.sin_addr.s_addr = INADDR_ANY; // Aceita conexões de qualquer IP
    endereco.sin_port = htons(PORTA);

    // 3. Vinculando o socket à porta 8080 (Bind)
    if (bind(servidor_fd, (struct sockaddr *)&endereco, sizeof(endereco)) < 0) {
        perror("Falha no bind");
        exit(EXIT_FAILURE);
    }

    // 4. Colocando o servidor em modo de escuta (Listen)
    if (listen(servidor_fd, 10) < 0) {
        perror("Falha no listen");
        exit(EXIT_FAILURE);
    }

    printf("Servidor HTTP rodando na porta %d...\n", PORTA);
    printf("Abra no seu navegador: http://localhost:%d\n", PORTA);

    // 5. Loop infinito para aceitar as conexões dos clientes (Navegadores)
    while(1) {
        if ((novo_socket = accept(servidor_fd, (struct sockaddr *)&endereco, (socklen_t*)&addrlen)) < 0) {
            perror("Falha ao aceitar conexao");
            exit(EXIT_FAILURE);
        }

        // Buffer para ler a requisição do navegador (Request)
        char buffer[1024] = {0};
        read(novo_socket, buffer, 1024);
        
        // (Opcional) Printa no terminal o que o navegador pediu
        printf("\n--- Nova Requisicao Extraida ---\n%s\n", buffer);

        // 6. Envia a resposta HTTP de volta para o navegador
        write(novo_socket, resposta_http, strlen(resposta_http));
        
        // Fecha a conexão com este cliente específico
        close(novo_socket);
    }

    // Fecha o socket principal (nunca será alcançado neste loop)
    close(servidor_fd);
    return 0;
}

