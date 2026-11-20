#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
int main(void)
{
    setlocale(LC_ALL, "Russian");
    int A[100], n, i;
    int first = -1, second = -1;
    double sum = 0;
    printf("Введите n (от 1 до 100): ");
    scanf("%d", &n);
    if (n < 1 || n > 100)
    {
        printf("n должно быть от 1 до 100.\n");
        return 0;
    }
    for (i = 0; i < n; i++)
    {
        printf("A[%d] = ", i + 1);
        scanf("%d", &A[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (A[i] < 0)
        {
            if (first == -1)
                first = i;
            else
            {
                second = i;
                break;
            }
        }
    }
    if (second == -1)
    {
        printf("В массиве меньше двух отрицательных элементов.\n");
        return 0;
    }
    if (second == first + 1)
    {
        printf("Между первыми двумя отрицательными элементами нет чисел.\n");
        return 0;
    }
    for (i = first + 1; i < second; i++)
        sum = sum + A[i];
    printf("Среднее значение: %.2f\n", sum / (second - first - 1));
    return 0;
}
