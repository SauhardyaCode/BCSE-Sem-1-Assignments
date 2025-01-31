/* Program 13: Menu driven Number system converter */

#include<stdio.h>
#define size 40

char dig[16]; // Array to store 0-f as chars
char n[size];
int inp,out,len;

int myPow(int,int); //not necessary if <math.h> works properly
int typeErr(int);
int numErr(int);
int intify(int);
char *dec2base(int,int);
void printChar(char*);

void bin2oct(){printChar(dec2base(intify(2),8));}
void bin2dec(){printf("%d",intify(2));}
void bin2hex(){printChar(dec2base(intify(2),16));}
void oct2bin(){printChar(dec2base(intify(8),2));}
void oct2dec(){printf("%d",intify(8));}
void oct2hex(){printChar(dec2base(intify(8),16));}
void dec2bin(){printChar(dec2base(intify(10),2));}
void dec2oct(){printChar(dec2base(intify(10),8));}
void dec2hex(){printChar(dec2base(intify(10),16));}
void hex2bin(){printChar(dec2base(intify(16),2));}
void hex2oct(){printChar(dec2base(intify(16),8));}
void hex2dec(){printf("%d",intify(16));}

void main(){
    // Initializing the digits array
    for (int i=0;i<10;i++) dig[i] = '0'+i;
    for (int i=0;i<6;i++) dig[10+i] = 'a'+i;

    // Taking the Input Menu Number
    printf("1. Binary, 2. Octal, 3. Decimal, 4. Hexadecimal\n");
    printf("Enter the input number type [1-4]: ");
    scanf("%d",&inp);
    // Checking the Input Menu Number
    if (typeErr(inp)) return;

    // Taking the Number as a character
    printf("Enter the number: ");
    scanf("%s",n);
    // Calculating the string length of the Number
    for (int i=0;i<size;i++){
        if (!n[i]){ //breaks the loop when it encounters a '\0' (null) character
            len=i;
            break;
        }
    }
    // Checking if the digits of the Number are in the Number System
    if (inp==1 && numErr(2) || inp==2 && numErr(8) || inp==3 && numErr(10) || inp==4 && numErr(16)) return;

    // Taking the Output Menu Number
    printf("1. Binary, 2. Octal, 3. Decimal, 4. Hexadecimal\n");
    printf("Enter the output number type [1-4]: ");
    scanf("%d",&out);
    // Checking the Output Menu Number
    if (typeErr(out)) return;

    // Printing the Conversion based on Input and Output Menu Numbers
    printf("\nThe result is: "); // Left Padding of result
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
    else printf("%s",n); // Prints the Input String in case Input and Output Menu Numbers are same
    printf("\n"); // Right Padding of result

}

// In case the <math.h> does not work!
// Power function that calculates b raised to the power of e
int myPow(int b, int e){
    int res=1;
    for (int i=0;i<e;i++) res*=b;
    return res;
}

// Checks if the menu number entered is in the range [1-4]
int typeErr(int type){
    if (type>4 || type<1){
        printf("ERR: Invalid choice [Enter choice in 1-4]\n");
        return 1;
    }
    return 0;
}

// Checks if the string entered as the Input Number follows the rules in its respective Number System
// The 'end' parameter corresponds to the index in the array 'dig' upto which the digits are valid
int numErr(int end){
    for (int i=0;i<len;i++){
        for (int j=0;j<end;j++){
            if (n[i]==dig[j]) break; // If the digit at index 'i' is present in the valid subarray next digit is checked
            else if (j==end-1){ // If the last iteration occurs and still the digit is not found in the subarray
                printf("ERR: Invalid digits according to the input number system!\n");
                return 1;
            }
        }
    }
    return 0;
}

// Converts the input Number string to decimal integer
int intify(int base){
    int dec=0;
    for (int i=0;i<size;i++){
        if (!n[i]) break;
        for (int j=0;j<base;j++){
            if (n[i]==dig[j]){
                dec+=myPow(base,len-1-i)*j;
            }
        }
    }
    return dec;
}

// Converts decimal to any other base using repeated division and remainder appending
char *dec2base(int dec, int base){
    static char res[size];
    int i=0;
    while (dec){
        res[i] = dig[dec%base];
        dec/=base;
        i++;
    }
    return res;
}

// Prints the string of characters (for Binary, Octal and Hexadecimal) using inverted loop
void printChar(char *b){
    for (int i=size-1;i>=0;i--){
        printf("%c",b[i]);
    }
}