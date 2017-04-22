/*
 ============================================================================
 Name        : I01-IO.ncurses.c
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

 ============================================================================
 */

/*
 * Separation of ncurses from program body.
 */

#include <ncurses.h>
#include <float.h>
#include "I01-inf_series.h"

#define PAD_WIDTH       45                         /* Pad width             */
#define NUM_OPTS(a)     (sizeof(a)/sizeof(a[0]))   /* Number of menu option */
#define MENU_Y          10                         /* Menu window height    */
#define MENU_X          80                         /* Menu window width     */

static WINDOW*  my_win;
static WINDOW*  my_pad;

static int      max_y,
                max_x,
                port_y,
                port_x,
                y = 9,                             /* Margin top of pad     */
                x = 2;                             /* Margin left of pad    */

/*--------------------------------------------------------------------------*
 * Program base functionality
 *--------------------------------------------------------------------------*/

/*
 * Initialise screen.
 */

void init_scr()
{
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    get_screen_details();
}

/*
 * Retrieve and store screen size, make offset for margin
 */

void get_screen_details()
{
    getmaxyx(stdscr, max_y, max_x);
    port_y = max_y - 1;
    port_x = max_x;
}

/*
 * Clear pad
 */

void clear_pad()
{
    clear();
    werase(my_win);
    wrefresh(my_win);
    prefresh(my_pad, 0, 0, y, x, port_y, port_x);
    refresh();
}

void clear_win()
{
    werase(my_win);
    refresh();
}

/*
 * Display memory allocation failure.
 */

void mem_error()
{
    wprintw(my_win,"Memory allocation error ...");
}

/*
 * Close ncurses window.
 */

void close_curses()
{
    werase(my_win);
    endwin();
}

/*--------------------------------------------------------------------------*
 * Menu
 *--------------------------------------------------------------------------*/

/*
 * Structure and its array to hold the name and function pointer of the menu
 * options.
 */

static struct
{
    char*   string;
    void    (*func)(void);
}
    menu_opts[] =
{
    { "Set parameters",                             get_param        },
    { "Set number of divisions.",                   change_div       },
    { "Print harmonic series.",                     echo_harmonics   },
    { "Print series with divisions.",               echo_out         },
    { "Exit.",                                      quit_prg         }
};

/*
 * Display the full menu screen, then prompt for a choice and call the
 * appropriate function.
 */

void n_disp_menu(int* sta, int* qua, int* div)
{
    int     i;

    clear_win();
    curs_set(1);
    mvwprintw(my_win, 1, 2,"x(1/x) + x(1/2x) + x(1/3x) ... x(1/nx)");

    /*
     * Display the function menu.
     */

    for (i = 0; i < NUM_OPTS(menu_opts); i++)
        mvwprintw(my_win, (i+3), 2, "%d) %s", i+1, menu_opts[i].string);

    /*
     * Display user entered variables.
     */

    mvwprintw(my_win, (i-1), 33,"              1/12 = 0.08333");
    mvwprintw(my_win, (i+0), 33,"    sta = %-4d   e = 2.71828", *sta);
    mvwprintw(my_win, (i+1), 33,"    qua = %-4d  pi = 3.14159", *qua);
    mvwprintw(my_win, (i+2), 33," div(x) = %-4d   λ = 4.66920", *div);
    wrefresh(my_win);
}

/*--------------------------------------------------------------------------*
 * Input
 *--------------------------------------------------------------------------*/

/*
 * Get menu selection.
 */

void get_choice()
{
    int     choice;

    /*
     * Loop until they enter a valid choice.
     */

    for (;;)
    {
        mvwscanw(my_win,(NUM_OPTS(menu_opts)+4), 0, "%d", &choice);
        if (choice > 0 && choice <= NUM_OPTS(menu_opts))
            break;
        wrefresh(my_win);
    }

    wrefresh(my_win);
    menu_opts[choice-1].func();

}

/*
 * Get calc integers.
 */

void n_get_int(int* number, char string[])
{
    mvwprintw(my_win, (NUM_OPTS(menu_opts)+4), 0, "%s", string);
    wscanw(my_win,"%d", &(*number));
    wrefresh(my_win);
    wclear(my_win);
}

/*--------------------------------------------------------------------------*
 * Output
 *--------------------------------------------------------------------------*/

/*
 * Output harmonic array, used in testing.
 */

void n_print_harmonics(harmonic* harm_series, int* quantity)
{
    int     i;

    clear_pad();

    for (i = 1; i <= (*quantity); i++)
    {
        mvwprintw(my_pad, i-1, 20, "%2d >>> %.18Le\n",

                                                        harm_series[i].id,
                                                        harm_series[i].value);
    }

    prefresh(my_pad, 0, 0, y, x, max_y, PAD_WIDTH);
    refresh();

}

/*
 * Output full calculated data struct.
 */

void n_print_calc(calc* divisions, int* quantity, int* divs)
{
    int     i;

    clear_pad();

    for (i = 1; i <= (*quantity) * (*divs); i++)
    {
        mvwprintw(my_pad, i-1, 0, "%-4d z=z+1/%-4d/%4d/%d -> %.18Le\n",

                                                        divisions[i].id,
                                                        divisions[i].harmonic,
                                                        divisions[i].fraction,
                                                        *divs,
                                                        divisions[i].value);
    }

    prefresh(my_pad, 0, 0, y, x, max_y, PAD_WIDTH);

}

/*--------------------------------------------------------------------------*
 * Windows and pads.
 *--------------------------------------------------------------------------*/

WINDOW* new_window(int height, int width, int y, int x)
{
    WINDOW* local_win;

    local_win = newwin(height, width, y, x);
    wrefresh(local_win);
    return local_win;
}

WINDOW* new_pad(int nlines, int ncols)
{
    WINDOW* local_pad;
    local_pad = newpad(nlines, ncols);
    return local_pad;
}

void make_pad(int* length)
{
    if (my_pad != NULL)
        delwin(my_pad);

    my_pad = newpad(*length, PAD_WIDTH);

}

void menu_window()
{
    if (my_win != NULL)
        delwin(my_win);

    my_win = new_window( MENU_Y, MENU_X, 0, 0);
}

/*
 * Scroll pad display.
 */

void scroll_pad()
{
    int     c,
            start = 0;

    curs_set(0);
    prefresh(my_pad, start, 0, y, x, port_y, PAD_WIDTH);
    noecho();

    while((c = getch()) != '1')
    {
        switch(c)
        {   case KEY_DOWN:
                prefresh(my_pad, start++, 0, y, x, port_y, PAD_WIDTH);
                break;
            case KEY_UP:
                prefresh(my_pad, start--, 0, y, x, port_y, PAD_WIDTH);
                break;
        }
    }

    clear_pad();
    delwin(my_pad);
    disp_menu();
    echo();
    get_choice();

}
