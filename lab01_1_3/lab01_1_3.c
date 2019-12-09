#include<stdio.h>

int main(void)
{
    // Объявление переменных
    float v1, t1, v2, t2; // Изменено: int на float
	float v = 0.0;
	float t = 0.0;
	// Ввод данных
    printf("Input v1:");
    scanf("%f", &v1);
    printf("Input t1:");
    scanf("%f", &t1);
    printf("Input v2:");
    scanf("%f", &v2);
    printf("Input t2:");
    scanf("%f", &t2);
    // Операции
    v = v1 + v2;
    t = (v1 * t1 + v2 * t2) / v;
	// Вывод
    printf("Volumee = %f\n", v);
    printf("Temperature = %f\n", t);
    return 0;
}