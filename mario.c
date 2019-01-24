// Mario code less comfortable

#include <cs50.h>
#include <stdio.h>

int get_positive_int(string prompt);
int main(void)

{
    int height = get_positive_int("Height: ");
}

// Prompt user for positive integer between 1-8 inclusive
int get_positive_int(string prompt)
{
    int max_height;
    do
    {
        max_height = get_int("%s", prompt);
    }
    while (max_height <1 || max_height >8);
    
    // This calculates the height and width of the pyramid
    for (int current_height = 0; current_height < max_height; current_height++)
    {
        // This prints the number of dots for every given line
        for (int column = 0; column < max_height-current_height -1; column++)
        {
            printf(" ");
        }
        
        // This prints the number of hashes for every given height and line
        for (int column = 0; column < current_height + 1; column++)
        {
            printf("#");
        }
        
        printf("\n");
    }
    
    return max_height;
}

