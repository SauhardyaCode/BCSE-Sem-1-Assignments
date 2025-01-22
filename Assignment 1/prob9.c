#include<stdio.h>

int main(){
    int sal;
    printf("Enter your basic salary (Rs.): ");
    scanf("%d",&sal);
    
    int gross = sal + sal*.6 + sal*.15;
    printf("The gross salary is Rs. %d", gross);
    return 0;
}