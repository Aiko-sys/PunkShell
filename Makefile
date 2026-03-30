CC = gcc
CFLAGS = -Wall -g -Iinclude

SRC = src/main.c src/commands.c src/exec.c src/parser.c src/utils.c src/signals.c
OBJ = $(SRC:.c=.o)

TARGET = build/pksh

RM = rm -f
MKDIR = mkdir -p

all: $(TARGET)

$(TARGET): $(OBJ)
	$(MKDIR) build
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) src/*.o $(TARGET)

.PHONY: all clean