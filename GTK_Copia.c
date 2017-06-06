#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void  on_window_closed (GtkWidget  *Widget ,  gpointer  d) {
    gtk_main_quit  ();
}

void  on_botao_clicked(GtkWidget  *thisButton, GtkWidget  *url, GtkWidget  *saida) {
    char copia[150];

    strcpy(copia, gtk_entry_get_text(GTK_ENTRY(url)));
    gtk_entry_set_text(GTK_ENTRY(saida), copia);

}

int main(int argc, char* argv[]){
    GtkBuilder *builder;
    GtkWidget *janela,*botao,*url,*saida;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder,"inverte.glade",NULL);

    janela = GTK_WIDGET(gtk_builder_get_object(builder, "gtk_janela"));
    botao = GTK_WIDGET(gtk_builder_get_object(builder, "button_invert"));
    url = GTK_WIDGET(gtk_builder_get_object(builder, "text_entry0"));
    saida = GTK_WIDGET(gtk_builder_get_object(builder, "text_entry1"));

    g_signal_connect(botao , "clicked" ,  G_CALLBACK(on_botao_clicked), NULL);

    gtk_widget_show_all(janela);
    gtk_main();

    return(0);
}
