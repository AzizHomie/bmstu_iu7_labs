#include "io.h"
#include "calc.h"
#include "process.h"
#include <stdio.h>
#include <stdlib.h>
#define OK 0
#define ERR_INPUT -1
#define ERR_RANGE -2
#define ERR_ALLOCATION -3

int main(void)
{
    float *array = NULL;
    float ave, maximum = 0;
    int n, p;
    int rc = OK;

    rc = input(&array, &n);
    if (rc == OK)
    {
        ave = average(array, n);
        if (rc == OK)
        {
            rc = remove_element(&array, &n, ave);
            if (rc == OK)
            {
                maximum = max_element(array, n);
                printf("Enter p: ");
                if (scanf("%d", &p) != 1)
                    rc = ERR_INPUT;
                else if (p < 0 || p >= n)
                    rc = ERR_RANGE;
                else
                {
                    rc = paste(&array, &n, maximum, p);
                    if (rc == OK)
                        print(array, n);
                }
            }
        }
    }
    free(array);

    return rc;
}
