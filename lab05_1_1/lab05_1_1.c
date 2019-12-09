#include<stdio.h>
#define OK 0
#define INPUT_ERROR 1
#define RANGE_ERROR 2
#define ROWS 10
#define COLS 10

int input(int matrix[ROWS][COLS], int *rows, int *cols)
{
    printf("Enter number of rows: ");
    if (scanf("%d", rows) != 1)
    {
        printf("Input error!");
        return INPUT_ERROR;
    }
    if (*rows <= 0 || *rows > ROWS)
    {
        printf("Range error!");
        return RANGE_ERROR;
    }
    printf("Enter number of cols: ");
    if (scanf("%d", cols) != 1)
    {
        printf("Input error!");
        return INPUT_ERROR;
    }
    if (*cols <= 0 || *cols > COLS)
    {
        printf("Range error!");
        return RANGE_ERROR;
    }
    printf("Enter elements:\n");
    for (int i = 0; i < *rows; i++)
        for (int j = 0; j < *cols; j++)
        {
            if (scanf("%d", &matrix[i][j]) != 1)
            {
                printf("Input error!");
                return INPUT_ERROR;
            }
        }
    return OK;
}

void func(int matrix[ROWS][COLS], int *rows, int *cols, int *array)
{
    int counter = 0;
    for (int i = 0; i < *rows; i++)
    {
        for (int j = 0; j < *cols / 2; j++)
        {
            if (j != *cols - j - 1)
            {
                if (matrix[i][j] == matrix[i][*cols - j - 1])
                    counter++;
            }
        }
        if (counter >= (*cols) / 2)
            array[i] = 1;
        else
            array[i] = 0;
        counter = 0;
    }
}

void output(const int *rows, const int *array)
{
    printf("Array:\n");
    for (int i = 0; i < *rows; i++)
        printf("%d ", array[i]);
}

int main(void)
{
    int matrix[ROWS][COLS], rows, cols, array[ROWS];
    if (input(matrix, &rows, &cols) == OK)
    {
        func(matrix, &rows, &cols, array);
        output(&rows, array);
    }
    else
    {
        printf("Input error!");
        return INPUT_ERROR;
    }
    return OK;
}