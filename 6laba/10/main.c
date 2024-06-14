#include <stdio.h>
#include <string.h>

int main() {
    struct student{
        char fio[60];
        char group[7];
    };
    struct student Group0ne[3]={
            {"Brutskaya N.S.","251001"},
            {"HatalskiyD.V.","251001" },
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
//        fputs(Group0ne[i].fio,F1);
//        fputc('\0',F1);
//        fputs(Group0ne[i].group,F1);
//        fputc('\0',F1);
        fprintf(F1,"%s\n%s\n",Group0ne[i].fio,Group0ne[i].group);
        }
    fprintf(F1,"\n");
    fprintf(F1,"\n");
   for (int i = 0; i < 3; ++i) {
//       fputs(GroupTwo[i].fio,F2);
//       fputc('\0',F2);
//       fputs(GroupTwo[i].group,F2);
//       fputc('\0',F2);
       fprintf(F2,"%s\n%s\n",GroupTwo[i].fio,GroupTwo[i].group);
    }
    fprintf(F2,"\n");
    fprintf(F2,"\n");
   fclose(F1);
   fclose(F2);
    F1=fopen("file21.txt","r+t");
    F2=fopen("file22.txt","r+t");
struct student ab={"lox","pidor"};
    do{
    fgets(ab.fio, 60, F1);
    fgets(ab.group, 60, F1);
        if(strcmp(ab.fio,"\n")!=0 && strcmp(ab.group,"\n")!=0){
    fprintf(F3, "%s%s", ab.fio, ab.group);
        }
}
    while (!feof(F1));
    while (!feof(F2)){
        fgets(ab.fio,60,F2);
        fgets(ab.group,60,F2);
        if(strcmp(ab.fio,"\n")!=0 && strcmp(ab.group,"\n")!=0) {
            fprintf(F3, "%s%s", ab.fio, ab.group);
        }

        }
    fclose(F1);
    fclose(F2);
    fclose(F3);

    return 0;
}