#include <gtk/gtk.h>
#include <string.h>

void on_botao_activate(GtkWidget *thisButton, GtkWidget *combo_box){
  gchar var[15];
  GtkBuilder *builder;
  GtkWidget *window1,*window2;

  builder = gtk_builder_new();
  gtk_builder_add_from_file(builder,"combobox.glade", NULL);

  strcpy(var,gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(combo_box)));

  if(strcmp(var,"Janela") == 0){
    window1 = GTK_WIDGET(gtk_builder_get_object(builder, "janela1"));
    gtk_widget_show(window1);
  }

  else if(strcmp(var,"Tela") == 0){
    window2 = GTK_WIDGET(gtk_builder_get_object(builder, "janela2"));
    gtk_widget_show(window2);
  }

}

int main(int argc, char** argv){

  GtkBuilder *builder;
  GtkWidget *window;
  GtkWidget *combo_box, *botao;

  gtk_init(&argc, &argv);

  builder = gtk_builder_new();
  gtk_builder_add_from_file(builder, "combobox.glade", NULL);

  window = GTK_WIDGET(gtk_builder_get_object(builder,"gtk_abrir"));

  combo_box = GTK_WIDGET(gtk_builder_get_object(builder,"gtk_combobox"));

  botao = GTK_WIDGET(gtk_builder_get_object(builder,"gtk_botao"));
  g_signal_connect(botao,"clicked", G_CALLBACK(on_botao_activate), combo_box);

  gtk_widget_show(window);

  gtk_main();

  return 0;
}
