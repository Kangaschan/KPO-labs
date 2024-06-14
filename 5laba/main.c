#include <stdio.h>
int  Mystrcmp(const char *s1, const char *s2){
    int result;
    do{
        result= *s1-*s2;
    }
    while(*s1++ && *s2++ && !result);
    return result;
}
int main() {
    struct student {
        char name[50];
        char home[25];
        float avg;
    };;
    const int amount = 5;
    struct student temp;
    struct student arr[5] = {
            {"Hatalskiy",  "Homel",   8.1},
            {"S+6969Brutskaya",  "Stlolin", 8.5},
            {"Politikina", "Homel",   7.2},
            {"Amblachencko",  "Minsk",9},
            {"Pupkin",     "Moskow",  6.2}
    };
    float summ = 0;
    for (int i = 0; i < amount; ++i) {
        summ += arr[i].avg;
    };
    summ = summ / amount;

    for (int i = 0; i < amount; ++i) {
        for (int k = 0; k < amount - 1; ++k) {
            if (Mystrcmp(arr[k].name, arr[k + 1].name)>0) {
                temp = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = temp;
            }
        }
    }
    printf("Sredni ball - %f ",summ);
    for (int i = 0; i < amount; ++i) {
        if (arr[i].avg >= summ) {
            printf("\n %s %s %f", arr[i].name, arr[i].home, arr[i].avg);
        }
    }
    return 0;
}

