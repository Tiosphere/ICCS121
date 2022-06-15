#include<stdio.h>
#include<stdlib.h>


void matrixVector(int **inMatrix, int *inVector, int * result, int sizeX, int sizeY) {
    for (int row = 0; row < sizeY; row++)
    {
        int total = 0;
        for (int col = 0; col < sizeX; col++)
        {
            total += inMatrix[row][col] * inVector[col];
        }
        result[row] = total;
    }

}
int main(int argc, char const *argv[])
{
    int a1[5] = {112,1150,4,2,0}, a2[5] = {1,2,3,4,5}, a3[5] = {2,2,2,2,2}, a4[5] = {3,4,3,4,3}, a5[5] = {5,1,5,6,7};
    // int a[5][5] = {{112,1150,4,2,0},{1,2,3,4,5},{2,2,2,2,2}, {3,4,3,4,3}, {5,1,5,6,7}};
    int **pointA;
    pointA[0] = a1;
    pointA[1] = a2;
    pointA[2] = a3;
    pointA[3] = a4;
    pointA[4] = a5;
    int b[5] = {7,9,8,6,7};
    int result[5];
    matrixVector(pointA ,b , result, 5, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", result[i]);
    }
    return 0;
}
