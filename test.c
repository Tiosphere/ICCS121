#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void main()
{
    int *a;
    a = malloc(sizeof(int) * 10);
    for (int size = 0; size < 10; size++) {
        *(a + size) = size;
    }
    for (int size = 0; size < 12; size++) {
        printf("%d\n", *(a + size));
    }
}
