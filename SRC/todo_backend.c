#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../DEP/todo_frontend.h"

// Callback function to handle button click
void on_button_clicked(GtkWidget *widget, gpointer data) {
	g_print("Button clicked\n");
}

// -------------------------------------
// TODO: TEST EVERY FUNC BELOW HERE
// -------------------------------------
// create storage file (if not exists)
FILE* create_file() {
	// int fd = create("./.todo", O_RDWR | O_CREAT | O_EXCL );
	FILE* fptr = fopen(".todo", "w");
	if (fptr == NULL) {
		perror("create()");
	}
}

// open storage file for program while running
FILE* open_file() {
	char* homedir = getenv("HOME");
	if (homedir == NULL) {
		perror("getenv fail");
		exit(1);
	}
	char* filename = "/.todo";
	size_t len = strlen(homedir) + strlen(filename) + 1;
}
// close file when naturally closed AND killed
void close_file(FILE* file) {}

// read existing tasks from file and display previously stored tasks
void read_file(FILE* file) {}

// read task from form in gtk and write to file
void writeTasksToFile(FILE* file) {}