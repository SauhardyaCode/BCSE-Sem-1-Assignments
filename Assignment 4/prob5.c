#include<stdio.h>
#define size 20

int intify(char* num){
    int factor=1,dec=0;
    for (int i=size-1;i>=0;i--){
        if (!num[i]) continue;
        dec+=(num[i]-'0')*factor;
        factor*=10;
    }
    return dec;
}

void main(){
    static char num[size];
    printf("Enter a number (string): ");
    scanf("%19s",num);
    printf("The integer converted is: %d\n",intify(num));
}