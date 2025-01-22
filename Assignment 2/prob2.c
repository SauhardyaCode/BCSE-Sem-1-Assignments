#include<stdio.h>

void main(){
    int num,sum=0;
    printf("Enter a number: ");
    scanf("%d",&num);
    while (num){
        sum+=num%10;
        num/=10;
    }
    printf("The sum of the digits is %d",sum);
}