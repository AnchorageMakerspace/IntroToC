#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "gameutils.h"

/* Adds a new location on the map */
map *addPlace(char *name, enum terrain_t terrain)
{
	// Allocate space for a new place on the map
	map *place = (map *)malloc(sizeof(map));
	place->name = name;
	place->terrain = terrain;;
	place->direction_sign = NULL;
	return place;
}

/* A sign that shows what is available in different directions */
sign *newSign(char *n, char *s, char *e, char *w) 
{
	sign *direction_sign = (sign *)malloc(sizeof(sign));
	direction_sign->n = n;
	direction_sign->s = s;
	direction_sign->e = e;
	direction_sign->w = w;
	return direction_sign;
}


/* Travel in some direction on the map */
map* travel(map *WorldMap, char direction)
{
	// can travel n, s, e, w
	switch(direction) {
		case 'n':
			if(WorldMap->n != 0) {
				msgbox(NULL, WorldMap->n->name, CYAN);
				return WorldMap->n;
			} else { 
				msgbox(NULL, "Sorry, the trail doesn't lead there.", CYAN);
				return WorldMap;
			}
		break;
		case 's':
			if(WorldMap->s != 0) {
				msgbox(NULL, WorldMap->s->name, CYAN);
				return WorldMap->s;
			} else { 
				msgbox(NULL, "Sorry, the trail doesn't lead there.", CYAN);
				return WorldMap;
			}
		break;
		case 'e':
			if(WorldMap->e != 0) {
				msgbox(NULL, WorldMap->e->name, CYAN);
				return WorldMap->e;
			} else { 
				msgbox(NULL, "Sorry, the trail doesn't lead there.", CYAN);
				return WorldMap;
			}
		break;
		case 'w':
			if(WorldMap->w != 0) {
				msgbox(NULL, WorldMap->w->name, CYAN);
				return WorldMap->w;
			} else { 
				msgbox(NULL, "Sorry, the trail doesn't lead there.", CYAN);
				return WorldMap;
			}
		break;
		default:
			return WorldMap;
		break;
	}
}

/* Function links two map locations together */
void linkMap(map *loc1, map *loc2, linkdir_t linkdirection){

	if(linkdirection == NS) {		// Link North/South
		loc1->n = loc2;
		loc2->s = loc1;
	} else if(linkdirection == EW) { // Link East/West
		loc1->e = loc2;
		loc2->w = loc1;
	}
}
