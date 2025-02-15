#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../DEP/todo_frontend.h"

/* ---------------------
* BUTTON FUNCTIONALITY 
--------------------- */
// Callback function to handle button click
// TODO - rework into using gtk_list_box(?)
void on_button_clicked_addtask(GtkWidget *widget, gpointer data) {
	// get the button label
	const gchar* label = gtk_button_get_label(GTK_BUTTON(widget));

	// if button is "Add Task", open dialog to add task
	if (strcmp(label, "Add Task") == 0) {
		// open dialog
		GtkWidget* dialog = gtk_dialog_new_with_buttons("Add Task", GTK_WINDOW(data), GTK_DIALOG_MODAL, "_Cancel", GTK_RESPONSE_CANCEL, "_Add", GTK_RESPONSE_ACCEPT, NULL);
		GtkWidget* content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
		GtkWidget* entry = gtk_entry_new();
		gtk_container_add(GTK_CONTAINER(content_area), entry);
		gtk_widget_show_all(dialog);

		// run dialog
		gint response = gtk_dialog_run(GTK_DIALOG(dialog));
		if (response == GTK_RESPONSE_ACCEPT) {
			// get task from entry
			const gchar* task = gtk_entry_get_text(GTK_ENTRY(entry));
			// add task to list
			add_task(task);
		}
		gtk_widget_destroy(dialog);
	}
}

void on_button_clicked_removetask(GtkWidget *widget, gpointer data) {
	// get the button label
	const gchar* label = gtk_button_get_label(GTK_BUTTON(widget));
	// if button is "Remove Task", open dialog to remove task
	else if (strcmp(label, "Remove Task") == 0) {
		// open dialog
		GtkWidget* dialog = gtk_dialog_new_with_buttons("Remove Task", GTK_WINDOW(data), GTK_DIALOG_MODAL, "_Cancel", GTK_RESPONSE_CANCEL, "_Remove", GTK_RESPONSE_ACCEPT, NULL);
		GtkWidget* content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
		GtkWidget* entry = gtk_entry_new();
		gtk_container_add(GTK_CONTAINER(content_area), entry);
		gtk_widget_show_all(dialog);

		// run dialog
		gint response = gtk_dialog_run(GTK_DIALOG(dialog));
		if (response == GTK_RESPONSE_ACCEPT) {
			// get task from entry
			const gchar* task = gtk_entry_get_text(GTK_ENTRY(entry));
			// remove task from list
			remove_task(task);
		}
		gtk_widget_destroy(dialog);
	}
}
void on_button_clicked_edittask(GtkWidget *widget, gpointer data) {
	// get the button label
	const gchar* label = gtk_button_get_label(GTK_BUTTON(widget));
	// if button is "Edit Task", open dialog to edit task
	else if (strcmp(label, "Edit Task") == 0) {
		// open dialog
		GtkWidget* dialog = gtk_dialog_new_with_buttons("Edit Task", GTK_WINDOW(data), GTK_DIALOG_MODAL, "_Cancel", GTK_RESPONSE_CANCEL, "_Edit", GTK_RESPONSE_ACCEPT, NULL);
		GtkWidget* content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
		GtkWidget
}

/* ---------------------
* FILE HANDLING
--------------------- */
// creates filepath to ~/.todo
char* get_file_path() {
	char* homedir = getenv("HOME");
	if (homedir == NULL) {
		perror("getenv fail");
		exit(1);
	}
	char* filename = "/.todo";

	size_t homelen = strlen(homedir);
	size_t filelen = strlen(filename);
	size_t len = homelen + filelen + 1;

	char* path = malloc(len);
	if (path == NULL) {
		perror("malloc");
		exit(1);
	}

	strncat(path, homedir, homelen);
	strncat(path, filename, filelen);

	return path;
}

// open storage file for program while running
FILE* open_file() {
	char* path = get_file_path();

	FILE* file = fopen(path, "a+");
	if (file == NULL) {
		free(path);
		exit(1);
	}

	free(path);
	return file;
}

// close file when naturally closed AND killed
void close_file(FILE* file) {
	if (fclose(file) == EOF) {
		perror("fclose");
		return 1;
	}
	return 0;
}

// read all existing tasks from file and display previously stored tasks
void read_file_alltasks(FILE* file) {}

// read specified task from file and display task
void read_file_task(FILE* file, char* task_key) {}

// read task from form in gtk and write to file
void write_file_task(FILE* file) {}