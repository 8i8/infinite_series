/* ==========================================================================
   Name        : I01-inf_series.h
   Author      : Iain Hill
   Version     : 1
   Copyright   : GPL

   Description : Exploring the patterns inherent within the harmonic series
          	through the following expansion:

   		x(1/x) + x(1/2x) + x(1/3x) ... x(1/nx)

      Copyright (C) 2017 Iain Hill. 

      This program is free software: you can redistribute it and/or modify
      it under the terms of the GNU General Public License as published by
      the Free Software Foundation, either version 3 of the License, or
      (at your option) any later version.

      This program is distributed in the hope that it will be useful,
      but WITHOUT ANY WARRANTY; without even the implied warranty of
      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
      GNU General Public License for more details.

      You should have received a copy of the GNU General Public License
      along with this program.  If not, see <http://www.gnu.org/licenses/>.

 ============================================================================ */
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
    long double value;
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
    long double value;

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

void get_start(int*);
void get_quantity(int*);
void get_divisions(int*);

/* IO.ncurses */

void init_scr();
void get_screen_details();
void mem_error();
void clear_pad();
void clear_win();
void close_curses();
WINDOW* new_window(int, int, int, int);
WINDOW* new_sub_window(WINDOW*, int, int, int, int);
WINDOW* new_pad(int, int);
void make_pad(int*);
void menu_window();
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

