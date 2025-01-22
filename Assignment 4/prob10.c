#include<stdio.h>
#include<stdlib.h>

char tokens[66] = "_\'-";

char **word_list(char *text, char *tokens){
    int i=0,cur=0,cur2=0;

    char **words = (char **)malloc(150*sizeof(char *));
    for (int j=0;j<150;j++) words[j] = (char *)malloc(150*sizeof(char));

    while (text[i]){
        for (int j=0;j<65;j++){
            if (text[i]==tokens[j]){
                words[cur][cur2]=text[i];
                cur2++;
                break;
            }
            else if (j==64){
                if (cur2){
                    words[cur][cur2]='\0';
                    cur++;
                    cur2=0;
                }
            }
        }
        i++;
    }
    return words;
}

char *reverse(char *word){
    int len=0;
    while (word[len]) len++;
    for (int i=0;i<len/2;i++){
        char temp = word[i];
        word[i] = word[len-1-i];
        word[len-1-i] = temp;
    }
    return word;
}

char *modify(char *str1){
    char **words = word_list(str1,tokens);
    char *str2 = (char *)malloc(200*sizeof(char));

    int len=0,x=0;
    while (words[len][0]) len++;
    for (int i=0;i<len;i++){
        char *word = reverse(words[i]);
        for (int j=0;j<150;j++){
            str2[x] = word[j];
            x++;
        }
    }
    return str2;
}

void main(){
    for (int i=0;i<26;i++) tokens[i+1]='A'+i;
    for (int i=0;i<26;i++) tokens[27+i]='a'+i;
    for (int i=0;i<10;i++) tokens[53+i]='0'+i;

    char text[200];
    printf("Enter some text: ");
    scanf("%199[^\n]s",text);

    printf("%s\n",modify(text));
}


// #include<stdio.h>
// #include<stdlib.h>

// char tokens[66] = "_\'-";

// char **word_list(char *text, char *tokens){
//     int i = 0, cur = 0, cur2 = 0;
//     char **words = (char **)malloc(150 * sizeof(char *));
    
//     for (int j = 0; j < 150; j++) {
//         words[j] = (char *)malloc(150 * sizeof(char));
//     }

//     while (text[i]) {
//         for (int j = 0; j < 63; j++) {
//             if (text[i] == tokens[j]) {
//                 words[cur][cur2] = text[i];
//                 cur2++;
//                 break;
//             } else if (j == 62) {
//                 if (cur2) {
//                     words[cur][cur2] = '\0';  // Null terminate the word
//                     cur++;
//                     cur2 = 0;
//                 }
//             }
//         }
//         i++;
//     }

//     if (cur2) {  // Handle the last word if any
//         words[cur][cur2] = '\0';
//         cur++;
//     }

//     return words;
// }

// char *reverse(char *word){
//     int len = 0;
//     while (word[len]) len++;
    
//     // Reverse the word in-place
//     for (int i = 0; i < len / 2; i++) {
//         char temp = word[i];
//         word[i] = word[len - 1 - i];
//         word[len - 1 - i] = temp;
//     }
//     return word;
// }

// char *modify(char *str1){
//     char **words = word_list(str1, tokens);
//     char *str2 = (char *)malloc(200 * sizeof(char));
//     int x = 0;

//     int len = 0;
//     while (words[len][0]) len++;  // Calculate the number of words

//     for (int i = 0; i < len; i++) {
//         char *word = words[i];
//         word = reverse(word);  // Reverse the word
//         int j = 0;
        
//         // Append reversed word to the result string
//         while (word[j]) {
//             str2[x++] = word[j++];
//         }
//     }
//     str2[x] = '\0';  // Null terminate the result string
//     return str2;
// }

// int main() {
//     // Populate the token list
//     for (int i = 0; i < 26; i++) tokens[i + 1] = 'A' + i;  // Uppercase letters
//     for (int i = 0; i < 26; i++) tokens[27 + i] = 'a' + i;  // Lowercase letters
//     for (int i = 0; i < 10; i++) tokens[53 + i] = '0' + i;  // Digits

//     char text[200];
//     printf("Enter some text: ");
//     scanf("%199[^\n]s", text);

//     char *modifiedText = modify(text);
//     printf("%s\n", modifiedText);
    
//     free(modifiedText);  // Free allocated memory
//     return 0;
// }
