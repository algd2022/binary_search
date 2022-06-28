/* 8.3 槍作り */
#include<stdio.h>

#define N 1000000000;//槍の長さの最大値は木の長さの最大値
int n;
int k;
int A[100000];

int p(int x){
    int i;
    //A/xの切り捨て　の総和がk未満で1 --> 求める値はlbになる
    int sum = 0;
    for(i = 0; i < n; i++){
        sum = sum + (A[i] / x);
    }
    return sum < k;
}

int main(){
    int i, lb, ub;
    scanf("%d%d", &n, &k);
    lb = 0;
    ub = N;
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    //binary search
    while(ub - lb > 1){
        int mid = (lb + ub) / 2;
        if(p(mid)){
            ub = mid;
        }else{
            lb = mid;
        }
    }
    //answer = lb(最大値を求める)
    printf("%d\n", lb);

    return 0;
}
