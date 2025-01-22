CC = gcc
SRC = main.c
OBJ = ${SRC:.c=.o}
CFLAGS = -Wall -g
PACKAGE = `pkg-config --cflags --libs gtk+-3.0`
LIBS = `pkg-config --libs gtk+-3.0`

#build: $(OBJ)
#	gcc $(CFLAGS) $(OBJ) -o app $(LIBS)

#./%.o: ./%.c
#	gcc $(CFLAGS) -c

build:
	gcc main.c -o app $(CFLAGS) `pkg-config --cflags --libs gtk+-3.0`
