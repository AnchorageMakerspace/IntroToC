#include <stdio.h>
#include <stdlib.h>
#include "character.h"

/*
 *  Returns a 0 if the fight continues returns a 1 if the fight is over
 *  Make sure to srand before calling this function
 */
int attack(character *attacker, character *defender)
{    
    int attack = attacker->str * attacker->dex;     // Need to figure in weapons later
    int defense = defender->str * defender->agl;   
    
    // Attack and Defend chances are generated
    float attack_chance = ( rand () % 100 ) * .01;
    float defend_chance = ( rand () % 100 ) * .01;

    printf("%f %f\n", attack_chance, defend_chance);

    if(attack_chance < 0.10) { // not good enough chance to do anything
        printf("%s swings wildly hitting nothing but air.\n", attacker->name);
    } else if( attack_chance > defend_chance ) { // attack is successful
        // amount of damage done
        int damage = attack_chance * attack / 10;
        printf("%s's strike connects and does %i damage\n", attacker->name, damage);
        defender->hp = defender->hp - damage; // reduce the hp
        if(defender->hp < 0)
            return 1;

    } else { // attack is blocked because the defense was higher then the attack
        printf("%s's attack was blocked\n", attacker->name);
    }
    return 0; //  the fight continues
}

/* Engage in battle */
void battle(character *p1, character *p2)
{
    printf("%s and %s have engaged in a battle!\n", p1->name, p2->name);
    
    srand(time(NULL)); // Seed the random number generator for the battle

    while(1) { // loop until explicitly broken
        // p1 attacks
        if(attack(p1, p2)) {
            printf("%s has defeated the %s in battle! \n", p1->name, p2->name);
            break;
        } else if (attack(p2,p1)) {
            printf("The %s proved to be too powerful. %s has died in battle.\n", p2->name, p1->name);
            break;
        }
    }

}
