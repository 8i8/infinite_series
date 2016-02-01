inf_series: I01-data.base.c I01-data.calc.c I01-data.memory.c I01-IO.ncurses.c I01-inf_series.h I01-input.c I01-main.c I01-output.c
	gcc -g -Wall -pedantic -o inf_series I01-data.base.c I01-data.calc.c I01-data.memory.c I01-IO.ncurses.c I01-inf_series.h I01-input.c I01-main.c I01-output.c -lncurses

