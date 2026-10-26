/*--------------------------------------------------
 * Ex18 - Programa de soma Modo gráfico usando GTK
 * Autor: Fabrício Ribeiro
 * Para compilar: make
 * Para limpar: make clean
 *--------------------------------------------------*/

#include <gtk/gtk.h>
#include <stdlib.h>

// Estrutura para passar as caixas de texto e o rótulo para a função de soma
typedef struct {
    GtkWidget *entry1;
    GtkWidget *entry2;
    GtkWidget *label_resultado;
} ElementosSoma;

// Função chamada quando o botão é clicado
static void somar_numeros(GtkWidget *widget, gpointer data) {
    ElementosSoma *elementos = (ElementosSoma *)data;

    // Obtém o texto digitado nas caixas de entrada
    const char *texto1 = gtk_editable_get_text(GTK_EDITABLE(elementos->entry1));
    const char *texto2 = gtk_editable_get_text(GTK_EDITABLE(elementos->entry2));

    // Converte o texto para números (double para aceitar decimais)
    double num1 = atof(texto1);
    double num2 = atof(texto2);
    double resultado = num1 + num2;

    // Formata o resultado em uma string e atualiza a interface
    char resultado_texto[64];
    snprintf(resultado_texto, sizeof(resultado_texto), "Resultado: %.2f", resultado);
    gtk_label_set_text(GTK_LABEL(elementos->label_resultado), resultado_texto);
}

// Configuração da interface gráfica
static void ativar_app(GtkApplication *app, gpointer user_data) {
    // Cria a janela principal
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Somador GTK4");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    // Cria uma caixa vertical (layout) com espaçamento de 10 pixels entre os elementos
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_widget_set_margin_top(box, 20);
    gtk_widget_set_margin_bottom(box, 20);
    gtk_widget_set_margin_start(box, 20);
    gtk_widget_set_margin_end(box, 20);
    gtk_window_set_child(GTK_WINDOW(window), box);

    // Cria as caixas de entrada de texto
    GtkWidget *entry1 = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry1), "Digite o primeiro número");
    gtk_box_append(GTK_BOX(box), entry1);

    GtkWidget *entry2 = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry2), "Digite o segundo número");
    gtk_box_append(GTK_BOX(box), entry2);

    // Cria o botão de somar
    GtkWidget *button = gtk_button_new_with_label("Somar");
    gtk_box_append(GTK_BOX(box), button);

    // Cria o rótulo (label) para o resultado
    GtkWidget *label_resultado = gtk_label_new("Resultado: ");
    gtk_box_append(GTK_BOX(box), label_resultado);

    // Aloca a estrutura na memória para enviar os widgets para o callback do botão
    ElementosSoma *elementos = g_new(ElementosSoma, 1);
    elementos->entry1 = entry1;
    elementos->entry2 = entry2;
    elementos->label_resultado = label_resultado;

    // Libera a memória da estrutura quando a janela for fechada
    g_object_set_data_full(G_OBJECT(window), "elementos-dados", elementos, g_free);

    // Conecta o clique do botão à função de somar
    g_signal_connect(button, "clicked", G_CALLBACK(somar_numeros), elementos);

    // Exibe a janela
    gtk_widget_set_visible(window, TRUE);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    // Inicializa a aplicação GTK
    app = gtk_application_new("org.exemplo.somador", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(ativar_app), NULL);
    
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
