#include<stdio.h>
#include<conio.h>
#define MAX 100

void BubbleSort(int a[],int n);
int main(){
    int i,arr[MAX],n;
    printf("\n Enter the number of elements: ");
    scanf("%d",&n);
    printf("\n Enter %d elements of array:\n",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);

    }
    printf("\n Elements before sorting:\n");
    for(i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    BubbleSort(arr,n);
    printf("\n Elements after sorting:\n");
    for(i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
    
}

void BubbleSort(int a[],int n){
    int temp,i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]= temp;
            }
        }
    }
}