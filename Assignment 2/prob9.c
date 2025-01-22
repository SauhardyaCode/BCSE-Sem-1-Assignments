#include<stdio.h>
#include<math.h>
#define N 100

int isPrime(int n){
    if (n<2) return 0;
    for (int i=2;i<=sqrt(n);i++){
        if (n%i==0) return 0;
    }
    return 1;
}

void main(){
    printf("All prime numbers between 1 and %d are as follows:\n",N);
    for (int i=0;i<=N;i++){
        if (isPrime(i)) printf("%d ",i);
    }
}