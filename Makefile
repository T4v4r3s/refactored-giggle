# Nome do compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -Wno-unused-result -Wuninitialized

# Objetos
OBJ = main.o msg.o usuario.o

# Nome do executável
TARGET = programa

# Regras
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

main.o: main.c msg.h usuario.h
	$(CC) $(CFLAGS) -c main.c

msg.o: msg.c msg.h
	$(CC) $(CFLAGS) -c msg.c

usuario.o: usuario.c usuario.h
	$(CC) $(CFLAGS) -c usuario.c

# Limpeza
clean:
	rm -f $(OBJ) $(TARGET)
