#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Program Function: min coins handed using 25c, 10c, 5c and 1c

    // variable set and accepting user input
    float change_owed;
    do
    {
        change_owed = get_float("Change owed: ");
    }
    while (change_owed > 100 || change_owed < 0);

    // setting coin variable and calculating number of coins provided
    int coins = 0;

    while (change_owed >= 0.249)
    {
        change_owed = change_owed - 0.25;
        coins++;
        printf("25c - change owed: %f, coins given: %i\n", change_owed, coins);
    }

    while (change_owed >= 0.099)
    {
        change_owed = change_owed - 0.1;
        coins++;
        printf("10c - change owed: %f, coins given: %i\n", change_owed, coins);
    }

    while (change_owed >= 0.049)
    {
        change_owed = change_owed - 0.05;
        coins++;
        printf("5c - change owed: %f, coins given: %i\n", change_owed, coins);
    }

    while (change_owed >= 0.009)
    {
        change_owed = change_owed - 0.01;
        coins++;
        printf("1c - change owed: %f, coins given: %i\n", change_owed, coins);
    }

    // printing calculated coins min to user
    printf("%i\n", coins);
}