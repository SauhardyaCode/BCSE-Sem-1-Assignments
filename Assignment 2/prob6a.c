#include<stdio.h>

int factorial(int x){
    if (x==0 || x==1){
        return 1;
    }
    else return x*factorial(x-1);
}

void main(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("%d! is equal to %d",n,factorial(n));
}