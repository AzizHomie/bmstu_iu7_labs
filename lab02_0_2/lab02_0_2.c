#include <stdio.h>
#include <math.h>
#define OK 0
#define INP_ERR 1
#define NOT_EXIST 2
#define TRUE 1
#define FALSE 0
#define PRECISION 0.00001
#define RIGHT 5
#define ACUTE 6
#define OBTUSE 7

float triangle(float x1, float y1, float x2, float y2, float x3, float y3)
{
    float a, b, c, h = 0, k = 0, l = 0, t_fir = 0, t_sec = 0;
    a = (y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1);
    b = (y3 - y1) * (y3 - y1) + (x3 - x1) * (x3 - x1);
    c = (y2 - y3) * (y2 - y3) + (x2 - x3) * (x2 - x3);
    if (a < b)
    {
        k = a;
        l = b;
    }
    else
    {
        k = b;
        l = a;
    }
    if (l < c)
    {
        h = c;
    }
    else
    {
        h = l;
        l = c;
    }
    t_fir = h;
    t_sec = k + l;
    if (t_fir == t_sec)
        return RIGHT;
    else if (t_fir < t_sec)
        return ACUTE;
    else
        return OBTUSE;
}

int is_equal(float num1, float num2)
{
    if (fabs(num1 - num2) < PRECISION)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int check(float x1, float y1, float x2, float y2, float x3, float y3)
{
    if ((is_equal(x1, x2) && is_equal(y1, y2)) || (is_equal(x1, x3) && is_equal(y1, y3)) || (is_equal(x2, x3) && is_equal(y2, y3)) || (is_equal(x1, y1) && is_equal(x2, y2) && is_equal(x3, y3)) || (is_equal(((x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3)), 0)))
    {
        return NOT_EXIST;
    }
    else
    {
        return OK;
    }
}

int main(void)
{
    float x1, y1, x2, y2, x3, y3;
    int answer = 0;
    int correct = OK;
    printf("Enter coordinates: ");
    if (scanf("%f%f%f%f%f%f", &x1, &y1, &x2, &y2, &x3, &y3) == 6)
    {
        if (check(x1, y1, x2, y2, x3, y3) == NOT_EXIST)
        {
            correct = NOT_EXIST;
        }
        else
        {
            if (triangle(x1, y1, x2, y2, x3, y3) == 5)
            {
                answer = 1;
            }
            else if (triangle(x1, y1, x2, y2, x3, y3) == 6)
            {
                answer = 0;
            }
            else
            {
                answer = 2;
            }
            printf("%d", answer);
        }
    }
    else
    {
        correct = INP_ERR;
    }
    return correct;
}