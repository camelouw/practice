#include <stdio.h>
#include <cs50.h>

// global variables

int main(void)
{
    // PROMPT input
    long cc = get_long("Number: ");
    //long cc = 378282246310005; //amex test

    // 'indexing' card numbers

    int i1  = (cc / 1) % 10;
    int i2  = (cc / 10) % 10;
    int i3  = (cc / 100) % 10;
    int i4  = (cc / 1000) % 10;
    int i5  = (cc / 10000) % 10;
    int i6  = (cc / 100000) % 10;
    int i7  = (cc / 1000000) % 10;
    int i8  = (cc / 10000000) % 10;
    int i9  = (cc / 100000000) % 10;
    int i10 = (cc / 1000000000) % 10;
    int i11 = (cc / 10000000000) % 10;
    int i12 = (cc / 100000000000) % 10;
    int i13 = (cc / 1000000000000) % 10;
    int i14 = (cc / 10000000000000) % 10;
    int i15 = (cc / 100000000000000) % 10;
    int i16 = (cc / 1000000000000000) % 10;

    // CHECKSUM

    // card number length
    long n = cc;
    int count = 0; //need to start at -2 as a workaround to multiplying cc by 100
    while (0 < n)
    {
        n = n / 10;
        count++;
    }

    //CHECKSUM

    int odd  = 0;
    int even = 0;
    int sum  = 0;

    // LUHN ALGORITHM TEST

    // variables
    bool la_valid = false;
    //bool type_valid = false;

    // algorithm
    //even = 2 * (i16 + i14 + i12 + i10 + i8 + i6 + i4 + i2);

    if ((count == 16) && ((i16 * 2) >= 10))
    {
        even = ((i16 * 2) % 10) + 1;
    }
    else
    {
        even = even + (i16 * 2);
    }

    if ((i14 * 2) >= 10)
    {
        even = ((i14 * 2) % 10) + 1;
    }
    else
    {
        even = even + (i14 * 2);
    }

    if ((i12 * 2) >= 10)
    {
        even = ((i12 * 2) % 10) + 1;
    }
    else
    {
        even = even + (i12 * 2);
    }

    if ((i10 * 2) >= 10)
    {
        even = ((i10 * 2) % 10) + 1;
    }
    else
    {
        even = even + (i10 * 2);
    }

    if ((i8 * 2) >= 10)
    {
        even = ((i8 * 2) % 10) + 1;
    }
    else
    {
        even = even + (i8 * 2);
    }

    if ((i6 * 2) >= 10)
    {
        even = ((i6 * 2) % 10) + 1;
    }
    else
    {
        even = even + (i6 * 2);
    }

    if ((i4 * 2) >= 10)
    {
        even = ((i4 * 2) % 10) + 1;
    }
    else
    {
        even = even + (i4 * 2);
    }

    if ((i2 * 2) >= 10)
    {
        even = ((i2 * 2) % 10) + 1;
    }
    else
    {
        even = even + (i2 * 2);
    }

    odd = (i15 + i13 + i11 + i9 + i7 + i5 + i3 + i1);
    sum = (odd + even);
    //type_valid = true;

    // luhn algorithm
    if (sum % 10 == 0)
        {
            la_valid = true;
        }
        else if (sum % 10 != 0)
        {
            la_valid = false;
        }

    // CARD TYPES TEST

    string card_type = "";

    // mastercard 16 digits, 51-55
    if ((count == 16) && (i16 == 5) && (i15 >= 1 && i15 <= 5))
    {
        //type_valid = true;
        card_type = "MASTERCARD";
    }

    // visa 13 and 16 digits, starts with 4
    else if ((count == 16 && i16 == 4) || (count == 13 && i13 == 4))
    {
        //type_valid = true;
        card_type = "VISA";
    }

    // amex (15 digits, starts with 34 or 37)
    else if ((count == 15) && (i15 == 3) && (i14 == 4 || i14 == 7))
    {
        //type_valid = true;
        card_type = "AMEX";
    }
    else
    {
        card_type = "INVALID";
    }

    // print card details
    if (la_valid == true)
    {
        printf("%s\n", card_type);
    }
    else
    {
        printf("INVALID");
    }

    // TESTS
/*
    printf("card type: %s\n", card_type);//testing card type
    printf("sum: %i\n", sum); //testing sum
    printf("type valid: %s\n", type_valid ? "true" : "false");//testing card type validity
    printf("luhn valid: %s\n", la_valid ? "true" : "false");//testing la validity
    printf("count: %i\n", count); //testing count
*/
}

//camelouw
//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








//    amex     371449635398431