#include<stdio.h>

void main(){
    int n,fac=1;
    printf("Enter a number: ");
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        fac*=i;
    }
    printf("%d! is equal to %d\n",n,fac);
}