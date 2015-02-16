#include <stdio.h>
#include "gameutils.h"

/* Displays ascii art scene at the top of the screen */
void showscene(int num)
{
	clear(); // Clear out the screen first
	// Display the scene.
	// http://ascii.co.uk/art has much more stuff
	switch(num) {
		case 1:
				// Display the forest
												  
			puts("                        .'`'.    .'`'.   .'`/\\'.					");
			puts("                    .,.'     `'.'     `'`  /%%\\ `/\\				");
			puts("          .'``'.,.'`                      /%%%%\\/%%\\				");
			puts("       .'`                       /\\       /%%%%\\/%%\\				");
			puts("    ..'              /\\         /%%\\  /\\ /%%%%%%/\\%%\\    			");
			puts("  .'   /\\           /%%\\   /\\   /%%\\ /%%\\%/\\%/\\/%%\\%/\\			");
			puts(".'    /%%\\ /\\       /%%\\  /%%\\ /%%%%\\/%%\\/%%\\%%\\%%%/%%\\			");
			puts("      /%%\\/%%\\ /\\  /%%%%\\/%%%%/%%%%%%\\%%/%%%%\\%%\\%/%%%%\\ 			");
			puts("     /%%%%\\%%%/%%\\ /%%%%\\/%%/\\/%%/\\%%\\%%/%%%%\\%%\\/%%%%%%\\ 		");
			puts("    /%%%%%%\\/\\/%%\\/%%%%%%\\%/%%\\%/%%\\%%\\/%%%%%%\\%%/%%%%%%\\			");
			puts("___ /%%%%%%/%%\\%%/%%%%%%%%\\/%%\\%/%%\\%%\\/%%%%%%\\%/%%%%%%%%\\___________");
			puts("   /%%%%%%%/%%\\%%/%%/\\%%%%/%%%%\\%%%%\\%/%%%%%%%%\\/%%%%%%%%\\		");
			puts("  /%%%%%%%/%%%%\\/%%/%%\\%%%/%%%%\\%%%%\\/%%%%%%%%%%\\%%%%%%%%%\\		");
			puts("  /%%%%%%/%%%%%/\\%%/%%\\%%/%%%%%%\\%%%%/%%%%%%%%%%\\%%%%%%%%%%\\		");
			puts(" /%%%%%%%/%%%%/%%\\/%%%%\\/%%%%%%%%\\%%/%%%%%%%%%%%%\\^^^^^^^^^^		");
			puts(" /%%%%%%/%%%%%/%%\\/%%%%\\/%%%%%%%%\\%/%%%%%%%%%%%%%%\\_- %\\% _-		");
			puts("/%%,\";,%/%%%%/%%%%\\%%%%/%%%%%%%%%%\\/%%%%%%%%%%%%lc\\     |%		");
			puts("^^'~%%;%^^^^^/%%%%\\^^^^/%%%%%%%%%%\\^^^^^^^^^^^^^^^^    %|%% 		");
			puts("  ~%\\/%%~ _- ^^^^^^ -_ ^^^^^^%\\%^^^  _-       %/% /%     _~~-		");
			puts("  ;%\\ /%'                      |/`             %\\|%    _-			");
			puts("    |(`   /% /%  _-  %\\%/%    %|%%     %    -    \\/%              ");
			puts("    |\\   %\\|%         %|%%    -~~-    %\\\\%      -~~~-          	");
			puts("   _||_ -  \\/_-      %\\|/%            %\\|/%                 		");
			puts("          -~~         -~~-    _-       ~~               			");
			puts("------------------------------------------------------------------------ ");
			puts(" ");
		break;
		case 2:
			printf("                                   /\\									\n");
			printf("                              /\\  //\\\\								\n");
			printf("                       /\\    //\\\\///\\\\\\        /\\				\n");
			printf("                      //\\\\  ///\\////\\\\\\\\  /\\  //\\\\			\n");
			printf("         /\\          /  ^ \\/^ ^/^  ^  ^ \\/^ \\/  ^ \\				\n");
			printf("        / ^\\    /\\  / ^   /  ^/ ^ ^ ^   ^\\ ^/  ^^  \\				\n");
			printf("       /^   \\  / ^\\/ ^ ^   ^ / ^  ^    ^  \\/ ^   ^  \\       *		\n");
			printf("      /  ^ ^ \\/^  ^\\ ^ ^ ^   ^  ^   ^   ____  ^   ^  \\     /|\\		\n");
			printf("     / ^ ^  ^ \\ ^  _\\___________________|  |_____^ ^  \\   /||o\\		\n");
			printf("    / ^^  ^ ^ ^\\  /______________________________\\ ^ ^ \\ /|o|||\\	\n");
			printf("   /  ^  ^^ ^ ^  /________________________________\\  ^  /|||||o|\\		\n");
			printf("  /^ ^  ^ ^^  ^    ||___|___||||||||||||___|__|||      /||o||||||\\     \n");
			printf(" / ^   ^   ^    ^  ||___|___||||||||||||___|__|||          | |          \n");
			printf("/ ^ ^ ^  ^  ^  ^   ||||||||||||||||||||||||||||||oooooooooo| |ooooooo 	\n");
			printf("oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo	\n\n");
		break;
	}
	// Adjust cursor position this is important so we can print things based on this value later
	current_y = 26;
	current_x = 1;
}

int scene_1()
{
	char c;
	char name[20];
	char buffer[150]; // general purpose buffer

	//Intro
	clear();
	printmsg("... Can you hear me? (y/n): ");
	//get player input
	scanf("%c", &c);
 	fgetc(stdin); // Consume the newline character leftover from scanf otherwise fgets wont work later
	if(c=='y' || c=='Y'){
		showscene(1);
		msgbox(NULL, "You wake up in a world you've never seen before", CYAN);
	} else{
		clear();
		printmsg("you pass into the darkness\n");
		return -1;
	}
	
	msgbox(NULL, "A face stares back at you with greyish skin and eyes that almost glow blue. I thought I lost you there for a moment.  What is your name? ", CYAN);
	questionbox(NULL, "Enter your name: ", 0, BLUE);
	fgets(name, 20, stdin);	// get 20 characters from stdin
	name[strnlen(name, 20)-1] = '\0'; // replace leftover \n with a null terminator
	showscene(1);
	snprintf(buffer, 150, "Nice to meet you %s. My name is Goran.", name);
	msgbox("Goran", buffer, GREEN);
	// A loop to display a list of questions

	while(1)
	{
		char item;
		int stop = 0;
		// print menu of questions
		puts(" ");
		char *questions[] = {"1) What am I doing here?", "2) What are you?", "3) How did I get here?"};
		questionbox(questions, "Enter a number (or 	q to quit): ", 3, BLUE);
		scanf("%c", &item);
		fgetc(stdin); // flush the buffer of the \n
		// Process the input
		switch(item) {
			case '1':
				showscene(1);
				msgbox("Goran", "I found you here, nearly dead. I wasn't sure I was going to be able to revive you.", GREEN);
			break;
			case '2':
				clear();
				showscene(1);
				msgbox("Goran", "I am a Dalrek, my people have lived here for centuries.", GREEN);
			break;
			case '3':
				showscene(1);
				msgbox("Goran", "I was hoping you could tell me that, I just found you here in the forest, half dead", GREEN);
				getchar();
				msgbox(name, "I can't seem to remember...", BLUE);
			break;
			case 'q':
				stop = 1;
			break;
			default:
				showscene(1);
				msgbox("Goran", "Sorry I didn't catch that.", GREEN);
			break;
		} 
		// Check to see if we should continue
		if(stop) {
			showscene(1);
			msgbox(name, "I'm Sorry I'cant remember much more then my name...", BLUE);
			msgbox("Goran", "I'll bring you back to my cabin.  Maybe after a warm meal you will remember more", GREEN);
			return 0;
		}
	}
}

int scene_2()
{
	showscene(2);
	msgbox(NULL,"Your arrive at a small cabin over shadowed by great mountains.", CYAN);
	msgbox(NULL, "A warm meal makes you feel alive again", CYAN);
	getchar();
	showstats();
	getchar();
	return 0;
}
