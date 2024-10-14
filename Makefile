CC = gcc
CFLAGS = -Wall -g -Iinclude
SRC = src/main.c src/commands.c src/exec.c src/parser.c src/utils.c src/signals.c
OBJ = $(SRC:.c=.o)

ifeq ($(OS), Windows_NT)
	TARGET = build/punkshell.exe
	RM = rm -rf
    MKDIR = mkdir build
else
	TARGET = build/punkshell.exe
    RM = rm -f
    MKDIR = mkdir -p build

endif 

all: $(TARGET)

$(TARGET): $(OBJ)
	$(MKDIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
ifeq ($(OS), Windows_NT)
	$(RM) src/*.o 
	$(RM) $(TARGET)
	$(RM) build
else
	$(RM) src/*.o $(TARGET)
endif