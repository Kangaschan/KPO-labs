#include <stdio.h>

int main() {

    char a[2]={};
    int j = 0;
    int k2=0;
    char str2[100]={};
    char strmatr2[10][15]={};
    int choise;
    printf("\n Input your string(1) or use base(2)?");
    scanf("%d",&choise);
    fgets(a,2,stdin);
    if(choise == 1){
        j=0;
        printf(" Enter your base string \n");
        fgets(str2, 100, stdin);
        for (int i = 0; (i < sizeof(str2)) && (str2[i+1] != 0); ++i) {
            if(str2[i] != '_'){
                strmatr2[k2][j]=str2[i];
                j++;
            }
            if (str2[i] == '_'){
                k2++;
                j=0;
            }
        }

    }

    char str1[100]={};
    printf("Enter your code string \n");

    fgets(str1, 100, stdin);
    char strmatr1[10][15]={};
    int k1 = 0;
    j=0;
    for (int i = 0; (i < sizeof(str1)) && (str1[i+1] != 0); ++i) {
         if(str1[i] != '_'){
             strmatr1[k1][j]=str1[i];
             j++;
         }
        if (str1[i] == '_'){
            k1++;
            j=0;
        }
    }


    char buildmatr[12][15]={"RUNES","WERE","OLD","LETTERS","ORIGINALLY","USED","FOR","CUTTING","OR","SCRATCHING","ON","WOOD"};

    if (choise == 1){
        for (int i = 0; i <= k1; ++i) {
            printf("%s_%s_%s",strmatr2[2*i],strmatr2[2*i+1],strmatr1[i]);
            if(k1!=i)
                printf("_");
        }
    }
    if (choise == 2){
        for (int i = 0; i <= k1; ++i) {
            printf("%s_%s_%s",buildmatr[2*i],buildmatr[2*i+1],strmatr1[i]);
            if(k1!=i)
                printf("_");
        }
    }
        return 0;
}
