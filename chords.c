/*
 * Import the required headers
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <menu.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD   4

char *choices[] = {
  "A chords",
  "B chords",
  "C chords",
  "D chords",
  "E chords",
  "F chords",
  "G chords",
};

int main()
{
    ITEM **my_items;
    int c;
    MENU *my_menu;
    int n_choices, i;
    ITEM *cur_item;
    /*
     * Initialise curses
     */
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    /*
     * Initialise items
     */
    n_choices = ARRAY_SIZE(choices);
    my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
    for(i = 0; i < n_choices; ++i)
        my_items[i] = new_item(choices[i], choices[i]);
    my_items[n_choices] = (ITEM *)NULL;
    /*
     * Create menu
     */
    my_menu = new_menu((ITEM **)my_items);
    /*
     * posting the menu
     */
    post_menu(my_menu);
    mvprintw(LINES - 2, 0, "Up and Down arrow keys to navigate (F1 to Exit)");
    refresh();
    
    /*
     * the loop
     */

    while((c = getch()) != KEY_F(1))
            {
            switch(c){
                case KEY_DOWN:
                    menu_driver(my_menu, REQ_DOWN_ITEM);
                    break;
                case KEY_UP:
                    menu_driver(my_menu, REQ_UP_ITEM);
                    break;
                     }
            }
    /*
     * clearing up the memory
     */

    unpost_menu(my_menu);
    for(i = 0; i < n_choices; ++i)
        free_item(my_items[i]);
    free_menu(my_menu);
    endwin();
}
