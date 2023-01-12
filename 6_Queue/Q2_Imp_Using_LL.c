#include <stdio.h>
#include <stdlib.h>
typedef struct node sll;
struct node {
    int data;
    sll *next;
};
sll *front=0;
sll *rear=0;

void enqueue(int c){
    sll *newnode;
    newnode=(sll*)malloc(sizeof(sll));
    newnode->data=c;
    newnode->next=0;

    if(front==0&&rear==0){
        front=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}

void dequeue(){
    sll*temp;
    temp=front;
   if(front==0&&rear==0){
        printf("Queue is empty");
    }
    else if(front==rear){
        front=rear=0;
        free(temp);
    }
    else{
        front=front->next;
        free(temp);
    }
}
void display(){
    sll*temp;
    if(front==0&&rear==0){
        printf("Queue is empty");
    }
    else{
    temp=front;
    while(temp!=0){
        printf("%3d",temp->data);
        temp=temp->next;
            }
    }
}


int main(){
    enqueue(2);
    enqueue(4);
    enqueue(7);
    printf("\nQueue after enqueue of  2,4 &7 :");
display();
    dequeue();
    printf("\nQueue after one dequeue :");
display();
    dequeue();
    dequeue();
    printf("\nQueue after two dequeue :");
display();
    enqueue(-1);

    printf("\nQueue after enqueue of -1 :");
display();
    return 0;
}