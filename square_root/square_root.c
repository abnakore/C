#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <time.h>

//prototype
double square_root(double number);

int main()
{
    // Get a user input
    int n = GetInt();
    double number = n;
    // Print the output
    printf("the square root of %f is %0.2f\n", number, square_root(number));
}

/*
 * @name: square_root
 * @param: number
 * @return: double
 * Compute the square root of the given number.
 */
double square_root(double number)
{
    // Making random values
    srand(time(NULL));
    double g = rand() % 10 + 1;

    printf("%f\n", g);

    // Using newton raphson method to compute the square root.
    while(g != number)
    {
        if(g * g >= number - 0.5 && g * g <= number + 0.00001)
        {
            
            return g;
        }
        g = (g + (number/g)) / 2;
    }
    return g;
}
