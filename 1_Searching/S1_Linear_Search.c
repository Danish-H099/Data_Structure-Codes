#include <stdio.h>
 
 int main(){
    int a[100];
    int n,num;

    printf("\nEnter the no. of Elements You want :");
    scanf("%d",&n);

    printf("Enter the Elements of array....\n");
    for(int i=0;i<n;i++){
        printf("Enter the %d element :",i+1);
        scanf("%d",&a[i]);
    }

    printf("Your Array is :");
    for(int i=0;i<n;i++){
        printf("%3d",a[i]);
    }

    printf("\nEnter the Element you are looking for :");
    scanf("%d",&num);

    int c=0;
    for(int i=0;i<n;i++){
        if(a[i]==num){
            printf("Your Element is present at %d position.",i+1);
            c=1;
            break;
        }
    }

    if(c==0){
         printf("Your Element is not present in the array.");
    }

    return 0;
 }