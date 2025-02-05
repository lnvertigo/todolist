CC = gcc
SRC_DIR = CORE
SRC = $(SRC_DIR)/*.c
OBJ_DIR = OBJS
OBJ = ${SRC:.c=.o}
INC_DIR = UTIL
DEPS = $(INC_DIR)/*.h
CFLAGS = -Wall -g -I/$(INC_DIR) -DGDK_DISABLE_DEPRECATED -DGTK_DISABLE_DEPRECATED
PACKAGE = `pkg-config --cflags --libs gtk+-3.0`

all: $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c

default: build

build: $(SRC)
	gcc $(SRC) -o todolist $(CFLAGS) $(PACKAGE)

clean:
	-rm -f todolist
	-rm -f $(OBJ)
