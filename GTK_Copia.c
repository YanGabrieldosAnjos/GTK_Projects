#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void  on_window_closed (GtkWidget  *Widget ,  gpointer  d) {
    gtk_main_quit  ();
}

void  on_botao_clicked(GtkWidget  *thisButton, GtkWidget  *widgets[]) {
    gchar copia[150];
	
	GtkWidget *url,*saida;

	url  = widgets[0];
	saida = widgets[1];
	
    strcpy(copia, gtk_entry_get_text(GTK_ENTRY(url)));
    gtk_entry_set_text(GTK_ENTRY(saida), copia);

}

int main(int argc, char* argv[]){
    GtkBuilder *builder;
    GtkWidget *janela,*botao;
	GtkWidget *widgets[2];
	
    gtk_init(&argc, &argv);
	
    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder,"inverte.glade",NULL);

    janela = GTK_WIDGET(gtk_builder_get_object(builder, "gtk_janela"));
    botao = GTK_WIDGET(gtk_builder_get_object(builder, "button_invert"));
    widgets[0] = GTK_WIDGET(gtk_builder_get_object(builder, "text_entry0"));
    widgets[1] = GTK_WIDGET(gtk_builder_get_object(builder, "text_entry1"));

    g_signal_connect(botao , "clicked" ,  G_CALLBACK(on_botao_clicked), widgets);

    gtk_widget_show_all(janela);
    gtk_main();

    return(0);
}
