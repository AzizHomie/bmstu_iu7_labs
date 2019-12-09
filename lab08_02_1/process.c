#include <stdio.h>
#include <stdlib.h>
#define OK 0
#define ERR_INPUT -1
#define ERR_RANGE -2
#define ERR_ALLOCATION -3

/**
 * @brief Функция удаления чисел больших чем среднее арифметическое.
 *
 * @param *a - массив.
 * @param *n - количество элементов массива.
 * @param ave - среднее арифметическое элементов массива.
*/

int remove_element(float **a, int *n, float ave)
{
    int rc = OK;

    int j = 0;
    for (int i = 0; i < *n; i++)
        if ((*a)[i] <= ave)
        {
            (*a)[j] = (*a)[i];
            j++;
        }
    if (j != 0)
    {
        *n = j;
        *a = realloc(*a, *n * sizeof(float));
        if (!(*a))
            rc = ERR_ALLOCATION;
    }
    else
        rc = ERR_INPUT;

    return rc;
}

/**
 * @brief Функция для вставки максимального элемента в начале, конце и в заданной позиции.
 *
 * @param *a - массив
 * @param *n - количество элементов.
 * @param maximum - максимальный элемент массива.
 * @param p - позиция на которую нужно поставить максимальный элемент.
*/

int paste(float **b, int *n, float maximum, int p)
{
    int rc = OK;
    *n += 3;
    *b = realloc(*b, *n * sizeof(float));
    if ((*b))
    {
        for (int i = *n - 1; i > p; i--)
            (*b)[i] = (*b)[i - 1];
        (*b)[p] = maximum;

        for (int i = *n - 1; i > 0; i--)
            (*b)[i] = (*b)[i - 1];
        (*b)[0] = maximum;
        (*b)[*n - 1] = maximum;
    }
    else
        rc = ERR_ALLOCATION;

    return rc;
}
