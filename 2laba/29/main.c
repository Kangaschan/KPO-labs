#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    srand(time( NULL));
    int matrix[6][6];
    for (int i = 0;i<+6;++i){
        for (int j = 0; j < 6; ++j) {
            matrix[i][j]=rand()%50+12;
            if( j == 5){
                matrix[i][j]=3;
            }
            printf(" %d ",matrix[i][j]);
            }
            printf("\n");
        }
    int elem;
    for (int i = 0;i<6;++i){
        for (int j = 0; j < 6; ++j) {
            elem = matrix[i][j];
            for (int k = 0; k < 6; ++k) {
                for (int l = 0; l < 6; ++l) {
                    if ((matrix [k][l] == elem) && (((k != i) && (l != j)) || (k != i))){
                        matrix[i][j]=0;
                        matrix[k][l]=0;
                    }
                }

            }
            if (matrix[i][j] != 0){
                matrix[i][j] = 1;
            }
        }

    }
    printf("\n\n");
    for (int i = 0;i<6;++i){
        for (int j = 0; j < 6; ++j) {

            printf(" %d ",matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
