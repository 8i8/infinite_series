/*
 * Generate output to display calculations itterations in the terminal.
 */

#include <ncurses.h>
#include "I01-inf_series.h"

static int  start;
static int  quantity;
static int  divisions;

/*
 * Initialise screen.
 */

void init_scr()
{
    initscr();
}

/*
 * Set current variables for display.
 */

void show_var(int *p_start, int *p_quantity, int *p_divisions)
{
    start     = *p_start + 1;
    quantity  = *p_quantity - 1;
    divisions = *p_divisions;
    refresh();
}

/*
 * Menu screen.
 */

void disp_menu()
{
    graphic_bar();
    printw("                  x(1/x) + x(1/2x) + x(1/3x) ... x(1/nx)\n");
    printw("\n");
    printw("Please choose an option:\n");
    printw("    1). Set paramiters start and length of calc.\n");
    printw("    2). Set number of divisions.\n");
    printw("    3). Print to screen.\n");
    printw("    4). Exit.");
    printw("                    sta = %d qua = %d div = %d",    start, 
                                                                quantity,
                                                                divisions);
    graphic_bar();
    refresh();
}

/*
 * graphic_bar()
 *
 * Does what it says.
 */

void graphic_bar()
{
    printw("\n");
    printw("===============================================================================\n");
    printw("\n");
    refresh();
}

/*
 * Output harmonic array, used in testing.
 */

void print_harmonics(harmonic* harm_series, int quantity)
{
    int     i;

    for (i = 1; i <= quantity; i++)
    {
        printw("From the print function %2d >>> %.16f\n", harm_series[i].id,
                                                          harm_series[i].value);
    refresh();
    }
}

/*
 * Output full calculated data struct.
 */

void print_data(calc* divisions, int quantity, int divs)
{
    int     i;

    disp_menu();

    for (i = 1; i < ((quantity-1) * divs + 1); i++)
    {
        printw("%-4d z=z+1/%-4d %4d of %d -> %.15f\n",  divisions[i].harmonic,
                                                        divisions[i].harmonic,
                                                        divisions[i].fraction,
                                                        divs,
                                                        divisions[i].value); 
    }

    refresh();
    getch();
    clear();

}

void mem_error()
{
    printw("Memory allocation error ...");
}

void close_scr()
{
    endwin();
}

