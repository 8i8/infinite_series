/*
 ============================================================================
 Name        : I01-output.c
 Author      : Iain Hill
 Version     : 1
 Copyright   : GPL

 Description : Exploring the patterns inherent within the harmonic series
		through the following expansion:

 		x(1/x) + x(1/2x) + x(1/3x) ... x(1/nx)

    Copyright (C) 2017 Iain Hill. 

 ============================================================================
 */

/*
 * Generate output to display calculations iterations in the terminal.
 */

#include <ncurses.h>
#include "I01-inf_series.h"

#define WIDE   80               /* With of calc output for the pad */

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
    make_pad(quantity);
    n_print_harmonics(harm_series, quantity);
}

/*
 * Output full calculated data struct.
 */

void print_data(calc* divisions, int* quantity, int* divs)
{
    int     length = 1 + (*quantity) * (*divs);

    make_pad(&length);
    n_print_calc(divisions, &qua, &div);
}

