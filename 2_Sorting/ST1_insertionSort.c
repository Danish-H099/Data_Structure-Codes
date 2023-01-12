#include <stdio.h>
int main(){
    int n;
    
    printf("Enter the number of elements of Array :");
    scanf("%d",&n);

    int a[n];
    for(int i=0;i<n;i++){
        printf("Enter Element %d :",i+1);
        scanf("%d",&a[i]);
    }
    printf("Your Array is :");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    
    for(int i=0;i<n;i++){
        int min=a[i];
        for(int j=i+1;j<n;j++){
            if(a[j]<min){
                min=a[j];
                a[j]=a[i];
                a[i]=min;
            }
        }
    }

    printf("\nYour Sorted Array is :");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    return 0;
}