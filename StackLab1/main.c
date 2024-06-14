#include <time.h>
#include <stdio.h>
#include <malloc.h>
typedef struct stack
{
    int value;
    struct stack * next;
}node;

node * new(int keyvalue)
{
    node * temp = malloc(sizeof(node));
    temp->next=NULL;
    temp->value=keyvalue;
    return temp;
}

void push(int keyvalue,node ** Head)
{

    if(*Head !=NULL){
        node* temp;
        temp = *Head;
        *Head = new(keyvalue);
        (*Head)->next = temp;
    }
    else
    {
        *Head = new(keyvalue);
    }
}

int pop(node ** Head) {
    node * temp = *Head;
    if (temp != NULL){
    int a = temp->value;
    node *curr = *Head;
    *Head = temp->next;
    free(curr);
    return a;
    }
    else
    {
        return INT_MAX;
    }
}

void ShowStack(node ** Head)
{
    node * curr = *Head;
    while(curr!=NULL){
        printf(" %d ", curr->value);
        curr = curr -> next;
    }
}

node ** createstack(){
    node * temp = new(rand()%20);
    node ** Head1 = malloc(sizeof(node * ));
    *Head1 = temp;

    return Head1;
}

void initstack(node ** Head){
    for (int i = 0; i <15; ++i)
    push(rand()% 21 - 10, Head);
}

void dividestack(node ** Head1, node ** Head2, node ** Head3) {
    node *temp = *Head1;
    while (temp!= NULL) {
        if (temp->value >= 0)
            push(temp->value, Head2);
        else
            push(temp->value, Head3);
        temp = temp ->next;
    }
}
int main() {
    srand(time(NULL));
    node ** Head1 = createstack();
    initstack(Head1);

    printf("first stack: ");
    ShowStack(Head1);

    node ** Head2 = createstack();
    pop(Head2);
    node ** Head3 = createstack();
    pop(Head3);
    dividestack(Head1,Head2,Head3);

    printf("\nsecond stack: ");
    ShowStack(Head2);

    printf("\nthird stack: ");
    ShowStack((Head3));

    return 0;

}