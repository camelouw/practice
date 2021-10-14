// This readability test is based on the Coleman-Liau index, designed to output what (U.S.) grade level is needed to understand the text.
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// initialise that these functs exist after main()
int count_letters(string text); // function
int count_words(string text); // function
int count_sentences(string text); // function

int main(void)
{
    // prompt user for string of text to analyse
    string text = get_string("Text: ");

    // returned ints of functions: count of letters, words and sentences
    int l = count_letters(text);
    int w = count_words(text);
    int s = count_sentences(text);

    // calculation averages(a) along with coleman-liau index
    float as = ((float)s / (float)w) * 100; // (sentence/words) * 100 (2 deci) // S is the average sentences per 100 words
    float al = ((float)l / (float)w) * 100; // (letters/words) * 100 (2deci) // L is the average of letters per 100 words

    float grade = 0.0588 * al - 0.296 * as - 15.8; // coleman-liau index

    // print to screen (this will include if statements to determine the grade)
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)round(grade));
    }
}
// count letters in text - func
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n ; i++)
    {
        if (isalnum(text[i]))
        {
            letters++;
        }
    }
    return letters;
}
// count words in text
int count_words(string text)
{
    int words = 1;
    for (int j = 0, m = strlen(text); j < m ; j++)
    {
        if (isspace(text[j]))
        {
            words++;
        }
    }
    return words;
}
// count senstences in text
int count_sentences(string text) // count words in text (seperated by (a). (b)! (c)?)
{
    int sentence = 0;
    for (int k = 0, g = strlen(text); k < g ; k++)
    {
        if (text[k] == ('.'))
        {
            sentence++;
        }
        else if (text[k] == ('?'))
        {
            sentence++;
        }
        else if (text[k] == ('!'))
        {
            sentence++;
        }
    }
    return sentence;
}
