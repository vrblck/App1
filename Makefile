# Configuración del compilador
CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude

# Directorios
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Archivos fuente y objetos
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
TARGET = $(BIN_DIR)/app1

# Regla principal
all: directories $(TARGET)

# Crear directorios (Linux compatible)
directories:
	mkdir -p $(OBJ_DIR) $(BIN_DIR)

# Compilar ejecutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compilar archivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos generados (Linux compatible)
clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)

# Ejecutar el programa
run: all
	./$(TARGET)

# Evita problemas con nombres de archivos
.PHONY: all clean run directories