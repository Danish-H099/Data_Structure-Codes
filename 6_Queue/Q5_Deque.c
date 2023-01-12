#include <stdio.h>
#define N 5
int rear=-1;
int front=-1;
int que[N];

void enqueueFront(int x){
    if((front==0 && rear==N-1)||(front==rear+1)){
        printf("Queue is full");
    }
    else if(front==-1&&rear==-1){
        front=rear=0;
        que[front]=x;
    }
    else if(front==0){
        front=N-1;
        que[front]=x;
    }
    else{
        front--;
        que[front]=x;
    }
}

void enqueueRear(int x){
    if((front==0 && rear==N-1)||(front==rear+1)){
        printf("Queue is full");
    }
    else if(front==-1&&rear==-1){
        front=rear=0;
        que[front]=x;
    }
    else if(rear==N-1){
        rear=0;
        que[front]=x;
    }
    else{
        rear++;
        que[rear]=x;
    }
}

void dequeueFront(){
    if(front==-1&&rear==-1){
        printf("Queue is empty!");
    }
    else if(front==N-1){
        front=0;
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        front++;
    }
}

void dequeueRear(){
    if(front==-1&&rear==-1){
        printf("Queue is empty!");
    }
    else if(rear==0){
        rear==N-1;
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        rear--;
    }
}



void display(){
    int t=front;
    while(t!=rear){
        printf(" %d",que[t]);
        t=(t+1)%N;
    }
    printf(" %d",que[t]);
}

int main(){
    enqueueFront(3);
    enqueueFront(4);
    printf("\n Queue after front Enqueue of 3 & 4 :");
    display();

    enqueueRear(-2);
    printf("\n Queue after Rear Enqueue of -2 :");
    display();

    enqueueFront(13);
    printf("\n Queue after front Enqueue of 13 :");
    display();

    dequeueFront();
    printf("\n Queue after front Dequeue :");
    display();

    dequeueRear();
    printf("\n Queue after Rear Dequeue :");
    display();

}