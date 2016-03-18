/*
 * Data calculation by way of the itteration of two loops.
 */

/*
 * #include <math.h>
 */
#include "I01-inf_series.h"

/*
 * Create input offset for display reasons.
 */

void off_set_param(int* start, int* quantity)
{
    *start    = *start    - 1;
    *quantity = *quantity + 1;
}

/*
 * Generate an array of harmonic series of the required length within the
 * required bounds.
 *
 * An offset is required from the second array; the reason being that it uses
 * the previous value to calculate the required valus for the preceding fields
 * in the
 */

harmonic* gen_harmonics(harmonic* harm_series, int start, int quantity)
{
    int         i;
    int         j;
    double      k;

    i = 1;
    k = 0;

    while ( i < start )
    {
        k = k + ((double) 1/(i));
        i++;
    }

    /*
     * Generate data for the initial harmonic array.
     */

    for (j = 1; j <= quantity; j++)
    {
        k = k + ((double)1/(i));
        harm_series[j].id        = i;
        harm_series[j].value     = k;
        i++;
    }

    return harm_series;

}

/*
 * Generate values between harmonics.
 *
 *              x(1/x) + x(1/2x) + x(1/3x) ... x(1/nx)
 *
 */

calc* gen_subs(harmonic *harmonics, calc *divisions, int quantity, int divs)
{
    int     i;
    int     j;
    int     l;
    double  k;

    l = 0;

    for (i = 1; i <= quantity; i++)
    {
        k = harmonics[i-1].value;

        if ( i != 1 )
        {
            for (j = 0; j < divs; j++)
            {
                divisions[l].id       = l;
                divisions[l].harmonic = harmonics[i].id;
                divisions[l].division = divs;
                divisions[l].fraction = j+1;
                
                
                k = (k + (double)1/(divs*(double)harmonics[i].id));
                
/*
 *              x = (double)1/divs;
 *              y = (double)harmonics[i].id;
 *              k = fma(x,y,k);
 */

                divisions[l].value = k;

                l++; 
            }
        }
        else
        {
            divisions[l].id       = l;
            divisions[l].harmonic = harmonics[i].id;
            divisions[l].division = 1;
            divisions[l].fraction = 1;
            
            divisions[l].value = harmonics[0].value;
            l++;
        }
    }

    return divisions;

}

