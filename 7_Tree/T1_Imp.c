#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node * left;
    int data;
    struct node * right;
};

typedef struct node bt;

bt* create(){
    bt *newnode;
    int x;
    newnode=(bt*)malloc(sizeof(bt));
    printf("Enter data (-1 if you don't need another node) :");
    scanf("%d",&x);
    if(x==-1){
        return 0;
    }
    else{
        newnode->data=x;
        printf("\nEnter the left child of %d\n",x);
        newnode->left=create();
        printf("\nEnter the right child of %d\n",x);
        newnode->right=create();
        return newnode;
    }
}

void preorder(bt * root){
    if(root==0){
        return;
    }
    printf("%2d",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(bt * root){
    if(root==0){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%2d",root->data);
}

void inorder(bt * root){
    if(root==0){
        return;
    }
    inorder(root->left);
    printf("%2d",root->data);
    inorder(root->right);
}

void main(){
    bt * root;
    root=0;
    root=create();

    printf("\nPreorder display :");
    preorder(root);

    printf("\nPostorder display :");
    postorder(root);

    printf("\nInorder display :");
    inorder(root);

}
