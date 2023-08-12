#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <time.h>

//prototype
double square_root(double number);

int main()
{
    int n = GetInt();
    double number = n;
    printf("the square root of %f is %0.2f\n", number, square_root(number));
}

double square_root(double number)
{
    //making random values
    srand(time(NULL));
    
    double g = rand() % 10 + 1;
    printf("%f\n", g);
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
