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

int main (int argc, char *argv[])
{
    harmonic*   data_1;
    calc*       data_2;

    int         start       = 0,
                quantity    = 0,
                divisions   = 0,
                choice;

    /*
     * Program header request increments and other data.
     */

    init_scr();

    for (;;)
    {

        get_choice(&choice);

        switch (choice)
        {
            case 1:
                /* Get parameters */
                get_parameters(&start, &quantity, &divisions);
                off_set_param(&start, &quantity);
                show_var(&start, &quantity, &divisions);
                /* Generate the initial harmonics array. */
                data_1 = gen_data_1(&start, &quantity);
                /* Generate the subdivisions of each harmonic. */
                data_2 = gen_data_2(data_1, &quantity, & divisions);
                print_data(data_2, quantity, divisions);
                break;
            case 2:
                /* Request divisions */
                get_divisions(&divisions);
                show_var(&start, &quantity, &divisions);

                if (start > 0 && quantity > 0)
                {
                    data_2 = gen_data_2(data_1, &quantity, & divisions);
                    print_data(data_2, quantity, divisions);
                }
                break;
            case 3:
                if (start > 0 && quantity > 0 && divisions > 0)
                {
                    /* Generate the initial harmonics array. */
                    data_1 = gen_data_1(&start, &quantity);
                    /* Generate the subdivisions of each harmonic. */
                    data_2 = gen_data_2(data_1, &quantity, & divisions);
                    /* Print to screen. */
                    print_data(data_2, quantity, divisions);
                }
                break;
            case 4:
                break;
            default:
                continue;
        }

        if (choice == 4)
            break;

    }

    if (quantity != 0)
    {
        free_memory(data_1);
        free_memory(data_2);
    }

    return 0;

}
