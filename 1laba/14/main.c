#include <stdio.h>
int main() {
    int x;
    float res,k = 0;
    printf("enter x :\n");
    scanf("%d",&x);
    k = x;
    for (int i = 1; i <=13; i+=2) {
        res = res +k;
        k = k * (-1) * x *x / (i+1) / (i+2);
    }
    printf("result %f",res);
    return 0;
}
