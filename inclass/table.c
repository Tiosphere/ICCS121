#include<stdio.h>

void main()
{
    int upper, lower;
    printf("Lower limit: ");
    scanf("%d", &lower);
    printf("Upper limit: ");
    scanf("%d", &upper);
    printf("Celcius\t\tFahrenheit\n==========================\n");
    while (lower <= upper)
    {
        float fa = (lower*1.8) + 32;
        printf("   %d\t\t   %.1lf\n", lower, fa);
        lower+=5;
    }
    printf("--------------------------");
}