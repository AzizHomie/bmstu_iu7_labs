#include<stdio.h>

int main(void)
{
	int n;
    int entrance = 0;
    int floor = 0;
    //int room = 0;
	printf("Input n:");
	scanf("%d", &n);
    // Подьезд
    if (n % 36 == 0)
        entrance = n / 36;
    else
        entrance = n / 36 + 1;
    // Этаж
    //room = n - (entrance - 1) * 36;
    n = n - (entrance - 1) * 36;
    if (n % 4 == 0)
        floor = n / 4;
    else
        floor = n / 4 + 1;
    printf("Entrance: %d\n", entrance);
    printf("Floor: %d", floor);
    return 0;
}