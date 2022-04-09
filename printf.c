#include <stdio.h>

int main (void)
{
    // random print statements dealing with common data types
    printf("I am leaning something new in %c.\n", 'C');
    printf("How far can I take this %s.\n", "journey");
    printf("%d day I'll be incredible with coding. Watch me.\n", 1);
    printf("I'm %.1f%c sure it takes discipline to achieve your goals.\n", 99.9, '%'); //1floating point
    printf("I am %d%c sure, i can do at least %d thing better in this moment.\n", 100, '%', 1);


    // definining pointer
    int *p;
    // int grade is a regular int
    int grade = 100;
    // storing address of grade in p (sharing pointers)
    p = &grade;//dereference 

    printf("\npointer of p is at %p and pointer of grade is at %p. As you see they share memory after dereferncing.\n", p, &grade);

    return 0;
}

