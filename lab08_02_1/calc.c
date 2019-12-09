#include <stdio.h>

/**
  @brief Функция вычисления среднего арифметического.
  Суммирует элементы массива и делит на количество элементов массива.

  @param *array - массив
  @param n - количество элементов в массиве
  @param ave - результат, среднее арифметическое массива.
*/

float average(const float *array, int n)
{
    float ave = 0;

    for (int i = 0; i < n; i++)
        ave += array[i];
    ave /= (double) n;

    return ave;
}

/**
 * @brief Функция определения максимального элемента массива.
 * В цикле сравнивает элементы массива, и берёт самый большой из них.
 *
 * @param *array - массив.
 * @param n - количество элементов массива
 * @param maximum - результат, максимальное число в массиве.
*/

float max_element(const float *b, int n)
{
    float maximum = b[0];
    for (int i = 1; i < n; i++)
    {
        if (b[i] > maximum)
            maximum = b[i];
    }

    return maximum;
}
