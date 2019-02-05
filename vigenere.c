// Ann Navarrete
// 05 February 2019
// Problem Set 2 - Vigenere
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int shift(char c);

int main(int argc, string argv[])
{
    // Ensure the program has only one command-line
    if (argc != 2)
    {
        printf("Usage: ./vigenere key\n");
        return 1;
    }
    else
    { 
        // Ensure user only enter key in alphabet
        string key = (argv[1]);
        
        //Make sure command line argument is alpha
        for (int i = 0; i < strlen(key); i++)
        {
            if (isalpha(key[i]) == false)
            {
                printf("Usage: ./vigenere key\n");
                return 1;
            }
        } 
        // Prompt user input in plaintext
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        
        for (int i = 0; i < strlen(plaintext); i++)
        {   
            char keyChar = key[i % strlen(key)];
            int amountToShift = shift(keyChar);
            printf("%c", plaintext[i] + amountToShift);
        }
        printf("\n");
    }   
    return 0;
}

int shift(char c)
{
    // If isUpper then minus 65
    if (isupper(c))
    {
        return c - 65;
    }
    
    // If isLower then minus 97
    else if (islower(c))
    {
        return c - 97;
    }
    return 0;
}

