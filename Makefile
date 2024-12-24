# Variáveis para o compilador e as opções de compilação
CC = gcc
CFLAGS = -Wall -g -Iinclude

# Nome do arquivo executável e caminhos de diretórios
EXECUTABLE = ap5.out
EXEC_PATH = bin/$(EXECUTABLE)
OBJ_PATH = obj
SRC_PATH = src
INC_PATH = include

# Arquivos de código-fonte e objetos
SOURCES = $(wildcard $(SRC_PATH)/*.c)
OBJECTS = $(patsubst $(SRC_PATH)/%.c, $(OBJ_PATH)/%.o, $(SOURCES))

# A primeira regra é a que será executada quando não se especifica uma regra
all: $(EXEC_PATH)

# Como construir o executável final
$(EXEC_PATH): $(OBJECTS)
	@mkdir -p bin
	$(CC) $(OBJECTS) -o $@

# Como construir cada arquivo objeto
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar os arquivos compilados
clean:
	rm -rf $(OBJ_PATH) bin

# Regra para executar o programa
run: $(EXEC_PATH)
	./$(EXEC_PATH)

test:
	@echo "Running all tests:"
	@./bin/ap3.out all 1
	@./bin/ap3.out all 2
	@./bin/ap3.out all 3
	@./bin/ap3.out all 4
	@./bin/ap3.out all 5
	@./bin/ap3.out all 6
	@./bin/ap3.out all 7
	@./bin/ap3.out all 8
	@./bin/ap3.out all 9
	@./bin/ap3.out all 10
	@./bin/ap3.out all 11
	@./bin/ap3.out all 12
	@./bin/ap3.out all 13
	@./bin/ap3.out all 14
	@./bin/ap3.out all 15
	@./bin/ap3.out all 16
	@./bin/ap3.out all 17
	@./bin/ap3.out all 18
	@./bin/ap3.out all 19
	@./bin/ap3.out all 20