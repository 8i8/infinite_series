/*
 * Menu options.
 */

#include "I01-inf_series.h"

static    harmonic*   data_1;
static    calc*       data_2;

static    int         start       = 0,
                      quantity    = 0,
                      divisions   = 0;

/*
 * Get parameters from user.
 */

void get_param()
{
    get_parameters(&start, &quantity, &divisions);
    off_set_param(&start, &quantity);
    show_var(&start, &quantity, &divisions);
    /* Generate the initial harmonics array. */
    data_1 = gen_data_1(&start, &quantity);
    /* Generate the subdivisions of each harmonic. */
    data_2 = gen_data_2(data_1, &quantity, & divisions);
    print_data(data_2, quantity, divisions);
}

/*
 * Change number of divisions.
 */

void change_div()
{
    get_divisions(&divisions);
    show_var(&start, &quantity, &divisions);

    if (start > 0 && quantity > 0)
    {
        data_2 = gen_data_2(data_1, &quantity, & divisions);
        print_data(data_2, quantity, divisions);
    }
}

/*
 * Echo to calc to screen.
 */

void echo_out()
{
    if (quantity > 0 && divisions > 0)
    {
        /* Generate the initial harmonics array. */
        data_1 = gen_data_1(&start, &quantity);
        /* Generate the subdivisions of each harmonic. */
        data_2 = gen_data_2(data_1, &quantity, & divisions);
        /* Print to screen. */
        print_data(data_2, quantity, divisions);
    }
}

void quit_prg()
{
    free_memory(data_1);
    free_memory(data_2);
}
