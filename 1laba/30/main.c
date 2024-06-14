#include <stdio.h>
#include <stdlib.h>
int main() {
    float arr[10];
    float b,max,min;
    printf("Input arr:\n");
    for (int i = 0; i < 10; ++i) {
        b = rand();
        arr[i] = b / 1000 ;
        printf(" %f",arr[i]);
    }
    max = arr[0];
    min = arr[0];
    for (int i = 0; i < 10; ++i) {
        if(min > arr[i]){
            min = arr[i];
        }
        if (max < arr[i]){
            max = arr[i];
        }
    }
    b = max - min;
    printf("\n result: %f",b);
    return 0;
}
