#include <stdio.h>

int main() {
    char str[50]={},res[50]={};
    int strlen,reslen;
    printf("enter your string\n");
    fgets(str,50,stdin);
    for (int i = 0; (i < sizeof (str)) && (str[i] != (char)0); ++i) {
        strlen=i;
    }
    int k = 0;
    for (int i = 0; i < strlen; ++i) {
        if((str[i]>='a')&&(str[i]<='i')){
            str[i]=str[i]+'A'-'a';
        }
        if((str[i]>='A') && (str[i]<='I')){
            res[k]=str[i];
            k++;
        }
    }
    for (int i = 0; (i < sizeof (res)) && (res[i] != (char)0); ++i) {
        reslen=i;
    }

    char swap;
    for (int i = 0; i < reslen+1; ++i) {
        for (int j = 0; j < reslen; ++j) {
            if(res[j+1]<res[j]){
                swap = res[j];
                res[j]=res[j+1];
                res[j+1]=swap;
            }
        }
    }
    printf("%s \n",res);
    return 0;
}
