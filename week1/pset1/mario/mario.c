#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // user input for height specifications
    int height = 0;
    do
    {
        height = get_int("height: ");
    }
    while (height < 1 || height > 8);

    //bricks and spaces
    int r, b, s;
    //rows
    for (r = 0; r < height; r++)
    {
        //spaces
        for (s = 1; s < height - r; s++)
        {
            printf(" ");
        }
        //brick
        for (b = 0; b <= r; b++)
        {
            printf("#");
        }
        printf("  ");
        //brick
        for (b = 0; b <= r; b++)
        {
            printf("#");
        }
        printf("\n");
    }
}