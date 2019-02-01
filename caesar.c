#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
    
{
    // Ensure the program has only one command-line
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    { 
        // Converting string to integers
        int key = atoi(argv[1]);
        // Prompt user input in plaintext
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        
        for (int i = 0; i < strlen(plaintext); i++)
        {
            // Encrypt and preserve lower case characters
            if islower(plaintext[i])
            {
                // Position of the character in the alphabet
                int alphaPos = plaintext[i] + key - 97; 
                // Keep the number within the alphabet loop
                int wrappedChar = alphaPos % 26;
                printf("%c", wrappedChar + 97);
            }
            if isupper(plaintext[i])
            {
                int alphaPos = plaintext[i] + key - 65;
                int wrappedChar = alphaPos % 26;
                printf("%c", wrappedChar + 65);
            }
        }
        printf("\n");
    }   
    return 0;
}
