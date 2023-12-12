#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100

void BinarySearch(int arr[],int n,int x );
void BubbleSort(int a[],int n);
int main(){
    int arr[MAX],i,n,y;
    printf("\n Enter the number of elements:\n");
    scanf("%d",&n);
    printf("\n Enter %d elements:\n",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\n Enter the element you want to search:\n");
    scanf("%d",&y);
    BubbleSort(arr,n);
    BinarySearch(arr,n,y);

    return 0;
}

void BubbleSort(int a[],int n){
    int i,j,temp;
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
void BinarySearch(int arr[],int n,int x ){
    int f=0,l=n-1,m=0,i,j,temp;
    while(f<=l)
    {
        m=(f+l)/2;
        if(arr[m]== x){
            printf("\nElement found at %d",m);
            return;
        }
        else if(arr[m]<x){
            f= m+1;
        }
        else{
            l=m-1;
        }
        
        
    }

printf("\n Element not found");

}
