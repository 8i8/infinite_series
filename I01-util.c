/*
 * Program tools, not required for running the program.
 */

#include <stdio.h>
#include <stdlib.h>
#include "I01-inf_series.h"

void graphic_bar()
{
    printf("\n");
    printf("===============================================================================\n");
    printf("\n");
}

/*
 * Pause()
 *
 * A function used for testing the code.
 */

void pause()
{
    printf("Paused ...");
    fflush(stdin);
    getchar();
    /*
     * Flakey, yes very flakey; will worry about this later ...
     */
    getchar();
}
