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

