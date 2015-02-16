#ifndef MAP_H_INCLUDE
#define MAP_H_INCLUDE

static const char *WorldMap[] = {"\033[1;36m", "     _    _  ___________ _    ______  ___  ___  ___  ______ ",
"    | |  | ||  _  | ___ \\ |   |  _  \\ |  \\/  | / _ \\ | ___ \\",
"    | |  | || | | | |_/ / |   | | | | | .  . |/ /_\\ \\| |_/ /",
"    | |/\\| || | | |    /| |   | | | | | |\\/| ||  _  ||  __/ ",
"    \\  /\\  /\\ \\_/ / |\\ \\| |___| |/ /  | |  | || | | || |  ",  
"     \\/  \\/  \\___/\\_| \\_\\_____/___/   \\_|  |_/\\_| |_/\\_|\033[0;37m",    
"                                                       ",
"              	               __________",
"             	              /          \\            ______KEY______",
"               	  ___________/            \\          | \033[0;32m\%\%\033[0;37m = Forest   |",
"              	 /                 B       `'._      | \033[0;34m~~\033[0;37m = Water    |",
"        	/                              \\     | \033[0;30m/\\\033[0;37m = Mountains|",
"	       /      M                         |    | \033[0;33m..\033[0;37m = Desert   |",
"	      |          \033[0;32m\%\%\% \%\%\%\%\%\%\%\%\%\%\%\033[0;37m         `,  |_______________|",
"	     /         \033[0;32m\%\%\%\%\%\%\%\%\%\%\%\%\%\%\%\%\%\%\%\033[0;37m         |",
"	    |       \033[0;30m/\\/\\/\\ \033[0;32m\%\%\%\%\%  \%\%\%\%\%\%\%\033[0;37m         /",
"	    |     \033[0;30m/\\/\\/\\    \033[0;34m~~~~~   \033[0;32m\%\%\%\033[0;37m           |_",
"	   /   C  \033[0;30m /\\/\\/\\  \033[0;34m~~~~~~~    \033[0;32m\%\%\%\%\%\%\033[0;37m        |",
"	   \\      _\033[0;30m/\\/\\/\\  \033[0;34m~~~~~~~\033[0;37m                   \\____",
"	    \\____/  \\ \033[0;30m/\\    \033[0;34m~~~~~\033[0;37m                         \\",
"	            /       \033[0;34m~~\033[0;37m F                        S  |",
"	           /                     \033[0;32m\%\%\%\%\%\%\%\033[0;37m        __/",
"	        __/   \033[0;33m........\033[0;37m            \033[0;32m\%\%\%\%\%\033[0;37m        /",
"	       |     \033[0;33m............\033[0;37m       \033[0;32m\%\%\%\%\%\%\033[0;37m       ,'            ",        
"	      /   \033[0;33m.............\033[0;37m           \033[0;32m\%\%\%\%\%\%\033[0;37m     \\",
"	    _/   \033[0;33m.............\033[0;37m   \033[0;30m/\\/\\\033[0;37m                 |",
"	   /    \033[0;33m...\033[0;37mN\033[0;33m.........\033[0;37m \033[0;30m/\\/\\/\\\033[0;37m                 /",
"	  |      \033[0;33m...........\033[0;37m                        |",
"	  \\        \033[0;33m.......\033[0;37m                      ,_,'",
"	  |                                ____/",
"	  \\                           ,---'",
"	   \\                  ,.  H  /",
"	    `'\\___       ____/  `---' ",
"                  \\___,_/		       	    "};

enum terrain_t {GRASS = 0, forest = 1, DESERT = 2, MOUNTAIN = 3, TOWN = 5};
typedef enum linkdir_t{NS,EW} linkdir_t;

/* Map Node */
typedef struct map{
	char *name;  // The name of the place, if any    
	struct map *n;
	struct map *s;
	struct map *e;
	struct map *w;
	enum terrain_t terrain;
	struct sign *direction_sign; // A sign showing what's in different directions
} map;

/* Sign node,  tells the user what's in different directions */
typedef struct sign{
	char *n;
	char *s;
	char *e;
	char *w;
} sign;

/* Adds a new location on the map */
map *addPlace(char *name, enum terrain_t terrain);
/* A sign that shows what is available in different directions */
sign *newSign(char *n, char *s, char *e, char *w); 
/* Travel in some direction on the map */
map* travel(map *WorldMap, char direction);
/* Function links two map locations together */
void linkMap(map *loc1, map *loc2, linkdir_t linkdirection);

#endif



