
#include<stdio.h>
#include<conio.h>
#define MAX 100

int min(int m,int p){
    if(p>m)
        return m;
    else
        return p;
}

int main(){
    int a[MAX],i,j,k=0,num,offset,n;
    int f[]={0,1,1,2,3,5,8,13,21,34,55,89};
    printf("\nEnter the length of array");
    scanf("%d",&n);
    printf("\nEnter array:\n");
    for(j=0;j<n;j++){
        scanf("%d",&a[j]);
    }
    printf("\nEnter the number you want to search:\n");
    scanf("%d",&num);
    
    k=n;
    offset=-1;
    i= min((offset+f[k-2]),(n-1));
    while(k!=0){
        if(num==a[i]){
             printf("\nElement found at %d position",(i+1));
            break;
        }
        else if(num>a[i]){
            k=k-1;
            offset=i;
            i=min(offset+f[k-2],n-1);
        }
        else if(num<a[i])
        {
            k=k-2;
            i=min(offset+f[k-2],n-1);
        }
    }
    if(k==0){
        printf("\nElement not found");
    }
    


return 0;

}

