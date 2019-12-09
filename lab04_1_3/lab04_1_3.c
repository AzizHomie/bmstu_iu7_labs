#include "stdio.h"
#define INP_ERR -1
#define N 10

// This function adds Fibb numbers after all numbers divisible by 3
void new_array(int m[], int *new_m, const int len, int *size)
{
    int j = 0;
    int fib1 = 0, fib2 = 1, tmp;
    for (int i = 0; i < len; i++)
    {
        new_m[j] = m[i];
        j++;
        if ((m[i] % 3 == 0))
        {
            new_m[j] = fib1;
            j++;
            tmp = fib1;
            fib1 = fib2;
            fib2 += tmp;
        }
    }
    new_m[j] = fib2;
    *size = j;
}

int count(int m[], int *len)
{
    int count_div = 0;
    for (int i = 0; i < *len; i++)
    {
        if (m[i] % 3 == 0)
            count_div++;
    }
    return count_div;
}

int input(int m[], int *len)
{
    printf("Input size: ");
    if (scanf("%d", len) != 1)
        return INP_ERR;
    printf("Input sqc: ");
    for (int i = 0; i < *len; i++)
    {
        if (scanf("%d", &m[i]) != 1)
            return INP_ERR;
    }
    return 0;
}

void output(int *new_m, const int *size)
{
    for (int i = 0; i < *size; i++)
    {
        printf("%d ", new_m[i]);
    }
}

int main()
{
    int m[N];
    int len, size;
    if ((input(m, &len)))
    {
        printf("Input Error!");
        return INP_ERR;
    }
    int count_div = count(m, &len);
    int new_m[count_div + len];
    new_array(m, new_m, len, &size);
    output(new_m, &size);
    return 0;
}