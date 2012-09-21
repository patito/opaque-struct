CC      := gcc

CFLAGS  := -W -Wall -Werror -I./src/
#LDFLAGS := $(GLIB_LDFLAGS)

BIN     := bin/calculator

SRC := src/main.c src/calculator.c
OBJ := $(patsubst %.c,%.o,$(SRC))

%.o: %.c
		$(CC) $(CFLAGS) -o $@ -c $<

all: $(OBJ)
		$(CC) $(CFLAGS) -o $(BIN) $(OBJ)

clean:
		$(RM) $(BIN) $(OBJ) *.o $(LIB)
