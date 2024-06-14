#include <stdio.h>

int main() {
    char A[50]={},B[50]={};

    int Alen,Blen,M,N,k=0;
    printf("enter your string A\n");
    fgets(A,50,stdin);
    printf("enter your string B\n");
    fgets(B,50,stdin);
    printf("enter M\n");
    scanf("%d",&M);
    printf("enter N\n");
    scanf("%d",&N);
    for (int i = 0; (i < sizeof (A)) && (A[i] != (char)0); ++i) {
        Alen=i;
    }
    for (int i = 0; (i < sizeof (B)) && (B[i] != (char)0); ++i) {
        Blen=i;
    }

    for (int i = M-1; i < M+N-1; ++i,k++) {
        A[i]=B[k];
    }
    printf("%s\n",A);
    return 0;
}
