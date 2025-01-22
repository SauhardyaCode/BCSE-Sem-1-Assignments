#include<stdio.h>
#define size 40

long long int binary(int dec){
    if (dec){
        return dec%2 + 10*binary(dec/2);
    }
    else return 0;
}

void main(){
    int n;
    printf("Enter a decimal number: ");
    scanf("%d",&n);
    printf("The decimal equivalent of %d is %lld\n",n,binary(n));
}