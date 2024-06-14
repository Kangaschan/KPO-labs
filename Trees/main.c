#include <stdio.h>
#include <malloc.h>
#include "time.h"
typedef struct node{
    int value;
    struct node * left;
    struct node * right;
}Node;

Node * NewNode(int inpValue){
    Node * temp = malloc(sizeof (Node));
    temp -> value = inpValue;
    temp -> left  = NULL;
    temp -> right = NULL;
    return temp;
}

int AddNode(int inpValue, Node * Head){
    Node * temp = Head;
    short int flag = 1;
    while(flag)
    {
        if (temp-> value > inpValue){//going left side
            if(temp -> left != NULL){
                temp = temp->left;
            }
            else{//add new node
                temp->left = NewNode(inpValue);
//                flag = 0;
                return 0;
            }
        }
        if (temp-> value < inpValue){//going right side
            if(temp -> right != NULL){
                temp = temp->right;
            }
            else{//add new node
                temp->right = NewNode(inpValue);
//                flag = 0;
                return 0;
            }
        }
        if (temp-> value == inpValue){//already exist
//            flag = 0;
            return -1;
        }

    }
    return -2;
}

void PrintTree(Node * Head,int offset){
    //Node * temp;
    for (int i = 0; i < offset; ++i) {
        printf("   ");
    }
    printf("%d\n",Head->value);
    if(Head->left != NULL){
        PrintTree(Head->left,offset+1);
    }
    if(Head->right!= NULL){
        PrintTree(Head->right,offset+1);
    }
//      return;
}

Node * initTree(){
    Node * Head = NewNode(16);
    for (int i = 0; i < 10; ++i) {
        AddNode(rand() % 100, Head);
    }
    return Head;
}

int LookLongest(Node * Head){
    if((Head ->left==NULL)&&(Head->right==NULL))
        return 1;
    Node * temp;
    int l=-1,r=-1;
    if (Head->right != NULL){
        temp = Head ->right;
        r=LookLongest(temp);
    }
    if (Head ->left != NULL){
        temp = Head -> left;
        l = LookLongest(temp);
    }
    if (l>r)
        return l+1;
    else
        return r+1;
}
int main() {
    srand(time(NULL));
    Node * Head = initTree();
    PrintTree(Head,0);
    int x = LookLongest(Head);
    printf("\n%d",x);
    return 0;
}
