#include <stdio.h>
typedef struct {
//    int id;
    int salary;
    char Name[50];
    char Depart[50];
}info;
info workarr [20];
int amount;
FILE * F;
int strcmp(char str1[50],char str2[50]){
    int i = 0;
    while (str1[i]!="\n" || str2[i]!="\n")
    {
        if  (str1[i]!=str2[i])
            return -1;
        i++;
        if (i>5){
            return 1;
        }
    }
    return 1;
}
void ReadFile()
{
    if(F==NULL)
    F = fopen("f1","a+b");
    else
    {
        fclose(F);
        F = fopen("f1","a+b");
    }
//    for (int i = 0; i < 20; ++i)
    {
        fread(&workarr, sizeof(info),20,F);
    }
}
void WriteFile()
{
    if (F !=NULL){
        fclose(F);
    }
    F = fopen("f1","w+b");
    for (int i = 0; i < 20; ++i) {
//        fprintf(F,"%d%d%s%s",workarr[i].id,workarr[i].salary,workarr[i].Depart,workarr[i].Name);
        fwrite(&workarr[i], sizeof(info),1,F);
    }
}
void Add(info new)
{
    int i = 0;
    while (workarr[i].salary!=0)
        i++;
    workarr[i]=new;
}
void ShowArr()
{
    int i = 0;
    while  (workarr[i].salary!=0)
    {
        printf("\n %s %d %s",workarr[i].Name,workarr[i].salary,workarr[i].Depart);
        i++;
    }
}
void Change(int key)
{
    int i=0;
    while(workarr[i].salary!=key)
        i++;
    info temp;
    printf("\n Enter new values:");
    printf("\n Name:");
    scanf("%s",&temp.Name);
    printf("\n Salary:");
    scanf("%d",&temp.salary);
    printf("\n Department:");
    scanf("%s",&temp.Depart);
    workarr[i]=temp;
}
void Delete(int key)
{
    int i=0;
    while (workarr[i].salary!=key)
        i++;
    while(workarr[i].salary!=0){
        workarr[i]=workarr[i+1];
        i++;
    }
}
void ShowAvg(char key[50]){
    int k = 0,i=0,j=0;
    while (workarr[i].salary!=0)
    {
        if (strcmp(key,workarr[i].Depart)==1)
        {
            k+=workarr[i].salary;
            j++;
        }
        i++;
    }
    float f = k;
    f = f / j;
    printf("\n average salary is: %f \n amount of salary: %d",f,k);
}
int main() {
    const int N = 8;
    info Peoples[8]={
            {200,"Hatalskiy\0","Backend\0"},
            {450,"Brutskaya\0","Backend\0"},
            {957,"Zinovenko\0","Backend\0"},
            {123,"Linkov\0","Frontend\0"},
            {300,"Politikina\0","Frontend\0"},
            {756,"Voytovich\0","Backend\0"},
            {586,"Gustcha\0","Frontend\0"},
            {246,"Ivanov\0","Frontend\0"}
    };
    for (int i = 0; i < N; ++i) {
        Add(Peoples[i]);
    }
    WriteFile();
    ReadFile();
    ShowArr();
    while(1){
        printf("\nenter num to do 1 - add 2 - remove 3 - edit 4 - average 5 - save\n");
        int g = 0;
        scanf("%d",&g);

    int k;
    char str [50];
   info temp;
    if (g == 4){
    printf("\n Enter Department to check");
    scanf("%s",str);
    ShowAvg(str);
    ShowArr();
    }
    if (g == 3){
    printf("\nEnter salary to edit:");
    scanf("%d",&k);
    Change(k);
    ShowArr();
    }
    if (g == 2){
    printf("\nEnter salary to delete:");
    scanf("%d",&k);
    Delete(k);
    ShowArr();
    }
    if ( g == 1){
        printf("\n Enter data to add, name");
        scanf("%s",&temp.Name);
        printf("\n Enter data to add, department");
        scanf("%s",&temp.Depart);
        printf("\n Enter data to add, salary");
        scanf("%d",&temp.salary);
        Add(temp);
        ShowArr();
    }
    if(g == 5 ){
        WriteFile();
        return 0;
    }
    }
    return 0;
}
