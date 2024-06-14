#include <stdio.h>

int main() {
    int n;
    printf("enter your number\n");
    scanf("%d",&n);
    if(n<1){
        printf("invalid input");
    }
    else{
        float suma=0,sumb=0;
        float sign=-1;
        float j;
        for (int k=1;k<=n;k++){
            j=k*k*k*k*k;
            //printf("| %d %f %f |",k*k*k*k*k,suma,j);
            suma = suma + 1 / (j);
            sumb = sumb + sign/((2*k+1)*k);
            sign *= -1;
        }
        printf("your results: a) %f b)%f",suma,sumb);
    }
    return 0;
}
