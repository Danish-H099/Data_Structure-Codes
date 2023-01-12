#include <stdio.h>
#include <stdlib.h>

typedef struct node cll;

struct node {
    int data;
    cll* next;
};

cll*tail,*newnode,*temp;

        //     <-------------  CLL Creation  -------------->

void createCll(){
    
    int choice=1;
    while(choice){
        tail=0;
        newnode=(cll*)malloc(sizeof(cll));
        printf("Enter data :");
        scanf("%d",&newnode->data);
        if(tail==0){
            tail=newnode;
            tail->next=newnode;
        }
        else{
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
        }
        
        printf("Do You wanna add another node (0,1) :");
        scanf("%d",&choice);
    }
}

        //     <-----------------  Display  ---------------->
void display(){
    printf("Your linked List -> ");
    temp=tail->next;
    while(temp!=tail){
        printf(" %d",temp->data);
        temp=temp->next;
    }
    printf(" %d",tail->data);
}


int main(){
     int ch=1;
    printf("Create Your Linked List :\n");
    createCll();
    display();


    return 0;
}