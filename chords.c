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

/*
 * On select function declaration
 */

void func(char *name);

/*
 * Chord window declaration
 */
WINDOW *chord_win1;
WINDOW *chord_win2;

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
    chord_win1 = newwin(LINES - 3, 20, 0, 25);
    chord_win2 = newwin(LINES - 3, 20, 0, 50);
    /*
     * Initialise items
     */
    n_choices = ARRAY_SIZE(choices);
    my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
    for(i = 0; i < n_choices; ++i)
    {
        my_items[i] = new_item(choices[i], NULL);
        set_item_userptr(my_items[i], func);
    }
    my_items[n_choices] = (ITEM *)NULL;
    /*
     * Create menu
     */
    my_menu = new_menu((ITEM **)my_items);
    /*
     * posting the menu
     */
    post_menu(my_menu);
    mvprintw(LINES - 2, 0, "Up and Down arrow keys to navigate, ENTER to select (F1 to Exit)");
    refresh();
    wrefresh(chord_win1);
    wrefresh(chord_win2);
    /*
     * the loop
     */

    while((c = getch()) != KEY_F(1))
            {
            switch(c)
            {
                case KEY_DOWN:
                    menu_driver(my_menu, REQ_DOWN_ITEM);
                    break;
                case KEY_UP:
                    menu_driver(my_menu, REQ_UP_ITEM);
                    break;
                case 10:
                    {
                    ITEM *cur;
                    void (*p)(char *);
                    cur = current_item(my_menu);
                    p = item_userptr(cur);
                    p((char *)item_name(cur));
                    pos_menu_cursor(my_menu);
                    break;
                    }
            }
            }
    /*
     * clearing up the memory
     */

    unpost_menu(my_menu);
    for(i = 0; i < n_choices; ++i)
        free_item(my_items[i]);
    free_menu(my_menu);
    delwin(chord_win1);
    delwin(chord_win2);
    endwin();
}

void func(char *name)
{
    wclrtoeol(chord_win1);
    if(name == "A chords")
    {   wmove(chord_win1, 0, 0);
        wclrtoeol(chord_win1);
        int col = 1;
        FILE *fptr;
        char c;
        char *filename = "a.txt";
        fptr = fopen(filename, "r");
    if(fptr == NULL)
    {
        wprintw(chord_win1, "Cannot open file\n");
    }
    c = fgetc(fptr);
    while (c!= EOF)
    {
    if(c == '>')
    {
        c = fgetc(fptr);
        col++;
    }
    if(col == 1){
        wprintw(chord_win1, "%c", c);
        c = fgetc(fptr);
    }else if(col == 2){
        wprintw(chord_win2, "%c", c);
        c = fgetc(fptr);
    }    
    }
    wrefresh(chord_win1);
    wrefresh(chord_win2);
    fclose(fptr);
    }

if(name == "B chords")
    {   wmove(chord_win1, 0, 0);
        wclrtoeol(chord_win1);
        int col = 1;
        FILE *fptr;
        char c;
        char *filename = "b.txt";
        fptr = fopen(filename, "r");
    if(fptr == NULL)
    {
        wprintw(chord_win1, "Cannot open file\n");
    }
    c = fgetc(fptr);
    while (c!= EOF)
    {
    if(c == '>')
    {
        c = fgetc(fptr);
        col++;
    }
    if(col == 1){
        wprintw(chord_win1, "%c", c);
        c = fgetc(fptr);
    }else if(col == 2){
        wprintw(chord_win2, "%c", c);
        c = fgetc(fptr);
    }    
    }
    wrefresh(chord_win1);
    wrefresh(chord_win2);
    fclose(fptr);
    }
    
if(name == "C chords")
    {   wmove(chord_win1, 0, 0);
        wclrtoeol(chord_win1);
        int col = 1;
        FILE *fptr;
        char c;
        char *filename = "c.txt";
        fptr = fopen(filename, "r");
    if(fptr == NULL)
    {
        wprintw(chord_win1, "Cannot open file\n");
    }
    c = fgetc(fptr);
    while (c!= EOF)
    {
    if(c == '>')
    {
        c = fgetc(fptr);
        col++;
    }
    if(col == 1){
        wprintw(chord_win1, "%c", c);
        c = fgetc(fptr);
    }else if(col == 2){
        wprintw(chord_win2, "%c", c);
        c = fgetc(fptr);
    }    
    }
    wrefresh(chord_win1);
    wrefresh(chord_win2);
    fclose(fptr);
    }
    
if(name == "D chords")
    {   wmove(chord_win1, 0, 0);
        wclrtoeol(chord_win1);
        int col = 1;
        FILE *fptr;
        char c;
        char *filename = "d.txt";
        fptr = fopen(filename, "r");
    if(fptr == NULL)
    {
        wprintw(chord_win1, "Cannot open file\n");
    }
    c = fgetc(fptr);
    while (c!= EOF)
    {
    if(c == '>')
    {
        c = fgetc(fptr);
        col++;
    }
    if(col == 1){
        wprintw(chord_win1, "%c", c);
        c = fgetc(fptr);
    }else if(col == 2){
        wprintw(chord_win2, "%c", c);
        c = fgetc(fptr);
    }    
    }
    wrefresh(chord_win1);
    wrefresh(chord_win2);
    fclose(fptr);
    }
    
if(name == "E chords")
    {   wmove(chord_win1, 0, 0);
        wclrtoeol(chord_win1);
        int col = 1;
        FILE *fptr;
        char c;
        char *filename = "e.txt";
        fptr = fopen(filename, "r");
    if(fptr == NULL)
    {
        wprintw(chord_win1, "Cannot open file\n");
    }
    c = fgetc(fptr);
    while (c!= EOF)
    {
    if(c == '>')
    {
        c = fgetc(fptr);
        col++;
    }
    if(col == 1){
        wprintw(chord_win1, "%c", c);
        c = fgetc(fptr);
    }else if(col == 2){
        wprintw(chord_win2, "%c", c);
        c = fgetc(fptr);
    }    
    }
    wrefresh(chord_win1);
    wrefresh(chord_win2);
    fclose(fptr);
    }
    
if(name == "F chords")
    {   wmove(chord_win1, 0, 0);
        wclrtoeol(chord_win1);
        int col = 1;
        FILE *fptr;
        char c;
        char *filename = "f.txt";
        fptr = fopen(filename, "r");
    if(fptr == NULL)
    {
        wprintw(chord_win1, "Cannot open file\n");
    }
    c = fgetc(fptr);
    while (c!= EOF)
    {
    if(c == '>')
    {
        c = fgetc(fptr);
        col++;
    }
    if(col == 1){
        wprintw(chord_win1, "%c", c);
        c = fgetc(fptr);
    }else if(col == 2){
        wprintw(chord_win2, "%c", c);
        c = fgetc(fptr);
    }    
    }
    wrefresh(chord_win1);
    wrefresh(chord_win2);
    fclose(fptr);
    }
    
if(name == "G chords")
    {   wmove(chord_win1, 0, 0);
        wclrtoeol(chord_win1);
        int col = 1;
        FILE *fptr;
        char c;
        char *filename = "g.txt";
        fptr = fopen(filename, "r");
    if(fptr == NULL)
    {
        wprintw(chord_win1, "Cannot open file\n");
    }
    c = fgetc(fptr);
    while (c!= EOF)
    {
    if(c == '>')
    {
        c = fgetc(fptr);
        col++;
    }
    if(col == 1){
        wprintw(chord_win1, "%c", c);
        c = fgetc(fptr);
    }else if(col == 2){
        wprintw(chord_win2, "%c", c);
        c = fgetc(fptr);
    }    
    }
    wrefresh(chord_win1);
    wrefresh(chord_win2);
    fclose(fptr);
    }

else
{
    wclrtoeol(chord_win1);
    wprintw(chord_win1, "invalid Selection\n");
    wrefresh(chord_win1);
}

}

