#include<stdio.h>

void main(){
    const char vowels[] = "aeiouAEIOU";
    char text[200];
    printf("Enter some text: ");
    scanf("%199[^\n]s",text);

    int i=0,count=0;
    while (text[i]){
        int clearance=0;
        for (int j=0;j<10;j++){
            if (vowels[j]==text[i]) clearance++;
            if (vowels[j]==text[i+1]) clearance++;
        }
        if (clearance==2) count++;
        i++;
    }

    printf("Two successive vowels count: %d",count);
}