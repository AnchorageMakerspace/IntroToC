#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "gameutils.h"

int current_x;
int current_y;

/* Set the color of the font */
void fgcolor(enum color_t c, int boldness)
{
	printf("\033[%i;%im",boldness, c);
}

/* Prints out the message character by character instead of all at once */
/* Returns the number of lines */
int printmsg(char *msg)
{
	int size = strlen(msg);
	int i, lines = 0;
	
	for(i=0; i <= size; i++) {
		// every 60 characters print a newline
		if(i != 0 && i % 60 == 0) { // Max characters in a line
			printf("\n");
			if(msg[i] == ' ')	// Skip space characters so the newline doesn't start with one
				i++;
			movecursor(current_x, current_y +1); // move the cursor down 1
			lines++;
		}
		printf("%c",msg[i]);
		fflush(stdout);
		usleep(30000); // changed from 50000 to speed things up 
	}
	return lines;
}

/* Moves the cursor on the screen. Also saves the position globaly after the move*/
void movecursor(int x, int y)
{
	// Move cursor
	printf("\033[%i;%iH", y, x);
	// Save current position
	current_x = x;
	current_y = y;
}

/* Display the question box, possibly get rid of this and use msgbox */
void questionbox(char *msg[], int num, enum color_t color)
{
	// determine size of the box....
	int boxsize = num;
	int n;
	
	movecursor(current_x, current_y);	// Set the position for the box to start at....
	fgcolor(GRAY, 1);
	// Box holds 60 characters per line
	printf("\n");
	printf("   _______________________________________________________________ \n");
	printf("  |                                                               |\n");
	// Display the correct size box to hold the message
	for(n = 0; n <= boxsize; n++) {
		printf("  |                                                               |\n");
	}
	printf("  |_______________________________________________________________|\n");

	fgcolor(WHITE, 1);
	movecursor(5,current_y + 2); // Move the cursor to the top of the box.
	movecursor(current_x, current_y + 1); // Move 1 down from current position
	fgcolor(color,0);
	for(n = 0; n <= num; n++) {
		printf("%s\n", msg[n]);
	}
	printf("%s\n", msg);
	fgcolor(WHITE,0);
	movecursor(current_x, current_y + 1); // Move cursor down to right after the box	
}

/* Draw a message box */
void msgbox(char *name, char *msg, enum color_t color)
{
	// determine size of the box....
	int boxsize = (strlen(msg)) / 60;
	int n;
	
	movecursor(current_x, current_y);	// Set the position for the box to start at....
	fgcolor(GRAY, 1);
	// Box holds 60 characters per line
	printf("\n");
	printf("   _______________________________________________________________ \n");
	printf("  |                                                               |\n");
	// Display the correct size box to hold the message
	for(n = 0; n <= boxsize; n++) {
		printf("  |                                                               |\n");
	}
	printf("  |_______________________________________________________________|\n");

	fgcolor(WHITE, 1);
	movecursor(5,current_y + 2); // Move the cursor to the top of the box.
	if(name != NULL)
		printf("%s says:", name);
	movecursor(current_x, current_y + 1); // Move 1 down from current position
	fgcolor(color,0);
	printmsg(msg);
	fgcolor(WHITE,0);
	movecursor(current_x, current_y + 1); // Move cursor down to right after the box
}

void prompt()
{
	movecursor(current_x, current_y + 2);
	printf("> ");
	movecursor(current_x + 3 , current_y);
	getchar();
}

/* Clear the screen */
void clear()
{
	printf("\033[2J"); // Clear screen \033 is the ansi escape character and [2J is the clear action
	//printf("\033[6;1H"); // Put the cursor at 1,1 top left
	movecursor(1,6);
}




/* Display stats at the top of the screen */
void showstats()
{
	printf("\033[1;1H"); // Put the cursor to 1,1 top left
	printf(" -----------------\n");
	printf("| HP: 500         |\n");
	printf("| Attack: 10      |\n");
	printf("| Defense: 10     |\n");
	printf("| Money: 0        |\n");
	printf(" -----------------\n");
	printf("\033[37;1H"); // Put the cursor at 1,1 top left
}
