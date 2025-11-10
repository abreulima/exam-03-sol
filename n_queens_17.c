#include <stdio.h>

int board[100000] = {0};
int board_size = 0;

void display()
{
    for (int i = 0; i < board_size; i++)
    {
        printf("%d", board[i]);
        if (board_size - 1 != 1)
            printf(" ");
    }
    printf("\n");
}


int ft_abs(int n)
{
    return n > 0? n : -n;
}

int is_safe(int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        if (board[i] == row)
            return (0);

        if (board[i] - row == ft_abs(col - i))
            return (0);
    }
    return (1);
}


void solve(int col)
{
    if (col == board_size)
    {
        //display();
        return ;
    }
    for (int row = 0; row < board_size; row++)
    {
        if (is_safe(row, col))
        {
            board[col] = row;
            solve(col + 1);
        }
    }
}

#include <time.h>

int main()
{

    board_size = 12;
    clock_t t;
    t = clock();
    solve(0);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("fun() took %f seconds to execute \n", time_taken);
}
