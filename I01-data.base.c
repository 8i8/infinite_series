/*
 * Menu options.
 *
 *  {"Set paramiters start and length of calc.",   get_param        },
 *  {"Set number of divisions.",                   change_div       },
 *  {"Print harmonic series.",                     echo_harmonics   },
 *  {"Print series with divisions.",               echo_out         },
 *  {"Exit.",                                      quit_prg         }
 */

#include <stdlib.h>
#include "I01-inf_series.h"

static    harmonic*   data_1;
static    calc*       data_2;

static    int         start,
                      quantity,
                      divisions;

/*
 * Get parameters from user.
 */

void get_param()
{
    get_start(&start);
    get_quantity(&quantity);
    get_divisions(&divisions);
    off_set_param(&start, &quantity);
    show_var(&start, &quantity, &divisions);
    generate_data();
    echo_out();
    get_choice();
}

/*
 * Change number of divisions.
 */

void change_div()
{
    get_divisions(&divisions);
    show_var(&start, &quantity, &divisions);

    generate_data();
    echo_out();
    get_choice();
}

/*
 * Fill data structures.
 */

void generate_data()
{
    free_all();

    /* Generate the initial harmonics array. */
    data_1 = gen_data_1(&start, &quantity);
    /* Generate the subdivisions of each harmonic. */
    data_2 = gen_data_2(data_1, &quantity, & divisions);
}

/*
 * Echo to calc to screen.
 */

void echo_harmonics()
{
    if (quantity > 0 && divisions > 0)
    {
        /* Print to screen. */
        print_harmonics(data_1, &quantity);
        disp_menu();
    }
}

void echo_out()
{
    if (quantity > 0 && divisions > 0)
    {
        /* Print to screen. */
        print_data(data_2, &quantity, &divisions);
        disp_menu();
        scroll_pad();
    }
}

void free_all()
{
    free_memory(data_1);
    free_memory(data_2);
}

void quit_prg()
{
    close_curses();
    free_all();
    exit(0);
}

