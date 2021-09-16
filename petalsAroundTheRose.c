#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <stdbool.h>

/*
Author: Kyle Gorr
Version: 1.2.0
===========
"Petals Around the Rose" is a puzzle game played with dice. This code will randomly generate 5 numbers (roll the dice) and will ask you for an answer to the puzzle.

The Rules: The key to the formula is given by the name of the puzzle, and the presenter should state the name of the challenge distinctly. The calculated (announced) result for a throw is calculated by counting only the "petals around the rose", where a "rose" is any die face with a center dot. On a standard 6-sided die, this corresponds to the three odd faces—1, 3, and 5. The rose's "petals" are the dots which surround the center dot. There is no rose on the 2, 4, or 6 faces, so these count as zero. There are no petals on the 1 face, so it also counts as zero. There are two petals and four petals on the 3 and 5 faces, respectively. Thus, the solution to a given throw can be found by:

Adding the total petals, or;
Starting with 2 times the number of dice that land on the 3 face and adding to it 4 times the number of dice that lands on the 5 face.
For example, in a roll of 1-2-3-4-5-6, there is one 3 and one 5 face, so the result is two plus four, or six.

(Rules supplied by wikipedia)
*/


int main() {
   int i, n, a;
   time_t t;
   n = 5;
   int roll[5];
   int random;
   int input;
   bool restart = false;

   srand((unsigned) time(&t));

   do {
      restart = false;
      system("cls");
      printf("Your roll is: ");

      for ( i = 0 ; i < n ; i++ ) {
         random = rand() % 6 + 1;

         roll[i] = random;
         
         switch (random) {
            case 3: {
               a += 2;
               break;
            };

            case 5: {
               a += 4;
               break;
            };
         };

         printf("%d ", random);
      };

      printf("\n\nWhat is this answer to this roll?\nYour answer: ");

      scanf("%i", &input);

      if (input == a) {
         printf("Correct!");
         Sleep(3000);
      } else {
         printf("Incorrect, the answer was %d. Try again...\n", a);
         Sleep(3000);
         restart = true;
      };
   } while (restart);
   

   return 0;
};