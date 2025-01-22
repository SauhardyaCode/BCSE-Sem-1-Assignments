#include<stdio.h>

void main(){
    int a=1;
    int b=1;
    int c = ++a||b++;
    int d = b--&&--a;

    printf("%d %d %d %d\n",d,c,b,a);
}