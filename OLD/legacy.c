// todo_frontend.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <gtk/gtk.h>
// OLD VERSION, USE gtk_xml_builder()
void gtk_display(int argc, char *argv[]) {
	GtkWidget *window;
	GtkWidget *grid;
	GtkWidget *submit_button;
	GtkWidget *taskname_field;
	GError *error = NULL;

	// initialize GTK
	gtk_init(&argc, &argv);

	// create a new window
	// TODO look into app_window vs window
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "todolist");
	gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	// construct container packing the widgets
	grid = gtk_grid_new();
	gtk_container_add(GTK_CONTAINER(window), grid);

	// TODO create 2 text fields: task name + description
	taskname_field = gtk_entry_new();
	gtk_container_add(GTK_CONTAINER(window), taskname_field);

	// create a button + assign function to button + add button to window
	submit_button = gtk_button_new_with_label("submit");
	g_signal_connect(submit_button, "clicked", G_CALLBACK(on_button_clicked), NULL);
	gtk_container_add(GTK_CONTAINER(window), submit_button);

	// place widgets into grid by cell and fill
	gtk_grid_attach(GTK_GRID(grid), taskname_field, 0, 0, 10, 1);
	gtk_grid_attach(GTK_GRID(grid), submit_button, 0, 1, 3, 1);

	// whow all widgets in the window
	gtk_widget_show_all(window);

	// start the GTK main loop
	gtk_main();
}
