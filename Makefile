CC = gcc

SRC_DIR = SRC
OBJ_DIR = OBJ
DEP_DIR = DEP
BIN_DIR = bin

SRCS = $(wildcard $(SRC_DIR)/*.c)
# SRCS = $(SRC_DIR)/*.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
# OBJS = $(patsubst $(SRC_DIR)/%, $(OBJS_DIR)/%, $(SRCS:.c=.o))
DEPS = $(wildcard $(DEP_DIR)/*.h)
XMLS = builder.ui

CFLAGS = -Wall -g -I/$(DEP_DIR) -DGDK_DISABLE_DEPRECATED -DGTK_DISABLE_DEPRECATED -MMD -MP
LDLIBS = `pkg-config --cflags --libs gtk+-3.0`
# LDLIBS = $(shell pkg-config --libs gtk+-3.0)

# default target
all: $(BIN_DIR)/todolist $(BIN_DIR)/$(XMLS)

# linking the final binary
$(BIN_DIR)/todolist: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDLIBS) 

# copy xml into bin
$(BIN_DIR)/$(XMLS): $(SRC_DIR)/$(XMLS)
	cp $(SRC_DIR)/$(XMLS) $(BIN_DIR)/$(XMLS)

# rule to compile src files > obj files in dir
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(DEP_DIR) $(LDLIBS) -c $< -o $@

# create OBJ_DIR if doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	-rm -f $(BIN_DIR)/*
	-rm -f $(OBJ_DIR)/*
