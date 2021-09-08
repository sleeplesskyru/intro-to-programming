#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

float radius, area;
char str[25];

int main(void) {
    bool restart = false;
    do {
        restart = false;
        system("cls");

        printf("Enter the radius: \n");

        if (scanf("%f", &radius) != 1) {
            printf("The radius must be a number.\n\n");
            
            system("pause");

            restart = true;
        };

        printf("You said %.1f... Is that right?\n", radius);
        scanf("%s", str);

        if (strcmp(strlwr(str), "yes") == 0 || strcmp(strlwr(str), "y") == 0) {
            area = (float) (3.14159 * radius * radius);

            printf("The area of the circle is: %.1f\n\n", area);

            system("pause");
        } else if (strcmp(strlwr(str), "no") == 0 || strcmp(strlwr(str), "n") == 0) {
            restart = true;
        };
    } while (restart);

    return 0;
};