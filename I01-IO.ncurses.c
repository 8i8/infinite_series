/*
 * Separation of ncurses from program body.
 */

#include <ncurses.h>
#include "I01-inf_series.h"

#define PAD_WIDTH       80                          /* Pad width             */
#define Nelts(a)        (sizeof(a)/sizeof(a[0]))    /* Number of menu option */
#define MENU_Y          12                          /* Menu window height    */
#define MENU_X          80                          /* Menue window width    */

static WINDOW*  my_win;
static WINDOW*  my_pad;

static int      max_y,
                max_x,
                y = 10,
                x = 4;

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
    getmaxyx(stdscr, max_y, max_x);
    max_y = max_y - 4;
    max_x = max_x -(2 * x);
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
    { "Set paramiters start and length of calc.",   get_param        },
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

    mvwprintw(my_win, 1, 20,"x(1/x) + x(1/2x) + x(1/3x) ... x(1/nx)");
    mvwprintw(my_win, 2, 0,"");
    mvwprintw(my_win, 3, 0,"Please choose an option:");

    /*
     * Display the function menu.
     */

    for (i = 0; i < Nelts(menu_opts); i++)
        mvwprintw(my_win, (i+4), 4, "%2d). %s", i+1, menu_opts[i].string);

    /*
     * Display user entered variables.
     */

    mvwprintw(my_win, (i+1), 65," sta = %4d", *sta);
    mvwprintw(my_win, (i+2), 65," qua = %4d", *qua);
    mvwprintw(my_win, (i+3), 65," div = %4d", *div);
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
        mvwscanw(my_win,(Nelts(menu_opts)+4), 0, "%d", &choice);
        if (choice > 0 && choice <= Nelts(menu_opts))
            break;
        wrefresh(my_win);
    }

    wrefresh(my_win);
    menu_opts[choice-1].func();

}

/*
 * Get calc intagers.
 */

void n_get_int(int* number, char string[])
{
    mvwprintw(my_win, (Nelts(menu_opts)+4), 0, "%s", string);
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

    for (i = 1; i <= (*quantity); i++)
    {
        mvwprintw(my_pad, i, 10, "From the print function %2d >>> %.16f\n",
                                                        harm_series[i].id,
                                                        harm_series[i].value);
    }

}

/*
 * Output full calculated data struct.
 */

void n_print_calc(calc* divisions, int* quantity, int* divs)
{
    int     i;

    wclear(my_pad);

    for (i = 1; i < (*quantity) * (*divs); i++)
    {
        mvwprintw(my_pad, i, 10, "%-4d z=z+1/%-4d %4d of %d -> %.15f\n",
                                                        divisions[i].harmonic,
                                                        divisions[i].harmonic,
                                                        divisions[i].fraction,
                                                        *divs,
                                                        divisions[i].value); 
    }

    prefresh(my_pad, 0, 0, y, x, max_y, max_x);

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
    my_pad = newpad(*length, PAD_WIDTH);

    mvprintw(LINES - 3, 1, "Use the Up/Down arrows to scroll.");
    mvprintw(LINES - 2, 1, "F1 Return to menu");
}

void menu_window()
{
    my_win = new_window( MENU_Y, MENU_X, 0, 0);
}

/*
 * Scroll pad display.
 */

void scroll_pad()
{
    int     c,
            start = 1;

    prefresh(my_pad, start, 0, y, x, max_y, max_x);

    while((c = getch()) != KEY_F(1))
    {   
        switch(c)
        {   case KEY_DOWN:
                prefresh(my_pad, start++, 0, y, x, max_y, max_x);
                break;
            case KEY_UP:
                prefresh(my_pad, start--, 0, y, x, max_y, max_x);
                break;
        }
    }

    delwin(my_pad);
    wclear(my_win);
    disp_menu();
    get_choice();

}

