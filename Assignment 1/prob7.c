#include<stdio.h>

int main(){
    int a,b,c;
    printf("Enter first number: ");
    scanf("%d",&a);
    printf("Enter second number: ");
    scanf("%d",&b);
    printf("Enter third number: ");
    scanf("%d",&c);

    float avg = (a+b+c)/3;
    printf("The average is %f\n",avg);
    int arr[3] = {a,b,c};

    for (int i=0; i<3; i++){
        if (arr[i]>avg){
            printf("%d is above average\n",arr[i]);
        }
        else if (arr[i]<avg){
            printf("%d is below average\n",arr[i]);
        }
    }
    return 0;
}