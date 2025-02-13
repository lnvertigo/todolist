#ifndef TODO_BACKEND_H
#define TODO_BACKEND_H

#include "../DEP/todo_frontend.h"

// Callback function to handle button click
void on_button_clicked(GtkWidget *widget, gpointer data);

// storage file handlers
FILE* create_file();
FILE* open_file();
void close_file(FILE*);

// read from file
void read_file(FILE*);
void writeTasksToFile(FILE*);

#endif