#include <stdio.h>

int main (void)
{
    // declaring members of TeamCamel
    int rach = 27;
    int cam = 32;

    // Who is younger in TeamCamel
    int youngest = ((cam < rach) ? cam : rach); // check for smallest variable

    // print youngest in statement
    printf("Within TeamCamel, the youngest partner is %d years old.\n", youngest);

    return 0;
}

