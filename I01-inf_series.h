/*
 * Program to explore the patterns inherent within an infinite series, also
 * those between it and the bounds that are the environment within which it is
 * propagated.
 */

/*****************************************************************************
 *                                                                           *
 * Program structures.                                                       *
 *                                                                           *
 *****************************************************************************/

/*
 * A structure to formulate an array of harmonics.
 *
 * id = basic line number
 * value = the decimal value of the corresponding harmonic.
 */

struct harmonics
{
    int         id;
    double      value;
};

typedef struct harmonics    harmonic;

/*
 * A structure to store the values of the divisors calculated between each
 * harmonic.
 * id = the line number.
 * harmonic = the line number from the previous array, the number of the
 * harmonic.
 * division = the number of subdivisions.
 * fraction = which sub-division is the current sub-devision.
 */

struct calculation
{
    int         id;      
    int         harmonic;
    int         division;
    int         fraction;
    double      value;

};

typedef struct calculation  calc;

/*****************************************************************************
 *                                                                           *
 * Function definitions.                                                     *
 *                                                                           *
 *****************************************************************************/

/* data.calc */

harmonic* gen_harmonics(harmonic* harm_series, int start, int quantity);
calc* gen_subs(harmonic *harmonics, calc *divisions, int quantity, int divs);

/* data.memory */

harmonic* new_data_struct_1(int quant);
calc* new_data_struct_2(int quant, int divisions);
harmonic* gen_data_1(int* start, int* quantity);
calc* gen_data_2(harmonic* data_1, int* quantity, int* divisions);
void free_memory(void *data);

/* input */

void init_scr();
void off_set_param(int* start, int* quantity);
void get_choice(int* choice);
void get_parameters(int *start, int *quantity, int *divisions);
void get_divisions();

/* main */

/* output */

void disp_menu();
void print_harmonics(harmonic* harm_series, int quantity);
void print_data(calc* divisions, int quantity, int divs);
void graphic_bar();
void show_var(int *start, int *quantity, int *divisions);

