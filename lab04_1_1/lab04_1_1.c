#include <stdio.h>
#define OK 0
#define NOT_ODD_NUMBER -1
#define NO_ODD -2
#define RNG_ERR -3
#define INP_ERR -4
#define N 10

//Array Input Function
int msv_input(int a[], int *size)
{
    printf("Enter number of elements: ");
    if (scanf("%d", size) != 1)
        return INP_ERR;
    if (*size <= 0 || *size > N)
        return RNG_ERR;
    printf("\nEnter elements: ");
    for (int i = 0; i < *size; i++)
    {
        if (scanf("%d", &a[i]) != 1)
            return INP_ERR;
    }
    return OK;
}

//Parity checking function
int is_odd_number(int number)
{
    if (number % 2 == 0)
        return NOT_ODD_NUMBER;
    return OK;
}

//Multiplication of odd numbers
int counter(const int a[], int size, int *new_a, int count)
{
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (!(is_odd_number(a[i])))
        {
            new_a[j] = a[i];
            j++;
        }
    }
    if (j == 0)
        return NO_ODD;
    size = j;
    int f = 0;
    int answer = new_a[0];
    for (int i = 1; i < j; i++)
    {
        f = new_a[i] * answer;
        answer = f;
    }
    return answer;
}

int main(void)
{
    int a[N], new_a[N], size, correct = OK;
    int count = 0;
    correct = msv_input(a, &size);
    if (correct == OK)
    {
        if (size == 0 || counter(a, size, new_a, count) == NO_ODD)
        {
            printf("\nThere's No odd numbers!");
            correct = NO_ODD;
        }
        else
            printf("\nProizvedenie nechetnix chisel: %d", counter(a, size, new_a, count));
    }
    else if (correct == RNG_ERR)
        printf("\nRange error!");
    else if (correct == INP_ERR)
        printf("\nInput error!");
    return correct;
}