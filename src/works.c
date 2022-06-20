#include <stdio.h>

int n;
int k;
int A[100000];


int main(){
    int i, lb, ub, num, sum, max;
    max = 0;
    sum = 0;
    scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++){
        scanf("%d", &num);
        A[i] = num;
        sum = sum + num;
        if(num > max){
            max = num;
        }
    }
    lb = max - 1;
    ub = sum;
    int clk; /*clock*/
    int pl; /*people*/
    int work;
    while(ub - lb > 1){
        unsigned int mid = (lb + ub)/2;
        pl = 0;
        work = 0;
        /*最大値をmidにしたときk人に収まるか計算*/
        for(clk = 0; clk < n; clk++){
            work = work + A[clk];
            if(work + A[clk + 1] > mid){
                pl = pl + 1;
                work = 0;
            }
        }
        if(pl + 1 > k){
            lb = mid;
        }
        else{
            ub = mid;
        }
    }
    printf("\n%d",ub);
    return 0;
}
