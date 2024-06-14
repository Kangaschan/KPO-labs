#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
        srand(time( NULL));
        int matrix[10][10];
    for (int i = 0;i<10;++i){
        for (int j = 0; j < 10; ++j) {
            matrix[i][j]=rand()%90+10;
            printf(" %d ",matrix[i][j]);
        }
        printf("\n");
    }
    int swap;
    printf("\n|||||||||||||||||||||||||||||||||||||||\n");
    for (int i = 0; i < 10; ++i) {
        swap = matrix[i][i];
        matrix[i][i] = matrix[i][0];
        matrix[i][0] = swap;
    }
    for (int i = 0;i<10;++i){
        for (int j = 0; j < 10; ++j) {
            printf(" %d ",matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
