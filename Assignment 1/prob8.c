#include<stdio.h>

int main(){
    float far, cel;
    printf("Enter the temperature in Farenheit: ");
    scanf("%f", &far);

    /* Conversion */
    cel = 5*(far-32)/9;
    printf("The temperature is equivalent to %f deg celcius",cel);
    return 0;
}