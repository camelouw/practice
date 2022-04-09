#include <stdio.h>
// program that promts for 3 numbers and adds them together.

int main (void)
{
    // define 3 values we're adding
    float value_1 = 0.0, value_2 = 0.0, value_3 = 0.0;

    // describe program to user
    printf("\nLet's add 3 values, when i promt a value, give me a number.\n\n");
    // Ask for values using scanf
    printf("\tWhat's the first value? ");
    scanf(" %f", &value_1);
    printf("\tWhat's the second value? ");
    scanf(" %f", &value_2);
    printf("\tWhat's the last value? ");
    scanf(" %f", &value_3);
    // Add values and print statement
    float total = value_1 + value_2 + value_3;

    // creating int equavalint for code below (removal of decimal where not needed
    int itotal = (int)total; // truncated

    // removing decimal if needed
    if (total - (float)itotal > 0) // when a float is present
    {
        printf("\nThx\be total value is $%.2f\n\n", total); //\b is a backslash that will remove the x and e follows
    }
    if (total == (float)itotal) // when it's better to print int
    {
        printf("\nThe total value is $%d\n\n", itotal);
    }
    return 0;
}

