#include<stdio.h>

int factorial(int x){
    if (x==0 || x==1){
        return 1;
    }
    else return x*factorial(x-1);
}

void main(){
    int n,sum=0;
    printf("Enter a number: ");
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        sum+=factorial(i);
    }
    printf("Sum of the series is %d",sum);
}