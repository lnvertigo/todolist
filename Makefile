CC = gcc
SRC = todolist.c
OBJ = ${SRC:.c=.o}
CFLAGS = -Wall -g -I.
PACKAGE = `pkg-config --cflags --libs gtk+-3.0`
LIBS = `pkg-config --libs gtk+-3.0`

default: todolist

todolist: todolist.c
	gcc todolist.c -o todolist $(CFLAGS) `pkg-config --cflags --libs gtk+-3.0`

clean:
	-rm -f todolist
	-rm -f $(OBJ)
