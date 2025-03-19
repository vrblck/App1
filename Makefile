# Configuración del compilador
CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude

# Directorios
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INCLUDE_DIR = include

# Archivos fuente y objetos
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
TARGET = $(BIN_DIR)/app1.exe

# Regla principal
all: directories $(TARGET)

# Crear directorios
directories:
	@mkdir "$(OBJ_DIR)" 2> NUL || exit 0
	@mkdir "$(BIN_DIR)" 2> NUL || exit 0

# Compilar ejecutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compilar archivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | directories
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	@del /Q "$(OBJ_DIR)\*.o" 2> NUL || exit 0
	@del /Q "$(TARGET)" 2> NUL || exit 0

# Ejecutar el programa
run: all
	@$(TARGET)

# Evita problemas con nombres de archivos
.PHONY: all clean run directories
