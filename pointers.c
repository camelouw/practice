#include <stdio.h>

int main(void)
{
    /*
    *p - pointer, &n - address.
    I'm storing an address in a pointer here
    */
    int n = 50;
    int *p = &n;

    //printing variable and pointer. %p is to read the pointer data type
    printf("The number in the variable is %i, while the address pointer is %p\n", n, p);
    printf("");
}