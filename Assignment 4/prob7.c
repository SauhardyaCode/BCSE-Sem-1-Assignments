#include<stdio.h>
#define size 20

char *stringify(int num){
    if (!num) return "0";
    static char str[size];
    int i=0,neg=0,len;
    if (num<0){
        neg=1;
        num*=-1;
    }
    while (num){
        str[i]='0'+(num%10);
        num/=10;
        i++;
    }
    if (neg) str[i]='-';
    for (int j=size;j>=0;j--){
        if (str[j]){
            len=j+1;
            break;
        }
    }
    int temp; 
    for (int j=0;j<len/2;j++){
        temp = str[j];
        str[j] = str[len-1-j];
        str[len-1-j] = temp;
    }
    return str;
}

void main(){
    int num;
    printf("Enter an integer: ");
    scanf("%d",&num);

    printf("The string version of the number is: %s\n",stringify(num));
}