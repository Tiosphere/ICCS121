#include<stdio.h>
#include<stdlib.h>

void main(int argc, char *argv[])
{
    int result = 0;
    for (size_t i = 1; i < argc; i++)
    {
        int num = strtol(argv[i], NULL, 10);
        result = result + num;
    }
    printf("Result: %d", result);
}