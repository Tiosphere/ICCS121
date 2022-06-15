#include <stdio.h>


void prefix_sum (int *a, int *b, int *c) {  
    *b = *a + *b;
    *c = *b + *c;
}
void main()
{
    int a = 10;
    int b = 21;
    int c = 32;
    prefix_sum(&a, &b, &c);
    printf("A = %d\n", a);
    printf("B = %d\n", b);
    printf("C = %d\n", c);
}
