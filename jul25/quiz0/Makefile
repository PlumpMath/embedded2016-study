BIN = bubblesort
OBJ = main.c bubblesort.s

CC = arm-linux-gnueabihf-gcc

CFLAGS = -Wall -Werror -std=gnu99 -O0

all: $(BIN)

%.o: %.c %.s
	$(CC) $(CFLAGS) -c $< -o $@

bubblesort:
	$(CC) -static $(CFLAGS) $(OBJ) -o $@

clean:
	$(RM) $(BIN)
