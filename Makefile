CC = gcc
CFLAGS = -Wall
OBJ = main.o usuario.o mensagem.o pedido.o

all: programa

programa: $(OBJ)
	$(CC) $(CFLAGS) -o programa $(OBJ)

main.o: main.c usuario.h mensagem.h pedido.h
	$(CC) $(CFLAGS) -c main.c

usuario.o: usuario.c usuario.h
	$(CC) $(CFLAGS) -c usuario.c

mensagem.o: mensagem.c mensagem.h usuario.h
	$(CC) $(CFLAGS) -c mensagem.c

pedido.o: pedido.c pedido.h usuario.h
	$(CC) $(CFLAGS) -c pedido.c

clean:
	rm -f *.o programa
