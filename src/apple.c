/* 8.2 リンゴ狩り */
#include<stdio.h>

#define N 1000000000;//a_iが最大かつn,kが最小の時ubも最大
int n;
int k;
int A[100000];

int p(int x){
    int i;
    //（A/xの切り上げ　の総和）<=　k　で1、それ以外で0
    int sum = 0;
    for(i = 0; i < n; i++){
        sum = sum + ((A[i] + x -1) / x);
    }
    return sum <= k;
}

int main(){
    int i, lb, ub, A_sum = 0;//A_sum:リンゴの総和
    scanf("%d%d", &n, &k);
    
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
        A_sum = A_sum + A[i];
    }
    lb = A_sum / k;//バッグのサイズは、（リンゴの総和/バッグの数）を下回らない
    ub = N;

    //binary search
    while(ub - lb > 1){
        int mid = (lb + ub) / 2;
        if(p(mid)){
            ub = mid;
        }else{
            lb = mid;
        }
    }
    //answer = ub
    printf("%d\n", ub);

    return 0;
}