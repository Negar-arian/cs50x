#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long n = get_long("Number: ");
    int i = 0;
    long c = n;
    long a = n;
    long b = n;
    int f;
    int sum1 = 0;
    int sum2 = 0;
    int num1;
    int num2;
    int c1;
    int c2;
    while (c > 0)
    {
        c = c / 10;
        i++;
    }
    do
    {
        num1 = a % 10;
        a /= 10;
        sum1 += num1;

        num2 = a % 10;
        a /= 10;
        num2 *= 2;
        if (num2 >= 10)
        {
            c1 = num2 % 10;
            c2 = num2 / 10;
            sum2 += c1 + c2;
        }
        else
        {
            sum2 += num2;
        }
    }
    while (a > 0);
    sum2 = sum1 + sum2;
    printf("sum2 = %i",sum2);
    sum1 = sum2 % 10;
    while (b > 100)
    {
        b /= 10;
    }
    f = b / 10;
    if (sum1 != 0)
    {
        printf("INVALID\n");
    }
    else if (i == 15 && (b == 34 || b == 37))
    {
        printf("AMEX\n");
    }
    else if (i == 16 && (51 <= b && b <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((i == 13 || i == 16) && f == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
