/*
 * Separation of ncurses from program body.
 */

#include <ncurses.h>
#include "I01-inf_series.h"

/*--------------------------------------------------------------------------*
 * Program functionality
 *--------------------------------------------------------------------------*/

/*
 * Initialise screen.
 */

void init_scr()
{
    initscr();
}

/*
 * Display memory allocation failure.
 */

void mem_error()
{
    printw("Memory allocation error ...");
}

/*
 * Close ncurses window.
 */

void close_scr()
{
    endwin();
}

/*--------------------------------------------------------------------------*
 * Input
 *--------------------------------------------------------------------------*/

void n_get_int(int* number, char string[])
{
    disp_menu();
    printw("%s", string);
    scanw("%d", &(*number));
    clear();
}

/*--------------------------------------------------------------------------*
 * Output
 *--------------------------------------------------------------------------*/

/*
 * graphic_bar()
 *
 * Does what it says.
 */

void graphic_bar()
{
    printw("===============================================================================\n");
    refresh();
}

/*
 * Output harmonic array, used in testing.
 */

void n_print_harmonics(harmonic* harm_series, int* quantity)
{
    int     i;

    for (i = 1; i <= (*quantity); i++)
    {
        printw("From the print function %2d >>> %.16f\n", harm_series[i].id,
                                                          harm_series[i].value);
    refresh();
    }
}

/*
 * Output full calculated data struct.
 */

void n_print_data(calc* divisions, int* quantity, int* divs)
{
    int     i;

    disp_menu();

    for (i = 1; i < (((*quantity)-1) * (*divs) + 1); i++)
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

