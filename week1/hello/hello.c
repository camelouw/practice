#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //promnt user's name and print a greeting to them
    string user_name = get_string("What is your name? ");
    printf("hello, %s\n", user_name);
}