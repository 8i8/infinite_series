/*
 * Program to explore the patterns inherent within an infinite series, also
 * those between it and the bounds that are the environment within which it is
 * propagated.
 */

#include <stdio.h>
#include "I01-inf_series.h"

/*
 * Create input offset for display reasons.
 */

void off_set_param(int* start, int* quantity)
{
    start = start - 1;
    quantity = quantity + 1;
}

/*
 * Choice for switch statment.
 */

void get_choice(int* choice)
{
    scanf(" %d", &(*choice));
}

/*
 * Request and obtain user parameters.
 */

void get_parameters(int *start, int *quantity, int *divisions)
{
    printf("Start harmonic: ");
    fflush(stdin);
    scanf(" %d", &(*start));
    printf("Quantity of harmonics: ");
    fflush(stdin);
    scanf(" %d", &(*quantity));
    printf("Quantity of divisions: ");
    fflush(stdin);
    scanf(" %d", &(*divisions));
}
