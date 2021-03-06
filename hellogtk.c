#include <gtk/gtk.h>

GtkWidget *txt;

void copy_text(GtkWidget *wid, gpointer ptr) {
  const char *input = gtk_entry_get_text(GTK_ENTRY(txt));
  gtk_label_set_text(GTK_LABEL(ptr), input);
}

void end_program(GtkWidget *wid, gpointer ptr) { gtk_main_quit(); }

void count_button(GtkWidget *wid, gpointer ptr) {
  static int count = 0;
  char buffer[30];
  ++count;
  sprintf(buffer, "Button pressed %d times", count);
  gtk_label_set_text(GTK_LABEL(ptr), buffer);
}

int main(int argc, char *argv[]) {
  gtk_init(&argc, &argv);

  GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  g_signal_connect(win, "delete_event", G_CALLBACK(end_program), NULL);

  GtkWidget *btn = gtk_button_new_with_label("Close window");
  g_signal_connect(btn, "clicked", G_CALLBACK(end_program), NULL);

  GtkWidget *lbl = gtk_label_new("My label");

  GtkWidget *btn2 = gtk_button_new_with_label("Copy button");
  g_signal_connect(btn2, "clicked", G_CALLBACK(copy_text), lbl);
  
  txt = gtk_entry_new();

  // GtkWidget *box = gtk_vbox_new(false, 5);
  // gtk_box_pack_start(GTK_BOX(box), btn2, true, true, 0);
  // gtk_box_pack_start(GTK_BOX(box), lbl, true, true, 0);
  // gtk_box_pack_start(GTK_BOX(box), btn, true, true, 0);
  // gtk_container_add(GTK_CONTAINER(win), box);

  GtkWidget *tbl = gtk_table_new(2, 2, TRUE);
  gtk_table_attach_defaults(GTK_TABLE(tbl), lbl, 0, 1, 0, 1);
  gtk_table_attach_defaults(GTK_TABLE(tbl), btn2, 1, 2, 0, 1);
  gtk_table_attach_defaults(GTK_TABLE(tbl), btn, 0, 1, 1, 2);
  gtk_table_attach_defaults(GTK_TABLE(tbl), btn, 0, 1, 1, 2);
  gtk_table_attach_defaults(GTK_TABLE(tbl), txt, 1, 2, 1, 2);
  gtk_container_add(GTK_CONTAINER(win), tbl);

  gtk_widget_show_all(win);
  gtk_main();
  return 0;
}
