#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main()
{
    char ch;
    int scores[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    char alpha[27] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    while((ch = getchar()) != EOF && ch != '\n')
    {
        if (isalpha(ch))
        {
            for (int j = 0; j < 26; j++)
            {
                if (alpha[j] == tolower(ch))
                {
                    scores[j]++;
                }
            }
        }
    }
    int max = 1;
    for (int i = 0; i < 26; i++)
    {
        if (scores[i] > max){max = scores[i];}
    }
    while (max > 0)
    {
        for (int i = 0; i < 26; i++)
        {
            if (max == scores[i]){
                printf("*");
                scores[i]--;
            }
            else{printf(" ");}
        }
        printf("\n");
        max--;
    }
    printf("%s\n", alpha);
    return 0;
}
