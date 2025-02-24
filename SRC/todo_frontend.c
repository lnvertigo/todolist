#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <gtk/gtk.h>

#include "../DEP/todo_backend.h"

void gtk_xml_builder(int argc, char *argv[]) {
	GtkBuilder *builder;
	GObject *window;
	GObject *task_display;
	GObject *taskname_field;
	GObject *add_task_button, *edit_task_button, *remove_task_button;
	GError *error = NULL;

	// initialize GTK
	gtk_init(&argc, &argv);

	// construct GtkBuilder instance and load XML ui description
	builder = gtk_builder_new();
	if (gtk_builder_add_from_file(builder, "./bin/builder.ui", &error) == 0) {
		g_printerr("error loading file: %s\n", error->message);
		g_clear_error(&error);
		exit(1);
	} 

	// connect signal handlers to xml-made widgets
	window = gtk_builder_get_object(builder, "window");
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	task_display = gtk_builder_get_object(builder, "task_display");
	taskname_field = gtk_builder_get_object(builder, "taskname_field");

	add_task_button = gtk_builder_get_object(builder, "add_button");
	edit_task_button = gtk_builder_get_object(builder, "edit_button");
	remove_task_button = gtk_builder_get_object(builder, "remove_button");
	g_signal_connect(add_task_button, "clicked", G_CALLBACK(button_click_dialog_test), NULL);
	g_signal_connect(edit_task_button, "clicked", G_CALLBACK(on_button_clicked), NULL);

	gtk_main();
}

int main(int argc, char *argv[]) {
	gtk_xml_builder(argc, argv);
	return 0;
}
