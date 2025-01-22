#include<stdio.h>

void main(){
    int num,rev=0;
    printf("Enter a number: ");
    scanf("%d",&num);
    while (num){
        rev*=10;
        rev+=num%10;
        num/=10;
    }
    printf("The reverse of the number is %d",rev);
}