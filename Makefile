EXE = inf_series
SRC = I01-data.base.c I01-data.calc.c I01-data.memory.c I01-IO.ncurses.c I01-input.c I01-main.c I01-output.c
OBJ = $(SRC:.c=.o)
CC  = gcc
#CFLAGS = -g
CFLAGS = -Wextra -Wall -pedantic
#CFLAGS	+= -fsanitize=address
#CFLAGS	+= -fno-omit-frame-pointer
LFLAGS = -lncurses

vpath %.c src/
vpath %.h src/

.PHONY: all clean distclean

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE) $(LFLAGS)

$(OBJ): I01-inf_series.h Makefile

clean:
	rm -f *.o

distclean: clean
	rm -f inf_series
