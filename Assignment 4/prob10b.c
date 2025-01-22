#include<stdio.h>
#include<stdlib.h>
#define size 300
#define tok 3+26+26+10+1

char **words(char *text, char *tokens){
    char **words = (char **)malloc(size/2*sizeof(char *));
    for (int i=0;i<size/2;i++){
        words[i] = (char *)malloc(size/2*sizeof(char));
    }

    int cur1=0,cur2=0;
    for (int i=0;text[i];i++){
        for (int j=0;j<tok;j++){
            if (text[i]==tokens[i]){
                words[cur1][cur2] = text[i];
                cur2++;
                break;
            }
            else if (j==tok-1){
                if (cur2){
                    words[cur1][cur2] = 0;
                    cur2=0;
                    cur1++;
                }
            }
        }
    }
    return words;
}

void main(){
    char tokens[tok] = "'-_";
    for (int i=0;i<26;i++) tokens[3+i]='A'+i;
    for (int i=0;i<26;i++) tokens[3+26+i]='a'+i;
    for (int i=0;i<10;i++) tokens[3+26+26+i]='0'+i;

    char text[size];
    printf("Write something: ");
    scanf("%299[^\n]s",text);   //adjust the 299 according to the size(300), 299=size(300)-1

    for (int i=0;i<size/2;i++){
        printf("%s\n",words(text,tokens)[i]);
    }
}