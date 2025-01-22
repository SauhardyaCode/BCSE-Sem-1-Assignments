#include<stdio.h>

void main(){
    char line[100];
    printf("Write a line: ");
    scanf("%[^\n]s",line);

    int i=0;
    while (line[i]){
        if (line[i]>='a' && line[i]<='z'){
            line[i]+=('A'-'a');
        }
        i++;
    }

    printf("The line in capitals is: %s",line);
}