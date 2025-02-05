// chatgpt gtk example
#include <gtk/gtk.h>
// #include <todo_backend.h>

// Callback function to handle button click
static void on_button_clicked(GtkWidget *widget, gpointer data) {
	g_print("Button clicked\n");
}

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

void gtk_xml_builder(int argc, char *argv[]) {
	GtkBuilder *builder;
	GObject *window;
	GObject *taskname_field;
	GObject *submit_button;
	GError *error = NULL;

	// initialize GTK
	gtk_init(&argc, &argv);

	// construct GtkBuilder instance and load XML ui description
	builder = gtk_builder_new();
	if (gtk_builder_add_from_file(builder, "./CORE/builder.ui", &error) == 0) {
		g_printerr("error loading file: %s\n", error->message);
		g_clear_error(&error);
		exit(1);
	} 

	// connect signal handlers to xml-made widgets
	window = gtk_builder_get_object(builder, "window");
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	taskname_field = gtk_builder_get_object(builder, "taskname_field");

	submit_button = gtk_builder_get_object(builder, "submit_button");
	g_signal_connect(submit_button, "clicked", G_CALLBACK(on_button_clicked), NULL);

	gtk_main();
}

int main(int argc, char *argv[]) {
	gtk_xml_builder(argc, argv);
	return 0;
}
