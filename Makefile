# Makefile

CC = gcc
CFLAGS = -Wall -std=c99
LDFLAGS =
LIBS = -lm

LIB_NAME = libstatslib.a
SRC = statslib.c
OBJ = $(SRC:.c=.o)

all: main

main: main.o $(LIB_NAME)
	$(CC) $(CFLAGS) -o main main.o -L. -lstatslib $(LIBS)

$(LIB_NAME): $(OBJ)
	ar rcs $(LIB_NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(LIB_NAME) main
