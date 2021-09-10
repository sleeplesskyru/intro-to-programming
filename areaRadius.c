#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
Author: Kyle Gorr
Version: 1.0.2
====
This code is based off the code in section 1 of our C Programming text book with a little extra added to it.

In addition to the main purpose, finding the area of a circle by it's given radius, this program also implements if statements to ensure you enter the correct values.
I have also used a `do...while` loop which is similar to a `while` loop but it will run the code first and THEN check the `while` condition and loop back if the value is true.
*/

//Defining variables outside of main() so we can use them anywhere in this file.
float radius, area;
char str[];

int main(void) {
    bool restart = false; //`restart` will be `false` by default and changed if needed... (bool uses <stdbool.h>)
    do {
        restart = false; //If loop restarts, we want `restart` to be `false` again...
        system("cls"); //Clears all previous text in the console... (system() uses <stdlib.h>)

        printf("Enter the radius: \n");

        if (scanf("%f", &radius) != 1) { //checks if the user input value is a float and store value in `radius`. If false: runs code in {} block...
            printf("The radius must be a number.\n\n");
            
            system("pause"); //waits for user to press a key to continue...

            restart = true; //Sets `restart` to true so the `while` condition reads `true` and restarts the `do` loop...
        };

        printf("You said %.1f... Is that right?\n", radius);
        scanf("%s", str);

        if (strcmp(strlwr(str), "yes") == 0 || strcmp(strlwr(str), "y") == 0) { //strcmp compares two strings (0 means that the strings are the same). strlwr(x) takes the given string and converts it to lowercase... (uses <string.h>)
            area = (float) (3.14159 * radius * radius);

            printf("The area of the circle is: %.1f\n\n", area);

            system("pause");
        } else if (strcmp(strlwr(str), "no") == 0 || strcmp(strlwr(str), "n") == 0) {
            restart = true;
        };
    } while (restart); //if `restart` == true, the whole `do...while` loop starts back at the top. To check `false`, you would write it as `while (!restart)`...

    return 0;
};