#include <stdio.h>

int main (void)
{
    // Printing ASCII Values from numbers
    for (int i = 33; i < 127; i++)
    {
        printf("\nASCII Value: %c, Number Value: %d\n", i, i);
    }
    return 0;
}

