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
        printf("Input error!\n");
        return INPUT_ERROR;
    }
    if (*rows <= 0 || *rows > ROWS)
    {
        printf("Range error!\n");
        return RANGE_ERROR;
    }
    printf("Enter number of cols: ");
    if (scanf("%d", cols) != 1)
    {
        printf("Input error!\n");
        return INPUT_ERROR;
    }
    if (*cols <= 0 || *cols > COLS)
    {
        printf("Range error!\n");
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

void sort(int matrix[ROWS][COLS], int *rows, int *cols)
{
    int msv[ROWS];
    for (int i = 0; i < *rows; i++)
    {
        int max_element = matrix[i][0];
        for (int j = 0; j < *cols; j++)
        {
            if (matrix[i][j] > max_element)
                max_element = matrix[i][j];
            msv[i] = max_element;
        }
    }
    int box = 0;
    for (int i = 0; i < *rows; i++)
    {
        for (int k = i + 1; k < *rows; k++)
            if (msv[i] < msv[k])
                for (int j = 0; j < *cols; j++)
                {
                    box = matrix[i][j];
                    matrix[i][j] = matrix[k][j];
                    matrix[k][j] = box;
                }
    }
}

void output(int matrix[ROWS][COLS], int rows, int cols)
{
    printf("\nMatrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int main(void)
{
    int matrix[ROWS][COLS], rows, cols;
    if (input(matrix, &rows, &cols) == OK)
    {
        sort(matrix, &rows, &cols);
        output(matrix, rows, cols);
    }
    else if (input(matrix, &rows, &cols) == INPUT_ERROR)
    {
        printf("Input Error!");
        return INPUT_ERROR;
    }
    else if (input(matrix, &rows, &cols) == RANGE_ERROR)
    {
        printf("Range Error!");
        return RANGE_ERROR;
    }
    return OK;
}