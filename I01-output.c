/*
 * Generate output to display calculations itterations in the terminal.
 */

#include <ncurses.h>
#include "I01-inf_series.h"

static int  sta = 0;
static int  qua = 0;
static int  div = 0;

/*
 * Remove variable offset for display.
 */

void show_var(int *p_start, int *p_quantity, int *p_divisions)
{

    sta = *p_start + 1;
    qua = *p_quantity - 1;
    div = *p_divisions;
    refresh();
}

/*
 * Menu screen.
 */

void disp_menu()
{
    n_disp_menu(&sta, &qua, &div);
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
    make_window(divisions, quantity, divs);
}

