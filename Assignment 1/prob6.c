#include<stdio.h>

int main(){
    int a,b,c;
    printf("Enter first number: ");
    scanf("%d",&a);
    printf("Enter second number: ");
    scanf("%d",&b);
    printf("Enter third number: ");
    scanf("%d",&c);

    int max=a,min=a;
    if (b>max)
        max = b;
    else if (c>max)
        max = c;
    if (b<min)
        min = b;
    else if (c<min)
        min = c;
    printf("The maximum number is %d while the minimum number is %d",max,min);
    return 0;
}