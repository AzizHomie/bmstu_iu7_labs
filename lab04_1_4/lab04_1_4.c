#include<stdio.h>
#define N 10
#define INP_ERR -1
#define RNG_ERR -2

void sort(int m[], int *len)
{
    int tmp;
    int j;
    for (int i = 1; i < *len; i++)
    {
        tmp = m[i];
        j = i - 1;
        while ((j >= 0) && (m[j] > tmp))
        {
            m[j + 1] = m[j];
            j -= 1;
        }
        m[j + 1] = tmp;
    }
}

int input(int m[], int *len)
{
    printf("Input size: ");
    if (scanf("%d", len) != 1)
    {
        printf("Input Error!");
        return INP_ERR;
    }
    if (*len <= 0)
    {
        printf("Range Error!");
        return RNG_ERR;
    }
    else
    {
        printf("Input sqc: ");
        for (int i = 0; i < *len; i++)
        {
            if (scanf("%d", &m[i]) != 1)
            {
                printf("Input error!");
                return INP_ERR;
            }
        }
    }
    return 0;
}

void output(int m[], int *len)
{
    printf("\nNew array: ");
    for (int i = 0; i < *len; i++)
        printf("%d ", m[i]);
}

int main()
{
    int m[N];
    int len;
    if ((input(m, &len)))
        return INP_ERR;
    else
    {
        sort(m, &len);
        output(m, &len);
    }
    return 0;
}