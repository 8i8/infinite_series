/*
 * Program tools, not required for running the program.
 */

#include <stdio.h>
#include "I01-inf_series.h"

/*
 * Pause()
 *
 * Used for testing the code; also does wht it says.
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
