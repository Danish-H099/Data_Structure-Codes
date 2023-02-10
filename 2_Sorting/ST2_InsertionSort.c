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
    for(int i=1;i<n;i++){
        for(int j=i-1;j;j--){
            

        }
    }

return 0;
}