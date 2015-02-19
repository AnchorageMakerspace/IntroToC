#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "character.h"

void spawnMonster() // THIS WILL BE CHANGED TO RETURN A POINTER TO A NEW MONSTER
{
	printf("A monster has been summoned");
}

character *newCharacter(char *name) 
{
	character *new_character = (character *)malloc(sizeof(character));
	strncpy(new_character->name, name, 20); // strncpy not strcpy extra insurance against overflow
	return new_character;
}
