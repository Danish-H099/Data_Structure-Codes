#include <stdio.h>

 void bsearch(int a[],int num,int low,int high){
    int mid;
    mid=(low+high)/2;

    if(high==low){
        printf("Your Element isn't present in Array");
        return;
    }
    else if(a[mid]==num){
        printf("Your Element is present in Array");
        return;
    }
    else if(a[mid]<num){
        low=mid+1;
        bsearch(a,num,low,high);
    }
    else{
        high=mid-1;
        bsearch(a,num,low,high);
    }
}

int main(){
int a[100];
    int n,num;

    printf("\nEnter the no. of Elements You want :");
    scanf("%d",&n);

    int low=0,high=n;

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

    bsearch(a,num,low,high);

    return 0;
}
