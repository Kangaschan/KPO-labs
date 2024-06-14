#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    double arr[50];
    double b,x,n,prev=1;
    int  number;
    printf("input array: \n");
    for (int i = 0; i <50; ++i) {
        b=rand();
        arr[i]=b / 1000;
        printf("%f ",arr[i]);
    }
    for (int i = 0; i < 50; ++i) {
        n = modf(arr[i],&b);
        if (n>0.5){
            n = 1 - n;
        }
        if (n<prev){
            prev = n;
            number = i;
        }
    }
    printf("\n result is %f",arr[number]);

    return 0;
}
