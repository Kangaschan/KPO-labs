#include <stdio.h>

int main() {
    char str[50]={};
    char word[50]={};
    int strlen,wordlen;
    printf("enter your string\n");
    fgets(str,50,stdin);
    printf("enter your word\n");
    fgets(word,50,stdin);
    for (int i = 0; (i < sizeof (str)) && (str[i] != (char)0); ++i) {
        strlen=i;
    }
    for (int i = 0; (i < sizeof (word)) && (word[i] != (char)0); ++i) {
        wordlen=i;
    }

    int flag,k,amount=0;
    for (int i = 0; i < strlen; ++i) {
        if ((str[i]==word[0]) && ((i==0) || (str[i-1] == ' '))){
            flag = 1;
            for (int j = 0; j < wordlen; ++j) {
                if (str[i + j] != word[j]) {
                    flag = 0;
                }
                k = j;
            }
                if( (flag!=0) && ((i+k+1==strlen || (str[i+k+1]==' ')) )){
                    amount++;
                    }
            i+=k;
        }
    }


    printf(" %d\n",amount);
    return 0;
}
