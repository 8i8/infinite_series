/*
 ============================================================================
 Name        : I01-main.c
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
 * Program to explore the patterns inherent within an infinite series, also
 * those between it and the bounds that are the environment within which it is
 * propagated.
 */

#include <stdio.h>
#include "I01-inf_series.h"

/*
 * Set the ball rolling ...
 */

int main(void)
{
    /*
     * Program header request increments and other data.
     */

    init_scr();
    menu_window();
    disp_menu();
    get_choice();
    quit_prg();

    return 0;

}

