// Ann Navarrete
// 29 January 2019
// Problem Set 1 - Cash code less comfortable
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(int argc, string argv[])
{
    // Set my coin integers
    int quarter;
    int dime;
    int nickle;
    int pennies;
    
    // Set my count or number of coins change owed
    int count = 0;
    
    float change;
    // To ensure user provides a valid float
    do
    {
        change = get_float("Change owed: ");
    }
    while (change < 0);
    
    // Round and convert dollar to cents
    int cents = round(change * 100);
    
    // Number of quarters
    for (quarter = 0; cents >= 25; quarter++)
    {
        cents -= 25;
        count += 1;
    }
    
    // Number of dimes
    for (dime = 0; cents >= 10; dime++)
    {
        cents -= 10;
        count += 1;
    }
    
    // Number of nickles
    for (nickle = 1; cents >= 5; nickle++)
    {
        cents -=5;
        count +=1;
    }
    
    // Number of pennies
    for (pennies = 0; cents >= 1; pennies++)
    {
        cents -=1;
        count +=1;
    }

    printf("%d\n", count);
}
