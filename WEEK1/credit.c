#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long cc_num = get_long("Number: ");//卡号
    int size = 0;     //卡号有几位数字
    int first_digit;  //先指向倒数第一位，一直循环，直到指向到第一位卡号
    int second_digit; //第二次循环开始指向第一位，一直循环，知道指向第二位卡号
    int checksum = 0; //算法的计算结果
    long temp = cc_num;//临时变量
    for (; temp > 0; size++)
    {
        if (size > 0)//第二次循环开始有效
        {
            second_digit = first_digit;
        }
        first_digit = temp % 10;
        temp /= 10;
        if (size % 2 == 0)
        {
            checksum += first_digit;
        }
        else//倒数第二位开始每个各一个数都要*2，结果大于10要把个位和十位拆开相加
        {
            checksum += first_digit * 2 % 10 + first_digit * 2 / 10;
        }
    }
    if (checksum % 10 == 0)
    {
        //AMEX
        if (size == 15 && first_digit == 3 &&
         (second_digit == 4 || second_digit == 7))
        {
            printf("AMEX\n");
        }
        //MASTERCARD
        else if (size == 16 && first_digit == 5 &&
         (second_digit >= 1 && second_digit <= 5))
        {
            printf("MASTERCARD\n");
        }
        //VISA
        else if((size ==13 || size == 16) &&
         first_digit == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    //INVALID
    else
    {
        printf("INVALID\n");
    }
}
