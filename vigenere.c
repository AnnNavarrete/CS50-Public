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
        
        int j = 0;
        
        for (int i = 0; i < strlen(plaintext); i++)
        {   
            char keyChar = key[j % strlen(key)];
            int amountToShift = shift(keyChar);
            
            // Encrypt and preserve lower case characters
            if islower(plaintext[i])
            {
                // Position of the character in the alphabet
                int alphaPos = plaintext[i] + amountToShift - 97; 
                // Keep the number within the alphabet loop
                int wrappedChar = alphaPos % 26;
                j = j + 1;
                printf("%c", wrappedChar + 97);
            } 
            else if isupper(plaintext[i])
            {
                int alphaPos = plaintext[i] + amountToShift - 65;
                int wrappedChar = alphaPos % 26;
                j = j + 1;
                printf("%c", wrappedChar + 65);
            }
            else 
            {
                printf("%c", plaintext[i]);
            }
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

