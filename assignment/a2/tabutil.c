#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main(int arvc, char const *argv[])
{
    int limit = strtol(argv[2], NULL, 10);
    char ch;
    if (argv[1][1] == 'd'){
        while ((ch = getchar()) != EOF && ch != '\n')
        {
            if (ch == '\t'){printf("%*s", limit, " ");}
            else{printf("%c", ch);}
        }
    }
    else{
        int count = 0;
        while ((ch = getchar()) != EOF && ch != '\n')
        {
            if (ch == ' ')
            {
                count++;
                if (count == limit)
                {
                    printf("\t");
                    count = 0;
                }
            }
            else {
                if (count > 0)
                {
                    printf("%*s", count, " ");
                    count = 0;
                }
                printf("%c", ch);
            }
        }
    }
    return arvc;
}
