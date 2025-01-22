#include<stdio.h>

int main(){
    int amount;
    printf("Enter the amount to be withdrawn: ");
    scanf("%d", &amount);

    int n100=0, n50=0, n10=0;
    while (amount>=100){
        n100++;
        amount-=100;
    }
    while (amount>=50){
        n50++;
        amount-=50;
    }
    while (amount>=10){
        n10++;
        amount-=10;
    }
    printf("Rs. 10 notes: %d\nRs. 50 notes: %d\nRs. 100 notes: %d\n",n10,n50,n100);

    return 0;
}