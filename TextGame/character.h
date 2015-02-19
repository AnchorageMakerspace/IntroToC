#ifndef CHARACTER_H_INCLUDE
#define CHARACTER_H_INCLUDE

/* Defines weapons */
typedef struct weapon{
		char name[10];
		int damage;
} weapon;

/* Defines Armor */
typedef struct armor{
		char name[10];
		int defense;
} armor;

/* Defines any type of character, monster or player */
typedef struct character{
		char name[20];			// Name of the creature
		char *picture;		// ASCII art picture
		int str;			// Strength
		int dex;			// Dexterity
		int agl;			// Agility
		int hp;				// Hitpoints
		struct weapon *weapon;
		struct armor *armor;
} character;

extern struct character *player;

void spawnMonster();
character *newCharacter(char *name);

#endif
