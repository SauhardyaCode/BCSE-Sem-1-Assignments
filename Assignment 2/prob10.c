#include<stdio.h>
#include<math.h>

int isPrime(int n){
    if (n<2) return 0;
    for (int i=2;i<=sqrt(n);i++){
        if (n%i==0) return 0;
    }
    return 1;
}

void main(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("The prime factors of %d are:\n",n);
    for (int i=1;i<=n/2;i++){
        if (n%i==0 && isPrime(i)) printf("%d ",i);
    }
}