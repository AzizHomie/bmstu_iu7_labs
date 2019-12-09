#include <stdio.h>
#define OK 0
#define NOT_PRIME 1
#define NO_PRIME 2
#define RANGE_ERR 3
#define INPUT_ERR 4
#define N 10
// Array Input Function
int msv_input(int msv[], int *len_msv)
{
    printf("Enter number of elements: ");
    if (scanf("%d", len_msv) != 1)
        return INPUT_ERR;
    if (*len_msv <= 0 || *len_msv > N)
        return RANGE_ERR;
    printf("\nEnter elements: ");
    for (int i = 0; i < *len_msv; i++)
    {
        if (scanf("%d", &msv[i]) != 1)
            return INPUT_ERR;
    }
    return OK;
}
// Array Output Function
void msv_output(const int msv[], const int len_msv)
{
    for (int i = 0; i < len_msv; i++)
    {
        printf("%d ", msv[i]);
    }
}
//Prime number check
int is_prime(int number)
{
    if (number < 2)
        return NOT_PRIME;
    else
        for (int i = 2; i < number; i++)
        {
            if (number % i == 0)
                return NOT_PRIME;
        }
    return OK;
}
//Array of prime numbers
void prime_msv(const int old_msv[], const int len_msv, int *new_msv, int *prime_count)
{
    int j = 0;
    for (int i = 0; i < len_msv; i++)
    {
        if (!(is_prime(old_msv[i])))
        {
            new_msv[j] = old_msv[i];
            j++;
        }
    }
    *prime_count = j;
}

int main(void)
{
    int msv[N], new_msv[N], prime_count, len_msv, correct = OK;
    correct = msv_input(msv, &len_msv);
    if (correct == OK)
    {
        printf("\nPrime msv: ");
        prime_msv(msv, len_msv, new_msv, &prime_count);
        if (!prime_count)
        {
            printf("\nNo prime numbers detected!");
            correct = NO_PRIME;
        }
        else
            msv_output(new_msv, prime_count);
    }
    else if (correct == RANGE_ERR)
        printf("\nRange error!");
    else if (correct == INPUT_ERR)
        printf("\nInput error!");
    return correct;
}
