#include<stdio.h>

int func(int n, int a)
{
    if (n == 0)
    {
        a = 1;
    }
    else
    {
        int f = a;
        for (int i = 1; i < n; i++)
        {
            a = a * f;
        }
    }
    return a;
}

int main(void)
{
    int a, n;
    printf("Input a: ");
    if (scanf("%d", &a) != 1)
    {
        printf("Error!");
        return 1;
    }
    printf("Input n: ");
    if (scanf("%d", &n) != 1)
    {
        printf("Error");
        return 1;
    }
    if (n <= 0)
    {
        printf("Input Error");
        return 1;
    }
    else
    {
        printf("a in n is: %d", func(n, a));
    }
    return 0;
}