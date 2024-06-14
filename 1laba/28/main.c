#include <stdio.h>

int main() {
    int n,m;
    float res,n_fact=1,m_fact=1;
    float x;
    printf("enter number n\n");
    scanf("%d",&n);
    printf("enter m\n");
    scanf("%d",&m);
    if (m<1 || n<1){
        printf("invalid input\n");
    }
    else{
        for (int i = 1; i<=n;i++){
            n_fact *= i;
        }
        for (int i = 1; i <= m; ++i) {
            m_fact *= i;
        }
        res = m_fact+n_fact;
        for (int i = 1; i <= m+n; ++i) {
            res /= i;
        }
        printf("result = %f",res);
    }
    return 0;
}