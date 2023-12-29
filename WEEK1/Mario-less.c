#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)//打印一竖列#
    {
        for (int j = 0; j < n; j++)//打印一横行#
        {
            if (j + i >= n - 1)//满足要打印图形条件的坐标系构成的函数
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
