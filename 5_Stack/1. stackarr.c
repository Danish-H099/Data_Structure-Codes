#include <stdio.h>

int stack[5];
int top=-1;

void push(){
    int x;
    printf("Enter Data :");
    scanf("%d",&x);
    if(top==4){
        printf("Stack Overflow");
    }
    else{
        //top++;
        stack[++top]=x;
    }
}

void pop(){
    int x;
    if(top==-1){
        printf("Stack is Empty");
    }
    else{
        x=stack[top--];
        //top--;
        printf("Deleted element is %d",x);
    }
}
 
void seek(){
    if(top==-1){
        printf("Stack is Empty");
    }
    else{
        printf("Element on the Top is %d",stack[top]);
    }
}

void display(){

     if(top==-1){
        printf("Stack is Empty");
    }
    else{
        for(int t=top;t>=0;t--){
            printf("%3d",stack[t]);
        }
    }
}

int main(){
    int ch;
    do{
        printf("\n Enter 1->push,2->pop,3->seek,4->display :");
        scanf("%d",&ch);
        switch (ch) {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            seek();
            break;
        case 4:
            display();
            break;
        default:
            printf("Enter valid option");
            break;
        }
        printf("\nDo you again want to manipulate stack (0,1) :");
        scanf("%d",&ch);
    }while(ch);
    return 0;
}