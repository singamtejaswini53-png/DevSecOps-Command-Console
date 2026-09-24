
CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude

SRC = src/main.c \
      src/input.c \
      src/parser.c \
      src/process.c \
      src/builtin.c \
      src/signals.c

TARGET = bin/devshell

FIFO_SERVER = bin/fifo_server
FIFO_CLIENT = bin/fifo_client

all: $(TARGET) $(FIFO_SERVER) $(FIFO_CLIENT)

$(TARGET):
	mkdir -p bin
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

$(FIFO_SERVER):
	mkdir -p bin
	$(CC) src/fifo_server.c -o $(FIFO_SERVER)

$(FIFO_CLIENT):
	mkdir -p bin
	$(CC) src/fifo_client.c -o $(FIFO_CLIENT)

run:
	./$(TARGET)

clean:
	rm -rf bin/*
