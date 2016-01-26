/*
 * Generate output to display calculations itterations in the terminal.
 */

#include <stdio.h>
#include "I01-inf_series.h"


/*
 * Output harmonic array, used in testing.
 */

void print_harmonics(harmonic* harm_series, int quantity)
{
    int     i;

    for (i = 1; i <= quantity; i++)
        printf("From the print function %2d >>> %.16f\n", harm_series[i].id,
                                                          harm_series[i].value);
}

/*
 * Output full calculated data struct.
 */

void print_data(calc* divisions, int quantity, int divs)
{
    int     i;

    for (i = 1; i < ((quantity-1) * divs + 1); i++)
    {
        printf("%-4d z=z+1/%-4d %4d of %d -> %.15f\n",  divisions[i].harmonic,
                                                        divisions[i].harmonic,
                                                        divisions[i].fraction,
                                                        divs,
                                                        divisions[i].value); 
    }
}
