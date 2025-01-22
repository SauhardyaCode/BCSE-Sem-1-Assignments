#include<stdio.h>

void main(){
    int n,sum=0;
    printf("Enter a number: ");
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        sum+=i;
    }
    printf("The sum of the series is %d",sum);
}