#include <stdio.h>
#include <string.h>
int  Mystrcmp(const char *s1, const char *s2){
    int result;
    do{
        result= *s1-*s2;
    }
    while(*s1++ && *s2++ && !result);
    return result;
}
int lab2(){
    struct student{
        char fio[60];
        char group[7];
    };
    struct student Group0ne[3]={
            {"HatalskiyD.V.\0","251001\0" },
            {"Brutskaya N.S.\0","251001\0"},
            {"PolitikinaE.O.\0","251001\0"}
    };
    struct student GroupTwo[3]={
            {"ZinovenkoV.S\0","251002\0"},
            {"UbozhenkoM.A.\0","251005\0"},
            {"BeskostiyV.P.\0","251003\0"}
    };
    FILE *F1,*F2,*F3;
    F1=fopen("file21.txt","w+t");
    F2=fopen("file22.txt","w+t");
    F3=fopen("file23.txt","w+t");

    int n1=0,n2=0,a=1;
    for (int i = 0; i < 3; ++i) {
        fprintf(F1,"%s\n%s\n",Group0ne[i].fio,Group0ne[i].group);
    }
    fprintf(F1,"\n");
    fprintf(F1,"\n");
    for (int i = 0; i < 3; ++i) {
        fprintf(F2,"%s\n%s\n",GroupTwo[i].fio,GroupTwo[i].group);
    }
    fprintf(F2,"\n");
    fprintf(F2,"\n");
    fclose(F1);
    fclose(F2);
    F1=fopen("file21.txt","r+t");
    F2=fopen("file22.txt","r+t");
    struct student ab[10]={};
    int i =0;
    do{
        fgets(ab[i].fio, 60, F1);
        fgets(ab[i].group, 60, F1);
//        if(strcmp(ab[i].fio,"\n")!=0 && strcmp(ab[i].group,"\n")!=0){
//            fprintf(F3, "%s%s", ab[i].fio, ab[i].group);
//        }
        i++;
    }
    while (!feof(F1));
    while (!feof(F2)){
        fgets(ab[i].fio,60,F2);
        fgets(ab[i].group,60,F2);
//        if(strcmp(ab[i].fio,"\n")!=0 && strcmp(ab[i].group,"\n")!=0) {
//            fprintf(F3, "%s%s", ab[i].fio, ab[i].group);
//        }
        i++;
    }
    struct student temp;
    int n = i;
    for (int j = 0; j < n-1; ++j) {
        for (int k = 0; k < n-2; ++k) {
                if(Mystrcmp(ab[k].fio,ab[k+1].fio)>0){
                    temp = ab[k];
                    ab[k]=ab[k+1];
                    ab[k+1]=temp;
                }
        }
    }
    fprintf(F3,"%s",ab[3].fio);
    for (int j = 3; j < n-1; ++j) {
        if(strcmp(ab[j].fio,"\n")!=0 && strcmp(ab[j].group,"\n")!=0) {
            if ((ab[j].fio[0]!='\0')&&(ab[j].group[0]!='\0') ){
            //   printf("%d",j);
                fprintf(F3, "%s", ab[j].group);
//                fprintf(F3, "%s A %s B ", ab[j].fio, ab[j].group);
            }
        }
    }
    fclose(F1);
    fclose(F2);
    fclose(F3);

}
int lab1() {
    FILE *F1,*F2,*F3;
    F1=fopen("file1.txt","r+t");
    F2=fopen("file2.txt","r+t");
    F3=fopen("file3.txt","w+t");

    int arr1[10]={};
    int arr2[10]={};
    int n1=0,n2=0,a=1;

printf("\n File 1:");
    while(fscanf(F1,"%d",&arr1[n1++])==1){
        printf("\n %d",arr1[n1-1]);
    }
    n1--;
    printf("\n File2:");
    while(fscanf(F2,"%d",&arr2[n2++])==1){
        printf("\n %d",arr2[n2-1]);
    }
    n2--;

while((n1!=0) || (n2!=0)){
    if(n1==0){
        fprintf(F3,"%d ",arr2[n2-1]);
        n2--;
    }
    if(n2==0){
        fprintf(F3,"%d ",arr1[n1-1]);
        n1--;
    }
    if(arr1[n1-1]<arr2[n2-1]){
        fprintf(F3,"%d ",arr1[n1-1]);
        n1--;
    }
    else{
        fprintf(F3,"%d ",arr2[n2-1]);
        n2--;
    }
}

    return 0;

}
int main(){
    printf("enter lab num:\n");
    int a;
    scanf("%d",&a);
    printf("%d",a);
    if (a==1){
        lab1();
    }
    else{
        lab2();
    }
}