#include <stdio.h>

int main(){
    char c;
    //Intro
    printf("... Can you hear me?     ");
    
    //get player input
    scanf("%c", &c);

    if(c=='y' || c=='Y'){
        printf("You wake up in a world you've never seen before");
    } else{
        printf("you pass into the darkness");
        return -1;
    }
    return 0;
}