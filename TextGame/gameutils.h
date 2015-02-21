#ifndef GAMEUTIL_H_INCLUDE
#define GAMEUTIL_H_INCLUDE
#include "character.h"
/* Macro for getting size of ascii art picture in multidimensional array */
#define picsize(a) (sizeof(a)/sizeof(a[0]))-1

extern int current_x;	// Global variable for saving the cursor x position
extern int current_y;	// Global variable for saving the cursor y position

enum color_t { GRAY = 30, RED = 31, GREEN = 32, YELLOW = 33, BLUE=34, PURPLE=35, CYAN=36, WHITE=37} ;

/* Sets the foreground color of text */
void fgcolor(enum color_t c, int boldness);
/* Prints a message one character at a time */
int printmsg(char *msg);
/* Moves the cursor to a different position on the screen */
void movecursor(int x, int y);
/* Displays a question box */
void questionbox(char *msg[], char *prompt, int size, enum color_t color);
/* Displays a message box */
void msgbox(char *name, char *msg, enum color_t color);
/* Clears the screen */
void clear();
/* Displays stats box */
void showstats(character *person);
/* Displays an ascii art picture */
void showpicture(const char *picture[], int size);
/* Displays standard menu for when nothing else is going on */
void standardmenu(void);

#endif
