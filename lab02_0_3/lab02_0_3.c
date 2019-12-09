#include <stdio.h>
#include <math.h>
#define OK 0
#define INP_ERR 1
#define RANGE_ERR 2
#define TRUE 1
#define FALSE 0
#define PRECISION 0.0000001

double sum(float x, float eps)
{
    double s = 1 + x, t = x;
    int n = 1;
    while (fabs(t) > eps)
    {
        n += 1;
        t = (t * x) / (n);
        s += t;
    }
    return s;
}

double sum_f(double x)
{
    double s = 1 + x, t = x;
    int n = 1;
    while (fabs(t) > 0.0000001)
    {
        n += 1;
        t = (t * x) / (n);
        s += t;
    }
    return s;
}

int is_equal(double num1, double num2)
{
    if (fabs(num1 - num2) < PRECISION)
        return TRUE;
    else
        return FALSE;
}

int main(void)
{
    double eps, x, f, absol = 0, otnos = 0;
    int correct = 0;
    printf("Enter x and eps: ");
    if (scanf("%lf%lf", &x, &eps) == 2)
    {
        if (eps < 0 || eps > 1 || is_equal(eps, 0))
        {
            correct = RANGE_ERR;
            printf("Range error!");
        }
        else
        {
            correct = OK;
            f = sum_f(x);
            printf("\n%lf\n", f);
            if (is_equal(x, 0))
                otnos = 0;
            else
                otnos = fabs((f - sum(x, eps)) / f);
            absol = fabs(f - sum(x, eps));
            printf("s(x): %.3lf\n", sum(x, eps));
            printf("f(x): %.7lf\n", f);
            printf("Abs: %lf\n", absol);
            printf("Otnos: %lf", otnos);
        }
    }
    else
    {
        correct = INP_ERR;
        printf("I/O error!");
    }
    return correct;
}