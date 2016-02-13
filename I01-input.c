/*
 * Program to explore the patterns inherent within an infinite series, also
 * those between it and the bounds that are the environment within which it is
 * propagated.
 */

#include "I01-inf_series.h"

/*
 * Request and obtain user parameters.
 */

void get_parameters(int *start, int *quantity, int *divisions)
{
    char    question1[17] = "Start harmonic: ";
    char    question2[24] = "Quantity of harmonics: ";
    char    question3[24] = "Quantity of divisions: ";

    n_get_int(&(*start),     question1);
    disp_menu();
    n_get_int(&(*quantity),  question2);
    disp_menu();
    n_get_int(&(*divisions), question3);
    disp_menu();
}

/*
 * Request divisions.
 */

void get_divisions(int* divisions)
{
    char    question3[24] = "Quantity of divisions: ";

    n_get_int(&(*divisions), question3);
}

