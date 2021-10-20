#include <stdio.h>

int main(void) {
    int x = 7;
    int *aptr = &x;

    printf("x = %d\n", x);
    printf("The address of x is: %x\n", aptr);

    getchar();
    
    return 0;
};