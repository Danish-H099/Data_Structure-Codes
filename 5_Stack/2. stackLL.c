#include <stdio.h>
#include <stdlib.h>

typedef struct node sll;

struct node {
    int data;
    sll* next;
};

sll *top=0;

void push(int x){
    sll* newnode;
    newnode=(sll*)malloc(sizeof(sll));
    newnode->data=x;
    newnode->next=top;
    top=newnode;
}

void pop(){
    sll* temp;
    temp=top;
    if(top==0)
    printf("Stack is Empty");
    else
    top=top->next;
    
    free(temp);
}

void seek(){
    if(top==0)
    printf("\nStack is Empty");
    else
    printf("\nElement on top is %d",top->data);
}

void display(){
    sll*temp;
    temp=top;
    printf("\nElements in Stack are :");
    if(top==0)
    printf("\nStack is Empty");
    else{
        while(temp!=0){
        printf("%3d",temp->data);
        temp=temp->next;
        }
    }
}

int main()
{
    int a=3,b=2,c=5;
    push(c);
     push(b);
    push(a);
    display();
    printf("\nPOP");
    pop();
    display();
    seek();
    

return 0;
}