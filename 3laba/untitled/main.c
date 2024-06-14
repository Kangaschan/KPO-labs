#include <stdio.h>
#include <windows.h>
#include <locale.h>
int main() {
    char str[100]={};
    printf("Enter your string  \n");
    fgets(str,10,stdin);
    char strmatr[10][15]={};
    int k = 0,j=0;
    for (int i = 0; i < sizeof(str); ++i) {
         if(str[i]!='_'){
             strmatr[k][j]=str[i];
             j++;
         }
        if ((str[i]='_') && (str[i+1]!=' ')){
            k++;
            j=0;
        }
    }
    for (int i = 0; i < k; ++i) {
        printf("\n %s",strmatr[k]);
    }
    return 0;
}
