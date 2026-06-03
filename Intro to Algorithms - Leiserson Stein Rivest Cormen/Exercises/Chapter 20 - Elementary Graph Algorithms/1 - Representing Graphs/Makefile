CFLAGS = -Wall -ggdb -O2 -I. -std=c23 -fsanitize=address -DNDEBUG 
SRC = $(wildcard *.c)
TARGET=main

all: CFLAGS+=-DDEBUG_FILE=$(TARGET)
all: 
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

