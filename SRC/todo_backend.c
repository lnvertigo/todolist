#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../DEP/todo_frontend.h"

/* ---------------------
* # FILE HANDLING
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
int close_file(FILE* file) {
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

/* ---------------------
* # BUTTON BASE CASES
--------------------- */
void on_button_clicked(GtkWidget *widget, gpointer data) {
	g_print("Button clicked\n");
}

/* ---------------------
* # BUTTON FUNCTIONALITY 
--------------------- */
// Callback function to handle button click
// TODO - rework into using gtk_list_box(?)

void on_button_clicked_addtask(GtkWidget *widget, gpointer data) {
	// get the button label
	const char* label = gtk_button_get_label(GTK_BUTTON(widget));

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
		const char* task = gtk_entry_get_text(GTK_ENTRY(entry));
		// add task to list
		add_task(task);
	}
	gtk_widget_destroy(dialog);
}

/* ## REMOVE TASK */
void on_button_clicked_removetask(GtkWidget *widget, gpointer data) {
	// get the button label
	const gchar* label = gtk_button_get_label(GTK_BUTTON(widget));

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
		//remove_task(task);
	}
	gtk_widget_destroy(dialog);
}

/* ## EDIT TASK */
void on_button_clicked_edittask(GtkWidget *widget, gpointer data) {
	// get the button label
	const gchar* label = gtk_button_get_label(GTK_BUTTON(widget));

	// open dialog
	GtkWidget* dialog = gtk_dialog_new_with_buttons("Edit Task", GTK_WINDOW(data), GTK_DIALOG_MODAL, "_Cancel", GTK_RESPONSE_CANCEL, "_Edit", GTK_RESPONSE_ACCEPT, NULL);
	GtkWidget* content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
}

/* ## BUTTON HELPERS */
void add_task(char* task) {}

/* 
* TEST AREA
*/
void button_click_dialog_test(GtkWidget *widget, gpointer data) {
	// get button label - eg "add_button"
	const char* label = gtk_button_get_label(GTK_BUTTON(widget));

	// dialog - "modal dialog" w/ _Add button and _Cancel button
	GtkWidget* dialog = gtk_dialog_new_with_buttons("Add Task", GTK_WINDOW(data), \
	GTK_DIALOG_MODAL, "_Cancel", \
	GTK_RESPONSE_CANCEL, "_Submit", GTK_RESPONSE_ACCEPT, NULL);

	// access to dialog/content_area (window space)
	GtkWidget* content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
	// create text entry widget
	GtkWidget* entry = gtk_entry_new();
	// add text entry widget to dialog/content_area
	gtk_container_add(GTK_CONTAINER(content_area), entry);
	// display dialog (with txt entry and buttons)
	gtk_widget_show_all(dialog);

	// run dialog
	gint response = gtk_dialog_run(GTK_DIALOG(dialog));
	// wait for response
	if (response == GTK_RESPONSE_ACCEPT) {
		// get task from text entry
		const char* task = gtk_entry_get_text(GTK_ENTRY(entry));
		// add task to list
		strncat(task, "\n", 2);
		g_print(task);
	}
	// free() for dialog
	gtk_widget_destroy(dialog);
}