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

void get_param();
void change_div();
void generate_data();
void echo_harmonics();
void echo_out();
void free_all();
void quit_prg();

/* data.calc */

void off_set_param(int*, int*);
harmonic* gen_harmonics(harmonic*, int, int);
calc* gen_subs(harmonic*, calc*, int, int);

/* data.memory */

harmonic* new_data_struct_1(int);
calc* new_data_struct_2(int, int);
harmonic* gen_data_1(int*, int*);
calc* gen_data_2(harmonic*, int*, int*);
void free_memory(void*);

/* input */

void get_parameters(int*, int*, int*);
void get_divisions();

/* IO.ncurses */

void init_scr();
void mem_error();
void close_curses();
WINDOW* new_window(int, int, int, int);
WINDOW* new_sub_window(WINDOW*, int, int, int, int);
WINDOW* new_pad(int, int);
void make_window(int*);
void menu_window();
void my_win_refresh();
void my_pad_refresh();
void scroll_pad();
void n_disp_menu(int*, int*, int*);
void get_choice();
void n_get_int(int*, char*);
void n_print_harmonics(harmonic*, int*);
void n_print_calc(calc*, int*, int*);

/* output */

void show_var(int*, int*, int*);
void disp_menu();
void print_harmonics(harmonic*, int*);
void print_data(calc*, int*, int*);

