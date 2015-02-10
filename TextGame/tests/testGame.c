#include <stdio.h>
#include "../gameutils.h"
#include "../scenes.h"

/******************************************************************************
*	Structure:
*	Intro - 
*		-print "can you hear me? (y/n)"
*		-get input
*		-check input, continue (y) or end (n) and show correct message box
*
*	First Encounter
*		-Being talks to you and asks your name
*		-get name input
*		-show what the scene looks like
*		-add reply with inputted name
*
******************************************************************************/

int main ( void ){
	/************
	|	Intro	|
	************/
	char c;
	char name[20];
	char buffer[150];

	clear(); 			//clear console for a fresh screen
	printmsg("... Can you hear me? (y/n): ");
	scanf("%c", &c); 	//get player input
 	fgetc(stdin); 		//use to clear newline character for future inputs

	if(c=='y' || c=='Y'){ 	//check input
		showscene(1);
		msgbox(NULL, "You wake up in a world you've never seen before", CYAN);
	} else{
		clear();
		msgbox(NULL, "you pass into the darkness\n", CYAN);
		return -1;
	}
	
	/********************
	|	First Encounter	|
	********************/

	//Being talks to you and asks your name
	msgbox(NULL, "A face stares back at you with greyish skin and eyes that almost glow blue. I thought I lost you there for a moment.  What is your name? ", CYAN);
	fgets(name, 20, stdin);				// get name input
	name[strnlen(name, 20)-1] = '\0';	// replaces \n with null terminator

	showscene(1);						// show what the scene looks like

	// add reply with inputted name
	snprintf(buffer, 150, "Nice to meet you %s. My name is Goran.", name);
	msgbox("Goran", buffer, GREEN);	
	showscene(1);
	msgbox("You", "\" I'm sorry I cant remember much more then my name...\"\n", GREEN);
	msgbox("The strange creature", "\"I'll bring you back to my cabin. Maybe after a warm meal you will remember more. \"\n", GREEN);
}
