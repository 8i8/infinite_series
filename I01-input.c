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

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

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

