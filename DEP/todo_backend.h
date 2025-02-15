#ifndef TODO_BACKEND_H
#define TODO_BACKEND_H

#include "../DEP/todo_frontend.h"

// Callback function to handle button click
void on_button_clicked(GtkWidget *widget, gpointer data);

// storage file handlers
char* get_file_path();
FILE* open_file();
void close_file(FILE*);

// read/write from file
void read_file_alltasks(FILE*);
void read_file_task(FILE*, char*);
void write_file_task(FILE*);

#endif