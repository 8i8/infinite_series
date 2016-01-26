/*
 * Program to explore the patterns inherent within an infinite series, also
 * those between it and the bounds that are the environment within which it is
 * propagated.
 */

#include <stdio.h>
#define MAX     100000000 /* Magic number, to be removed with malloc. */

/*
 * A structure to formulate an array for calculation results.
 */

struct calculation
{
    int         id;      
    int         harmonic;
    int         division;
    int         fraction;
    double      result;
};

typedef struct calculation  calc;

/*
 * The data.
 */

static  int     increment;
static  calc    data[MAX];

void pause()
{
    puts("Paused ...");
    fflush(stdin);
    getchar();
    getchar();
}

/*
 * Generate a list of calculations for the given number of iterations and
 * of the specified increment.
 */

void generate_data(int iteration)
{
    double  k;
    int     i;
    int     j;
    int     count;

    for (i = 0; i <= iteration; i++)
    {
        for (j = 0; j < increment; j++)
        {
            k = k + ( 1/( (double)(increment) * (double)(i+1) ) );
            data[count].result    = k;
            data[count].fraction  = increment*(i+1);
            data[count].harmonic  = i+1;
            data[count].division  = j+1;
            data[count].id        = count+1;
            count++;
        }
    }
}

/*
 * Output data.
 */

void output_data(calc *data)
{

    /*
     * Print to screen.
     */

    printf("%-4d  %2d  %3d/%-3d 1/%-4d >>> %.15f\n ", data->id
                                                    , data->harmonic
                                                    , data->division
                                                    , increment
                                                    , data->fraction
                                                    , data->result);
}

void output_loop(iteration)
{
    int     i;

    /*
     * Check the initial dataset size, fill the screen initially.
     */ 

    for (i = 0; i < iteration; i++)
        output_data(&data[i]);
}

/*
 * Set the ball rolling ...
 */

int main()
{
    int     iteration;
    int     previous = 0;

    /*
     * Program header request increment.
     */

    for (;;)
    {
        puts("");
        puts("=====================================================================================");
        if (previous)
            printf("%d", previous);
        printf("          x(1/x) + 2x(1/2x) + 3x(1/3x) ... nx(1/nx)  | ");
        printf(" x = ");
        fflush(stdin);
        scanf(" %d", &increment);
        puts("=====================================================================================");
        puts("");
        printf(" ");

        /*
         * Set initial iteration relative to the increment; looking at pi.
         */

        iteration = increment*13;

        /*
         * Run and output the calc.
         */

        generate_data(iteration);

        output_loop(iteration);

        previous = increment;
    }

    return 0;
}
