#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <gtk/gtk.h>
// #include "./LIBS/todo_frontend.h"

// Callback function to handle button click
// static void on_button_clicked(GtkWidget *widget, gpointer data) {
// 	g_print("Button clicked\n");
// }

/*
// create storage file if not exists
void create_file() {
	int fd = create("./.todo", O_RDWR | O_CREAT | O_EXCL );
	if (fd == -1) {
		perror("create()");
	}
}
// open storage file for program while running
void open_file() {
	char* homedir = getenv("HOME");
	if (homedir == NULL) {
		perror("getenv fail");
		exit(1);
	}
	char* filename = "/.todo";
	size_t len = strlen(homedir) + strlen(filename) + 1;
}
// close file when naturally closed AND killed
void close_file() {}

// read existing tasks from file and display previously stored tasks
void readFile_PrintToWindow(file) {}

// read task from form in gtk and write to file
void writeTasksToFile(file) {}
*/
