#include<stdio.h>

int main(){
    int a,b, temp;
    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    /* Swapping */
    temp = a;
    a = b;
    b = temp;
    
    printf("%d %d",a,b);
    return 0;
}