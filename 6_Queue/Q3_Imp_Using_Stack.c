
#include <stdio.h>
#define N 5
int top1=-1,top2=-1;
int s1[N],s2[N];
int count=0;

void enqueue(int x){
    push1(x);
    count++;
}

void dequeue(){
    int b;
    if(top1==-1&&top2==-1){
        printf("Queue is empty!");
    }
    else{
        for(int i=0;i<count;i++){
            b=pop1();
            push2(b);
        }
        pop2();
        count--;
        for(int i=0;i<count-1;i++){
            b=pop2();
            push1(b);
        }
    }
}

void push1(int x){
    if(top1==N-1){
        printf("Queue is full ");
    }
    else{
        top1++;
        s1[top1]=x;
    }
}

void push2(int x){
    if(top2==N-1){
        printf("Queue is full ");
    }
    else{
        top2++;
        s2[top2]=x;
    }
}

int pop1(){
    return s1[top1--];
}

int pop2(){
    return s2[top2--];
}

void display(){
    if(top1=-1){
        printf("Queue is empty\n");
    }
    else{
        for(int i=0;i<=count;i++){
            printf("%2d",s1[i]);
        }
    }
}

int main(){
    enqueue(2);
    enqueue(-4);
    enqueue(7);
    display();
    // dequeue();
    // display();
    return 0;
}
