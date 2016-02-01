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
    int     choice;

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
                get_param();
                break;
            case 2:
                change_div();
                break;
            case 3:
                echo_out();
                break;
            case 4:
                quit_prg();
                break;
            default:
                continue;
        }

        if (choice == 4)
            break;

    }

    return 0;

}
