/*
 * Program to explore the patterns inherent within an infinite series, also
 * those between it and the bounds that are the environment within which it is
 * propagated.
 */

#include <stdio.h>
#include <stdlib.h>
#include "I01-inf_series.h"

/*
 * Set the ball rolling ...
 */

int main (int argc, char *argv[])
{
    harmonic*   data_1;
    calc*       data_2;
    int         choice;
    int         start;
    int         quantity;
    int         divisions;

    /*
     * Program header request increment.
     */

    for (;;)
    {

        graphic_bar();
        printf("                  x(1/x) + x(1/2x) + x(1/3x) ... x(1/nx)\n");
        printf("\n");
        printf("Please choose an option:\n");
        printf("    1). Set paramiters start and length of calc.\n");
        printf("    2). Set number of divisions.\n");
        printf("    3). Run calc.\n");
        printf("    4). Exit.\n");
        graphic_bar();

        get_choice(&choice);

        switch (choice)
        {
            case 1:

                /*
                 * Get parameters.
                 */

                get_parameters(&start, &quantity, &divisions);
                off_set_param(&start, &quantity);
                break;
            case 2:
            case 3:
                /*
                 * Generate the initial harmonics array.
                 */

                data_1 = new_data_struct_1(quantity);
                data_1 = gen_harmonics(data_1, start, quantity);

                /*
                 * Generate the subdivisions of each harmonic.
                 */

                data_2 = new_data_struct_2(quantity, divisions);
                data_2 = gen_subs(data_1, data_2, quantity, divisions);
                free(data_1);

                print_data(data_2, quantity, divisions);
                free(data_2);
                break;
            case 4:
                break;
            default:
                continue;
        }

        if (choice == 4)
            break;

    }

    return 0;

}
