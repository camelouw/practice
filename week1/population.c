#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size (using do-while)
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    // Prompt for end size (using do-while)
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    //declare variable - prototype
    int year = 0;

    //calculation for number of years to reach end population
    while (start < end)
    {
        start = (start/3) - (start/4) + start;
        year++;
    }
    printf ("Years: %i\n", year);
}