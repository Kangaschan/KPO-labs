#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;
   srand(time(NULL));
    scanf("%d",&n);
    int matrix[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = rand() % 90 + 10;
//            matrix[i][j]=0;
            printf(" %d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("||||||||||||||||||||||||||||||||||||\n");
    int min = matrix[1][0];
    int h = n/2,k=-1;

    for (int i = 0; i <= h; ++i) {
        k++;
        for (int j = k; j > 0; --j) {
            if(matrix[i][j-1]<min){
                min = matrix[i][j-1];
            }
        }
    }
k++;
    for (int i = h; i < n; ++i) {
        k--;
        for (int j = k; j > 0; --j) {
            if(matrix[i][j-1]<min){
                min = matrix[i][j-1];
            }
        }
    }
    printf("\n 2-d figure min - %d",min);
min = 1000;
k = n-2;
int m=0;
    for (int i = 0; i < h; ++i,k-=2,m++) {
        for (int j = k; j > 0; --j) {
            if(matrix[i][j+m] < min){
                min = matrix[i][j+m];
            }
           // matrix[i][j+m]=1;
        }
    }

    k = 1;
    for (int i = h+1; i < n; ++i,k+=2) {
        for (int j = 0; j < k; ++j) {
            if(matrix[i][n-i+j]<min){
                min = matrix[i][n-i+j];
            }
           // matrix[i][n-i+j]=1;
        }
    }
    printf("\n 1-t figure min - %d",min);

//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            printf(" %d ", matrix[i][j]);
//        }
//        printf("\n");
//    }
    printf("\n%d\n",min);
    return 0;
}

