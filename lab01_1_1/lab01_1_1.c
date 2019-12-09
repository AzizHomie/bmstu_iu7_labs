#include<stdio.h>
#include<math.h> 

int main(void)
{
    float a, b;
    float alpha;
    float s = 0.0;
    float h = 0.0;
    printf("Input a:");
    scanf("%f", &a);
    printf("Input b:");
    scanf("%f", &b);
    printf("Input alpha:");
    scanf("%f", &alpha);
    h = fabs((b - a)) / 2 * tan(alpha * 3.14159 / 180);
    s = (a + b) / 2 * h;
    printf("Ploshad trapetsii ravno: %f", s);
    return 0;
}