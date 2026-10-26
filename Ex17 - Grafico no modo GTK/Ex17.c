/*--------------------------------------------------
 * Ex17 - Modo gráfico usando GTK
 * Autor: Fabrício Ribeiro
 * Para compilar: make
 * Para limpar: make clean
 *--------------------------------------------------*/

#include <gtk/gtk.h>

// Função callback que será chamada quando o botão for clicado
static void on_button_clicked(GtkWidget *widget, gpointer data) {
    g_print("Botão clicado! Olá Mundo.\n");
}

// Função de ativação do aplicativo
static void on_app_activate(GtkApplication *app, gpointer user_data) {
    
    GtkWidget *window;
    GtkWidget *button;

    // 1. Cria a janela principal do aplicativo
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Minha Interface GTK");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);

    // 2. Cria um botão com rótulo
    button = gtk_button_new_with_label("Clique Aqui");

    // 3. Conecta o sinal de clique do botão à função de callback
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);

    // 4. Adiciona o botão dentro da janela
    gtk_window_set_child(GTK_WINDOW(window), button);

    // 5. Exibe a janela na tela
    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv) {

    GtkApplication *app;
    int status;

    // Cria uma instância do aplicativo GTK
    app = gtk_application_new("br.com.meuapp.exemplo", G_APPLICATION_DEFAULT_FLAGS);
    
    // Conecta o sinal "activate" à nossa função de inicialização
    g_signal_connect(app, "activate", G_CALLBACK(on_app_activate), NULL);

    // Executa o aplicativo
    status = g_application_run(G_APPLICATION(app), argc, argv);
    
    // Libera a memória alocada pelo app
    g_object_unref(app);

    return status;
}
