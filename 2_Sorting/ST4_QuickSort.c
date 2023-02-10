#include <stdio.h>

int partition(int a[],int l,int u){
    int start =l;
    int end = u;
    int pivot=a[l];
    int temp;

    while(start<end){
        while(a[start]<=pivot){
            start++;
        }

        while(a[end]>pivot){
            end--;
        }

        if(start<end){
            temp=a[start];
            a[start]=a[end];
            a[end]=temp;
        }
    }

    temp=a[l];
    a[l]=a[end];
    a[end]=temp;

    return end;
}

void quickSort(int a[],int l,int u){
    if(l<u){
        int loc=partition(a,l,u);
        quickSort(a,l,loc-1);
        quickSort(a,loc+1,u);
    }
}

int main(){
    int n;
    printf("Enter the number of elements you want :");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        printf("Enter %d Element :",i+1);
        scanf("%d",&a[i]);
    }
    int l=0;
    int u=n-1;
    quickSort(a,l,u);
    printf("The Sorted Array is :");

    for(int i=0;i<=u;i++){
        printf("%d ",a[i]);
    }
return 0;
}