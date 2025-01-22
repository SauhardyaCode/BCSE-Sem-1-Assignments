#include<stdio.h>
#define N 3

void main(){
    printf("All combinations of digits 1, 2 and 3 are:\n");
    for (int i=1;i<=N;i++){
        for (int j=1;j<=N;j++){
            for (int k=1;k<=N;k++){
                printf("%d%d%d\n",i,j,k);
            }
        }
    }
}