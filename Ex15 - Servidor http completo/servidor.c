#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 8192

// CORREÇÃO: Adicionado "Connection: close" nos cabeçalhos para evitar o travamento
void enviar_html(int client_socket) {
    FILE *html_file = fopen("index.html", "r");
    if (html_file == NULL) {
        char *erro = "HTTP/1.1 404 Not Found\r\n"
                     "Connection: close\r\n"
                     "Content-Type: text/plain\r\n\r\n"
                     "Arquivo index.html nao encontrado.";
        send(client_socket, erro, strlen(erro), 0);
        return;
    }

    // Informa explicitamente ao navegador para fechar a conexão após receber esta página
    char *header = "HTTP/1.1 200 OK\r\n"
                   "Connection: close\r\n"
                   "Content-Type: text/html; charset=utf-8\r\n\r\n";
    send(client_socket, header, strlen(header), 0);

    char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), html_file)) > 0) {
        send(client_socket, buffer, bytes_read, 0);
    }

    fclose(html_file);
}

void salvar_dados_post(char *requisicao) {
    char *corpo = strstr(requisicao, "\r\n\r\n");
    if (corpo != NULL) {
        corpo += 4; 

        if (strlen(corpo) > 0) {
            FILE *txt_file = fopen("dados.txt", "a"); 
            if (txt_file != NULL) {
                fprintf(txt_file, "Dados recebidos: %s\n-----------------------\n", corpo);
                fclose(txt_file);
                printf("[SUCESSO] Dados adicionados em dados.txt: %s\n", corpo);
            }
        }
    }
}

int main() {
    int server_fd, client_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Falha ao criar o socket");
        exit(EXIT_FAILURE);
    }

    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Falha no bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 10) < 0) {
        perror("Falha no listen");
        exit(EXIT_FAILURE);
    }

    printf("Servidor HTTP corrigido rodando na porta %d...\n", PORT);
    printf("Abra no seu navegador: http://localhost:%d\n\n", PORT);

    while (1) {
        if ((client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Falha ao aceitar conexao");
            continue;
        }

        memset(buffer, 0, BUFFER_SIZE);
        read(client_socket, buffer, BUFFER_SIZE);

        if (strncmp(buffer, "GET", 3) == 0) {
            enviar_html(client_socket);
        } 
        else if (strncmp(buffer, "POST", 4) == 0) {
            salvar_dados_post(buffer);

            // CORREÇÃO: Resposta do POST também incluindo "Connection: close"
            char *resposta_post = "HTTP/1.1 200 OK\r\n"
                                  "Connection: close\r\n"
                                  "Content-Type: text/html; charset=utf-8\r\n\r\n"
                                  "<h3>Dados enviados com sucesso!</h3><a href='/'>Voltar</a>";
            send(client_socket, resposta_post, strlen(resposta_post), 0);
        }

        // CORREÇÃO: Força o encerramento do envio/recepção antes de fechar o descritor
        shutdown(client_socket, SHUT_RDWR);
        close(client_socket);
    }

    close(server_fd);
    return 0;
}
