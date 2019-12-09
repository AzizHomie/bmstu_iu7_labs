#include <stdio.h>
#include <stdlib.h>
#define OK 0
#define ERR_INPUT -1
#define ERR_RANGE -2
#define ERR_ALLOCATION -3

/**
 * @brief Функция ввода.
 *
 * @param **array - массив.
 * @param *n - количество элементов массива.
 * @param *p - позиция на которую нужно вставить максимальный элемент.
*/

int input(float **array, int *n)
{
    int rc = OK;
    float *a = NULL;

    printf("Enter n: ");
    if (scanf("%d", n) != 1)
    {
        rc = ERR_INPUT;
        return rc;
    }
    if (*n <= 0)
    {
        rc = ERR_RANGE;
        return rc;
    }
    a = malloc(*n * sizeof(float));
    if (a == NULL)
    {
        rc = ERR_ALLOCATION;
        return rc;
    }
    printf("Enter elements:\n");
    for (int i = 0; i < *n; i++)
    {
        if (scanf("%f", &a[i]) != 1)
        {
            rc = ERR_INPUT;
            free(a);
            return rc;
        }
    }
    *array = a;
    //a = NULL;

    return rc;
}

//Функция вывода.
void print(const float *b, int n)
{
    printf("\nNew Array:\n");
    for (int i = 0; i < n; i++)
        printf("%.6f ", b[i]);
}
