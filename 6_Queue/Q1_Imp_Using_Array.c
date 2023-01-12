#include <stdio.h>
#define N 5
int queue[N];
front=-1;
rear=-1;

void enqueue(int a){
    if(front==-1&&rear==-1){
        front=rear=0;
        queue[rear]=a;
    }
    else if(rear==N-1){
        printf("overflow");
    }
    else{
        rear++;
        queue[rear]=a;
    }
}

void dequeue(){
    if(front==-1&&rear==-1){
        printf("Queue is empty!");
    }
    else if(front==rear){
        front=rear=0;
    }
    else{
        front++;
    }
}

void seek(){
    if(front==-1&&rear==-1){
        printf("Queue is empty!");
    }
    else{
        printf("%d",queue[front]);
    }
}
void display(){
    if(front==-1&&rear==-1){
        printf("Queue is empty!");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("%3d",queue[i] );
        }
    }
}


int main(){
    enqueue(2);
    enqueue(4);
    enqueue(-1);
    printf("\n display :");
    display();
   
    printf("\n seek :");
    seek();

    dequeue();
    printf("\n display after dequeue :");
    display();
    return 0;

}
