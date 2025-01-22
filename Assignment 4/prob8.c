#include<stdio.h>

int palindrome(char *str){
    int len=0;
    while (str[len]) len++;
    for (int i=0;i<len/2;i++){
        if (str[i]!=str[len-1-i]) return 0;
    }
    return 1;
}

void main(){
    char str[40];
    printf("Enter a string: ");
    scanf("%39[^\n]s",str);

    if (palindrome(str)) printf("The string is a palindrome!\n");
    else printf("The string is not a palindrome!\n");
}