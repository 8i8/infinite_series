/*
 * Program to explore the patterns inherent within an infinite series, also
 * those between it and the bounds that are the environment within which it is
 * propagated.
 */

#include <ncurses.h>
#include "I01-inf_series.h"

/*
 * Retrieve choice for switch statement.
 */

void get_choice(int* choice)
{
    disp_menu();
    scanw(" %d", &(*choice));
    clear();
}

/*
 * Request and obtain user parameters.
 */

void get_parameters(int *start, int *quantity, int *divisions)
{
    disp_menu();
    printw("Start harmonic: ");
    scanw(" %d", &(*start));
    clear();
    disp_menu();
    printw("Quantity of harmonics: ");
    scanw(" %d", &(*quantity));
    clear();
    disp_menu();
    printw("Quantity of divisions: ");
    scanw(" %d", &(*divisions));
    clear();
}

/*
 * Request divisions.
 */

void get_divisions(int* divisions)
{
    disp_menu();
    printw("Quantity of divisions: ");
    scanw(" %d", &(*divisions));
    clear();
}
