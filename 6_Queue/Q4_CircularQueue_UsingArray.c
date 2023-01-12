#include <stdio.h>
#define N 5
int queue[N];
int front=-1;
rear=-1;

void enqueue(int c){
    if(front==-1&&rear==-1){
        front=rear=0;
        queue[front]=c;
    }
    else if (front==((rear+1)%N) ){
        printf("Queue in overflow");
    }
    else{
        rear=(rear+1)%N;
        queue[rear]=c;
    }
}

void dequeue(){
    if(front==-1&&rear==-1){
        printf("Queue is empty");
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        front=(front+1)%N;
    }
}

void display(){
    int temp;
    temp=front;
    if(front==-1&&rear==-1){
        printf("Queue is empty");
    }
    else{
        while(temp!=rear){
            printf("%2d",queue[temp]);
            temp=(temp+1)%N;
        }
        printf("%2d",queue[temp]);
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

    enqueue(1);
    enqueue(8);
    enqueue(5);
    printf("\nQueue after enqueue of 1,8 & 5 :");
display();

    enqueue(4);
    printf("\nQueue after enqueue of 4 :");
display();
    
    printf("\nQueue after enqueue of 7 :");
    enqueue(7);

    printf("\nFinal State of Queue :");
display();
    return 0;
}