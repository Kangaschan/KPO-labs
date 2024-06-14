#include <stdio.h>
#include <time.h>
#include <malloc.h>
//#include <rando>
typedef struct node{
    struct node * next;
    int value;
}Node;
Node * Head = NULL;
Node * Add(int inp){
    Node * temp = malloc(sizeof(Node));
    temp -> value = inp;
    temp -> next = NULL;
    return temp;
}
void InitList(){
    Node * curr = NULL;
    curr = Head;
    for (int i = 0; i < 15; ++i) {
        //curr->value = rand() % 20;
        curr->next  = Add(rand() % 20);
        curr = curr -> next;
    }
}
void ShowList(){
    printf("\n");
    Node * curr = Head;
    while ( curr -> next != NULL)
    {
        printf(" %d",curr->value);
        curr  = curr->next;
    }
}
void removeOdd(){
    Node * curr = Head;
    Node * parent = NULL;
    int i = 1;
    while (curr != NULL)
    {
    if(i%2==1){//odd position
     if(curr->value % 2 == 0)
     {
         if(parent==NULL)
         {
         Head = curr->next;
         }
         else
         {
             parent->next = curr ->next;
             free(curr);
         }
         return;
     }
    }
    i++;
        parent = curr;
        curr = curr -> next;
    }
}
int main() {
    srand(time(NULL));
    Head = Add(rand() % 20);
    InitList();
    ShowList();
    removeOdd();
    ShowList();
    return 0;
}
