#include <cs50.h>
#include <stdio.h>
#include <time.h>

void quize(int fn, int sn, int scores);

int main()
{
    // Set random numbers
    srand(time(NULL));
    int fn = rand() % 10;
    int sn = rand() % 10;
    quize(fn, sn, 0);
}

/*
 * @name: quize
 * @param: fn, sn, scores
 * @return: void
 * Ask a user questions on addition.
 */
void quize(int fn, int sn, int scores)
{
    // Ask a user the sum of the first and second number
    printf("what is %i + %i\n", fn, sn);
    // Computing the correct answer
    const int myanswer = fn + sn;
    // Getting the users input
    int u_answer = GetInt();
    // Check if the inputted answer is correct
    if(u_answer == myanswer)
    {
        printf("Correct answer!\n");
        // Regenerate another random numbers
        srand(time(NULL));
        int n1 = rand() % 10;
        int n2 = rand() % 10;
        quize(n1, n2, scores + 1);
    }
    else
    {
        // If the answer is not correct
        // Display the correct answer
        // display the scores
        printf("Wrong answer\n");
        printf("The correct answer is %i\n", myanswer);
        printf("Your total score is %i\n", scores);
    }
}
