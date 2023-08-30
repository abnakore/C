#include <stdio.h>
#include <cs50.h>
#define DIVISOR 2

// prototype
long long to_binary(int number);

int main ()
{
    // Get an number from the user n
   int n = GetInt();
   printf("Decimal \t Binary\n");
    // Give the binary values of numbers form 1 throught n
   for(int number = 1; number <= n; number++)
   {        
        printf("%i \t|\t %lli\n", number, to_binary(number));
   }
}

/*
 * @name: to_binary
 * @param: number
 * @return: long long
 * Convert the number from decimal to binary.
 */
long long to_binary(int number)
{
    // Declaring variables
    int remainder = 0;
    int position = 1;
    int binary = 0;
    while(number != 0)
    {
        // Get the remainder
        remainder = number % DIVISOR;
        // Placing the remainder to the begining of the binary
        binary += remainder * position;
        position *= 10;
        // Divide the number by the divisor
        number = number / DIVISOR;
    }
    // return the final binary value
    return binary;
}
