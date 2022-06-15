#include<stdio.h>
#include<stdlib.h>


int isFib(int n) {
    if (n < 0){printf("0");}
    else if (n < 2) {printf("%d", n);}
    else {
        long a1 = 1;
        long a2 = 1;
        long now = 0;
        int th = 3;
        while (n > now)
        {
            now = a1 + a2;
            if (now == n)
            {
                printf("%d", th);
                return th;
            }
            a1 = a2;
            a2 = now;
            th++;
        }
        printf("0");
    }
}
int main(int argc, char const *argv[])
{
    int n = strtol(argv[1], NULL, 10);
    isFib(n);
    return 0;
}
