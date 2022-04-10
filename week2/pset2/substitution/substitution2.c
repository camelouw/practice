#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
z
// command line argument
int main (int argc, string argv[]) 
{
    // simplify "key" and key_length
    string key = argv[1];
    int key_length = strlen(argv[1);

    // is there a command argument?
    if (argc == 1)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // 2 check for spaces
    for (int i = 0; i < argv; i++)
    {
        if (isspace(key[i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }
    // 2 check == 26 length
    if (strlen(argv) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // 2 isalpha?
    for (int i = 0; i < strlen(argv[i]); i++)
    {
        if (isalpha(key[i]))
        {
            // 2  convert to UPPER (insensitive)
            key[i] = toupper(key[i]);
        }
        else
        {
            printf("Key must only contain aplhabetic characters.\n");
            return 1;
        }
        // check repeating // factoring in when index matches
        for (int j = 0; j < strlen(argv[j]); j++)
        {
            if (key[i] == key[j] && (i != j))
            {
                printf("Key must not contain repeated character.\n");
                return 1;
            }
        }
    }    

    // get plaintext and ciphertext
    string plaintext = get_string("plaintext: ");
    int plaintext_length = strlen(plaintext);
    char ciphertext[26];

    // plaintext to ciphertext
    for (int i = 0; i < strlen(alphabet); i++) 
    {
        if (islower(plaintext[i])) // lower?
        {
            if (plaintext[i] == tolower(alphabet[i]))
            {
                ciphertext[i] = tolower(key[i]);
            }
        }
        else // upper?
        {
            if (plaintext[i] == toupper(alphabet[i]))
            {
                ciphertext[i] = toupper(key[i]);
            }
        }
    }
    
    // 5 print ciphertext
    ciphertext[plaintext_length] = '\0'; // end or string
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}
/*
Github created token
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
*/





    /*
    for (int i = 0; i < plaintext_length; i++)
    {
        for (int j = 0; j < 26; j++)
        {   
            //upper?
            if (isupper(plaintext[i]) == alphabet[j])
            {
                ciphertext[i] = toupper(key[j]);
            }
            else if (islower(plaintext[i]) == tolower(alphabet[j]))
            {
                ciphertext[i] = tolower(key[j]);
            }
            else
            {
                // 4 non alphabetic chars
                ciphertext[i] = plaintext[i];
            }
            */