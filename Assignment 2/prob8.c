#include<stdio.h>

int fac_sum(int x){
    int sum=0;
    for (int i=1;i<=x;i++){
        if (x%i==0) sum+=i;
    }
    return sum;
}

void main(){
    int n,sum=0;
    printf("Enter a number: ");
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        sum+=fac_sum(i);
    }
    printf("Sum of the series is %d",sum);
}