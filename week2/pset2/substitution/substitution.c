#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

// command line argument
int main(int argc, string argv[]) 
{
    // simplify "key" 
    string key = argv[1];

    // is there a command argument?
    if (argc == 1)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // check for spaces
    for (int i = 0; i < strlen(key) ; i++)
    {
        if (isspace(key[i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }
    // check == 26 length
    if (strlen(key)  != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // isalpha?
    for (int i = 0; i < strlen(key) ; i++)
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
        for (int j = 0; j < strlen(key) ; j++)
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
    char ciphertext[plaintext_length];
    int key_length = strlen(key);

    // plaintext to ciphertext
    for (int i = 0; i < plaintext_length; i++)
    {
        // upper?
        if (isupper(plaintext[i]))
        {
            for (int j = 0; j < key_length; j++)
            {
                if (plaintext[i] == alphabet[j])
                {
                    ciphertext[i] = key[j];
                }
            }
        }
        
        // lower?
        else if (islower(plaintext[i]))
        {
            for (int j = 0; j < strlen(alphabet); j++)
            {
                if (plaintext[i] == tolower(alphabet[j]))
                {
                    ciphertext[i] = tolower(key[j]);
                }
            }
        }
        else
        {
            // non alphabetic chars
            ciphertext[i] = plaintext[i];
        }
    }
    // print ciphertext
    ciphertext[plaintext_length] = '\0';
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}


/*
Github created token
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
*/