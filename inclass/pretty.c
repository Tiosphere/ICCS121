#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void printnum(int num) {  
    if (num < 10) 
    {
        printf("00%d\n", num);
    }
    else if (num < 100) 
    {
        printf("0%d\n", num);
    }
    else{
        printf("%d\n", num);
    }
}
void main()
{
    char input[1000];
    printf("Enter the text below. Press '[tab]' to end the process\n");
    scanf("%[^\t]s", input);
    char alpha[20] = "\0";
    printf("================================\n");
    for (int i = 0; i < strlen(input); i++)
    {
        char pos = input[i];
        if (isspace(pos)) {
            int num = atoi(alpha);
            if (num > 0) {
                printnum(num);
            }
            else{
                printf("%-15.10s",alpha);
            }
            alpha[0] = '\0';
        }
        else
        {
            strncat(alpha, &pos, 1);
        }
    }
    int num = atoi(alpha);
    if (num > 0) {
        printnum(num);
        alpha[0] = '\0';
    }
    printf("================================");
}
