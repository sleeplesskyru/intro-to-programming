#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <Windows.h>

/* 
Author: Kyle Gorr
Version: 1.0.0
============================================================================
This script is for the midterm in CSCI-4 in person class with Sean Worthington.
============================================================================
Instructions for Midterm:

Greet: Welcome to Cat Fun!

Q: Which cat do you want to play with?
A: user enters a cat's name

Affirmation: Ok, ___ it is. (repeats the cat name it was given)

"A bullet has been placed in a chamber #" (random number)
"You spin the revolver and chamber #__ is at the trigger"

=if match "BLAMO!! Dead cat." (written in red)
=else "Click! Cat lives." (written in green)

"You have ___ points" (everytime the trigger is pulled and the cat lives, the user gets a point)\

while the cat is alive, keep playing - putting new bullets in random chambers.

Congradulate: "Thank for playing cat fun. You have ___ points."
*/

int main(void) {
    char *catName;
    int bullet;
    int spin;
    int points = 0;
    char trigger[25];
    bool restart = false;
    srand(time(NULL));

    system("cls");

    printf("Welcome to Cat Fun!\n\n");

    printf("Which cat do you want to play with?\n");
    printf("> ");
    gets(catName);

    printf("\nAlright, %s it is!\n\n", catName);
    Sleep(3000);

    system("cls");
    bullet = rand() % 6 + 1; //Bullet placed into a random chamber between 1 and 6
    printf("A bullet has been placed into a random chamber of a 6 chamber revolver... But which one?");
    Sleep(5000);

    do {
        restart = false; //Set restart to false so we do not loop again unless told to
        system("cls");

        spin = rand() % 6 + 1; //The barrel has been spun and landed on a random chamber

        printf("The barrel has been spun. You land on chamber #%d. \nWould you like to pull the trigger? (y/n)", spin);
        printf("\n\n> ");
        scanf("%s", &trigger);

        if (strcmp(strlwr(trigger), "yes") == 0 || strcmp(strlwr(trigger), "y") == 0) { //User pulled the trigger
            if (bullet == spin) { //Dead cat! Show your final score and close the game
                printf("\033[0;31m");
                printf("\nBLAMO!!! You shot your cat... You ended with %d points.", points);
                printf("\033[0m");

                Sleep(5000);
                system("cls");
                
                printf("Game Over!");
                
                Sleep(2000);
                return 0;
            } else { //Alive cat! Add 1 point to the score and loop back to the start
                points++;
                printf("\033[0;32m");
                printf("\n*Click*! Your cat survived! You gain 1 point for a total of %d.\n\n", points);
                printf("\033[0m");
                
                printf("Let's play again!");
                
                Sleep(3000);
                restart = true; //Set restart to true so that the doWhile loop goes back up to the top
            }
        } else if (strcmp(strlwr(trigger), "no") == 0 || strcmp(strlwr(trigger), "n") == 0) { //User did not pull the trigger
            printf("\033[0;33m");
            printf("\nWhew! Alright, let's spin again!");
            printf("\033[0m");
            
            Sleep(3000);
            restart = true; //Set restart to true so that the doWhile loop goes back up to the top
        };
    } while (restart); //Check if restart is true or false

    return 0;
};