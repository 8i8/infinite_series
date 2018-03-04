/*
 ============================================================================
 Name        : I01-input.c
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

#include "I01-inf_series.h"

/*
 * Request and obtain user parameters.
 */

void get_start(int* start)
{
    char    question1[] = "Start harmonic: ";

    n_get_int(&(*start),     question1);
    disp_menu();
}

void get_quantity(int* quantity)
{
    char    question2[] = "Quantity of harmonics: ";

    n_get_int(&(*quantity),  question2);
    disp_menu();
}

void get_divisions(int* divisions)
{
    char    question3[] = "Quantity of divisions: ";

    n_get_int(&(*divisions), question3);
    disp_menu();
}

