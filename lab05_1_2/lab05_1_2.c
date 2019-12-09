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

int sum_of_digits(int elem)
{
    if (elem < 0)
        elem = -elem;
    int last_digit = elem % 10;
    while (elem > 0)
    {
        elem /= 10;
        last_digit += elem % 10;
    }
    return last_digit;
}

void func(int matrix[ROWS][COLS], int *rows, int *cols)
{
    int row = 0, column = 0;
    int min = sum_of_digits(matrix[0][0]);
    for (int i = 0; i < *rows; i++)
        for (int j = 0; j < *cols; j++)
        {
            if (sum_of_digits(matrix[i][j]) < min)
            {
                min = sum_of_digits(matrix[i][j]);
                row = i;
                column = j;
            }
        }
    for (int i = row; i < *rows; i++)
        for (int j = 0; j < *cols; j++)
            matrix[i][j] = matrix[i + 1][j];
    for (int i = 0; i < *rows; i++)
        for (int j = column; j < *cols; j++)
            matrix[i][j] = matrix[i][j + 1];
    *rows -= 1;
    *cols -= 1;
}

void output(int matrix[ROWS][COLS], const int rows, const int cols)
{
    printf("Array:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int main(void)
{
    int rc = OK;
    int matrix[ROWS][COLS], rows, cols;
    rc = input(matrix, &rows, &cols);
    if (rc == OK)
    {
        func(matrix, &rows, &cols);
        output(matrix, rows, cols);
    }
    else if (rc == INPUT_ERROR)
        printf("Input Error!");
    else if (rc == RANGE_ERROR)
        printf("Range Error!");
    return rc;
}