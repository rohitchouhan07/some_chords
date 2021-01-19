/* SOME CHORDS */
/* Ncurses way to checking guitar chord shapes */

/* Import the required header files */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <menu.h>
#include <signal.h>
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
  "Help",
};

/* On select function declaration */

void func(char *name);

/* SIGWINCH handler declaration */
/* this function should make the output resposive to window size changes */
void handle_winch(int sig);

/* Chord window and menu window declarations */
WINDOW *chord_win1;
WINDOW *chord_win2;
WINDOW *my_menu_win;

/* MAIN FUNCTION */
int main()
{   
    ITEM **my_items;
    int c;
    MENU *my_menu;
    int n_choices, i;
    ITEM *cur_item;
    ITEM *cur;
    void (*p)(char *);
    
    /* Initialise curses */
    
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE); 
    
    struct sigaction sa;
    memset(&sa, 0, sizeof(struct sigaction));
    sa.sa_handler = handle_winch;
    sigaction(SIGWINCH, &sa, NULL);
    
    
    chord_win1 = newwin(LINES - 3, 20, 0, 25);
    chord_win2 = newwin(LINES - 3, 20, 0, 50);
    my_menu_win = newwin(10, 12, 0, 0);
    keypad(my_menu_win, TRUE);
    
    /* Initialise items */
    
    n_choices = ARRAY_SIZE(choices);
    my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
    for(i = 0; i < n_choices; ++i)
    {
        my_items[i] = new_item(choices[i], NULL);
        set_item_userptr(my_items[i], func);
    }
    my_items[n_choices] = (ITEM *)NULL;
    
    /* Create menu */
    
    my_menu = new_menu((ITEM **)my_items);
    
    /* Set main window and sub window */
    
    set_menu_win(my_menu, my_menu_win);
    set_menu_sub(my_menu, derwin(my_menu_win, 8, 10, 1, 1));
    
    /* Set menu mark to the string " * " */
   
    set_menu_mark(my_menu, "*");
    
	/* Print a border around the menu */
    
    box(my_menu_win, 0, 0);
        
    /* posting the menu and refreshing windows */
    
    post_menu(my_menu);
    mvprintw(LINES - 2, 0, "Up and Down arrow keys to navigate, ENTER to select (F1 to Exit)");
    refresh();
    wrefresh(my_menu_win);
    wrefresh(chord_win1);
    wrefresh(chord_win2);
    
    /* the main loop for getting keystrokes */

    while((c = getch()) != KEY_F(1))
        {
            switch(c)
            {
                case KEY_DOWN:
                    menu_driver(my_menu, REQ_DOWN_ITEM);
                    cur = current_item(my_menu);
                    p = item_userptr(cur);
                    p((char *)item_name(cur));
                    pos_menu_cursor(my_menu);
                    wrefresh(my_menu_win);
                    break;
                case KEY_UP:
                    menu_driver(my_menu, REQ_UP_ITEM);
                    cur = current_item(my_menu);
                    p = item_userptr(cur);
                    p((char *)item_name(cur));
                    pos_menu_cursor(my_menu);
                    wrefresh(my_menu_win);
                    break;
                case 10:
                    cur = current_item(my_menu);
                    p = item_userptr(cur);
                    p((char *)item_name(cur));
                    pos_menu_cursor(my_menu);
                    wrefresh(my_menu_win);
                    break;
            }
            
         }
    
    /* clearing up the memory */

    unpost_menu(my_menu);
    for(i = 0; i < n_choices; ++i)
        free_item(my_items[i]);
    free_menu(my_menu);
    delwin(chord_win1);
    delwin(chord_win2);
    endwin();
}

/* On select function definition */

void func(char *name)
{
    if(name == "A chords")
    {   
		wclear(chord_win1);
        wclear(chord_win2);
        int col = 1;
        FILE *fptr;
        char c;
        char *filename = "/usr/share/some_chords/a.txt";
        fptr = fopen(filename, "r");
    if(fptr == NULL)
    {
        wmove(chord_win1, 1, 0);
        wprintw(chord_win1, "Cannot open file\n");
        wrefresh(chord_win1);
        wrefresh(chord_win2);
    }
    else
    {
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
	}

	else if(name == "B chords")
    {   
		wclear(chord_win1);
        wclear(chord_win2);
        int col = 1;
        FILE *fptr;
        char c;
        char *filename = "/usr/share/some_chords/b.txt";
        fptr = fopen(filename, "r");
    if(fptr == NULL)
    {
        wmove(chord_win1, 1, 0);
        wprintw(chord_win1, "Cannot open file\n");
        wrefresh(chord_win1);
        wrefresh(chord_win2);
    }
    else
    {
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
}
    
	else if(name == "C chords")
    {   		
		wclear(chord_win1);
        wclear(chord_win2);
        int col = 1;
        FILE *fptr;
        char c;
        char *filename = "/usr/share/some_chords/c.txt";
        fptr = fopen(filename, "r");
    if(fptr == NULL)
    {
        wprintw(chord_win1, "Cannot open file\n");
    }
    else
    {
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
}
    
	else if(name == "D chords")
    {   		
		wclear(chord_win1);
        wclear(chord_win2);
        int col = 1;
        FILE *fptr;
        char c;
        char *filename = "/usr/share/some_chords/d.txt";
        fptr = fopen(filename, "r");
    if(fptr == NULL)
    {
        wmove(chord_win1, 1, 0);
        wprintw(chord_win1, "Cannot open file\n");
        wrefresh(chord_win1);
        wrefresh(chord_win2);
    }
    else
    {
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
}
    
	else if(name == "E chords")
    {   
		wclear(chord_win1);
        wclear(chord_win2);
        int col = 1;
        FILE *fptr;
        char c;
        char *filename = "/usr/share/some_chords/e.txt";
        fptr = fopen(filename, "r");
    if(fptr == NULL)
    {
		wmove(chord_win1, 1, 0);
        wprintw(chord_win1, "Cannot open file\n");
        wrefresh(chord_win1);
        wrefresh(chord_win2);
    }
    else
    {
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
}
	else if(name == "F chords")
    {   	
		wclear(chord_win1);
        wclear(chord_win2);
        int col = 1;
        FILE *fptr;
        char c;
        char *filename = "/usr/share/some_chords/f.txt";
        fptr = fopen(filename, "r");
    if(fptr == NULL)
    {
        wmove(chord_win1, 1, 0);
        wprintw(chord_win1, "Cannot open file\n");
        wrefresh(chord_win1);
        wrefresh(chord_win2);
    }
    else
    {
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
}
    
	else if(name == "G chords")
    {   
		wclear(chord_win1);
        wclear(chord_win2);
        int col = 1;
        FILE *fptr;
        char c;
        char *filename = "/usr/share/some_chords/g.txt";
        fptr = fopen(filename, "r");
    if(fptr == NULL)
    {
        wmove(chord_win1, 1, 0);
        wprintw(chord_win1, "Cannot open file\n");
        wrefresh(chord_win1);
        wrefresh(chord_win2);
    }
    else
    {
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
}
	else
	{
		wmove(chord_win1, 0, 0);
        wclrtoeol(chord_win1);
        wmove(chord_win2, 0, 0);
        wclrtoeol(chord_win2);
        wprintw(chord_win1, "Cannot open file\n");
	}

}
	
/* sigwinch_handler function definition */

void handle_winch(int sig)
{
    //endwin();
    // Needs to be called after an endwin() so ncurses will initialize
    // itself with the new terminal dimensions.
    wrefresh(my_menu_win);
    wrefresh(chord_win1);
    wrefresh(chord_win2);
    refresh();
}  
