#include<stdio.h>

int main(){
    int l,b,rad;
    float pi = 3.14;
    printf("Enter the length of rectangle: ");
    scanf("%d", &l);
    printf("Enter the breadth of rectangle: ");
    scanf("%d", &b);
    printf("Enter the radius of circle: ");
    scanf("%d", &rad);

    /* Mensuration of rectangle */
    int area_r, per_r;
    area_r = l*b;
    per_r = 2*(l+b);

    /* Mensuration of circle */
    float area_c, cir_c;
    area_c = pi*rad*rad;
    cir_c = 2*pi*rad;

    printf("Area of rectangle: %d\nPerimeter of rectangle: %d\n",area_r,per_r);
    printf("Area of circle: %f\nCircumference of circle: %f",area_c,cir_c);
    return 0;
}