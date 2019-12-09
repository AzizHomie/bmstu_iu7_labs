#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#include "process.h"
#define EPS 1.0e-5

int average_test(void)
{
    int counter = 0;

    // Test 1
    {
        float a[] = { 1, 2, 3, 4, 5 };
        float ave;
        float result = 3.0;
        
        ave = average(a, 5);

        printf("Test 1: ");
        if (fabs(ave - result) > EPS)
        {
            counter++;
            printf("FAIL\n");
        }
        else
            printf("OK\n");
    }

    // Test 2
    {
        float a[] = { 10, 10, 10 };
        float ave;
        float result = 10;

        ave = average(a, 3);

        printf("Test 2: ");
        if (fabs(ave - result) > EPS)
        {
            counter++;
            printf("FAIL\n");
        }
        else
            printf("OK\n");
    }

    // Test 3
    {
        float a[] = { 3, 7, 5, 2, 1, 0, 3, -1, 7 };
        float ave;
        float result = 3.0;

        ave = average(a, 9);

        printf("Test 3: ");
        if (fabs(ave - result) > EPS)
        {
            counter++;
            printf("FAIL\n");
        }
        else
            printf("OK\n");
    }

    return counter;
}

int max_test(void)
{
    int counter = 0;

    // Test 1
    {

        float a[] = { 1, 2, 3, 4, 5 };
        float max;
        float result = 5;

        max = max_element(a, 5);

        printf("Test 1: ");
        if (fabs(max - result) > EPS)
        {
            counter++;
            printf("FAIL\n");
        }
        else
            printf("OK\n");
    }

    // Test 2
    {
        float a[] = { -100, 26, 32, 99, 0 };
        float max;
        float result = 99;

        max = max_element(a, 5);

        printf("Test 2: ");
        if (fabs(max - result) > EPS)
        {
            counter++;
            printf("FAIL\n");
        }
        else
            printf("OK\n");
    }

    // Test 3
    {
        float a[] = { 10, 10, 10, 10 };
        float max;
        float result = a[0];

        max = max_element(a, 4);

        printf("Test 2: ");
        if (fabs(max - result) > EPS)
        {
            counter++;
            printf("FAIL\n");
        }
        else
            printf("OK\n");
    }

    return counter;
}

int remove_test(void)
{
    int error_counter = 0;
    float *a = NULL;

    // Test 1
    {
        int n = 5;
        int elem = 0;

        a = malloc(n * sizeof(float));
        if (a == NULL)
        {
            printf("Allocation error\n");
            error_counter++;
        }
        else
        {
            for (int i = 0;  i < n; i++)
                a[i] = elem + 1;
            float result[] = { 1.0, 2.0, 3.0 };

            if (remove_element(&a, &n, 3) != 0)
            {
                printf("Couldn't test function remove_element\n");
                error_counter++;
            }
            else
            {
                printf("Test 1: ");

                if (fabs(result - a) > EPS)
                    printf("OK\n");
                else
                {
                    error_counter++;
                    printf("FAIL\n");
                }
            }
        }
        free(a);
    }
    // Test 2
    {
        int n = 9;

        a = malloc(n * sizeof(float));
        if (a == NULL)
        {
            printf("Allocation error\n");
            error_counter++;
        }
        else
        {
            a[0] = 3;
            a[1] = 7;
            a[2] = 5;
            a[3] = 2;
            a[4] = 1;
            a[5] = 0;
            a[6] = 3;
            a[7] = -1;
            a[8] = 7;
            float result[] = { 3, 2, 1, 0, 3, -1 };

            if (remove_element(&a, &n, 3) != 0)
            {
                printf("Couldn't test function remove_element\n");
                error_counter++;
            }
            else
            {
                printf("Test 2: ");
                if (fabs(result - a) > EPS)
                    printf("OK\n");
                else
                {
                    printf("FAIL\n");
                    error_counter++;
                }
            }
        }
        free(a);
    }

    // Test 3
    {
        int n = 8;

        a = malloc(n * sizeof(float));
        if (a == NULL)
        {
            printf("Allocation error\n");
            error_counter++;
        }
        else
        {
            a[0] = 7;
            a[1] = 2;
            a[2] = 6;
            a[3] = 2;
            a[4] = 5;
            a[5] = 2;
            a[6] = 4;
            a[7] = 6;

            float result[] = { 2, 2, 2, 4 };

            if (remove_element(&a, &n, 4.25) != 0)
            {
                printf("Couldn't test function remove_test\n");
                error_counter++;
            }
            else
            {
                printf("Test 3: ");
                if (fabs(result - a) > EPS)
                    printf("OK\n");
                else
                {
                    error_counter++;
                    printf("FAIL\n");
                }
            }
        }
        free(a);
    }

    return error_counter;
}

int compare(float *a, float b[], int n)
{
    int rc = 0;
    for (int i = 0; i < n; i++)
    {
        if (fabs(a[i] - b[i]) > EPS)
            rc++;
    }
    return rc;
}

int paste_test(void)
{
    int counter = 0;
    float *a = NULL;
    // Test 1
    {
        int n = 3;
        a = malloc(n * sizeof(float));
        if (a == NULL)
        {
            printf("Allocation error\n");
            counter++;
        }
        else
        {
            a[0] = 1;
            a[1] = 2;
            a[2] = 3;

            float result[] = { 5, 1, 2, 5, 3, 5 };

            if (paste(&a, &n, 5, 2) != 0)
            {
                printf("Couldn't test function paste\n");
                counter++;
            }
            else
            {
                printf("Test 1: ");
                if (compare(a, result, n) == 0)
                    printf("OK\n");
                else
                {
                    counter++;
                    printf("FAIL\n");
                }
            }
        }
        free(a);
    }
    // Test 2
    {
        int n = 6;
        a = malloc(n * sizeof(float));
        if (a == NULL)
        {
            printf("Allocation error\n");
            counter++;
        }
        else
        {
            a[0] = 3;
            a[1] = 7;
            a[2] = 5;
            a[3] = 2;
            a[4] = 1;
            a[5] = 0;

            float result[] = { 10, 3, 7, 5, 10, 2, 1, 0, 10 };

            if (paste(&a, &n, 10, 3) != 0)
            {
                printf("Couldn't test function paste\n");
                counter++;
            }
            else
            {
                printf("Test 2: ");
                if (compare(a, result, n) == 0)
                    printf("OK\n");
                else
                {
                    counter++;
                    printf("FAIL\n");
                }
            }
        }
        free(a);
    }

    // Test 3
    {
        int n = 8;
        a = malloc(n * sizeof(float));
        if (a == NULL)
        {
            printf("Allocation error\n");
            counter++;
        }
        else
        {
            a[0] = 7;
            a[1] = 2;
            a[2] = 6;
            a[3] = 2;
            a[4] = 5;
            a[5] = 2;
            a[6] = 4;
            a[7] = 6;

            float result[] = { 14, 7, 2, 6, 2, 14, 5, 2, 4, 6, 14 };

            if (paste(&a, &n, 14, 4) != 0)
            {
                printf("Couldn't test function paste\n");
                counter++;
            }
            else
            {
                printf("Test 3: ");
                if (compare(a, result, n) == 0)
                    printf("OK\n");
                else
                {
                    counter++;
                    printf("FAIL\n");
                }
            }
        }
        free(a);
    }
    return counter;
}

int main(void)
{
    int rc = 0;
    int result = 0;
    printf("\nTesting function average\n");
    rc = average_test();
    if (rc != 0)
    {
        result++;
        printf("average: FAILED\n");
    }
    else
        printf("average: PASSED\n");

    printf("\nTesting function max_element\n");
    rc = max_test();
    if (rc != 0)
    {
        result++;
        printf("max_element: FAILED\n");
    }
    else
        printf("max_element: PASSED\n");


    printf("\nTesting function remove_element\n");
    rc = remove_test();
    if (rc != 0)
    {
        result++;
        printf("remove_element: FAILED\n");
    }
    else
        printf("remove_element: PASSED\n");

    printf("\nTesting function paste\n");
    rc = paste_test();
    if (rc != 0)
    {
        result++;
        printf("paste: FAILED\n");
    }
    else
        printf("paste: PASSED\n");

    if (result > 0)
        system("color 4");
    else
        system("color 2");

    return result;
}
