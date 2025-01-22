#include<stdio.h>
#include<math.h>
#define size 40

const char dig[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
char num[size];
char ans[size];

int inpErr(int);
int intify(int);
char* binary(int);
void printBin(char*);

void bin2dec();
void bin2oct();
void bin2hex();
void oct2bin();
void oct2dec();
void oct2hex();
void dec2bin();
void dec2oct();
void dec2hex();
void hex2bin();
void hex2oct();
void hex2dec();

int main(){
    int inp,out;
    printf("\n1) Binary 2) Octal 3) Decimal 4) Hexadecimal\nEnter the input number system [1-4]: ");
    scanf("%d",&inp);
    if (inp>4 || inp<1){
        printf("Enter menu number [1-4] !!");
        return 0;
    }
    printf("1) Binary 2) Octal 3) Decimal 4) Hexadecimal\nEnter the output number system [1-4]: ");
    scanf("%d",&out);
    if (out>4 || out<1){
        printf("Enter menu number [1-4] !!");
        return 0;
    }
    printf("\nEnter the number: ");
    scanf("%s",num);
    if (inp==1 && inpErr(1) || inp==2 && inpErr(7) || inp==3 && inpErr(9) || inp==4 && inpErr(15)) return 0;

    printf("In output number system it is: ");
    if (inp==1&&out==2) bin2oct();
    else if (inp==1&&out==3) bin2dec();
    else if (inp==1&&out==4) bin2hex();
    else if (inp==2&&out==1) oct2bin();
    else if (inp==2&&out==3) oct2dec();
    else if (inp==2&&out==4) oct2hex();
    else if (inp==3&&out==1) dec2bin();
    else if (inp==3&&out==2) dec2oct();
    else if (inp==3&&out==4) dec2hex();
    else if (inp==4&&out==1) hex2bin();
    else if (inp==4&&out==2) hex2oct();
    else if (inp==4&&out==3) hex2dec();
    else printf("%s",num);
    printf("\n");
    return 0;
}

int inpErr(int end){
    for (int i=0;i<size;i++){
        if ((int)num[i]==0) break; //ASCII code 0 that is NULL character is used to represent end of string in C
        for (int j=0;j<=end;j++){
            if (num[i]==dig[j]) break;
            else if (j==end && num[i]!=dig[j]){
                printf("Invalid Input! Digits must be 0-%c\n",dig[end]);
                return 1;
            }
        }
    }
    return 0;
}

int intify(int base){
    int exp=-1;
    float dec=0;
    for (int i=size-1;i>=0;i--){
        if (num[i]!='\0'){
            exp+=1;
            for (int j=0;j<base;j++){
                if (dig[j]==num[i]){
                    dec+=j*pow(base,exp);
                }
            }
        }
    }
    return (int)dec;
}

char* binary(int dec){
    static char bin[size];
    int rem;
    for (int i=0;i<size;i++){
        if (dec==0) break;
        rem = dec%2;
        dec/=2;
        if (rem==1) bin[i]='1';
        else bin[i]='0';
    }
    return bin;
}

void printBin(char* bin){
    for (int j=size-1;j>=0;j--){
        if (bin[j]!='\0') printf("%c",bin[j]);
    }
}

void bin2dec() {printf("%d",intify(2));}
void bin2oct() {printf("%o",intify(2));}
void bin2hex() {printf("%x",intify(2));}
void oct2dec() {printf("%d",intify(8));}
void oct2hex() {printf("%x",intify(8));}
void dec2bin() {printBin(binary(intify(10)));}
void oct2bin() {printBin(binary(intify(8)));}
void dec2oct() {printf("%o",intify(10));}
void dec2hex() {printf("%x",intify(10));}
void hex2bin() {printBin(binary(intify(16)));}
void hex2oct() {printf("%o",intify(16));}
void hex2dec() {printf("%d",intify(16));}