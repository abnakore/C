#include <cs50.h>
#include <stdio.h>
#include <time.h>

void quize(int fn, int sn, int scores);

int main()
{
    srand(time(NULL));
    int fn = rand() % 10;
    int sn = rand() % 10;
    quize(fn, sn, 0);
}

void quize(int fn, int sn, int scores)
{
    printf("what is %i + %i\n", fn, sn);
    const int myanswer = fn + sn;
    int u_answer = GetInt();
    if(u_answer == myanswer)
    {
        printf("Correct answer!\n");
        srand(time(NULL));
        int n1 = rand() % 10;
        int n2 = rand() % 10;
        quize(n1, n2, scores + 1);
    }
    else
    {
        printf("Wrong answer\n");
        printf("The correct answer is %i\n", myanswer);
        printf("Your total score is %i\n", scores);
    }
}
