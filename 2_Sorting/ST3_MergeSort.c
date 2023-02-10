// WAP to implement Merge Sort using divide and conquer method

#include <stdio.h>


void merge(int a[],int l,int m,int u){
    int i=l;
    int j=m+1;
    int k=l;
    int x=u-l+1;
    int b[x];
    while(i<=m && j<=u){
        if(a[i]<=a[j]){
            b[k++]=a[i++];
        }
        else{
            b[k++]=a[j++];
        }
    }
    if(i>m){
        while(j<=u){
            b[k++]=a[j++];
        }
    }
    else{
        while(i<=m){
            b[k++]=a[i++];
        }
    }

    for(int k=l;k<=u;k++){
        a[k]=b[k];
    }

}

void mergeSort(int a[],int l,int u){
    if(l<u){
        int m=(l+u)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,u);
        merge(a,l,m,u);
    }
}


int main(){
    int n;
    printf("Enter the number of elements you want :");
    scanf("%d",&n);
    int a[n];
    int l=0;
    int u=n-1;
    for(int i=0;i<n;i++){
        printf("Enter %d Element :",i+1);
        scanf("%d",&a[i]);
    }
    mergeSort(a,l,u);
    printf("The Sorted Array is :");
    for(int i=0;i<=u;i++){
        printf("%d ",a[i]);
    }
return 0;
}