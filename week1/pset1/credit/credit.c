#include <stdio.h>
#include <cs50.h>

// global variables

int main(void)
{
    // PROMPT input
    long cc = get_long("Number: ");


    // card length
    long n = cc;
    int count = 0;
    while (0 < n)
    {
        n = n / 10;
        count++;
    }

    // CARD TYPES TEST

    int i16 = (cc / 1000000000000000 % 10);
    int i15 = (cc / 100000000000000 % 10);
    int i14 = (cc / 10000000000000 % 10);
    int i13 = (cc / 1000000000000 % 10);

    string card_type = "";

    // mastercard 16 digits, 51-55
    if ((i16 == 5) && (i15 >= 1 && i15 <= 5))
    {
        card_type = "MASTERCARD";
    }

    // visa 13 and 16 digits, starts with 4
    else if ((i16 == 4) || (i13 == 4))
    {
        card_type = "VISA";
    }

    // amex (15 digits, starts with 34 or 37)
    else if ((i15 == 3) && (i14 == 4 || i14 == 7))
    {
        card_type = "AMEX";
    }
    else
    {
        card_type = "INVALID";
    }

    // CHECKSUM

    int sum  = 0;
    int mod = 0;
    long x = cc;
    bool la_valid = false;

    while (x > 0)
    {
        mod = x % 10; // modulate odd
        sum = mod + sum; // add to sum
        x = x / 10; // next digit
        mod = x % 10; // modulate even digit

        // if double digit we need to treat different
        if ((mod * 2) > 9)
        {
            mod = ((mod * 2) % 10) + 1;
        }
        else
        {
            mod = mod * 2;
        }

        sum = (mod + sum); // add the even to sum
        x = x / 10; // grab the next digit for the cycle
    }

    if ((sum % 10) == 0)
    {
        la_valid = true;
    }
    else
    {
        la_valid = false;
    }

    if (la_valid == false)
    {
        card_type = "INVALID";
    }

    // print card details
    if (la_valid == true)
    {
        printf("%s\n", card_type);
    }
    else if (la_valid == false)
    {
        printf("%s\n", card_type);
    }
}
