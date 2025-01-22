#include<stdio.h>
#define N 5

int main(){
    int arr[N];
    for (int i=0;i<N;i++){
        printf("Enter the marks for Subject %d: ",i+1);
        scanf("%d",&arr[i]);
        if (arr[i]<0 || arr[i]>100){
            printf("Marks must be in range 0-100 !\n");
            i--;
        }
    }
    int sum=0;
    for (int i=0;i<N;i++){
        sum+=arr[i];
    }
    float per=sum/(float)N;
    printf("The aggegate marks is %d which is equivalent to %f %%\n",sum,per);
    return 0;
}