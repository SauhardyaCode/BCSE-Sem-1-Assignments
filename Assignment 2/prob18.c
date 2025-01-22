#include<stdio.h>
#define maxIter 100

// void main(){
//     int count=0,n=1,happy;
//     while (count<10){
//         happy=0;
//         for (int i=0;i<maxIter;i++){
//             while (n>0){
//                 happy+=(n%10)*(n%10);
//                 n/=10;
//             }
//             if (happy==1){
//                 count+=1;
//                 break;
//             };
//             n=happy;
//         }
//     }
//     printf("%d\n",count);
// }

void main(){
    int count=0,happy,num=0,var,iter=0;
    while (count<10){
        num++;
        var=num;
        while (iter<maxIter){
            if (happy==1){
                count+=1;
                break;
            };
            iter++;
            happy=0;
            while (var){
                happy+=(var%10)*(var%10);
                var/=10;
            var=happy;
            }
        }
    }
}