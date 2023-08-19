#include <stdio.h>
#include <cs50.h>

// function prototype
void board();
char* validate(int index, char tmp);
int checkwin();
int check(int fst, int scnd, int trd);

// array of chars
char numbers [9] = {
    '1', '2', '3',
    '4', '5', '6',
    '7', '8', '9'
};
int main()
{
    // declaring variables
    char tmp = 0;
    int i = 0;
    int index = 0;
    int player = 0;
    int change_player = 1;
    
    // printing the game(board, X and O )
    do
    {
        printf("\t\t\t\tTic Tac Toe\n");
        printf("\t\t\t\tPlayer one X\n");
        printf("\t\t\t\tPlayer two O\n");
        // calling board function
        board();
        
        // changing player fron one to two and vice vercer
        if(change_player == 1)
        {
            if(player == 1)
            {
                player = 2;
            }
            else
            {
                player = 1;
            }
        }
        
        // setting player X and O
        if(player == 1)
        {
            tmp = 'X';
        }
        else
        {
            tmp = 'O';
        } 
               
        printf("Player %d(%c) Enter a number (1-9): ", player, tmp);
        index = GetInt();
        validate(index, tmp);
       
        i = checkwin();
    }
    while(i == 0);
    
    board();
    if(i == -1)
    {
        printf("Draw\n");
    }
    else if(i == 1)
    {
        printf("player %d(%c) wins\n", player, tmp);
    }
}
/*
 * Function that draw the board of the game
 * @param: list[]
 * @return: void
 */
void board()
{    
    int n = 0; 
    for(int i = 0; i < 3; i++)
    {
        
        printf("\t\t\t\t %c |", numbers[i + n]);
        n++;
        printf(" %c |", numbers[i + n]);
        n++;
        printf(" %c \n", numbers[i + n]);
        printf("\t\t\t\t---+---+---\n");
    }
}
/*
 * validate
 * Return numbers
 * @param: index, tmp
 * @return: char*
 */

char* validate(int index, char tmp)
{
        if(index == 1 && numbers[index - 1] == '1')
        {
            numbers[index - 1] = tmp;
        }
        else if(index == 2 && numbers[index - 1] == '2')
        {
            numbers[index - 1] = tmp;
        }
        else if(index == 3 && numbers[index - 1] == '3')
        {
            numbers[index - 1] = tmp;
        }
        else if(index == 4 && numbers[index - 1] == '4')
        {
            numbers[index - 1] = tmp;
        }
        else if(index == 5 && numbers[index - 1] == '5')
        {
            numbers[index - 1] = tmp;
        }
        else if(index == 6 && numbers[index - 1] == '6')
        {
            numbers[index - 1] = tmp;
        }
        else if(index == 7 && numbers[index - 1] == '7')
        {
            numbers[index - 1] = tmp;
        }
        else if(index == 8 && numbers[index - 1] == '8')
        {
            numbers[index - 1] = tmp;
        }
        else if(index == 9 && numbers[index - 1] == '9')
        {
            numbers[index - 1] = tmp;
        }
        else
        {
           printf("Invalid move\n");
        }
        return numbers;
}

int checkwin()
{
    //
    if(check(numbers[0], numbers[1], numbers[2]) == 1)
    {
        return 1;
    }
    else if(check(numbers[3], numbers[4], numbers[5]) == 1)
    {
        return 1;
    }
    else if(check(numbers[6], numbers[7], numbers[8]) == 1)
    {
        return 1;
    }
    else if(check(numbers[0], numbers[3], numbers[6]) == 1)
    {
        return 1;
    }
    else if(check(numbers[1], numbers[4], numbers[7]) == 1)
    {
        return 1;
    }
    else if(check(numbers[2], numbers[5], numbers[8]) == 1)
    {
        return 1;
    }
    else if(check(numbers[0], numbers[4], numbers[8]) == 1)
    {
        return 1;
    }
    else if(check(numbers[2], numbers[4], numbers[6]) == 1)
    {
        return 1;
    }
    else if(numbers[0] != '1' && numbers[1] != '2' && numbers[2] != '3' &&
            numbers[3] != '4' && numbers[4] != '5' && numbers[5] != '6' &&
            numbers[6] != '7' && numbers[7] != '8' && numbers[8] != '9')
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int check(int fst, int scnd, int trd)
{
    if(fst == scnd && scnd == trd)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
