#include<stdio.h>
#include<math.h>
#define pi 3.14

int main(){
    int l,b;
    printf("Enter the length of the rectangle: ");
    scanf("%d",&l);
    printf("Enter the breadth of the rectangle: ");
    scanf("%d",&b);
    int per_r = 2*(l+b);
    int ar_r = l*b;
    float r,ratio;

    /* Areas of the rectangle and circle are equal --> pi*r*r = l*b */
    r = sqrtf((l*b)/pi);
    float per_c = 2*pi*r;
    ratio = per_r/per_c;
    printf("If the areas of the rectangle and circle are equal then,\nthe radius of the circle is %f units and the ratio of perimeters of rectangle and circle is %f\n",r,ratio);

    /* Perimeters of the rectangle and circle are equal --> 2*pi*r = 2*(l+b) */
    r = (l+b)/pi;
    float ar_c = pi*r*r;
    ratio = ar_r/ar_c;
    printf("If the perimeters of the rectangle and circle are equal then,\nthe radius of the circle is %f units and the ratio of areas of rectangle and circle is %f\n",r,ratio);
    return 0;
}