#include<stdio.h>
#include<stdlib.h>

int count_words(char *text, char *tokens){
    int i=0,cur=0,cur2=0;

    char **words = (char **)malloc(150*sizeof(char *));
    for (int j=0;j<150;j++) words[j] = (char *)malloc(150*sizeof(char));

    for (int i=0;i<150;i++){
        for (int j=0;j<150;j++) words[i][j]=0;
    }
    while (text[i]){
        for (int j=0;j<63;j++){
            if (text[i]==tokens[j]){
                words[cur][cur2]=text[i];
                cur2++;
                break;
            }
            else if (j==62){
                if (cur2){
                    cur++;
                    cur2=0;
                }
            }
        }
        i++;
    }

    for (int k=0;k<150;k++){
        if (words[k][0]) printf("%s\n",words[k]);
    }

    int count=0;
    for (int k=0;k<150;k++){
        if (words[k][0]) count++;
    }

    for (int i=0;i<150;i++){
        free(words[i]);
    }
    free(words);
    words = NULL;

    return count;
}

void main(){
    char tokens[66] = "_\'-";
    for (int i=0;i<26;i++) tokens[i+1]='A'+i;
    for (int i=0;i<26;i++) tokens[27+i]='a'+i;
    for (int i=0;i<10;i++) tokens[53+i]='0'+i;

    char text[200];
    printf("Enter some text: ");
    scanf("%199[^\n]s",text);
    printf("Words count: %d\n",count_words(text,tokens));
}