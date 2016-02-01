/*
 * Generate output to display calculations itterations in the terminal.
 */

#include <ncurses.h>
#include "I01-inf_series.h"

static int  start;
static int  quantity;
static int  divisions;

/*
 * Remove variable offset for display.
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
    printw("                    x(1/x) + x(1/2x) + x(1/3x) ... x(1/nx)\n");
    printw("\n");
    printw("Please choose an option:\n");
    printw("    1). Set paramiters start and length of calc.\n");
    printw("    2). Set number of divisions.\n");
    printw("    3). Print to screen.\n");
    printw("    4). Exit.");
    printw("                                    sta = %d qua = %d div = %d\n",  
                                                                              start, 
                                                                              quantity,
                                                                              divisions);
    graphic_bar();
    refresh();
}

/*
 * Output harmonic array, used in testing.
 */

void print_harmonics(harmonic* harm_series, int* quantity)
{
    n_print_harmonics(harm_series, quantity);
}

/*
 * Output full calculated data struct.
 */

void print_data(calc* divisions, int* quantity, int* divs)
{
    n_print_data(divisions, quantity, divs);
}

