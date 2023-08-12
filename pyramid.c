#include <stdio.h>
#include <cs50.h>

//prototype
void pattern(int height, int n, int i);
void row(int n);
void space(int n);
void column(int n);
void pattern2(int height, int n, int i);

int main()
{ 
    printf("height:~ ");
    int height = GetInt();
    printf("_____________________________\n");
    pattern(height, 1, height - 1);
    pattern2(height, height, 0);
}

void pattern(int height, int n, int i)
{
    if (height > 0)
    {
        space(i);
        row(n);
        printf(" ");
        column(n);
        printf("\n");
        pattern(height - 1, n + 1, i - 1);
    }
}

void row(int n)
{
    if(n > 0)
    {
        printf("*");
        row(n - 1);
    }
}

void space(int n)
{
    if(n > 0)
    {
        printf(" ");
        space(n - 1);
    }
}

void column(int n)
{
    if(n > 0)
    {
        printf("*");
        column(n - 1);
    }
}

void pattern2(int height, int n, int i)
{
    if (height > 0)
    {
        space(i);
        row(n);
        printf(" ");
        column(n);
        printf("\n");
        pattern2(height - 1, n - 1, i + 1);
    }
}
