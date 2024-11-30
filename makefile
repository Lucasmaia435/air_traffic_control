# Nome do executável
TARGET = main

# Compilador
CC = gcc

# Opções de compilação
CFLAGS = -Wall -std=c11

# Arquivos de objeto
OBJS = main.o funcs.o

# Regra padrão para compilar o projeto
all: $(TARGET)

# Regra para gerar o executável
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) -lm

# Regra para compilar o main.c
main.o: main.c funcs.h definitions.h
	$(CC) $(CFLAGS) -c main.c

# Regra para compilar o funcs.c
funcs.o: funcs.c funcs.h definitions.h
	$(CC) $(CFLAGS) -c funcs.c

# Regra para limpar os arquivos gerados
clean:
	rm -f $(OBJS) $(TARGET)