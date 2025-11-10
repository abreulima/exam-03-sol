#include <stdio.h>

void display(int *sub, int subsize)
{
    for (int i = 0; i < subsize; i++)
    {
        printf("%d",  sub[i]);
        if (subsize - 1 != i )
            printf(" ");
    }
    printf("\n");
}

int subsum(int *sub, int subsize)
{
    int total;

    total = 0;

    for (int i = 0; i < subsize; i++)
    {
        total += sub[i];
    }

    return (total);
}

void solve(int *num, int size, int *sub, int target, int subsize, int level)
{
    if (level == size)
    {
        if (subsum(sub, subsize) == target)
            display(sub, subsize);
        return ;
    }
    sub[subsize] = num[level];
    solve(num, size, sub, target, subsize + 1, level + 1);
    solve(num, size, sub, target, subsize, level + 1);
}

int main()
{
    int nums[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    int subsize[1000];
    int target = 5;


    solve(nums, size, subsize, target, 0, 0);
}
