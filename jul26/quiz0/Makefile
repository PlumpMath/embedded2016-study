BIN = is_aligned
OBJ = main.c

CFLAGS =  -std=gnu99 -O0

all: $(BIN)

%.o: %.c %.s
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN):
	$(CC) $(CFLAGS) $(OBJ) -o $@

clean:
	$(RM) $(BIN)
