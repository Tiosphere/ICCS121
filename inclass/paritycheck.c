#include <stdio.h>
int parity_check(int x){
    int count = 0;
    while (x > 0) {
        if (x % 2 == 1) {count++;}
        x = x / 2;
    }
    return count % 2;
}


int main(int argc, char const *argv[])
{
    printf("Int: 1 Ans: %d\n", parity_check(1));
    printf("Int: 2 Ans: %d\n", parity_check(2));
    printf("Int: 3 Ans: %d\n", parity_check(3));
    printf("Int: 9 Ans: %d\n", parity_check(9));
    printf("Int: 82 Ans: %d\n", parity_check(82));
    printf("Int: 300 Ans: %d\n", parity_check(300));
    printf("Int: 625 Ans: %d\n", parity_check(625));
    printf("Int: 888 Ans: %d\n", parity_check(888));
    return 0;
}
