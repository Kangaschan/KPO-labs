#include <stdio.h>
struct inf{
    char surname[50];
    char breanch[20];
    int  salary;
    int  id;
};
void add(FILE * F,int MaxId){
    struct inf temp={};
    fseek(F,0,SEEK_SET);
    fscanf(F,"%s%s%d%d",&temp.surname,&temp.breanch,&temp.salary,&temp.id);
    if(temp.id = 0){

    }
};
void delete(FILE * F,int id){

}
void change(FILE * F, int id){

};
int main() {
    FILE *F;
    F=fopen("file.dat","a+b");

    fclose(F);
    return 0;
}
