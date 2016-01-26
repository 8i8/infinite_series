/*
 * Data structures and memory allocation for program data.
 */

#include <stdio.h>
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
        printf("Memory allocation error");
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
        printf("Memory allocation error");
        exit(1);
    }
    return _new;
}

/*
 * free memory.
 */

void free_memory(void *data)
{
    free(data);
}
