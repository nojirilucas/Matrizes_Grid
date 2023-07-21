CC = gcc
CFLAGS = -Wall -Wextra

# Lista de arquivos objeto
OBJS = grafo.o estrategia1.o estrategia2.o main.o

# Nome do arquivo executável
TARGET = tp2

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

grafo.o: grafo.c grafo.h
	$(CC) $(CFLAGS) -c grafo.c

estrategia1.o: estrategia1.c estrategia1.h grafo.h
	$(CC) $(CFLAGS) -c estrategia1.c

estrategia2.o: estrategia2.c estrategia2.h grafo.h
	$(CC) $(CFLAGS) -c estrategia2.c

main.o: main.c grafo.h estrategia1.h estrategia2.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f $(OBJS) $(TARGET)
