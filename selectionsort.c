#include<stdio.h>
#include<conio.h>
#define MAX 100

void SelectionSort(int a[],int n);
int main(){
    int n,i,a[MAX];
    //clrscr();
    printf("Enter Number of Element to be sort:");
    scanf("%d",&n);
    printf("\n Enter %d Elements in array to sort:",n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("\n Elements before sorting:\n");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    SelectionSort(a,n);
    printf("\n Elements after sorting:\n");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }

return 0;
}

void SelectionSort(int a[],int n){
    int i,j,swap,position;
    for(i=0;i<n-1;i++){
       
        position=i;
    
        for(j=i+1;j<n;j++){
            if(a[position]>a[j]){
                position=j;

            }
        
        if(position!=i){
            swap=a[i];
            a[i]=a[position];
            a[position]=swap;
        }
        }
        
    }
}