#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main () {
   int i, n, a;
   time_t t;
   n = 5;
   char roll;
   char r;

   srand((unsigned) time(&t));

   printf("Your roll is: ");

   for ( i = 0 ; i < n ; i++ ) {
      r = rand() % 6 + 1;

      strcat(roll, r);

      if (r == 3) {
         a + 2;
      };

      if (r == 5) {
         a + 4;
      };
   };

   printf("Your roll is: ");

   printf("\n\nWhat is the answer to this roll?\n");
   
   return(0);
};
