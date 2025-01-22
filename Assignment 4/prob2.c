#include<stdio.h>

int digit_sum(int num){
    if (num>10){
        return num%10+digit_sum(num/10);
    }
    else return num;
}

void main(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("Sum of the digits of %d is %d\n",n,digit_sum(n));
}