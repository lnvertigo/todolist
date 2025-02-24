#ifndef TODO_BACKEND_H
#define TODO_BACKEND_H

#include "../DEP/todo_frontend.h"

// # FILE HANDLING
char* get_file_path();
FILE* open_file();
int close_file(FILE*);

// read/write from file
void read_file_alltasks(FILE*);
void read_file_task(FILE*, char*);
void write_file_task(FILE*);

// # BUTTON BASE CASES
void on_button_clicked(GtkWidget *widget, gpointer data);

// # BUTTON FUNCTIONALITY
void on_button_clicked_addtask(GtkWidget *widget, gpointer data);
void on_button_clicked_removetask(GtkWidget *widget, gpointer data);
void on_button_clicked_edittask(GtkWidget *widget, gpointer data);

// ## BUTTON HELPERS
void add_task(gchar* task);

// # TESTS
void button_click_dialog_test(GtkWidget *widget, gpointer data);

#endif