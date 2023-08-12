#include <stdio.h>
#include <cs50.h>
#define DIVISOR 2

// prototype
long long to_binary(int number);

int main ()
{
   
   int n = GetInt();
   printf("Decimal \t Binary\n");
   for(int number = 1; number <= n; number++)
   {
        
        printf("%i \t|\t %lli\n", number, to_binary(number));
   }
}

long long to_binary(int number)
{
    int remainder = 0;
    int position = 1;
    int binary = 0;
    while(number != 0)
    {
        remainder = number % DIVISOR;
        binary += remainder * position;
        position *= 10;
        number = number / DIVISOR;
    }
    return binary;
}
