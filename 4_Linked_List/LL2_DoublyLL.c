#include <stdio.h>
#include <stdlib.h>

typedef struct node dll;
struct node{
    dll* prev;
    int data;
    dll* next;
};
dll *head,*temp,*newnode;

        //    <---------------   CREATING DLL  --------------->
void create(){
    int choice=1;
    head=0;
    while(choice){
        newnode=(dll*)malloc(sizeof(dll));
        printf("Enter data :");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0){
            head=temp=newnode;
            head->prev=0;
        }
        else{
            newnode->prev=temp;
            temp->next=newnode;
            newnode->next=0;
            temp=newnode;
        }
        printf("Do You wanna add another node (0,1) :");
        scanf("%d",&choice);
    }
}

       //    <----------  Insertion At Beginning  -------->
void insertAtBeg(){
        newnode=(dll*)malloc(sizeof(dll));
        printf("\nEnter data :");
        scanf("%d",&newnode->data);
        newnode->next=head;
        newnode->prev=0;
        head->prev=newnode;
        head=newnode;
}

        //    <-----------  Insertion At The End  --------->
void insertAtEnd(){
        newnode=(dll*)malloc(sizeof(dll));
        printf("\nEnter data :");
        scanf("%d",&newnode->data);
        newnode->next=0;
        temp=head;
        while(temp->next!=0){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
        
}

        //    <---------  Insertion At Any Position  ------->
void insertAtPos(){
    int pos;
    printf("\nEnter the Position where You Want to add :");
    scanf("%d",&pos);
    int c=count();
    if(pos>c || pos<0){
        printf("Invalid Position!");
    }
    else if(pos==1){
        insertAtBeg();
    }
    else{
        newnode=(dll*)malloc(sizeof(dll));
        printf("Enter data :");
        scanf("%d",&newnode->data);
        temp=head;
        for(int i=1;i<pos-1;i++){
            temp=temp->next;
        }
        newnode->next=temp->next;
        newnode->prev=temp;
        temp->next->prev=newnode;
        temp->next=newnode;
        }
}

        //    <---------  Deletion From Beginning -------->
void delFromBeg(){
    if(head==0){
        printf("List is Empty!");
    }
    else{
        temp=head;
        temp->next->prev=0;
        head=temp->next;
        free(temp);
    }
}

       //    <---------  Deletion From End -------->
void delFromEnd(){
    dll*prevtemp;
    if(head==0){
        printf("List is Empty!");
    }
    else{
        temp=head;
        while(temp->next!=0){
            prevtemp=temp;
            temp=temp->next;
        }
        prevtemp->next=0;
        free(temp);
    }
}

        //    <---------  Deletion From Any Position  -------->
void delFromPos(){
    int pos;
    printf("\nEnter the position which You want to delete :");
    scanf("%d",&pos);
    if(pos>count()||pos<0){
        printf("Invalid Position!");
    }
    else if(pos==count){
        delFromEnd();
    }
    else{
    temp=head;
    for(int i=1;i<pos;i++){
        temp=temp->next;
    }
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
    free(temp);
    }
}

        //    <----------- Searching in Linked List ------>
void search(){
    int num;
    printf("\nEnter the Element you are looking for :");
    scanf("%d",&num);
    temp=head;
    while(temp!=0){
        if(temp->data==num){
            printf("Your Element is present in the List");
            return;
        }
        temp=temp->next;
    }
    printf("Your Element isn't present in the List");
}

        //    <------------- Reverse Linked List --------->
void reverse(){
    dll*prevtemp,*nexttemp;
    nexttemp=head;
      
    while(nexttemp!=0){
        prevtemp=nexttemp;
        nexttemp=prevtemp->next;
        prevtemp->next=prevtemp->prev;
        prevtemp->prev=nexttemp;
    }
    head=prevtemp;
}
        //    <---------------  Count SLL  --------------->
int count(){
    int count=0;
    temp=head;
    while(temp!=0){
        temp=temp->next;
        count++;
    }
    return count;
}

        //    <---------------   Display SLL  --------------->
void display(){
    temp=head;
    printf("\nYour Linked list ->");

    while(temp!=0){
        printf(" %d",temp->data);
        temp=temp->next;
    }
}


int main(){
    int ch=1;

    printf("\nCreate Your Doubly Linked List \n");
    create();
    display();

    printf("\nDo You want to add element in the Beginning (0,1) :");
    scanf("%d",&ch);
    if(ch){
        printf("\n<---------   Insertion At Beginning   ------->");
        insertAtBeg();
        display();
    }

    printf("\nDo You want to add element at the End (0,1) :");
    scanf("%d",&ch);
    if(ch){
        printf("\n<---------    Insertion At the End    ------->");
        insertAtEnd();
        display();
    }

    printf("\nDo You want to add element at any Position (0,1) :");
    scanf("%d",&ch);
    if(ch){
        printf("\n<------   Insertion At Any Position   ------>");
        insertAtPos();       
        display();
    }

printf("\nDo You want to Delete From Beginning (0,1) :");
    scanf("%d",&ch);
    if(ch){
        printf("\n<------    Deletion from Beginnng    ------>");
        delFromBeg();
        display();
    }

    printf("\nDo You want to Delete from End (0,1) :");
    scanf("%d",&ch);
    if(ch){
        printf("\n<---------    Deletion from End    ------->");
        delFromEnd();
        display();
    }

    printf("\nDo You want to Delete from Any Position (0,1) :");
    scanf("%d",&ch);
    if(ch){
        printf("\n<-------   Deletion from any Position   ----->");
        delFromPos();
        display();
    }

    printf("\nDo You want to Search any Element from Linked List (0,1) :");
    scanf("%d",&ch);
    if(ch){
        printf("\n<-------   Linear Search in the List   ----->");
        search();
    }

    printf("\nDo You want to reverse The Linked List (0,1) :");
    scanf("%d",&ch);
    if(ch){
        printf("\n<-------   Revering Linked List   ----->");
        reverse();
        display();
    }

    

    int c=count();
    printf("\n\n Total no. of Element in the List is %d",c);

    return 0;
}