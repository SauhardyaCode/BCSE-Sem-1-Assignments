#include<stdio.h>

int main(){
    FILE *file = fopen("prob2.c","r");
    char content[1000];

    while (fgets(content,sizeof(content),file)){
        printf("%s",content);
    }
    printf("\n");
    return 0;
}