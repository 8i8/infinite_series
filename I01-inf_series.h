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

#include <ncurses.h>

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

/* data.base */

void disp_menu();
void get_param();
void change_div();
void generate_data();
void echo_harmonics();
void echo_out();
void free_all();
void quit_prg();

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

void off_set_param(int* start, int* quantity);
void get_parameters(int *start, int *quantity, int *divisions);
void get_divisions();
void close_scr();

/* output */

void disp_menu();
void print_harmonics(harmonic* harm_series, int* quantity);
void print_data(calc* divisions, int* quantity, int* divs);
void show_var(int *start, int *quantity, int *divisions);
void close_scr();

/* IO.ncurses */

void init_scr();
void close_scr();
void p_refresh();
WINDOW* new_window(int height, int width, int y, int x);
WINDOW* new_sub_window(WINDOW *orig, int height, int width, int y, int x);
WINDOW* new_pad(int nlines, int ncols);
void make_window();
void mem_error();
void get_choice();
void n_get_int(int* number, char* string);
void n_disp_menu(int* sta, int* qua, int* div);
void graphic_bar();
void n_print_data(calc* divisions, int* quantity, int* divs);
void n_print_harmonics(harmonic* harm_series, int* quantity);

