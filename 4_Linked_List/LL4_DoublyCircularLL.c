// danish hussain dar / 2106112  / 30-09-22

#include <stdio.h>
#include <stdlib.h>

typedef struct node dcll;
struct node {
    dcll *prev;
    int data;
    dcll *next;
};

dcll *head,*tail,*newnode,*temp;


// <------------------   CREATION OF DCLL     ----------------->

void create (){
    printf("Make your linked list :\n");
    head=0;
    int choice=1;
    while (choice)
    {
    newnode=(dcll*)malloc(sizeof(dcll));
    printf("Enter data :");
    scanf("%d",&newnode->data);
    if(head==0){
        head=tail=newnode;
    }
    else{
        head->prev=newnode;
        tail->next=newnode;
        newnode->prev=tail;
        newnode->next=head;
        tail=newnode;
    }
    printf("Do you want to add another node (0,1) :");
    scanf("%d",&choice);
    }

}

// <------------------   INSERTION AT BEGINING   --------------->

void insertAtBeg(){
    newnode=(dcll*)malloc(sizeof(dcll));
    printf("Enter data :");
    scanf("%d",&newnode->data);
    if(head==0){
        head=newnode;
        tail=newnode;
        newnode->prev=tail;
        newnode->next=head;
    }
    else{
        newnode->next=head;
        newnode->prev=tail;
        head->prev=newnode;
        tail->next=newnode;
        head=newnode;
    }
}

// <---------------------   INSERTION AT END   ------------------->

void insertAtEnd(){
    newnode=(dcll*)malloc(sizeof(dcll));
    printf("Enter data :");
    scanf("%d",&newnode->data);
    if(head==0){
        head=newnode;
        tail=newnode;
        newnode->prev=tail;
        newnode->next=head;
    }
    else{
        newnode->prev=tail;
        newnode->next=head;
        tail->next=newnode;
        head->prev=newnode;
        tail=newnode;
    }

}

// <------------------   INSERTION AT ANY POSITION   --------------->

void insertAtPos(){
    int pos;
    int i=1;
    printf("Enter the position where you want to insert a node :");
    scanf("%d",&pos);
    int a=length();
    if(pos<1 || pos>a){
        printf("Position is Invalid!");
    }
    else if(pos==1){
        insertAtBeg();
    }
    else{
    newnode=(dcll*)malloc(sizeof(dcll));
    printf("Enter data :");
    scanf("%d",&newnode->data);
    temp=head;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    newnode->prev=temp;
    newnode->next=temp->next;
    temp->next=newnode->next->prev=newnode;
    }

}

//<--------------------  DELETION FROM THE BEGINING  ----------------->

void delFromBeg(){
    if(head==0){
        printf("List is Empty");
    }
    else if(head==tail){
        temp=head;
        head=tail=0;
        free(temp);
    }
    else{
        temp=head;
        head=head->next;
        head->prev=tail;
        tail->next=head;
        free(temp);
    }
}

//<--------------------  DELETION FROM THE END  ----------------->

void delFromEnd(){
    if(head==0){
        printf("List is Empty");
    }
    else{
        temp=tail;
        tail=tail->prev;
        tail->next=head;
        head->prev=tail;
        free(temp);

    }
}

//<--------------------  DELETION FROM ANY LOCATION  ----------------->

void delFromPos(){
    int pos ,i=1;
    int a=length();
    printf("Enter any location which you want to delete :");
    scanf("%d",&pos);
    if(pos<1||pos>a){
        printf("Enter a valid Position");
    }
    else if(pos==1){
        delFromBeg();
    }
    else if(pos==a){
        delFromEnd();
    }
    else{
        temp=head;
        while(i<pos){
            temp=temp->next;
            i++;
        }
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
    }
    free(temp);
}

// <-------------------   DISPLAY DCLL   ----------------->

void display(){
    temp=head;
    printf("\nYour Linked List is :");
    while(temp!=tail){
        printf("%3d",temp->data);
        temp=temp->next;
    }
    printf("%3d",tail->data);
}

// <----------------   LENGTH OF LINKED LIST -------------->

int length(){
    int count=1;
    temp=head;
    while(temp!=tail){
        count++;
        temp=temp->next;
    }
    return count;
}


//            <---------------------------  MAIN   ------------------------------->

int main(){
    create();
    display();

    int mchoice;

    printf("\n\nDo You want to add a node in the begining (0,1) :");
    scanf("%d",&mchoice);
    if(mchoice!=0){
        printf("\n<-----------  INSERTION AT BEGINING   ----------->\n");
        insertAtBeg();
        display();
    }

    printf("\n\nDo You want to add a node in the End (0,1) :");
    scanf("%d",&mchoice);
    if(mchoice!=0){
        printf("\n<---------------  INSERTION AT END   ------------->\n");
        insertAtEnd();
        display();
    }

    printf("\n\nDo You want to add a node at any location (0,1) :");
    scanf("%d",&mchoice);
    if(mchoice!=0){
        printf("\n<----------  INSERTION AT ANY POSITION   --------->\n");
        insertAtPos();
        display();
    }

    printf("\n\nDo You want to Delete a node at the Begining (0,1) :");
    scanf("%d",&mchoice);
    if(mchoice!=0){
        printf("\n<---------  DELETION FROM THE BEGINING   --------->\n");
        delFromBeg();
        display();
    }


    printf("\n\nDo You want to Delete a node at the End (0,1) :");
    scanf("%d",&mchoice);
    if(mchoice!=0){
        printf("\n<------------  DELETION AT THE END   ------------->\n");
        delFromEnd();
        display();
    }

    printf("\n\nDo You want to Delete a node at any Position (0,1) :");
    scanf("%d",&mchoice);
    if(mchoice!=0){
        printf("\n<-----------  DELETION AT ANY POSITION   ---------->\n");
        delFromPos();
        display();
    }

    int a=length();
    printf("\n\nLenght of Your linked List is : %d",a);

    return 0;
}