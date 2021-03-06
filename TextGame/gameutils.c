#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "gameutils.h"
#include "map.h"

int current_x;
int current_y;

/* Set the color of the font */
void fgcolor(enum color_t c, int boldness)
{
	printf("\033[%i;%im",boldness, c);
}

/* Prints out the message character by character instead of all at once */
/* Returns the number of lines, this may be useful later */
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
		usleep(10000); // changed from 50000 to speed things up 
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
void questionbox(char *msg[], char *prompt, int num, enum color_t color)
{
	int n;
	int lines = (num == 0) ? 1 : num; // If num is 0 then go ahead and make it 1 so we can build the box
	movecursor(current_x, current_y);	// Set the position for the box to start at....
	fgcolor(GRAY, 1);
	// Box holds 60 characters per line
	printf("\n");
	printf("   _______________________________________________________________\n");
	printf("  |                                                               |\n");
	// Display the correct size box to hold the message
	for(n = 0; n < lines; n++) {
		printf("  |                                                               |\n");
	}
	printf("   ---------------------------------------------------------------\n");

	fgcolor(WHITE, 1);
	movecursor(5,current_y + 2); // Move the cursor to the top of the box.
	movecursor(current_x, current_y + 1); // Move 1 down from current position
	fgcolor(color,0);
	for(n = 0; n <= (num - 1); n++) {
		printf("%s", msg[n]);
		// Move the cursor down, dont use /n because it will jump out of the box
		movecursor(current_x, current_y+1);
	}
	fgcolor(WHITE,0);
	printf("%s", prompt);
	movecursor(current_x + (strlen(prompt) + 1), current_y); // Move cursor to directly after the question
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

/* Clear the screen */
void clear()
{
	printf("\033[2J"); // Clear screen \033 is the ansi escape character and [2J is the clear action
	//printf("\033[6;1H"); // Put the cursor at 1,1 top left
	movecursor(1,6);
}


/* Display stats at the top of the screen */
void showstats(character *person)
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

/* Displays an ascii art picture, provided in the form of a multi demensional array.
The number of elements in the array must be provided for size */
void showpicture(const char *picture[], int size)
{
	int i;
	for(i = 0; i <= size; i++) {
		printf("%s", picture[i]);
		movecursor(current_x, current_y + 1);	// Move the cursor to next line
	}
}


/* Displays the standard menu for when nothing else is going on */
void standardmenu( void )
{
	char i;
	// Display Menu
	char *menuitems[] = { "1) View Inventory", "2) View Map", "3) Character Stats", "4) Game Menu"};
	questionbox(menuitems, "Enter a number: ", 4, BLUE);
	
	scanf("%c", &i);
	fgetc(stdin);
	
	switch(i) {
		case '1':	// View Inventory
		
		break;		
		case '2':	// View Map
		
		break;
		case '3':	// Character Stats
		
		break;
		case '4':	// Game Menu
		
		break;
		default:
		
		break;
	}
	
}
