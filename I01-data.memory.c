/*
 ============================================================================
 Name        : I01-data.memory.c
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
 * Data structures and memory allocation for program data.
 */

#include <stdlib.h>
#include "I01-inf_series.h"

/*
 * Dynamicaly allocate memory for the array of harmonics.
 */

harmonic* new_data_struct_1(int quant)
{
    harmonic* _new = malloc((quant+1) * sizeof(harmonic));
    if (_new == NULL)
    {
        mem_error();
        exit(1);
    }
    return _new;
}

/*
 * Dynamicaly allocate memory for the final data structure.
 */

calc* new_data_struct_2(int quant, int divisions)
{
    calc* _new = malloc(quant * divisions * sizeof(calc));
    if (_new == NULL)
    {
        mem_error();
        exit(1);
    }
    return _new;
}

/*
 * Generate inital harmonics array.
 */

harmonic* gen_data_1(int* start, int* quantity)
{
    harmonic* data_1;

    /* Generate the initial harmonics array. */
    data_1 = new_data_struct_1(*quantity);
    data_1 = gen_harmonics(data_1, *start, *quantity);

    return data_1;
}

/*
 * Generate array of divisions between harmonics.
 */

calc* gen_data_2(harmonic* data_1, int* quantity, int* divisions)
{
    calc* data_2;

    /* Generate the subdivisions of each harmonic. */
    data_2 = new_data_struct_2(*quantity, *divisions);
    data_2 = gen_subs(data_1, data_2, *quantity, *divisions);

    return data_2;
}

/*
 * free memory.
 */

void free_memory(void *data)
{
    if (data != NULL)
        free(data);
}

