#include<stdio.h>

int main(){
    int a,b;
    float frac;
    printf("Enter first number: ");
    scanf("%d",&a);
    printf("Enter second number: ");
    scanf("%d",&b);

    if (a>b){
        frac = a/b;
        printf("%d/%d is equal to %f",a,b,frac);
    }
    else{
        frac = b/a;
        printf("%d/%d is equal to %f",b,a,frac);
    }
    return 0;
}