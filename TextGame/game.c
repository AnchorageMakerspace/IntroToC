#include <stdio.h>
#include "gameutils.h"
#include "scenes.h"


int main ( void )
{		
	while (1) { // Main game loop
		// Scene 1
		if((scene_1()) == -1) {
			return 1;
		}
		scene_2();
	}
}
