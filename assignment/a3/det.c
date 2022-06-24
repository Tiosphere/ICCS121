#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double compute_det(int **a, int n){
    if(n == 1){return (double) a[0][0];}
    else if(n == 2){return (double) a[0][0] * a[1][1] - a[0][1] * a[1][0];}
    else if(n == 3){return (double) a[0][0] * a[1][1] * a[2][2] + a[0][1] * a[1][2] * a[2][0] + a[0][2] * a[1][0] * a[2][1] - a[0][0] * a[1][2] * a[2][1] - a[0][1] * a[1][0] * a[2][2] - a[0][2] * a[1][1] * a[2][0];}
    else{
        double det = 0.0;
        for(int pos = 0; pos < n; pos++) {
            int **tmp = malloc(sizeof(int *) * (n-1));
            for (int i = 1; i < n; i++)
            {
                int count = 0;
                int *l = malloc(sizeof(int) * (n-1));
                for(int j = 0; j < n; j++){
                    if(j != pos){
                        l[count] = a[i][j];
                        count++;
                    }
                }
                tmp[i-1] = l;
            }
            if(pos % 2 == 1){
                det -= a[0][pos] * compute_det(tmp, n-1);
            }
            else{
                det += a[0][pos] * compute_det(tmp, n-1);
            }
            for (int i = 0; i < n-1; i++){free(tmp[i]);}
            free(tmp);
        }
        return det;
    }
}
/*
TEST: ./det < det.in
OUTPUT:
-105.00000
*/
int main(void){
    int size;
    scanf("%d",&size);
    int *matrix[size];
    for(int i = 0; i < size; i++) {
        int *arr = malloc(sizeof(int) * size);
        for (int j = 0; j < size; j++){
            scanf("%d", &arr[j]);
        }
        matrix[i] = arr;
    }
    printf("%f", compute_det(matrix, size));
    for(int i = 0; i < size; i++){
        free(matrix[i]);
    }
}