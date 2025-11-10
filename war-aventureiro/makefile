# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Arquivos fonte e objeto
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
TARGET = $(BIN_DIR)/war_aventureiro

# Regra principal
all: $(TARGET)

# Linkar o executável
$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CC) $(OBJECTS) -o $@

# Compilar arquivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Criar diretórios
$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

# Limpar build
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Instalar (copiar para /usr/local/bin)
install: $(TARGET)
	cp $(TARGET) /usr/local/bin/war_aventureiro

# Desinstalar
uninstall:
	rm -f /usr/local/bin/war_aventureiro

.PHONY: all clean install uninstall