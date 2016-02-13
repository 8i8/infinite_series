/*
 * Separation of ncurses from program body.
 */

#include <ncurses.h>
#include "I01-inf_series.h"

#define Nelts(a)      (sizeof(a)/sizeof(a[0]))

static WINDOW*  my_pad;
static WINDOW*  my_sub_win;

static int      width,
                height,
                max_y,
                max_x,
                y      = 2,
                x      = 4;

/*--------------------------------------------------------------------------*
 * Program functionality
 *--------------------------------------------------------------------------*/

/*
 * Initialise screen.
 */

void init_scr()
{
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
}

/*
 * Display memory allocation failure.
 */

void mem_error()
{
    printw("Memory allocation error ...");
}

/*
 * Close ncurses window.
 */

void close_curses()
{
    clear();
    refresh();
    endwin();
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

WINDOW* new_sub_window(WINDOW *orig, int height, int width, int y, int x)
{
    WINDOW* local_win;

    local_win = subwin(orig, height, width, y, x);
    wrefresh(local_win);
    return local_win;
}

WINDOW* new_pad(int nlines, int ncols)
{
    WINDOW* local_pad;
    local_pad = newpad(nlines, ncols);
    return local_pad;
}

void make_window(calc* divisions, int* quantity, int* divs)
{
    int     nlines = (((*quantity)-1) * (*divs) + 1),
            ncols;

    clear();

    getmaxyx(stdscr, max_y, max_x);

    height = max_y - (2 * y);
    width  = max_x - (2 * x);
    ncols  = max_x;

    my_pad = newpad(nlines, ncols);
    my_sub_win = new_sub_window(my_pad, height, width, y, x);
    mvprintw(LINES - 2, 0, "Use the Up/Down arrows to scroll.\nF1 to Exit");
    refresh();
}

/*
 * Scroll pad display.
 */

void scroll_pad(WINDOW* _pad)
{
    int     c,
            start = 0;
    /*
     * Refresh pad.
     *
     * int prefresh(WINDOW *pad, int pminrow, int pmincol, int sminrow,
     *                                  int smincol, int smaxrow, int smaxcol);
     */

    prefresh(_pad, start, 0, y+1, x+1, height, width);

    while((c = getch()) != KEY_F(1))
    {   switch(c)
        {   case KEY_DOWN:
                prefresh(_pad, start++, 0, y+1, x+1, height, width);
                break;
            case KEY_UP:
                prefresh(_pad, start--, 0, y+1, x+1, height, width);
                break;
        }
    }

    delwin(my_pad);
    delwin(my_sub_win);
    clear();
    disp_menu();       
    get_choice();

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
    {"Set paramiters start and length of calc.",   get_param        },
    {"Set number of divisions.",                   change_div       },
    {"Print harmonic series.",                     echo_harmonics   },
    {"Print series with divisions.",               echo_out         },
    {"Exit.",                                                       }
};

/*
 * Display the full menu screen ONCE, then prompt for a choice and call the
 * appropriate function.
 */

void n_disp_menu(int* sta, int* qua, int* div)
{
    int     i;

    printw("===============================================================================\n");
    printw("                    x(1/x) + x(1/2x) + x(1/3x) ... x(1/nx)\n");
    printw("\n");
    printw("Please choose an option:\n");

    /*
     * Display the menu.
     */

    for (i = 0; i < Nelts(menu_opts); i++)
        printw("    %2d). %s\n", i+1, menu_opts[i].string);

    printw("                                   sta = %d qua = %d div = %d\n", *sta, *qua, *div);
    printw("===============================================================================\n");
    refresh();
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
        scanw("%d", &choice);
        if (choice > 0 && choice <= Nelts(menu_opts))
            break;
        printw("Invalid Selection.\n");
        clear();
        disp_menu();
    }

    clear();
    disp_menu();

    /*
     * Call the function via the function pointer.
     */

    menu_opts[choice-1].func();

}

/*
 * Get calc intagers.
 */

void n_get_int(int* number, char string[])
{
    printw("%s", string);
    scanw("%d", &(*number));
    refresh();
    clear();
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

    disp_menu();

    for (i = 1; i <= (*quantity); i++)
    {
        printw("From the print function %2d >>> %.16f\n", harm_series[i].id,
                                                          harm_series[i].value);
    }

    refresh();
    getch();
    clear();

}

/*
 * Output full calculated data struct.
 */

void n_print_calc(calc* divisions, int* quantity, int* divs)
{

    int     i;

    for (i = 1; i < (((*quantity)-1) * (*divs) + 1); i++)
    {
        mvwprintw(my_pad, i, 1, "%-4d z=z+1/%-4d %4d of %d -> %.15f\n",
                                                        divisions[i].harmonic,
                                                        divisions[i].harmonic,
                                                        divisions[i].fraction,
                                                        divs,
                                                        divisions[i].value); 
    }

    scroll_pad(my_pad);

}

